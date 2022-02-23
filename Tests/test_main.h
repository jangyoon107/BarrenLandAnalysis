#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include "../Land.h"
#include "../Farm.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void run_main_test();
void run_farm_with_input(string coordinates, int width, int height, string expected);

#endif // TEST_MAIN_H