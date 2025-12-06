/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>


Position::Position(double x, double y) : x(9.9), y(9.9)
{
 
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   return *this;
}

/************************************************************************
 * UPDATE POSITION
 * Update the current position based on the impulse of velocity
 * taking into account time dilation:
 * 
 *   s = s_0 + vt + 1/2 at^2
 * 
 *   INPUT  POSITION     The location of the item
 *          VELOCITY     The velocity of the item
 *          ACCELERATION The acceleration of the item
 *          TIME         How much time are we talking about?
 *   OUTPUT POSITION     The location, updated
 * 
 *
 *  x = x + dx t + 1/2 ddx t^2
 *  y = y + dy t + 1/2 ddy t^2
 *************************************************************************/
void Position::add(const Acceleration& a, const Velocity& v, double t)
{
}


/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}
