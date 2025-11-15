/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "acceleration.h"

 /******************************************
  * POSITION Constructors
  *****************************************/

  // Default constructor
Position::Position()
{
    x = 0.0;
    y = 0.0;
}

// Constructor given x and y
Position::Position(double x, double y)
{
    this->x = x;
    this->y = y;
}

// Constructor copy
Position::Position(const Position& pos)
{
    x = pos.x;
    y = pos.y;
}


/******************************************
 * POSITION assign
 * Copy the values of another Position & returns itself
 *****************************************/

Position Position::assign(const Position& pos)
{
    x = pos.x;
    y = pos.y;
    return *this;
}


/******************************************
 * POSITION getters
 *****************************************/

 // Getter for x
double Position::getX() const
{
    return x;
}

// Getter for y
double Position::getY() const
{
    return y;
}

/******************************************
 * POSITION equality operators
 *****************************************/

 // == operator
bool Position::operator == (const Position& rhs) const
{
    // If elements of the position are equal, return true
    if (x == rhs.x && y == rhs.y)
    {
        return true;
    }

    // If elements of the position are not equal, return false
    return false;
}

// != operator
bool Position::operator != (const Position& rhs) const
{
    // If either element of the position unequal, return true
    if (x != rhs.x || y != rhs.y)
    {
        return true;
    }

    // If elements of the position are equal, return false
    return false;
}


/******************************************
 * POSITION setters
 *****************************************/

 // Setter for x
void Position::setX(double x)
{
    this->x = x;
}

// Setter for y
void Position::setY(double y)
{
    this->y = y;
}


/******************************************
 * POSITION Adders
 * Update point based on the distance formula
 *   s = s_0 + vt + 1/2 a t^2
 *****************************************/

 // Adder for x and y
void Position::add(const Acceleration& a, const Velocity& v, double t)
{
    x += v.getDX() * t + 0.5 * a.getDDX() * t * t;
    y += v.getDY() * t + 0.5 * a.getDDY() * t * t;
}

// Adder for x
void Position::addX(double x)
{
    this->x += x;
}

// Adder for y
void Position::addY(double y)
{
    this->y += y;
}