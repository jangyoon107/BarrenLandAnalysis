#ifndef FARM_H
#define FARM_H

#include "Land.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

/*
 * Class: Farm
 * Description: This class defines the Farm and handles majority of functionalities needed for farm calculations.
 */
class Farm
{
    private:
        // Land size definition
        int landWidth, landHeight;
        
        // 2d vector matrix for keeping track of visited/barren coordinates for calculating fertile land
        vector<vector<int>> landVisited;

        // vector storing all barren land inputs
        vector<Land> barrenLands;

        // Given all barrenLand inputs, update landVisited matrix to reflect barren lands
        void UpdateLandMatrix();

        // Function for traversing graph (BFS based) and identifying area of connected fertile land
        int AreaDetectorBFS(int y, int x);

        // Flag for validity of farm size
        bool validFarmFlag;

    public:
        // Constructors
        Farm();
        Farm(int w, int h);

        // Setter for landWidth, landHeight
        void SetWidthHeight(int w, int h);

        // Setter for barrenland (conversion from string to land object)
        bool SetBarrenAreas(vector<string> barrenString);
                
        // Perform Graph search to identify all fertile land
        vector<int> CalculateFertileLand();

        // Simple display function for debugging. Only for small test cases
        void DisplayFarm();

        // Getter for validity flag for farm
        bool IsValid() const;

        // Destructor
        ~Farm(){};
};

#endif // FARM_H