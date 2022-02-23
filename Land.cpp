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

bool Land::IsValid() const
{
    return validLand;
}

int Land::GetWidth() const
{
    return width;
}

int Land::GetHeight() const
{
    return height;
}

Point Land::GetUpperLeft() const
{
    return upperLeft;
}

Point Land::GetUpperRight() const
{
    return upperRight;
}

Point Land::GetBottomLeft() const
{
    return bottomLeft;
}

Point Land::GetBottomRight() const
{
    return bottomRight;
}
