#ifndef LAND_H
#define LAND_H

#include "Point.h"

class Land
{
    private:
        Point upperLeft, upperRight, bottomLeft, bottomRight;
        bool validLand;
        int width, height;


    public:
        Land(int bottomLeftX, int bottomLeftY, int topRightX, int topRightY);
        ~Land();

        bool IsValid();

        int GetWidth();
        int GetHeight();

        Point GetUpperLeft();
        Point GetUpperRight();
        Point GetBottomLeft();
        Point GetBottomRight();
};

#endif // LAND_H