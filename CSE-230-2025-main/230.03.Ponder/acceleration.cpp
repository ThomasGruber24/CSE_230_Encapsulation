/***********************************************************************
 * Source File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich Thomas, David
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

 /*********************************************
  * ACCELERATION : Default constructor
  *********************************************/
Acceleration::Acceleration()
{
   ddx = 0.0;
   ddy = 0.0;
}

/*********************************************
 * ACCELERATION : Non-default constructor
 *********************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
   this->ddx = ddx;
   this->ddy = ddy;
}

/*********************************************
 * ACCELERATION : Getters
 *********************************************/
double Acceleration::getDDX() const { return ddx; }
double Acceleration::getDDY() const { return ddy; }

/*********************************************
 * ACCELERATION : Setters
 *********************************************/
void Acceleration::setDDX(double ddx) { this->ddx = ddx; }
void Acceleration::setDDY(double ddy) { this->ddy = ddy; }

/*********************************************
 * ACCELERATION : Set by angle
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   double radians = angle.getRadians();
   ddx = magnitude * sin(radians);
   ddy = magnitude * cos(radians);
}

/*********************************************
 * ACCELERATION : Additional functions
 *********************************************/
void Acceleration::addDDX(double ddx)
{
   this->ddx += ddx;
}

void Acceleration::addDDY(double ddy)
{
   this->ddy += ddy;
}

void Acceleration::add(const Acceleration& rhs)
{
   this->ddx += rhs.ddx;
   this->ddy += rhs.ddy;
}
