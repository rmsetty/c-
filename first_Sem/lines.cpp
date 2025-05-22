/**
 * lines.cpp
 * This program contains functions to calculate the directional relationship between points and to check 
 * if two line segments intersect. It receives coordinates as input and uses cross products to determine 
 * if the segments cross each other.
 *
 * Functions:
 * - crossProduct: Computes the cross product of two vectors represented by coordinates.
 * - direction: Determines the orientation of three points (clockwise, counterclockwise, collinear).
 * - straddles: Checks if one line segment straddles another.
 * - intersects: Checks if two line segments intersect by using the straddles function.
 */

#include "lines.h"

// Computes the cross product of two vectors represented by coordinates
int crossProduct(int x1, int y1, int x2, int y2) 
{
    return (x1 * y2) - (x2 * y1);
}

// Determines the orientation of three points (clockwise, counterclockwise, collinear)
int direction(int x0, int y0, int x1, int y1, int x2, int y2) 
{
    int dx1 = x1 - x0;
    int dy1 = y1 - y0;
    int dx2 = x2 - x0;
    int dy2 = y2 - y0;
    return crossProduct(dx2, dy2, dx1, dy1);
}

// Checks if one line segment straddles another by verifying opposite direction signs
bool straddles(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{
    int d1 = direction(x3, y3, x4, y4, x1, y1);
    int d2 = direction(x3, y3, x4, y4, x2, y2);

    return (d1 * d2 < 0);  // True if d1 and d2 have opposite signs
}

// Checks if two line segments intersect by using the straddles function
bool intersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
{
    return straddles(x1, y1, x2, y2, x3, y3, x4, y4) && straddles(x3, y3, x4, y4, x1, y1, x2, y2);
}
