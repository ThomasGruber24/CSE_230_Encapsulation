/***********************************************************************
 * Source File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/ 

#include "velocity.h"
#include "acceleration.h"
#include "angle.h"

#include <math.h>  // for sqrt()

/*********************************************
 * VELOCITY Constructors
 *********************************************/

// Default constructor
Velocity::Velocity()
{
   dx = 0.0;
   dy = 0.0;
}

// Non-default constructor
Velocity::Velocity(double dx, double dy)
{
   this->dx = dx;
   this->dy = dy;
}

/*********************************************
 * VELOCITY Getters
 *********************************************/

//getDX
double Velocity::getDX() const
{
   return dx;
}

//getDY
double Velocity::getDY() const
{
   return dy;
}

//getSpeed: performs the pythagorean theorem on dx and dy, then returns the result (will be a positive value)
double Velocity::getSpeed() const
{
   return sqrt(dx * dx + dy * dy);
}

/*********************************************
 * VELOCITY Setters
 *********************************************/

// Set from angle and direction
void Velocity::set(const Angle& angle, double magnitude)
{
   // Get angle value
   double radians = angle.getRadians();
   // Convert to X and Y with magnitude
   dx = sin(radians) * magnitude;
   dy = cos(radians) * magnitude;
}

// Set just dx
void Velocity::setDX(double dx)
{
   this->dx = dx;
}

// Set just dy
void Velocity::setDY(double dy)
{
   this->dy = dy;
}


/*********************************************
 * VELOCITY : ADD
 *  v = v_0 + a t
 *********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
   // Get acceleration elements
   double ddx = acceleration.getDDX();
   double ddy = acceleration.getDDY();

   // Add acceleration values to velocity
   dx += ddx * time;
   dy += ddy * time;
}

/*********************************************
 * VELOCITY : ADDDX
 *  dx = dx_0 + input_dx
 *********************************************/
void Velocity::addDX(double dx)
{
   this->dx += dx;
}

/*********************************************
 * VELOCITY : ADDDY
 *  dy = dy_0 + input_dy
 *********************************************/
void Velocity::addDY(double dy)
{
   this->dy += dy;
}
