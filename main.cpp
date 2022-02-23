#include "Farm.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string.h>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    if(argc < 2)
    {
        cout<<"Not enought arguments to execute."<<endl;
        exit(0);
    }

    vector<string> barrenLandInputs;
    Farm farm;

    // default case: 400 x 600
    if(argc == 2)
    {
        string inputArg = argv[1];
        stringstream sstream(inputArg);

        while(sstream.good())
        {
            string argStr;
            getline(sstream, argStr, ',');
            barrenLandInputs.push_back(argStr);    
        }
        farm.SetBarrenAreas(barrenLandInputs);
    }

    // custom size for testing
    if(argc > 2)
    {
        char *w = "-w";
        char *h = "-h";

        int newWidth, newHeight;

        int index = 0;
        while(index < argc)
        {
            char *argi = argv[index];
            if (strcmp(argi, w) == 0 && (index + 1) < argc)
            {
                newWidth = atoi(argi);
            }
            else if (strcmp(argi, h) == 0 && (index + 1) < argc)
            {
                newHeight = atoi(argi);
            }
            else
            {
                string inputArg = argv[index];
                stringstream sstream(inputArg);

                while(sstream.good())
                {
                    string argStr;
                    getline(sstream, argStr, ',');
                    barrenLandInputs.push_back(argStr);    
                }
            }
            index++;
        }

        cout<<"width: "<<newWidth<<endl;
        cout<<"height: "<<newHeight<<endl;

        farm.SetWidthHeight(newWidth, newHeight);
        farm.SetBarrenAreas(barrenLandInputs);
    }

}