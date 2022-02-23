#ifndef LAND_H
#define LAND_H

#include "Point.h"

/*
 * Class: Land
 * Description: This class converts bottom left coordinate numbers and top right coordinate numbers to full coodinates of all four corners.
 * Includes additional getters for all four corners as well as width and height of the land.
 */
class Land
{
    private:
        // Coordinates of all four corners
        Point upperLeft, upperRight, bottomLeft, bottomRight;

        // Flag for validity of the land
        bool validLand;

        // width height of the land
        int width, height;

    public:
        // Constructor & destructor
        Land(int bottomLeftX, int bottomLeftY, int topRightX, int topRightY);
        ~Land(){};

        // Getter for validity of the land
        bool IsValid() const;

        // Getter for width, height of the land
        int GetWidth() const;
        int GetHeight() const;

        // Getter for coordinates of all four corners
        Point GetUpperLeft() const;
        Point GetUpperRight() const;
        Point GetBottomLeft() const;
        Point GetBottomRight() const;
};

#endif // LAND_H