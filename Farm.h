#ifndef FARM_H
#define FARM_H

#include "Land.h"

#include <cassert>
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

        // Helper function for propagating BFS
        int BFSHelper(int y, int x);

    public:
        // Constructors
        Farm();
        Farm(int w, int h);

        // Setter for landWidth, landHeight
        void SetWidthHeight(int w, int h);

        // Setter for barrenland (conversion from string to land object)
        void SetBarrenAreas(vector<string> barrenString);
                
        // Perform Graph search to identify all fertile land sizes
        vector<int> CalculateFertileLand();

        // Simple display function for debugging. Only for small test cases
        void DisplayFarm();

        // Destructor
        ~Farm(){};
};

#endif // FARM_H