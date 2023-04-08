#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE  */
     Ocean* CreateOcean(int num_boats, int hor_size, int vert_size){
       Ocean* newOcean;
       (*newOcean).grid = new int [hor_size*vert_size]{DamageType::dtOK};
       newOcean.boats = new Boat [num_boats];
       for(int i = 0; i<num_boats; i++){
          newOcean.boats[i].hits = 0;
          newOcean.boats[i].ID = 0;
       }
       //newOcean.boats->hits;
       //newOcean.boats->ID;
       newOcean.num_boats = num_boats;
       newOcean.x_size = hor_size;
       newOcean.y_size = vert_size;
       newOcean.stats.duplicates = 0;
       newOcean.stats.hits = 0;
       newOcean.stats.misses = 0;
       newOcean.stats.sunk = 0;
       
       Ocean* returnPtr = new Ocean;
       returnPtr = &newOcean; 

       return returnPtr;      
     }
     
     void DestroyOcean(Ocean *theOcean){
       delete[] theOcean->grid;
       delete[] theOcean->boats;
       delete theOcean;
     }

     BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat){
      //horizontal = 0 | vertical = 1
        const int& x = boat.position.x;
        const int& y = boat.position.y;
        if(boat.orientation == Orientation::oHORIZONTAL){
          //ARRAY[ROW * WIDTH + COL]
          for(int i = 0; i<4; i++){
              if((ocean.grid[x*ocean.y_size+y+i] == 0)){
                ocean.grid[x*ocean.y_size+y+i] = boat.ID;
              }else{
                return BoatPlacement::bpREJECTED;
               }
          }
          return BoatPlacement::bpACCEPTED;
        }else if(boat.orientation == Orientation::oVERTICAL){
          for(int i = 0; i<4; i++){
            if((ocean.grid[(x-i)*ocean.y_size+y]) == 0){
              ocean.grid[(x-i)*ocean.y_size+y] = boat.ID;
            }else{
              return BoatPlacement::bpREJECTED;
            }
          }

        }else{
          return BoatPlacement::bpREJECTED;
        }
        
        //return BoatPlacement::bpACCEPTED;
        return BoatPlacement::bpREJECTED;
     }
      //supposed to return Hit, Miss, Sunk, Duplicatee, Illegal
     ShotResult TakeShot(Ocean& ocean, Point const& coordinate){
      //if the shot is out of range
        int const& x = coordinate.x;
        int const& y = coordinate.y;

        if((coordinate.x >= ocean.x_size||coordinate.x<0)||(coordinate.y >= ocean.y_size || coordinate.y < 0)){
          return ShotResult::srILLEGAL;
        }else{
          int v = ocean.grid[x*ocean.y_size+y];

          if(v == dtOK){
            ocean.stats.misses++;
            ocean.grid[x*ocean.y_size+y] = dtBLOWNUP;
            ocean.stats.misses++;
            return srMISS;
          }

          if(v == dtBLOWNUP || (v >= 1+HIT_OFFSET && v <= 99+HIT_OFFSET)){
            ocean.stats.duplicates++;
            return srDUPLICATE;
          }

          if(v>=1 && v<=99){
            ocean.stats.hits++;
            ocean.boats[v-1].hits++;
            ocean.grid[x*ocean.y_size+y]+=HIT_OFFSET;

            if(ocean.boats[v-1].orientation == Orientation::oHORIZONTAL){
            //ARRAY[ROW * WIDTH + COL]
               for(int i = 0; i<4; i++){
                if((ocean.grid[x*ocean.y_size+y+i] >= 100)){
                }else{
                  break;
                }
              }
              ocean.stats.sunk++;
              return srSUNK;
            }


            if(ocean.boats[v-1].orientation == Orientation::oVERTICAL){
            //ARRAY[ROW * WIDTH + COL]
               for(int i = 0; i<4; i++){
                if((ocean.grid[(x-i)*ocean.y_size+y] >= 100)){
                }else{
                  break;
                }
              }
              ocean.stats.sunk++;
              return srSUNK;
            }


        }

        return srHIT;
      }
    }

      ShotStats GetShotStats(Ocean const& ocean){
        return ocean.stats;
      }

    /**************************************************************************/
    /*!
      \brief
        Prints the grid (ocean) to the screen.
      
      \param ocean
        The Ocean to print
      
      \param field_width
        How much space each position takes when printed.
      
      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.
        
      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean,
                                    int field_width, 
                                    bool extraline, 
                                    bool showboats) {
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
