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
   virtual double getDDX()   const           { return 9.9;             }
   virtual double getDDY()   const           { return 9.9;             }

   // setters                        
   virtual void setDDX(double ddx)           {  }
   virtual void setDDY(double ddy)           {  }
   virtual void set(const Angle & a, double magnitude);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};

#include <cassert>

/*********************************************
 * AccelerationDummy
 * A Dummy double for acceleration. This does nothing but assert.
 * Stubs will be derived from this for the purpose of making
 * isolated unit tests.
 *********************************************/
class AccelerationDummy : public Acceleration
{
public:
   // getters
   virtual double getDDX()   const { assert(false); return 99.9; }
   virtual double getDDY()   const { assert(false); return 99.9; }

   // setters                        
   virtual void setDDX(double ddx)           { assert(false); }
   virtual void setDDY(double ddy)           { assert(false); }
   virtual void set(const Angle& a, double magnitude);
   virtual void addDDX(double ddx)           { assert(false); }
   virtual void addDDY(double ddy)           { assert(false); }
   virtual void add(const Acceleration& rhs) { assert(false); }
};
