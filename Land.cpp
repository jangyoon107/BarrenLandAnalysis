#include "Land.h"

Land::Land(int bottomLeftX, int bottomLeftY, int topRightX, int topRightY)
{
    bottomLeft.x = bottomLeftX;
    bottomLeft.y = bottomLeftY;

    upperRight.x = topRightX;
    upperRight.y = topRightY;

    upperLeft.x = bottomLeftX;
    upperLeft.y = topRightY;

    bottomRight.x = topRightX;
    bottomRight.y = bottomLeftY;
}

Point Land::GetUpperLeft()
{
    return upperLeft;
}

Point Land::GetUpperRight()
{
    return upperRight;
}

Point Land::GetBottomLeft()
{
    return bottomLeft;
}

Point Land::GetBottomRight()
{
    return bottomRight;
}

Land::~Land(){}