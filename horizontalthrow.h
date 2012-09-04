#ifndef HORIZONTALTHROW_H
#define HORIZONTALTHROW_H

#include <qmath.h>
#include "F:\CPP\Fizyka\Jednostki\units.h"
#include <QPointF>

class HorizontalThrow
{
public:
    HorizontalThrow(Length height, Speed vel, double grav = GravAcc::NORM);
    HorizontalThrow(Length height, Length scope, double grav = GravAcc::NORM);
    HorizontalThrow(Length scope, Time time, double grav = GravAcc::NORM);
    HorizontalThrow(Time time, Speed vel, double grav = GravAcc::NORM);
    HorizontalThrow() { h=v=s=t=g=0; }

    double getHeight(){return h;}
    double getVelocity(){return v;}
    double getScope(){return s;}
    double getTime(){return t;}
    double getGravAcc(){return g;}

    double getY(double x);
    QPointF getPoint(double time);

private:
    void calcH() { h = g*t*t/2; }
    void calcV() { v = s/t; }
    void calcS() { s = v*t; }
    void calcT() { t = sqrt(2*h/g); }

    double h;
    double v;
    double s;
    double t;
    double g;
};

#endif // HORIZONTALTHROW_H
