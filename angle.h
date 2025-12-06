/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestHowitzer;
class TestProjectile;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   // for the unit tests
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestHowitzer;
   friend TestProjectile;

   // Constructors
   Angle()                  : radians(9.9)         {}
   Angle(const Angle& rhs)  : radians(9.9)         {}
   Angle(double degrees)    : radians(9.9)         {}

   // Getters
   double getDegrees() const { return 9.9; }
   double getRadians() const { return 9.9; }

   //         dx
   //    +-------/
   //    |      /
   // dy |     /
   //    |    / 1.0
   //    | a /
   //    |  /
   //    | /
   // dy = cos a
   // dx = sin a
   double getDx() const { return 9.9; }
   double getDy() const { return 9.9; }
   bool   isRight()          const { return true; }
   bool   isLeft()           const { return true; }


   // Setters
   void setDegrees(double degrees) { }
   void setRadians(double radians) { }
   void setUp()                    { }
   void setDown()                  { }
   void setRight()                 { }
   void setLeft()                  { }
   void reverse()                  { }
   Angle& add(double delta)        { return *this; }

   // set based on the components
   //         dx
   //     +-------/
   //     |      /
   //  dy |     /
   //     |    /
   //     | a /
   //     |  /
   //     | /
   void setDxDy(double dx, double dy)  { }
   Angle operator+(double degrees) const { return Angle(); }

private:

   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
   out << rhs.getDegrees() << "degree";
   return out;
}