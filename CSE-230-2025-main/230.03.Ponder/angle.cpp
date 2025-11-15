/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Thomas, David
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double radians) const
{
   const double twoPi = 2.0 * M_PI;
   
   while (radians < 0)
      radians += twoPi;

   while (radians >= twoPi)
      radians -= twoPi;

   return radians;
}

double Angle::getDegrees() const
{
   return radians * (180.0 / M_PI);
}

double Angle::getRadians() const
{
   return radians;
}


