/*!*************************************************************************
****
\file ocean.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201526
\par Assignment 2: Battleship
\date 19-01-2023
\brief
Creates a simple version of the board game Battleship.
 The function include:
- CreateOcean
It creates an ocean that serves as the playing area of the game.
- DestroyOcean
This function is called by the client to clean up after the game by deallocating all previously
allocated memory.
- PlaceBoat
The client will create a boat, specify a position to locate this boat in the ocean, and then call this
function to record the boat's placement in the ocean grid.
- TakeShot
The client will pick a position coordinate in the ocean to aim a shot at and then call this function
to determine the result of the shot.
- GetShotStats
This function returns the statistics from the free store object referenced by ocean.
- DumpOcean
Prints the grid (ocean) to the screen.
Takes in the text file and reads its contents, it will then print out the statistical results to an output file.
****************************************************************************
***/
#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw
using namespace std;

namespace HLP2 
{
  namespace WarBoats 
  {
    int const BOAT_LENGTH {4};  
    int const HIT_OFFSET  {100}; 

/*!*************************************************************************
****
\brief
It creates an ocean that serves as the playing area of the game.
\param num_boats
The number of boats
\param x_size
The size of the grid in the x-direction
\param y_size
The size of the grid in the y-direction
\return
Ocean pointer
****************************************************************************
***/
    Ocean* CreateOcean(int num_boats, int x_size, int y_size) 
    {
      Ocean* oceany = new Ocean;
      oceany->grid = new int[x_size * y_size]();
      oceany->boats = new Boat[num_boats];
      oceany->boats->hits = 0;
      oceany->boats->ID = 0;
      oceany->num_boats = num_boats;
      oceany->x_size = x_size;
      oceany->y_size = y_size;
      oceany->stats.hits = 0;
      oceany->stats.misses = 0;
      oceany->stats.duplicates = 0;
      oceany->stats.sunk = 0;
      return oceany;
    }

/*!*************************************************************************
****
\brief
This function is called by the client to clean up after the game by deallocating all previously
allocated memory.
\param theOcean
The pointer to the ocean grid object.
\return
void
****************************************************************************
***/
    void DestroyOcean(Ocean *theOcean) 
    {
      delete theOcean;
      return;
    }

/*!*************************************************************************
****
\brief
The client will create a boat, specify a position to locate this boat in the ocean, and then call this
function to record the boat's placement in the ocean grid.
\param ocean
The reference to the ocean grid.
\param boat
The reference boat position.
\return
BoatPlacment enum member
****************************************************************************
***/
    BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat) 
    {
      if (ocean.boats->ID >= ocean.num_boats)
      {
        return bpREJECTED;
      } 
      if (boat.orientation == oHORIZONTAL) 
      {
        if ((boat.position.x <= ocean.x_size - BOAT_LENGTH || boat.position.x >= 0) && (boat.position.y <= ocean.y_size || boat.position.y >= 0)) 
        {
          for (int i = 0; i < BOAT_LENGTH; i++) 
          {
            if (ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] != 0) 
            {
              return bpREJECTED;
            }  
          }  
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++)
          {
            ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] = ocean.boats->ID;
          } 
        }
      }

      else if (boat.orientation == oVERTICAL) 
      {
        if ((boat.position.y <= ocean.y_size - BOAT_LENGTH || boat.position.y >= 0) && (boat.position.x <= ocean.x_size || boat.position.x >= 0)) 
        {
          for (int i = 0; i < BOAT_LENGTH; i++)
          {
            if (ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] != 0)
            {
              return bpREJECTED;
            } 
          } 
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++)
          {
            ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] = ocean.boats->ID;
          } 
        }
      }
      return bpACCEPTED;
    }

/*!*************************************************************************
****
\brief
The client will pick a position coordinate in the ocean to aim a shot at and then call this function
to determine the result of the shot.
\param ocean
The reference to the ocean grid.
\param coordinate
The reference to shot positioning coordinates. 
\return
ShotResult enum member
****************************************************************************
***/
    ShotResult TakeShot(Ocean& ocean, Point const& coordinate) 
    {
      if (!((coordinate.x <= ocean.x_size && coordinate.x >= 0) && (coordinate.y <= ocean.y_size && coordinate.y >= 0))) 
      {
          return srILLEGAL;
      }
      
      if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtOK) 
      {
        ocean.stats.misses++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] = dtBLOWNUP;
        return srMISS;
      }

      else if ((ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtBLOWNUP) || (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 + HIT_OFFSET && ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99 + HIT_OFFSET)) 
      {
        ocean.stats.duplicates++;
        return srDUPLICATE;
      }

      else if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 || ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99) 
      {
        ocean.stats.hits++;
        ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 1].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;
        if (ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 101].hits == BOAT_LENGTH) 
        {
          ocean.stats.sunk++;
          return srSUNK;
        }
      }

      return srHIT;
    }


/*!*************************************************************************
****
\brief
This function returns the statistics from the free store object referenced by ocean.
\param ocean
The reference to the ocean grid.
\return
ShotStats struct 
****************************************************************************
***/
    ShotStats GetShotStats(Ocean const& ocean) 
    {
      return ocean.stats;
    }


/*!*************************************************************************
****
\brief
Prints the grid (ocean) to the screen.
\param ocean
The Ocean to print.
\param field_width
How much space each position takes when printed.
\param extraline
If true, an extra line is printed after each row. If false, no extra
line is printed.
\param showboats
If true, the boats are shown in the output. (Debugging feature)
\return
void 
****************************************************************************
***/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean, int field_width, bool extraline, bool showboats) {
      for (int y = 0; y < ocean.y_size; y++) { // For each row
        for (int x = 0; x < ocean.x_size; x++) { // For each column
            // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
            // Is it a boat that we need to keep hidden?
          value = ( (value > 0) && (value < HIT_OFFSET) && (showboats == false) ) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline) { std::cout << "\n"; }
      }
    }
  } // namespace WarBoats
} // namespace HLP2