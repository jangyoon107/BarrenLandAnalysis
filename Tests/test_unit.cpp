#include "acutest.h"

#include "../Land.h"
#include "../Farm.h"
#include "../Point.h"

void test_Land_Initialization(void)
{
    TEST_CHECK_(Land(0, 2, 5, 6).IsValid() == true, "Land(%d, %d, %d, %d) == %d", 0, 2, 5, 6, true);
}

TEST_LIST = {
    {"int add(int, int);", test_Land_Initialization}, {0} /*must be terminated with 0 */
};