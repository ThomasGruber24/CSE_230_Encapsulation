/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
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
	Acceleration();
	Acceleration(double ddx, double ddy);

	// getters
	double getDDX() const;
	double getDDY() const;

	// setters
	void setDDX(double ddx);
	void setDDY(double ddy);
	void set(const Angle& a, double magnitude);
	void addDDX(double ddx);
	void addDDY(double ddy);
	void add(const Acceleration& rhs);

private:
	double ddx; // horizontal acceleration
	double ddy; // vertical acceleration
};