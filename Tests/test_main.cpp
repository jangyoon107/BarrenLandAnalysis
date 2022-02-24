#include "test_main.h"

void run_main_test()
{
    cout<< "Running Default Tests..."<<endl;

    cout<<"Test 1: "<<endl;
    run_farm_with_input("0 292 399 307", 400, 600, "116800 116800");
    cout<<endl;

    cout<<"Test 2: "<<endl;
    run_farm_with_input("48 192 351 207, 48 392 351 407, 120 52 135 547, 260 52 275 547", 400, 600, "22816 192608");
    cout<<endl;

    cout<<endl;

    cout<< "Running Custom Tests..."<<endl;

    // Testing Invalid format within the inputs
    cout<<"Test 1: "<<endl;
    run_farm_with_input("48 192 351 207 48 392 351 407, 120 52 135 547, 260 52 275 547", 400, 600, "Invalid format of coodinates, 8 of numbers found on a input... Excluding from the barren list.\n224128");
    cout<<endl;

    // Testing invalid coordinate
    cout<<"Test 2: "<<endl;
    run_farm_with_input("48 192 351 207 48", 400, 600, "Invalid format of coodinates, 5 of numbers found on a input... Excluding from the barren list.\nInsufficient number of barren inputs.. Unable to contine. Exiting...\n");
    cout<<endl;

    // Small test case
    cout<<"Test 3: "<<endl;
    run_farm_with_input("0 2 9 5", 10, 10, "20 40");
    cout<<endl;

    // Small test case : zero land
    cout<<"Test 4: "<<endl;
    run_farm_with_input("1 1 3 3", 0, 0, "0");
    cout<<endl;

     // Small test case : negative barren land
    cout<<"Test 5: "<<endl;
    run_farm_with_input("-1 0 1 1, 4 4 9 9", 10, 10, "Invalid Barren Coordinates received... Excluding it from the barren list.\n64");
    cout<<endl;

     // Small test case : barren land extending to outside farm
    cout<<"Test 6: "<<endl;
    run_farm_with_input("0 5 12 12", 10, 10, "50");
    cout<<endl;

    // Small test case: isolated land in middle
    cout<<"Test 7: "<<endl;
    run_farm_with_input("1 1 2 4, 2 0 5 1, 2 4 5 5, 5 1 6 4", 10, 10, "4 68");
    cout<<endl;

    // Big test case: barren isolating three lands but barren intruding one land
    cout<<"Test 8: "<<endl;
    run_farm_with_input("0 292 399 307, 292 0 307 399", 400, 600, "26864 85264 115328");
    cout<<endl;

    // Big test case: barren completely seperating land into four
    cout<<"Test 9: "<<endl;
    run_farm_with_input("0 292 399 307, 195 0 205 599", 400, 600, "56648 56648 56940 56940");
    cout<<endl;

    // Big test case: only one barren cell
    cout<<"Test 10: "<<endl;
    run_farm_with_input("0 0 1 1", 400, 600, "239996");
    cout<<endl;

    // Big test case: no fertile land
    cout<<"Test 11: "<<endl;
    run_farm_with_input("0 0 399 599", 400, 600, "0");
    cout<<endl;

    // Big test case: barren surrounding fertile
    cout<<"Test 12: "<<endl;
    run_farm_with_input("0 0 1 599, 0 0 399 1, 0 598 399 599, 398 0 399 599", 400, 600, "236016");
    cout<<endl;
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

    bool success = farm.SetBarrenAreas(barrenLandInputs);
    if(success)
    {

        vector<int> result = farm.CalculateFertileLand();

        for (size_t i = 0; i < result.size() - 1; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<result[result.size() - 1];
    }
    
    // END:   Code being tested

    string outputs = buffer.str();
    int test_result = outputs.compare(expected);

    cout.rdbuf(prevcoutbuf);

    cout<<"Input: "<<coordinates<<endl;
    cout<<"Expected output: "<<expected<<endl;
    cout<<"Test output: "<<outputs<<endl;
    cout<<(test_result == 0 ? " Passed" : " Failed")<<endl; 
}