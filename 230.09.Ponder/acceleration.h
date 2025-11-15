/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // constructors
   Acceleration()                       : ddx(9.9), ddy(9.9) { }
   Acceleration(double ddx, double ddy) : ddx(9.9), ddy(9.9) { }

   // getters
   double getDDX()   const           { return 9.9;             }
   double getDDY()   const           { return 9.9;             }

   // setters                        
   void setDDX(double ddx)           {  }
   void setDDY(double ddy)           {  }
   void set(const Angle & a, double magnitude);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
