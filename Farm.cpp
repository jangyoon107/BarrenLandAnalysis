#include "Farm.h"


Farm::Farm()
{
    landWidth = 400;
    landHeight = 600;
}

Farm::Farm(int w, int h)
{
    landWidth = w;
    landHeight = h;
}

void Farm::SetWidthHeight(int w, int h)
{
    landWidth = w;
    landHeight = h;
}

void Farm::SetBarrenAreas(vector<string> barrenString)
{
    vector<int> coordinates;
    for (int i = 0; i < barrenString.size(); i++)
    {
        istringstream iss(barrenString[i]);

        string numString;
        while(iss>>numString)
        {
            int number = stoi(numString);
            coordinates.push_back(number);
        }

        if(coordinates.size() > 4)
        {
            // do error checking
        }

        Land barren(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
        barrenArea.push_back(barren);

        coordinates.clear();
    }
}

vector<int> Farm::CalculateFertileLand()
{

}