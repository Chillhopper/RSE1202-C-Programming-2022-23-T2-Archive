////////////////////////////////////////////////////////////////////////////////
#ifndef OCEAN_H
#define OCEAN_H
////////////////////////////////////////////////////////////////////////////////

namespace HLP2 {
  namespace WarBoats {

        struct ShotStats {
      int hits;       //!< The number of boat hits
      int misses;     //!< The number of boat misses
      int duplicates; //!< The number of duplicate (misses/hits)
      int sunk;       //!< The number of boats sunk
    };

    enum Orientation   { oHORIZONTAL, oVERTICAL };
    enum ShotResult    { srHIT, srMISS, srDUPLICATE, srSUNK, srILLEGAL };
    enum DamageType    { dtOK = 0, dtBLOWNUP = -1 };
    enum BoatPlacement { bpACCEPTED, bpREJECTED };

    //struct Ocean; //!< Forward declaration for the Ocean 
        struct Point {
      int x; //!< x-coordinate (column)
      int y; //!< y-coordinate (row)
    };

    struct Boat {
          int hits; 
          int ID; 
          Orientation orientation; 
          Point position;
          };

    struct Ocean {
          int *grid; 
          Boat *boats; 
          int num_boats; 
          int x_size; 
          int y_size; 
          ShotStats stats; 
          };

    




      //! A coordinate in the Ocean


      //! A boat in the Ocean
     /*
    struct Boat {
      int hits;                 //!< Hits taken so far
      int ID;                   //!< Unique ID 
      Orientation orientation;  //!< Horizontal/Vertical
      Point position;           //!< x-y coordinate (left-top)
    };
    */
      //! Statistics of the "game"


      // The interface
    Ocean* CreateOcean(int num_boats, int x_size, int y_size);
    void DestroyOcean(Ocean *theOcean);
    ShotResult TakeShot(Ocean& ocean, Point const& coordinate);
    BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat);
    ShotStats GetShotStats(Ocean const& ocean);

      // Provided
    void DumpOcean(const Ocean &ocean, int width = 4, bool extraline = false, 
                   bool showboats = true);

  } // namespace WarBoats

} // namespace HLP2


#endif // OCEAN_H
////////////////////////////////////////////////////////////////////////////////
