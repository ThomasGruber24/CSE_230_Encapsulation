// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.14159265358979323846264338327950288
#define GRAVITY -9.8

using namespace std;

// ---------- Equations ----------
double degreesToRadians(double degree)
{
    return (degree * PI) / 180.0;
}

double radiansToDegrees(double radians)
{
    return (radians * 180.0) / PI;
}

double verticalComponent(double speed, double angle)
{
    return speed * cos(angle);
}

double horizontalComponent(double speed, double angle)
{
    return speed * sin(angle);
}

double distanceFormula(double initialDistance, double velocity, double time, double equationAcceleration)
{
    return initialDistance + (velocity * time) + (0.5 * equationAcceleration * (time * time));
}

double kinematicsEquation(double initialVelocity, double equationAcceleration, double time)
{
    return initialVelocity + (equationAcceleration * time);
}

double linearInterpolation(double r0, double r1, double d0, double d1, double d)
{
    return r0 + (r1 - r0) * ((d - d0) / (d1 - d0));
}

double angleFromComponents(double dx, double dy)
{
   return atan2(dx, dy);
}


// ---------- Assignment ----------

// Inertia function, passed
void inertia(double initialSpeed, double initialAngle)
{
    double distance = 0.0;
    double altitude = 0.0;

    double angleInRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleInRadians); // s * sin(a)
    double dy = verticalComponent(initialSpeed, angleInRadians);   // s * cos(a)

    for (int time = 1; time <= 20; ++time)
    {
        distance += dx;
        altitude += dy;
    }

    cout << "Inertia -> Distance: " << distance << "m   Altitude: " << altitude << "m" << endl;
}


// Acceleration function, passed
void acceleration(double constantGravity, double initialSpeed, double initialAngle)
{
    double distance = 0.0;
    double altitude = 0.0;

    double angleInRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleInRadians);
    double dy = verticalComponent(initialSpeed, angleInRadians);

    for (int time = 1; time <= 20; ++time)
    {
        distance = distanceFormula(distance, dx, 1.0, 0.0);
        altitude = distanceFormula(altitude, dy, 1.0, constantGravity);
        dy = kinematicsEquation(dy, constantGravity, 1.0);
    }

    cout << "Acceleration -> Distance: " << distance << "m   Altitude: " << altitude << "m" << endl;
}

//Ground Impact, passed (round up the decimal, it has 2 digits instead of the 1 that is on the assignment)
void groundImpact(double timeInterval, double gravity, double initialSpeed, double initialAngle)
{
	double impactDistance = 0.0;
	double impactAltitude = 0.0;
	double hangTime = 0.0;

	double angleInRadians = degreesToRadians(initialAngle);

	double dx = horizontalComponent(initialSpeed, angleInRadians);
	double dy = verticalComponent(initialSpeed, angleInRadians);

    while (impactAltitude >= 0.0)
    {
		impactDistance = distanceFormula(impactDistance, dx, timeInterval, 0.0);
		impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, gravity);
		dy = kinematicsEquation(dy, gravity, timeInterval);
		hangTime += timeInterval;
    }

    cout << "distance: " << impactDistance << "m"
        << " altitude: " << impactAltitude << "m"
		<< " hang time: " << hangTime << "s" << endl;
}

double getGravity(double altitude, const vector<double>& altitudes, const vector<double>& gravities)
{
    if (altitude <= altitudes.front())
        return gravities.front();

    for (size_t i = 0; i < altitudes.size() - 1; ++i)
    {
        if (altitude >= altitudes[i] && altitude <= altitudes[i + 1])
        {
            return linearInterpolation(
                gravities[i],
                gravities[i + 1],
                altitudes[i],
                altitudes[i + 1],
                altitude
            );
        }
    }

    return gravities.back();
}


void gravity(double timeInterval, double initialSpeed, double initialAngle,
    const vector<double>& altitudes, const vector<double>& gravities)
{
    double impactDistance = 0.0;
    double impactAltitude = 0.0;
    double hangTime = 0.0;

    double angleRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleRadians);
    double dy = verticalComponent(initialSpeed, angleRadians);

    while (impactAltitude >= 0.0)
    {
        double g = -getGravity(impactAltitude, altitudes, gravities);

        impactDistance = distanceFormula(impactDistance, dx, timeInterval, 0.0);
        impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, g);
        dy = kinematicsEquation(dy, g, timeInterval);

        hangTime += timeInterval;
    }

    cout << "Distance: " << impactDistance << " m"
        << "   Altitude: " << impactAltitude << " m"
        << "   Hang Time: " << hangTime << " s" << endl;
}

// Drag
void dragStepFunction(double timeInterval, double initialSpeed, double initialAngle, const vector<double>& altitudes, const vector<double>& gravities)
{
   double dragCoefficient = 0.3;
   double airDensity = 0.6;
   double mass = 46.7;
   double area = PI * (.15489 / 2.0) * (.15489 / 2.0);

   double impactDistance = 0.0;
   double impactAltitude = 0.0;
   double hangTime = 0.0;

   double angleRadians = degreesToRadians(initialAngle);
   double dx = horizontalComponent(initialSpeed, angleRadians);
   double dy = verticalComponent(initialSpeed, angleRadians);

   while (impactAltitude >= 0.0)
   {
      // Gravity
      double gravity = -getGravity(impactAltitude, altitudes, gravities);
      // Speed
      double speed = sqrt(dx * dx + dy * dy);
      // Drag
      double drag = 0.5 * dragCoefficient * airDensity * speed * speed * area;
      double dragAcceleration = drag / mass;
      // Angle
      double angleRadians= angleFromComponents(dx, dy);
      // Acceleration from drag
      double ddx = -dragAcceleration * sin(angleRadians);
      double ddy = -dragAcceleration * cos(angleRadians);
      // Add gravity to acceleration
      ddy = ddy + gravity;

      impactDistance = distanceFormula(impactDistance, dx, timeInterval, ddx);
      impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, ddy);
      dx = kinematicsEquation(dx, ddx, timeInterval);
      dy = kinematicsEquation(dy, ddy, timeInterval);

      hangTime += timeInterval;
   }

   cout << "With Drag > Distance: " << impactDistance << " m"
      << "   Altitude: " << impactAltitude << " m"
      << "   Hang Time: " << hangTime << " s" << endl;
}


// Air density helper function
double getAirDensity(double altitude, const vector<double>& altitudes, const vector<double>& densities)
{
   if (altitude <= altitudes.front())
      return densities.front();

   for (size_t i = 0; i < altitudes.size() - 1; ++i)
   {
      if (altitude >= altitudes[i] && altitude <= altitudes[i + 1])
      {
         return linearInterpolation(
            densities[i],
            densities[i + 1],
            altitudes[i],
            altitudes[i + 1],
            altitude
         );
      }
   }

   return densities.back();
}

// Air Density
void airDensityStepFunction(double timeInterval, double initialSpeed, double initialAngle, const vector<double>& altitudes, const vector<double>& gravities, const vector<double>& densities)
{
   double dragCoefficient = 0.3;
   double mass = 46.7;
   double area = PI * (.15489 / 2.0) * (.15489 / 2.0);

   double impactDistance = 0.0;
   double impactAltitude = 0.0;
   double hangTime = 0.0;

   double angleRadians = degreesToRadians(initialAngle);
   double dx = horizontalComponent(initialSpeed, angleRadians);
   double dy = verticalComponent(initialSpeed, angleRadians);

   while (impactAltitude >= 0.0)
   {
      // Gravity
      double gravity = -getGravity(impactAltitude, altitudes, gravities);
      // Calculate air density
      double airDensity = getAirDensity(impactAltitude, altitudes, densities);
      // Speed
      double speed = sqrt(dx * dx + dy * dy);
      // Drag
      double drag = 0.5 * dragCoefficient * airDensity * speed * speed * area;
      double dragAcceleration = drag / mass;
      // Angle
      double angleRadians = angleFromComponents(dx, dy);
      // Acceleration from drag
      double ddx = -dragAcceleration * sin(angleRadians);
      double ddy = -dragAcceleration * cos(angleRadians);
      // Add gravity to acceleration
      ddy = ddy + gravity;

      impactDistance = distanceFormula(impactDistance, dx, timeInterval, ddx);
      impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, ddy);
      dx = kinematicsEquation(dx, ddx, timeInterval);
      dy = kinematicsEquation(dy, ddy, timeInterval);

      hangTime += timeInterval;
   }

   cout << "With Air Desity > Distance: " << impactDistance << " m"
      << "   Altitude: " << impactAltitude << " m"
      << "   Hang Time: " << hangTime << " s" << endl;
}


// Speed of Sound helper function
double getSpeedOfSound(double altitude, const vector<double>& altitudes, const vector<double>& speeds)
{
   if (altitude <= altitudes.front())
      return speeds.front();

   for (size_t i = 0; i < altitudes.size() - 1; ++i)
   {
      if (altitude >= altitudes[i] && altitude <= altitudes[i + 1])
      {
         return linearInterpolation(
            speeds[i],
            speeds[i + 1],
            altitudes[i],
            altitudes[i + 1],
            altitude
         );
      }
   }

   return speeds.back();
}

// Drag Coefficient helper function
double getDragCoefficient(double mach, const vector<double>& machNumbers, const vector<double>& coefficients)
{
   if (mach <= machNumbers.front())
      return coefficients.front();

   for (size_t i = 0; i < machNumbers.size() - 1; ++i)
   {
      if (mach >= machNumbers[i] && mach <= machNumbers[i + 1])
      {
         return linearInterpolation(
            coefficients[i],
            coefficients[i + 1],
            machNumbers[i],
            machNumbers[i + 1],
            mach
         );
      }
   }

   return coefficients.back();
}

// Drag Coefficient
void dragCoefficientStepFunction(double timeInterval, double initialSpeed, double initialAngle, const vector<double>& altitudes, const vector<double>& gravities, const vector<double>& densities, const vector<double>& soundSpeeds, const vector<double>& machNumbers, const vector<double>& coefficients)
{
   double mass = 46.7;
   double area = PI * (.15489 / 2.0) * (.15489 / 2.0);

   double impactDistance = 0.0;
   double impactAltitude = 0.0;
   double hangTime = 0.0;

   double angleRadians = degreesToRadians(initialAngle);
   double dx = horizontalComponent(initialSpeed, angleRadians);
   double dy = verticalComponent(initialSpeed, angleRadians);

   while (impactAltitude >= 0.0)
   {
      // Gravity
      double gravity = -getGravity(impactAltitude, altitudes, gravities);
      // Calculate air density
      double airDensity = getAirDensity(impactAltitude, altitudes, densities);
      // Sound speed
      double speedOfSound = getSpeedOfSound(impactAltitude, altitudes, soundSpeeds);
      // Speed
      double speed = sqrt(dx * dx + dy * dy);
      double machSpeed = speed / speedOfSound;
      // Drag doefficient
      double dragCoefficient = getDragCoefficient(machSpeed, machNumbers, coefficients);
      // Drag
      double drag = 0.5 * dragCoefficient * airDensity * speed * speed * area;
      double dragAcceleration = drag / mass;
      // Angle
      double angleRadians = angleFromComponents(dx, dy);
      // Acceleration from drag
      double ddx = -dragAcceleration * sin(angleRadians);
      double ddy = -dragAcceleration * cos(angleRadians);
      // Add gravity to acceleration
      ddy = ddy + gravity;

      impactDistance = distanceFormula(impactDistance, dx, timeInterval, ddx);
      impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, ddy);
      dx = kinematicsEquation(dx, ddx, timeInterval);
      dy = kinematicsEquation(dy, ddy, timeInterval);

      hangTime += timeInterval;
   }

   cout << "With Drag Coefficient > Distance: " << impactDistance << " m"
      << "   Altitude: " << impactAltitude << " m"
      << "   Hang Time: " << hangTime << " s" << endl;
}

// Hit The Ground
void hitTheGroundStepFunction(double timeInterval, double initialSpeed, double initialAngle, const vector<double>& altitudes, const vector<double>& gravities, const vector<double>& densities, const vector<double>& soundSpeeds, const vector<double>& machNumbers, const vector<double>& coefficients)
{
   double mass = 46.7;
   double area = PI * (.15489 / 2.0) * (.15489 / 2.0);

   double impactDistance = 0.0;
   double impactAltitude = 0.0;
   double hangTime = 0.0;

   double angleRadians = degreesToRadians(initialAngle);
   double dx = horizontalComponent(initialSpeed, angleRadians);
   double dy = verticalComponent(initialSpeed, angleRadians);

   double lastDistance = impactDistance;
   double lastAltitude = impactAltitude;
   double lastTime = hangTime;

   double actualImpactTime = -1;
   double actualImpactDistance = -1;

   while (impactAltitude >= 0.0)
   {
      // Save last state during iteration
      lastDistance = impactDistance;
      lastAltitude = impactAltitude;
      lastTime = hangTime;

      // Gravity
      double gravity = -getGravity(impactAltitude, altitudes, gravities);
      // Calculate air density
      double airDensity = getAirDensity(impactAltitude, altitudes, densities);
      // Sound speed
      double speedOfSound = getSpeedOfSound(impactAltitude, altitudes, soundSpeeds);
      // Speed
      double speed = sqrt(dx * dx + dy * dy);
      double machSpeed = speed / speedOfSound;
      // Drag doefficient
      double dragCoefficient = getDragCoefficient(machSpeed, machNumbers, coefficients);
      // Drag
      double drag = 0.5 * dragCoefficient * airDensity * speed * speed * area;
      double dragAcceleration = drag / mass;
      // Angle
      double angleRadians = angleFromComponents(dx, dy);
      // Acceleration from drag
      double ddx = -dragAcceleration * sin(angleRadians);
      double ddy = -dragAcceleration * cos(angleRadians);
      // Add gravity to acceleration
      ddy = ddy + gravity;

      impactDistance = distanceFormula(impactDistance, dx, timeInterval, ddx);
      impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, ddy);
      dx = kinematicsEquation(dx, ddx, timeInterval);
      dy = kinematicsEquation(dy, ddy, timeInterval);

      hangTime += timeInterval;

      // We hit the ground at some point... the artillery's not *that* powerful :)
      if (impactAltitude < 0.0)
      {
         // Find time and distance of actual impact
         actualImpactTime = linearInterpolation(lastTime, hangTime, lastAltitude, impactAltitude, 0.0);
         actualImpactDistance = linearInterpolation(lastDistance, impactDistance, lastAltitude, impactAltitude, 0.0);
      }
   }
   cout << fixed << setprecision(1);
   cout << "Distance:      " << actualImpactDistance << "m"
      << "       Hang Time : " << actualImpactTime << "s" << endl;
}

// Main fuction
int main()
{
    vector<double> altitudes = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0, 30000.0, 40000.0, 50000.0, 60000.0, 70000.0, 80000.0 };
	vector<double> gravities = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730, 9.715, 9.684, 9.654, 9.624, 9.594, 9.564 };
   vector<double> densities = { 1.2250000, 1.1120000, 1.0070000, 0.9093000, 0.8194000, 0.7364000, 0.6601000, 0.5900000, 0.5258000, 0.4671000, 0.4135000, 0.1948000, 0.0889100, 0.0400800, 0.0184100, 0.0039960, 0.0010270, 0.0003097, 0.0000828, 0.0000185 };
   vector<double> soundSpeeds = { 340, 336, 332, 328, 324, 320, 316, 312, 308, 303, 299, 295, 295, 295, 305, 324, 337, 319, 289, 269 };
   vector<double> machs = { 0.000, 0.300, 0.500, 0.700, 0.890, 0.920, 0.960, 0.980, 1.000, 1.020, 1.060, 1.240, 1.530, 1.990, 2.870, 2.890, 5.000 };
   vector<double> dragCoefficients = { 0.0000, 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };

	// Run cases for iterations
   inertia(827.0, 75.0);
	acceleration(GRAVITY, 827.0, 75.0);
	groundImpact(0.01, GRAVITY, 827.0, 75.0);
    gravity(0.01, 827.0, 75.0, altitudes, gravities);
   dragStepFunction(0.01, 827.0, 75.0, altitudes, gravities);
   airDensityStepFunction(0.01, 827.0, 75.0, altitudes, gravities, densities);
   dragCoefficientStepFunction(0.01, 827.0, 75.0, altitudes, gravities, densities, soundSpeeds, machs, dragCoefficients);
   hitTheGroundStepFunction(0.01, 827.0, 75.0, altitudes, gravities, densities, soundSpeeds, machs, dragCoefficients);

   // Run user-input cases (4 for the setup assignment)
   string userInput;
   double inputAngle;
   for (int i = 0; i < 4; ++i) {
      cout << "\nWhat is the angle of the howitzer where 0 is up? ";
      getline(cin, userInput);
      inputAngle = stod(userInput);
      // Latest version of the function, but the input angle is no longer pre-defined
      hitTheGroundStepFunction(0.01, 827.0, inputAngle, altitudes, gravities, densities, soundSpeeds, machs, dragCoefficients);
   }


    return 0;
}
