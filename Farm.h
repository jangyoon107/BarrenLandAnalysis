#ifndef FARM_H
#define FARM_H

#include "Land.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Farm
{
    private:
        int landWidth, landHeight;
        
        vector<Land> barrenArea;


    public:
        Farm();
        Farm(int w, int h);

        void SetWidthHeight(int w, int h);

        void SetBarrenAreas(vector<string> barrenString);
        vector<int> CalculateFertileLand();


};

#endif // FARM_H