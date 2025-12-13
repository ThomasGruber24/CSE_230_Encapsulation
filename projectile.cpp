/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/


 #include "projectile.h"
 #include "angle.h"
#include <cmath>
 using namespace std;

 Projectile::Projectile()
 {
     mass = DEFAULT_PROJECTILE_WEIGHT;
     radius = DEFAULT_PROJECTILE_RADIUS;
     flightPath.clear();
 }

 void Projectile::reset()
 {
     mass = DEFAULT_PROJECTILE_WEIGHT;
     radius = DEFAULT_PROJECTILE_RADIUS;
     flightPath.clear();
 }

 void Projectile::fire(const Position& posPixels, double time, const Angle& angle, double muzzleVelocity)
 {
     PositionVelocityTime pvt;
     pvt.pos = posPixels;

     double a = angle.getRadians();

     pvt.v.dx = muzzleVelocity * cos(a - M_PI / 2.0);
     pvt.v.dy = muzzleVelocity * sin(a - M_PI / 2.0);

     pvt.t = time;
     flightPath.push_back(pvt);
 }

 void Projectile::advance(double simulationTime)
 {
     if (flightPath.empty())
         return;

     PositionVelocityTime last = flightPath.back();

     double dt = simulationTime - last.t;
     if (dt <= 0.0)
         return;

     const double g = -9.8064;
     auto compute_ax = [&](double vx, double vy) 
         {

         const double Cx = -0.001598;

         return Cx * vx;
         };
     auto compute_ay = [&](double vx, double vy) 
         {

         const double Cy = -0.003893;

         return g + Cy * vy;
         };

     PositionVelocityTime next;
     next.pos = last.pos;
     next.v = last.v;
     next.t = simulationTime;

     // Compute accelerations
     double ax = compute_ax(last.v.dx, last.v.dy);
     double ay = compute_ay(last.v.dx, last.v.dy);

     // update position: p = p0 + v0 * dt + 0.5 * a * dt^2
     next.pos.x = last.pos.x + last.v.dx * dt + 0.5 * ax * dt * dt;
     next.pos.y = last.pos.y + last.v.dy * dt + 0.5 * ay * dt * dt;

     // update velocity: v = v0 + a * dt
     next.v.dx = last.v.dx + ax * dt;
     next.v.dy = last.v.dy + ay * dt;

     flightPath.push_back(next);
 }
