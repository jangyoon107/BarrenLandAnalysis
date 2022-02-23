#include "test_main.h"

void run_main_test()
{
    cout<< "Running Custom Tests..."<<endl;

    cout<<"Test 1: "<<endl;
    run_farm_with_input("0 292 399 307", 400, 600, "116800 116800");

    cout<<"Test 2: "<<endl;
    run_farm_with_input("48 192 351 207, 48 392 351 407, 120 52 135 547, 260 52 275 547", 400, 600, "22816 192608");

}

void run_farm_with_input(string coordinates, int width, int height, string expected)
{
    // Redirect std::cout to buffer for testing
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    vector<string> barrenLandInputs;
    Farm farm(width, height);

    stringstream sstream(coordinates);

    while (sstream.good())
    {
        string argStr;
        getline(sstream, argStr, ',');
        barrenLandInputs.push_back(argStr);
    }

    farm.SetBarrenAreas(barrenLandInputs);
    vector<int> result = farm.CalculateFertileLand();

    for (size_t i = 0; i < result.size() - 1; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result[result.size() - 1];
    
    // END:   Code being tested

    string outputs = buffer.str();
    int test_result = outputs.compare(expected);

    cout.rdbuf(prevcoutbuf);

    cout<<"Input: "<<coordinates<<endl;
    cout<<"Expected output: "<<expected<<endl;
    cout<<"Test output: "<<outputs<<endl;
    cout<<(test_result == 0 ? " Passed" : " Failed")<<endl; 
}