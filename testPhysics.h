/***********************************************************************
 * Header File:
 *    TEST PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    All the automation for the physics functions
 ************************************************************************/


#pragma once

#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include "physics.h"
#include "unitTest.h"



/*******************************
 * TEST PHYSICS
 * A class containing automation for all the physics functions
 ********************************/
class TestPhysics : public UnitTest
{
public:
   void run()
   {

      // Ticket 1: Physics equations
      areaFromRadius_zero();
      areaFromRadius_one();
      areaFromRadius_two();
      areaFromRadius_projectile();

      forceFromDrag_noVelocity();
      forceFromDrag_noRadius();
      forceFromDrag_noDrag();
      forceFromDrag_noDensity();
      forceFromDrag_one();
      forceFromDrag_twoDensity();
      forceFromDrag_twoDrag();
      forceFromDrag_twoRadius();
      forceFromDrag_twoVelocity();
      forceFromDrag_projectile();

      accelerationFromForce_noForce();
      accelerationFromForce_ones();
      accelerationFromForce_twoForce();
      accelerationFromForce_twoMass();
      accelerationFromForce_projectile();

      velocityFromAcceleration_zeroAcceleration();
      velocityFromAcceleration_zeroTime();
      velocityFromAcceleration_ones();
      velocityFromAcceleration_twoAcceleration();
      velocityFromAcceleration_twoTime();

      // Ticket 2: Linear Interpolation equation
      linearInterpolation_coordinatesZero();
      linearInterpolation_coordinatesOne();
      linearInterpolation_coordinatesMiddle();
      linearInterpolation_coordinatesTop();
      linearInterpolation_coordinatesBackwards();

      // Ticket 3: Linear Interpolation with Mapping
      linearInterpolation_mappingZero();
      linearInterpolation_mappingTwo();
      linearInterpolation_mappingMid01();
      linearInterpolation_mappingTop01();
      linearInterpolation_mappinglower23();
      linearInterpolation_mappingSmall();
      linearInterpolation_mappingLarge();

      // Ticket 4: Gravity
      gravityFromAltitude_0();
      gravityFromAltitude_10000();
      gravityFromAltitude_80000();
      gravityFromAltitude_5500();
      gravityFromAltitude_43333();
      gravityFromAltitude_3666();
      gravityFromAltitude_8848();

      // Ticket 5: Density
      densityFromAltitude_0();
      densityFromAltitude_10000();
      densityFromAltitude_80000();
      densityFromAltitude_5500();
      densityFromAltitude_43333();
      densityFromAltitude_3666();
      densityFromAltitude_8848();

      // Ticket 6: Speed of Sound
      speedSoundFromAltitude_0();
      speedSoundFromAltitude_10000();
      speedSoundFromAltitude_80000();
      speedSoundFromAltitude_5500();
      speedSoundFromAltitude_43333();
      speedSoundFromAltitude_3666();
      speedSoundFromAltitude_8848();

      // Ticket 7: Drag
      dragFromMach_000();
      dragFromMach_500();
      dragFromMach_100();
      dragFromMach_060();
      dragFromMach_010();
      dragFromMach_314();

      report("Physics");
   }
private:


   /*****************************************************************
    *****************************************************************
    * AREA FROM RADIUS
    *    area = pi * radius ^ 2
    * double areaFromRadius(double radius);
    *****************************************************************
    *****************************************************************/

   /*******************************************************
    * AREA FROM RADIUS - zero
    * input: radius = 0
    * output: area = 0
    ********************************************************/
   void areaFromRadius_zero()
   {  // setup
      double radius = 0.0;
      double area = -999.99;
      // exercise
      area = areaFromRadius(radius);
      // verify
      assertEquals(area, 0.0);
   }  // teardown
   
   /*******************************************************
    * AREA FROM RADIUS - one
    *    area = pi * radius ^ 2
    * input: radius = 1.0
    * output: area = 3.1415926
    ********************************************************/
   void areaFromRadius_one()
   {  // setup
      double radius = 1.0;
      double area = -999.99;
      // exercise
      area = areaFromRadius(radius);
      // verify
      assertEquals(area, M_PI);
   }  // teardown

   /*******************************************************
    * AREA FROM RADIUS - two
    *    area = pi * radius ^ 2
    * input: radius = 2.0
    * output: area = 12.56637
    ********************************************************/
   void areaFromRadius_two()
   {  // setup
      double radius = 2.0;
      double area = -999.99;
      // exercise
      area = areaFromRadius(radius);
      // verify
      assertEquals(area, M_PI * 4.0);
   }  // teardown

   /*******************************************************
    * AREA FROM RADIUS - projectile
    *    area = pi * radius ^ 2
    * input: radius = 0.077545 the radius of the M795 projectile
    * output: area = 0.018891109
    ********************************************************/
   void areaFromRadius_projectile()
   {  // setup
      double radius = 0.077545; // radius of the M795 projectile
      double area = -999.99;
      // exercise
      area = areaFromRadius(radius);
      // verify
      assertEquals(area, .018891109);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * FORCE FROM DRAG
    * Determine the drag on a shell based on several things:
    *    density  : The density of the air ?
    *    drag     : The drag coefficient of the shell (no units)
    *    radius   : the radius of the shell (m)
    *    velocity : the velocity of the shell (m/s)
    * This force is determined by
    *    force = 1/2 density drag area velocity ^ 2
    * double forceFromDrag(double density, double drag,
    *                      double radius, double velocity)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * FORCE FROM DRAG - no velocity
     * input:  density=1 drag=1 radius=1 velocity=0
     * output: force=0
     ********************************************************/
   void forceFromDrag_noVelocity()
   {  // setup
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 0.0;
      double force = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 0.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - no radius
     * input:  density=1 drag=1 radius=0 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noRadius()
   {  // setup
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 0.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 0.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - no drag
     * input:  density=1 drag=0 radius=1 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noDrag()
   {  // setup
      double density  = 1.0;
      double drag     = 0.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 0.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - no density
     * input:  density=0 drag=1 radius=1 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noDensity()
   {  // setup
      double density  = 0.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 0.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - one of all
     * input:  density=1 drag=1 radius=1 velocity=1
     * output: force=pi/2
     ********************************************************/
   void forceFromDrag_one()
   {  // setup
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 0.5 * M_PI);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - two density
     * input:  density=2 drag=1 radius=1 velocity=1
     * output: force=pi
     ********************************************************/
   void forceFromDrag_twoDensity()
   {  // setup
      double density  = 2.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, M_PI);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - two drag
     * input:  density=0 drag=2 radius=1 velocity=1
     * output: force=pi
     ********************************************************/
   void forceFromDrag_twoDrag()
   {  // setup
      double density  = 1.0;
      double drag     = 2.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, M_PI);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - two radius
     * input:  density=0 drag=1 radius=2 velocity=1
     * output: force=2pi
     ********************************************************/
   void forceFromDrag_twoRadius()
   {  // setup
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 2.0;
      double velocity = 1.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, M_PI * 2.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - two velocity
     * input:  density=0 drag=1 radius=1 velocity=2
     * output: force=2pi
     ********************************************************/
   void forceFromDrag_twoVelocity()
   {  // setup
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 2.0;
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, M_PI * 2.0);
   }  // teardown

    /*******************************************************
     * FORCE FROM DRAG - projectile
     * input:  density=0.4135000  density of air at 10,000 meters
     *         drag=0.4258        drag coefficient at mach 1 
     *         radius=0.077545    radius of the M795 projectile
     *         velocity=827       muzzle velocity
     * output: force=1137.416876
     ********************************************************/
   void forceFromDrag_projectile()
   {  // setup
      double density  = 0.4135000; // 10,000 meters
      double drag     = 0.4258;    // mach 1
      double radius   = 0.077545;  // radius of the M795 projectile
      double velocity = 827.0;     // muzzle velocity
      double force    = -999.99;
      // exercise
      force = forceFromDrag(density, drag, radius, velocity);
      // verify
      assertEquals(force, 1137.4168762);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * ACCELERATION FROM FORCE
    * How much acceleration can we expect from a given force
    *    force        : N
    *    mass         : kg
    *    acceleration : m / s^2
    * Equation:
    *    f = m a
    * double accelerationFromForce(double force, double mass)
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * ACCELERATION FROM FORCE - zero force
     * input:  force=0 mass=1
     * output: acceleration=0
     ********************************************************/
   void accelerationFromForce_noForce()
   {  // setup
      double force        = 0.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // exercise
      acceleration = accelerationFromForce(force, mass);
      // verify
      assertEquals(acceleration, 0.0);
   }  // teardown

    /*******************************************************
     * ACCELERATION FROM FORCE - ones
     * input:  force=1 mass=1
     * output: acceleration=1
     ********************************************************/
   void accelerationFromForce_ones()
   {  // setup
      double force        = 1.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // exercise
      acceleration = accelerationFromForce(force, mass);
      // verify
      assertEquals(acceleration, 1.0);
   }  // teardown

    /*******************************************************
     * ACCELERATION FROM FORCE - two force
     * input:  force=2 mass=1
     * output: acceleration=2
     ********************************************************/
   void accelerationFromForce_twoForce()
   {  // setup
      double force        = 2.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // exercise
      acceleration = accelerationFromForce(force, mass);
      // verify
      assertEquals(acceleration, 2.0);
   }  // teardown

    /*******************************************************
     * ACCELERATION FROM FORCE - two mass
     * input:  force=1 mass=2
     * output: acceleration=1/2
     ********************************************************/
   void accelerationFromForce_twoMass()
   {  // setup
      double force        = 1.0;
      double mass         = 2.0;
      double acceleration = -9999.99;
      // exercise
      acceleration = accelerationFromForce(force, mass);
      // verify
      assertEquals(acceleration, 0.5);
   }  // teardown

    /*******************************************************
     * ACCELERATION FROM FORCE - projectile
     * input:  force=1137.4168762     // force at mach 1 at 10,000meters at muzzle velocity
     *         mass=46.7kg            // mass of the M795 projectile
     * output: acceleration=24.35582
     ********************************************************/
   void accelerationFromForce_projectile()
   {  // setup
      double force        = 1137.4168762;
      double mass         = 46.7;
      double acceleration = -9999.99;
      // exercise
      acceleration = accelerationFromForce(force, mass);
      // verify
      assertEquals(acceleration, 24.355821);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * VELOCITY FROM ACCELERATION
    * Determine how much velocity will be imparted in a given amount of time
    * from a given acceleration
    *    acceleration : m / s^2
    *    time         : s
    * Equation:
    *    v = a t
    *  double velocityFromAcceleration(double acceleration,
    *                                  double time)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * VELOCITY FROM ACCELERATION - zero acceleration
     * input:  a=0 t=1
     * output: v=0
     ********************************************************/
   void velocityFromAcceleration_zeroAcceleration()
   {  // setup
      double acceleration = 0.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // exercise
      velocity = velocityFromAcceleration(acceleration, time);
      // verify
      assertEquals(velocity, 0.0);
   }  // teardown

    /*******************************************************
     * VELOCITY FROM ACCELERATION - zero time
     * input:  a=1 t=0
     * output: v=0
     ********************************************************/
   void velocityFromAcceleration_zeroTime()
   {  // setup
      double acceleration = 1.0;
      double time         = 0.0;
      double velocity     = -9999.99;
      // exercise
      velocity = velocityFromAcceleration(acceleration, time);
      // verify
      assertEquals(velocity, 0.0);
   }  // teardown

    /*******************************************************
     * VELOCITY FROM ACCELERATION - ones
     * input:  a=1 t=1
     * output: v=1
     ********************************************************/
   void velocityFromAcceleration_ones()
   {  // setup
      double acceleration = 1.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // exercise
      velocity = velocityFromAcceleration(acceleration, time);
      // verify
      assertEquals(velocity, 1.0);
   }  // teardown

    /*******************************************************
     * VELOCITY FROM ACCELERATION - two acceleration
     * input:  a=2 t=1
     * output: v=2
     ********************************************************/
   void velocityFromAcceleration_twoAcceleration()
   {  // setup
      double acceleration = 2.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // exercise
      velocity = velocityFromAcceleration(acceleration, time);
      // verify
      assertEquals(velocity, 2.0);
   }  // teardown

    /*******************************************************
     * VELOCITY FROM ACCELERATION - two time
     * input:  a=1 t=2
     * output: v=2
     ********************************************************/
   void velocityFromAcceleration_twoTime()
   {  // setup
      double acceleration = 1.0;
      double time         = 2.0;
      double velocity     = -9999.99;
      // exercise
      velocity = velocityFromAcceleration(acceleration, time);
      // verify
      assertEquals(velocity, 2.0);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * LINEAR INTERPOLATION (coordinates version)
    * From a pair of domain/range values, interpolate
    *
    *    |        *(d1,r1)
    *    |       /
    *    |      *(d,r)
    *   r|     /
    *    |    *(d0,r0)
    *    |
    *    +-------------
    *           d
    * equation:
    *   (r - r0) / (d - d0) = (r1 - r0) / (d1 - d0)
    * Thus
    *   r  = r0 + (r1 - r0) (d - d0) / (d1 - d0)
    *
    * linearInterpolation(double d0, double r0,
    *                     double d1, double r1,
    *                     double d)
    *****************************************************************
    *****************************************************************/

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is (d0,r0)
    *
    *    |     8,8 * (d1,r1)
    *    |        /
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0) (d,r)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesZero()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is (d1,r1)
    *
    *    |     8,8 * (d1,r1) (d,r)
    *    |        /
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0) 
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesOne()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is in middle
    *
    *    |     8,8 * (d1,r1)
    *    |        /
    *    |  4,4  * (d,r)
    *   r|      /
    *    | 0,0 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesMiddle()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is near one
    *
    *    |     8,8 * (d1,r1)
    *    |    6,6 * (d,r)
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesTop()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is near one
    *
    *    | 1,9 * (d0,r0)
    *    |      \
    *    |   3,5 * (d,r)
    *    |        \
    *   r|         \
    *    |      7,-3 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesBackwards()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*****************************************************************
    *****************************************************************
    * LINEAR INTERPOLATION (mapping version)
    * From a list of domains and ranges, linear interpolate
    * double linearInterpolation(const Mapping mapping[], int numMapping, double domain);
    * 
    *     +---------------------+
    *     | Mapping             |
    *     +---------------------+
    *     | + domain : Double   |
    *     | + range : Double    |
    *     +---------------------+
    *****************************************************************
    *****************************************************************/

   /*********************************************************
    * LINEAR INTERPOLATION - mapping at [0]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]  (d,r)
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingZero()
   {  // setup
      const Mapping mapping[] = 
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 1.0;
      double r = -999.999;  // output
      // exercise
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // verify
      assertEquals(r, 2.0);
   }  // teardown

   /*********************************************************
    * LINEAR INTERPOLATION - mapping at [2]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2] (d,r)
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0] 
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingTwo()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping midway between [0]and[1]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|2,2.5* (d,r)
    *    |1,2 * mapping[0]  
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingMid01()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping closer to [1] than [0]
    *
    *    |           8,6.5 * mapping[3]
    *    |               /
    *    |         7,5   * mapping[2]
    *    |             /
    *    |          /
    *    |     3,3 * mapping[1]
    *   r|2.8,2.9 * (d,r)
    *    |   1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingTop01()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping closer to [2] than [3]
    *
    *    |        8,6.5 * mapping[3]
    *    |     7.3,5.5 * (d,r)
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappinglower23()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*********************************************************
    * LINEAR INTERPOLATION - too small - off the end on the low side
    *
    *    |        8,6.5 * mapping[3]
    *    |             /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    |0,2 * (d,r)
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingSmall()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*********************************************************
    * LINEAR INTERPOLATION - too large - off the end on the high side
    *
    *    |       50,6.5 * (d,r)
    *    |        8,6.5 * mapping[3]
    *    |             /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingLarge()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


   /*****************************************************************
    *****************************************************************
    * GRAVITY FROM ALTITUDE
    * Determine gravity coefficient based on the altitude
    *   double gravityFromAltitude(double altitude)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * GRAVITY FROM ALTITUDE - at the low range, 0 meters
     * input:  altitude=0
     * output: gravity=9.807
     ********************************************************/
   void gravityFromAltitude_0()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }


    /*******************************************************
     * GRAVITY FROM ALTITUDE - exactly on 10,000 meters
     * input:  altitude=10,000m
     * output: gravity=9.776
     ********************************************************/
   void gravityFromAltitude_10000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - at the high range, 80,000m
     * input:  altitude=80,000m
     * output: gravity=9.564
     ********************************************************/
   void gravityFromAltitude_80000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - exactly between two values, 5,5000m
     * input:  altitude=5,5000m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_5500()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - one-third between two values, 43,333.3m
     * input:  altitude=43,333m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_43333()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - two-third between two values, 3,666.6m
     * input:  altitude=3,666.6m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_3666()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - elevation of Mt Everest, 8,848.86m
     * input:  altitude=8,848.86m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_8848()
   {  // setup
      double altitude = 8848.86;
      double gravity = -999.999;
      // exercise
      gravity = gravityFromAltitude(altitude);
      // verify
      assertEquals(gravity, 9.77945);
   }  // teardown



   /*****************************************************************
    *****************************************************************
    * DENSITY FROM ALTITUDE
    * Determine the density of air based on the altitude
    *    densityFromAltitude(double altitude);
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * DENSITY FROM ALTITUDE - at the low range, 0 meters
     * input:  altitude=0
     * output: density=1.225
     ********************************************************/
   void densityFromAltitude_0()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - exactly on 10,000 meters
     * input:  altitude=10,000m
     * output: density=0.4135000
     ********************************************************/
   void densityFromAltitude_10000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - at the high range, 80,000m
     * input:  altitude=80,000m
     * output: density=0.0000185
     ********************************************************/
   void densityFromAltitude_80000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - exactly between two values, 5,5000m
     * input:  altitude=5,5000m
     * output: density=0.69825
     ********************************************************/
   void densityFromAltitude_5500()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - one-third between two values, 43,333.3m
     * input:  altitude=43,333m
     * output: density=0.0030063   almost a vacuum
     ********************************************************/
   void densityFromAltitude_43333()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - two-third between two values, 3,666.6m
     * input:  altitude=3,666.6m
     * output: density=0.849372
     ********************************************************/
   void densityFromAltitude_3666()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - elevation of Mt Everest, 8,848.86m
     * input:  altitude=8,848.86m
     * output: density= 0.4759719  1/3 that of sea level
     ********************************************************/
   void densityFromAltitude_8848()
   {  // setup
      double altitude = 8848.86;
      double density = -999.999;
      // exercise
      density = densityFromAltitude(altitude);
      // verify
      assertEquals(density, 0.4759719);
   }  // teardown
   

   /*****************************************************************
    *****************************************************************
    * SPEED OF SOUND FROM ALTITUDE
    * determine the speed of sound for a given altitude.
    * double speedSoundFromAltitude(double altitude);
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : sea level
     * input:  altitude=0m
     * output: 340m/s
     ********************************************************/
   void speedSoundFromAltitude_0()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 10,000m
     * input:  altitude=10,000m
     * output: 299m/s
     ********************************************************/
   void speedSoundFromAltitude_10000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 80,000m
     * input:  altitude=80,000m
     * output: 269m/s
     ********************************************************/
   void speedSoundFromAltitude_80000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 5,500m
     * input:  altitude=5,500
     * output: 318.0m/s
     ********************************************************/
   void speedSoundFromAltitude_5500()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 43,333m
     * input:  altitude=43,333m
     * output: 328.3m/s
     ********************************************************/
   void speedSoundFromAltitude_43333()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 3,666m
     * input:  altitude=3,666m
     * output: 325.3m/s
     ********************************************************/
   void speedSoundFromAltitude_3666()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : on top of Mount Everest
     * input:  altitude=8,848m
     * output: 303.76m/s
     ********************************************************/
   void speedSoundFromAltitude_8848()
   {  // setup
      double altitude = 8848.0;
      double speed = -99.99;
      // exercise
      speed = speedSoundFromAltitude(altitude);
      // verify
      assertEquals(speed, 303.76);
   }  // teardown

   /*****************************************************************
    *****************************************************************
    * DRAG FROM MACH
    * Determine the drag coefficient for a M795 shell given speed in Mach
    * double dragFromMach(double speedMach)
    *****************************************************************
    *****************************************************************/
   
    /*******************************************************
     * DRAG FROM MACH : not moving
     * input:  speed=0mach
     * output: 0
     ********************************************************/
   void dragFromMach_000()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DRAG FROM MACH : top speed
     * input:  speed=5.00mach
     * output: 0.2656
     ********************************************************/
   void dragFromMach_500()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DRAG FROM MACH : speed of sound
     * input:  speed=1.00mach
     * output: 0.4258
     ********************************************************/
   void dragFromMach_100()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DRAG FROM MACH : halfway between 0.5 and 0.7
     * input:  speed=0.6mach
     * output: 0.1845
     ********************************************************/
   void dragFromMach_060()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DRAG FROM MACH : one third between 0 and .3
     * input:  speed=0.1mach
     * output: 00.0543
     ********************************************************/
   void dragFromMach_010()
   {
      assertUnit(NOT_YET_IMPLEMENTED);
   }

    /*******************************************************
     * DRAG FROM MACH : random spot
     * input:  speed=3.14159mach
     * output: 00.0543
     ********************************************************/
   void dragFromMach_314()
   {  // setup
      double speedMach = 0.1;
      double drag = -99.99;
      // exercise
      drag = dragFromMach(speedMach);
      // verify
      assertEquals(drag, 0.0543);
   }  // teardown

};
