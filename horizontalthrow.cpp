#include "horizontalthrow.h"
//**************************************************
//          constructors
//**************************************************

HorizontalThrow::HorizontalThrow(Length height, Speed vel, double grav)
{
    g = grav;
    h = height.to(Length::M);
    v = vel.to(Speed::MS);
    calcT();
    calcS();
}

HorizontalThrow::HorizontalThrow(Length height, Length scope, double grav)
{
    g = grav;
    h = height.to(Length::M);
    s = scope.to(Length::M);
    calcT();
    calcV();
}

HorizontalThrow::HorizontalThrow(Length scope, Time time, double grav)
{
    g = grav;
    s = scope.to(Length::M);
    t = time.to(Time::S);
    calcH();
    calcV();
}

HorizontalThrow::HorizontalThrow(Time time, Speed vel, double grav)
{
    g = grav;
    t = time.to(Time::S);
    v = vel.to(Speed::MS);
    calcH();
    calcS();
}

//**************************************************
//          getters
//**************************************************

double HorizontalThrow::getY(double x)
{
    return h - (g*x*x)/(2*v*v);
}

QPointF HorizontalThrow::getPoint(double time)
{
    double x = v*time;
    double y = h-g*time*time/2.0;
    return QPointF(x,y);
}
