/**********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    Thomas Gruber
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include <list>
#include "position.h"
#include "velocity.h"
#include "physics.h"
#include "uiDraw.h"

#define DEFAULT_PROJECTILE_WEIGHT 46.7       // kg
#define DEFAULT_PROJECTILE_RADIUS 0.077545   // m

// forward declaration for the unit test class
class TestProjectile; 

 /**********************************************************************
  * Projectile
  *    Everything we need to know about a projectile
  ************************************************************************/
class Projectile
{
public:
    friend ::TestProjectile;
   
    Projectile();

    void reset();

    void fire(const Position& posPixels, double time, const Angle& angle, double muzzleVelocity);

    void advance(double simulationTime);

private:
    struct PositionVelocityTime
    {
        PositionVelocityTime() : pos(), v(), t(0.0) {}
        Position pos;
        Velocity v;
        double t;
    };

    double mass;
    double radius;
    std::list<PositionVelocityTime> flightPath;
};