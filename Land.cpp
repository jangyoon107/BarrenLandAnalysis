#include "Land.h"

/*
 * Land(vector<int> coordinates): 
 * Constructor. from the given bottomleft and topright coordinates, calculate all four corners, size, and validity for future calculations.
 */
Land::Land(vector<int> coordinates)
{
    // Check if input coordinates have correct length (4 numbers)
    if(coordinates.size() != 4)
    {
        cout<<"Invalid format of coodinates, " <<coordinates.size() << " numbers found in a input... Excluding from the barren list."<<endl;
        validLand = false; 

        return;
    }

    int bottomLeftX = coordinates[0];
    int bottomLeftY = coordinates[1];
    int topRightX = coordinates[2];
    int topRightY = coordinates[3];

    // Check if input coordinates are valid (if coordinate is negative or coordinate has issues such as left x is bigger than right x)
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

        // Calculate the width and height of this particulate land object
        width = bottomRight.x - bottomLeft.x + 1;
        height = upperLeft.y - bottomLeft.y + 1;
    }
    else
    {
        cout<<"Invalid Barren Coordinates received... Excluding it from the barren list."<<endl;
        validLand = false; 
    }   
}

/*
 * bool IsValid(): 
 * Getter for validity of current land object.
 */
bool Land::IsValid() const
{
    return validLand;
}

/*
 * int GetWidth(): 
 * Getter for width of this land object
 */
int Land::GetWidth() const
{
    return width;
}

/*
 * int GetHeight(): 
 * Getter for height of this land object
 */
int Land::GetHeight() const
{
    return height;
}

/*
 * Point GetUpperLeft(): 
 * Getter for upper left point coordinate
 */
Point Land::GetUpperLeft() const
{
    return upperLeft;
}

/*
 * Point GetUpperRight(): 
 * Getter for upper right point coordinate
 */
Point Land::GetUpperRight() const
{
    return upperRight;
}

/*
 * Point GetBottomLeft(): 
 * Getter for bottom left point coordinate
 */
Point Land::GetBottomLeft() const
{
    return bottomLeft;
}

/*
 * Point GetBottomRight(): 
 * Getter for bottom right point coordinate
 */
Point Land::GetBottomRight() const
{
    return bottomRight;
}
