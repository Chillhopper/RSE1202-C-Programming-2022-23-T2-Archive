#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE  */
      Ocean* CreateOcean(int num_boats, int x_size, int y_size) {
      Ocean* ocean = new Ocean;
      ocean->grid = new int[x_size * y_size]();
      ocean->boats = new Boat[num_boats];
      ocean->boats->hits = 0;
      ocean->boats->ID = 0;
      ocean->num_boats = num_boats;
      ocean->x_size = x_size;
      ocean->y_size = y_size;
      ocean->stats.hits = 0;
      ocean->stats.misses = 0;
      ocean->stats.duplicates = 0;
      ocean->stats.sunk = 0;
      return ocean;
    }

    /*
     Ocean* CreateOcean(int num_boats, int hor_size, int vert_size){
       Ocean* newOcean = new Ocean;
       (*newOcean).grid = new int [hor_size*vert_size]{DamageType::dtOK};
       (*newOcean).boats = new Boat [num_boats];
       for(int i = 0; i < num_boats; i++)
       {
          (*newOcean).boats[i].hits = 0;
          (*newOcean).boats[i].ID = 0;
       }
       //(*newOcean).boats->hits;
       //(*newOcean).boats->ID;
       (*newOcean).num_boats = num_boats;
       (*newOcean).x_size = hor_size;
       (*newOcean).y_size = vert_size;
       (*newOcean).stats.duplicates = 0;
       (*newOcean).stats.hits = 0;
       (*newOcean).stats.misses = 0;
       (*newOcean).stats.sunk = 0;
       
       //Ocean* returnPtr = new Ocean;
       //returnPtr = &newOcean); 

       return newOcean;      
     }
     */
     
     void DestroyOcean(Ocean *theOcean){
       delete[] theOcean->grid;
       delete[] theOcean->boats;
       delete theOcean;
     }

         BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat) {
      if (ocean.boats->ID >= ocean.num_boats) return bpREJECTED;
      if (boat.orientation == oHORIZONTAL) {
        if ((boat.position.x <= ocean.x_size - BOAT_LENGTH || boat.position.x >= 0) && (boat.position.y <= ocean.y_size || boat.position.y >= 0)) {
          for (int i = 0; i < BOAT_LENGTH; i++) if (ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] != 0) return bpREJECTED;
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++) ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] = ocean.boats->ID;
        }
      }
      else if (boat.orientation == oVERTICAL) {
        if ((boat.position.y <= ocean.y_size - BOAT_LENGTH || boat.position.y >= 0) && (boat.position.x <= ocean.x_size || boat.position.x >= 0)) {
          for (int i = 0; i < BOAT_LENGTH; i++) if (ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] != 0) return bpREJECTED;
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++) ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] = ocean.boats->ID;
        }
      }
      return bpACCEPTED;
    }

      /*
     BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat)
     {
      //horizontal = 0 | vertical = 1
        const int& x = boat.position.x;
        const int& y = boat.position.y;

        int capx = x;
        int capy = y;
        
        for (int i = 0; i < 4; i++,capx++,capy++)
        {
          

          if (x > ocean.x_size || x < 0 || capx > ocean.x_size)
          {
            return BoatPlacement::bpREJECTED;
          }

          if (y > ocean.y_size || y < 0 || capy > ocean.y_size)
          {
            return BoatPlacement::bpREJECTED;
          }

        
        }
        

        if(boat.orientation == Orientation::oHORIZONTAL)
        {
          int flag = 0;

          for(int i = 0; i < 4; i++) //checking the whole 4 spaces
          {
            if((ocean.grid[y*ocean.y_size+x+i] != 0))
            {
              flag = 1;
            }
          }

          if (flag == 0) //means all the 4 spaces are ok
          {
            for(int i = 0; i < 4; i++) //ARRAY[ROW * WIDTH + COL]
            {
              if((ocean.grid[y*ocean.y_size+x+i] == 0))//checks whether there is an existing boat
              {
                ocean.grid[y*ocean.y_size+x+i] = boat.ID; //if empty put boat
              }
            }

            //return BoatPlacement::bpACCEPTED;

          }

          else //flag == 1, means one of the spaces there is an existing boat
          {
            flag = 0;
            return BoatPlacement::bpREJECTED;
          }

        }

        //-----------------------------------------------------------//
        else if(boat.orientation == Orientation::oVERTICAL)
        {
          int flag2 = 0;

          for(int i = 0; i < 4; i++) //checking the whole 4 spaces
          {
            if((ocean.grid[(y + i)*ocean.y_size+x] != 0))
            {
              flag2 = 1;
            }

            
          }

          if (flag2 == 0) //means all the 4 spaces are ok
          {
            for(int i = 0; i < 4; i++) //ARRAY[ROW * WIDTH + COL]
            {
              if((ocean.grid[(y + i)*ocean.y_size+x] == 0))//checks whether there is an existing boat
              {
                ocean.grid[(y + i)*ocean.y_size+x] = boat.ID; //if empty put boat
              }
            }

            //return BoatPlacement::bpACCEPTED;

          }

          else //flag == 1, means one of the spaces there is an existing boat
          {
            flag2 = 0;
            return BoatPlacement::bpREJECTED;
          }
        }

        return BoatPlacement::bpACCEPTED;
        
     }
     */

     ShotResult TakeShot(Ocean& ocean, Point const& coordinate) {
      if (!((coordinate.x <= ocean.x_size && coordinate.x >= 0) && (coordinate.y <= ocean.y_size && coordinate.y >= 0))) return srILLEGAL;
      if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtOK) {
        ocean.stats.misses++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] = dtBLOWNUP;
        return srMISS;
      }
      else if ((ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtBLOWNUP) || (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 + HIT_OFFSET && ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99 + HIT_OFFSET)) {
        ocean.stats.duplicates++;
        return srDUPLICATE;
      }
      else if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 || ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99) {
        ocean.stats.hits++;
        ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 1].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;
        if (ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 101].hits == BOAT_LENGTH) {
          ocean.stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }
      //supposed to return Hit, Miss, Sunk, Duplicatee, Illegal
      /*
     ShotResult TakeShot(Ocean& ocean, Point const& coordinate)
     {
      //if the shot is out of range
        int const& x = coordinate.x;
        int const& y = coordinate.y;

        if((coordinate.x >= ocean.x_size||coordinate.x<0)||(coordinate.y >= ocean.y_size || coordinate.y < 0))
        {
          return ShotResult::srILLEGAL;
        }
        
        else
        {
          int& v = ocean.grid[y*ocean.y_size+x];

          if(v == dtOK)
          {
            ocean.stats.misses++;
            ocean.grid[y*ocean.y_size+x] = dtBLOWNUP;
            return srMISS;
          }

          if(v == dtBLOWNUP || (v >= 1+HIT_OFFSET && v <= 99+HIT_OFFSET))
          {
            ocean.stats.duplicates++;
            return srDUPLICATE;
            
          }

          //if(v>=1 && v<=99)
          //{
            ocean.stats.hits++;
            ocean.boats[v-1].hits++;
            ocean.grid[y*ocean.y_size+x]+=HIT_OFFSET;

            if(ocean.boats[v-1].orientation == Orientation::oHORIZONTAL)
            {
            //ARRAY[ROW * WIDTH + COL]

              int temp = 0;

               for(int i = 0; i<4; i++)
               {
                

                if(((ocean.grid[y*ocean.y_size+x-i] >= 100) && (ocean.grid[y*ocean.y_size+x-i] == v)) || ((ocean.grid[y*ocean.y_size+x+i] >= 100) && (ocean.grid[y*ocean.y_size+x+i] >= 100) == v))
                {
                  temp++;
                }
               
              }

              if (temp == 4)
              {
                ocean.stats.sunk++;
                return srSUNK;
              }
              
            }


            if(ocean.boats[v-1].orientation == Orientation::oVERTICAL)
            {
            //ARRAY[ROW * WIDTH + COL]

            int temp = 0;

               for(int i = 0; i<4; i++)
               {

                if(((ocean.grid[(y+i)*ocean.y_size+x] >= 100) && (ocean.grid[(y+i)*ocean.y_size+x] >= 100) == v) || ((ocean.grid[(y-i)*ocean.y_size+x] >= 100) && (ocean.grid[(y-i)*ocean.y_size+x] >= 100) == v))
                {
                  temp++;
                }
                
                
              }

              if (temp == 4)
              {
                ocean.stats.sunk++;
                return srSUNK;
              }
             
             temp = 0;
            }


        //}

        
      }
      return srHIT;
    }
    */

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
