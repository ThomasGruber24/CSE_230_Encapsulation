/***********************************************************************
 * Header File:
 *    TEST HOWITZER
 * Author:
 *    Thomas Gruber
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include "howitzer.h"
#include "unitTest.h"
#include <cmath>

class TestHowitzer : public UnitTest
{
public:
    void run()
    {
        // Ticket 1: Getters
        defaultConstructor();
        getPosition_zero();
        getPosition_middle();
        getMuzzleVelocity_slow();
        getMuzzleVelocity_standard();
        getElevation_up();
        getElevation_right();
        getElevation_left();

        // Ticket 2: Setters
        generatePosition_small();
        generatePosition_large();
        raise_rightDown();
        raise_rightUp();
        raise_leftDown();
        raise_leftUp();
        rotate_clock();
        rotate_counterClock();
        rotate_wrapClock();
        rotate_wrapCounterClock();

        report("Howitzer");
    }

private:
    double metersFromPixels = -1.0;

    static double normalizeRadians(double r)
    {
        const double TWO_PI = 2.0 * M_PI;
        r = fmod(r, TWO_PI);
        if (r < 0.0) r += TWO_PI;
        return r;
    }

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     *********************************************/
    void defaultConstructor()
    {
        Howitzer h;
        // position default assumed zero
        assertEquals(0.0, h.position.getPixelsX());
        assertEquals(0.0, h.position.getPixelsY());

        // muzzle velocity default
        assertEquals(DEFAULT_MUZZLE_VELOCITY, h.getMuzzleVelocity());

        // elevation default is "45 degrees" per comment -> check radians = PI/4
        assertEquals(M_PI / 4.0, h.getElevation().getRadians());
    }

    /*********************************************
     * name:    GET POSITION ZERO
     *********************************************/
    void getPosition_zero()
    {
        Howitzer h;
        h.position.setPixelsX(0.0);
        h.position.setPixelsY(0.0);
        Position& p = h.getPosition();
        assertEquals(0.0, p.getPixelsX());
        assertEquals(0.0, p.getPixelsY());
    }

    /*********************************************
     * name:    GET POSITION MIDDLE
     *********************************************/
    void getPosition_middle()
    {
        Howitzer h;
        h.position.setPixelsX(123.4);
        h.position.setPixelsY(567.8);
        Position& p = h.getPosition();
        assertEquals(123.4, p.getPixelsX());
        assertEquals(567.8, p.getPixelsY());
    }

    /*********************************************
     * name:    GET MUZZLE VELOCITY - SLOW SPEED
     *********************************************/
    void getMuzzleVelocity_slow()
    {
        Howitzer h;
        h.muzzleVelocity = 24.68;
        assertEquals(24.68, h.getMuzzleVelocity());
    }

    /*********************************************
     * name:    GET MUZZLE VELOCITY - STANDARD SPEED
     *********************************************/
    void getMuzzleVelocity_standard()
    {
        Howitzer h;
        assertEquals(DEFAULT_MUZZLE_VELOCITY, h.getMuzzleVelocity());
    }

    /*********************************************
     * name:    GET ELEVATION - up
     *********************************************/
    void getElevation_up()
    {
        Howitzer h;
        h.elevation = Angle(0.0);
        assertEquals(0.0, h.getElevation().getRadians());
    }

    /*********************************************
     * name:    GET ELEVATION - right
     *********************************************/
    void getElevation_right()
    {
        Howitzer h;
        h.elevation = Angle(0.4);
        assertEquals(0.4, h.getElevation().getRadians());
    }

    /*********************************************
     * name:    GET ELEVATION - left
     *********************************************/
    void getElevation_left()
    {
        Howitzer h;
        // 5.8 is already in range [0,2pi)
        h.elevation = Angle(5.8);
        assertEquals(5.8, h.getElevation().getRadians());
    }

    /*********************************************
     * GENERATE POSITION small board
     *********************************************/
    void generatePosition_small()
    {
        Howitzer h;
        Position board;
        board.setPixelsX(10.0);
        board.setPixelsY(10.0);
        // call generatePosition - it sets h.position.px in [10*0.1, 10*0.9] => [1,9]
        h.generatePosition(board);
        double x = h.getPosition().getPixelsX();
        assertUnit(x >= 1.0 && x <= 9.0);
        assertEquals(0.0, h.getPosition().getPixelsY()); // generatePosition sets y=0
    }

    /*********************************************
     * GENERATE POSITION large board
     *********************************************/
    void generatePosition_large()
    {
        Howitzer h;
        Position board;
        board.setPixelsX(1000.0);
        board.setPixelsY(1000.0);
        h.generatePosition(board);
        double x = h.getPosition().getPixelsX();
        // expects 100px <= x <= 900px
        assertUnit(x >= 100.0 && x <= 900.0);
        assertEquals(0.0, h.getPosition().getPixelsY());
    }

    /*********************************************
     * RAISE to the right/down
     *********************************************/
    void raise_rightDown()
    {
        Howitzer h;
        h.elevation = Angle(0.5);
        // when pointing right, elevation.isRight() should be true; raising by -0.1 -> +0.1
        h.raise(-0.1);
        assertEquals(0.6, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * RAISE to the right/up
     *********************************************/
    void raise_rightUp()
    {
        Howitzer h;
        h.elevation = Angle(0.5);
        h.raise(0.1);
        assertEquals(0.4, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * RAISE to the left down
     *********************************************/
    void raise_leftDown()
    {
        Howitzer h;
        // input uses -0.5; convert to program expected 2pi - 0.5
        double start = normalizeRadians(-0.5);
        h.elevation = Angle(start);
        h.raise(-0.1);
        double expected = normalizeRadians(start + (-0.1)); // left: add(radian)
        assertEquals(expected, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * RAISE to the left up
     *********************************************/
    void raise_leftUp()
    {
        Howitzer h;
        double start = normalizeRadians(-0.5);
        h.elevation = Angle(start);
        h.raise(0.1);
        double expected = normalizeRadians(start + 0.1);
        assertEquals(expected, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * ROTATE CLOCKWISE no wrapping
     *********************************************/
    void rotate_clock()
    {
        Howitzer h;
        h.elevation = Angle(1.23);
        h.rotate(0.3);
        assertEquals(1.53, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * ROTATE COUNTER CLOCKWISE no wrapping
     *********************************************/
    void rotate_counterClock()
    {
        Howitzer h;
        h.elevation = Angle(1.23);
        h.rotate(-0.3);
        assertEquals(0.93, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * ROTATE CLOCKWISE WRAP
     *********************************************/
    void rotate_wrapClock()
    {
        Howitzer h;
        h.elevation = Angle(6.1);
        h.rotate(0.2);
        double expected = normalizeRadians(6.1 + 0.2);
        assertEquals(expected, normalizeRadians(h.getElevation().getRadians()));
    }

    /*********************************************
     * ROTATE COUNTER CLOCKWISE WRAP
     *********************************************/
    void rotate_wrapCounterClock()
    {
        Howitzer h;
        h.elevation = Angle(0.1);
        // rotate by (-0.2 - 4PI) per test description; compute expected after normalization
        double rotation = -0.2 - 4.0 * M_PI;
        h.rotate(rotation);
        double expected = normalizeRadians(0.1 + rotation);
        assertEquals(expected, normalizeRadians(h.getElevation().getRadians()));
    }

    // standard fixture helpers (unchanged)
    void setupStandardFixture()
    {
        Position p;
        metersFromPixels = p.metersFromPixels;
        p.metersFromPixels = 1100.0;
    }

    void teardownStandardFixture()
    {
        assert(metersFromPixels != -1.0);
        Position p;
        p.metersFromPixels = metersFromPixels;
    }
};