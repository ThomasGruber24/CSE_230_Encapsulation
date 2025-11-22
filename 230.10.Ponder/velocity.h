/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestProjectile;

// for add()
class Acceleration;
class Angle;

 /*********************************************
  * Velocity
  * I feel the need, the need for speed
  *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestProjectile;

   
public:
   // constructors
   Velocity()                     : dx(9.9), dy(9.9) { }
   Velocity(double dx, double dy) : dx(9.9), dy(9.9) { }

   // getters
   double getDX()       const { return 9.9; }
   double getDY()       const { return 9.9; }
   double getSpeed()    const;
   Angle  getAngle()    const;
   
   // setters
   void set(const Angle & angle, double magnitude);
   void setDX(double dx) {  }
   void setDY(double dy) {  }
   void addDX(double dx) {  }
   void addDY(double dy) {  }
   void add(const Acceleration & acceleration, double time);
   void add(const Velocity & rhs) { }
   void reverse() { }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

