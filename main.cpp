#include "Farm.h"
#include "./Tests/test_main.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string.h>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2)
    {
        cout << "Not enought arguments to execute." << endl;
        exit(0);
    }

    vector<string> barrenLandInputs;
    Farm farm;

    /* parameter check: 
     *  -w: this flag is used to specify custom width of the farm (for custom testing)
     *  -h: this flag is used to specify custom height of the farm (for custom testing)
     *  -runtest: this flag will run tests defined in Test/test_main.cpp
     */
    char w[] = "-w";
    char h[] = "-h";
    char runTest[] = "-runtest";

    int newWidth  = 400, newHeight = 600;
    bool customInputFlag = false;

    int index = 1;
    while (index < argc)
    {
        char* argi = argv[index];

        if(strcmp(argi, runTest) == 0)
        {
            run_main_test();
            exit(0);
        }
        if (strcmp(argi, w) == 0 && (index + 1) < argc)
        {
            newWidth = atoi(argv[++index]);
            customInputFlag = true;
        }
        else if (strcmp(argi, h) == 0 && (index + 1) < argc)
        {
            newHeight = atoi(argv[++index]);
            customInputFlag = true;
        }
        else
        {
            string inputArg = argv[index];
            stringstream sstream(inputArg);

            while (sstream.good())
            {
                string argStr;
                getline(sstream, argStr, ',');
                barrenLandInputs.push_back(argStr);
            }
        }
        index++;
    }
    if (customInputFlag)
        farm.SetWidthHeight(newWidth, newHeight);

    if (!farm.IsValid())
        return 0;

    bool success = farm.SetBarrenAreas(barrenLandInputs);
    if(!success)
        return 0;

    farm.DisplayFarm();

    vector<int> result = farm.CalculateFertileLand();

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

}