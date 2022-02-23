#include "acutest.h"

#include "../Land.h"
#include "../Farm.h"
#include "../Point.h"

void test_Land_Initialization()
{
    TEST_CHECK_(Land(0, 2, 5, 6).IsValid() == true, "Land(%d, %d, %d, %d) == %d", 0, 2, 5, 6, true);
    TEST_CHECK_(Land(-2, 3, -1, 2).IsValid() == false, "Land(%d, %d, %d, %d) == %d", 0, 2, 5, 6, false);
    TEST_CHECK_(Land(0, 2, 1, 1).IsValid() == false, "Land(%d, %d, %d, %d) == %d", 0, 2, 5, 6, false);
    TEST_CHECK_(Land(0, 0, -1, 6).IsValid() == false, "Land(%d, %d, %d, %d) == %d", 0, 2, 5, 6, false);
}

TEST_LIST = {
    {"Land(int, int, int, int);", test_Land_Initialization}, 
};