/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#pragma once


class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestLander;      // for the unit tests

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
    friend TestPosition;    // for the unit tests
    friend TestLander;      // for the unit tests

public:
    // constructors
    Position();
    Position(const Position& pos);
    Position(double x, double y);

    // getters
    double getX() const;
    double getY() const;
    bool operator == (const Position& rhs) const;
    bool operator != (const Position& rhs) const;

    // setters
    Position assign(const Position& pos);
    void setX(double x);
    void setY(double y);
    void addX(double x);
    void addY(double y);
    void add(const Acceleration& a, const Velocity& v, double t);
    Position& operator = (const Position& rhs)
    {
        x = 99.9;
        y = 88.8;
        return *this;
    }

private:
    double x;           // horizontal position
    double y;           // vertical position
};