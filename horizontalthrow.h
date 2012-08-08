#ifndef HORIZONTALTHROW_H
#define HORIZONTALTHROW_H

#include <qmath.h>
#include "units.h"
#include <QPointF>

class HorizontalThrow
{
public:
    HorizontalThrow(Length height, Velocity vel, double grav = GravAcc::NORM);
    HorizontalThrow(Length height, Length scope, double grav = GravAcc::NORM);
    HorizontalThrow(Length scope, Time time, double grav = GravAcc::NORM);
    HorizontalThrow(Time time, Velocity vel, double grav = GravAcc::NORM);

    double getHeight();
    double getVelocity();
    double getScope();
    double getTime();
    double getGravAcc();

    double getY(double x);
    QPointF getPoint(Time time);

private:
    void calcH() { h = g*t*t/2; }
    void calcV() { v = s/t; }
    void calcS() { s = v*t; }
    void calcT() { t = pow(2*h/g); }

    double h;
    double v;
    double s;
    double t;
    double g;
};

#endif // HORIZONTALTHROW_H
