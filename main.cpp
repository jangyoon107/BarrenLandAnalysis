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


    char w[] = "-w";
    char h[] = "-h";
    char runTest[] = "-runtest";

    int newWidth, newHeight;
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

    farm.SetBarrenAreas(barrenLandInputs);
    farm.DisplayFarm();


    vector<int> result = farm.CalculateFertileLand();

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

}