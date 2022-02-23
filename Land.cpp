#include "Land.h"

Land::Land(int bottomLeftX, int bottomLeftY, int topRightX, int topRightY)
{
    if(bottomLeftX <= topRightX && bottomLeftX >= 0 && bottomLeftY <= topRightY && bottomLeftY >= 0)
    {
        validLand = true;

        bottomLeft.x = bottomLeftX;
        bottomLeft.y = bottomLeftY;

        upperRight.x = topRightX;
        upperRight.y = topRightY;

        upperLeft.x = bottomLeftX;
        upperLeft.y = topRightY;

        bottomRight.x = topRightX;
        bottomRight.y = bottomLeftY;

        width = bottomRight.x - bottomLeft.x + 1;
        height = upperLeft.y - bottomLeft.y + 1;
    }
    else
        validLand = false;    
}

bool Land::IsValid()
{
    return validLand;
}

int Land::GetWidth()
{
    return width;
}

int Land::GetHeight()
{
    return height;
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