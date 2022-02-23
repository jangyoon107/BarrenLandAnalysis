#ifndef FARM_H
#define FARM_H

#include "Land.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Farm
{
    private:
        int landWidth, landHeight;
        
        vector<vector<int>> landVisited;
        vector<Land> barrenLands;

        void UpdateLandMatrix();
        int BFSHelper(int y, int x);

    public:
        Farm();
        Farm(int w, int h);

        void SetWidthHeight(int w, int h);

        void SetBarrenAreas(vector<string> barrenString);

        
        vector<int> CalculateFertileLand();

        void DisplayFarm();

};

#endif // FARM_H