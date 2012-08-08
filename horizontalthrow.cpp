#include "horizontalthrow.h"

HorizontalThrow(Length height, Velocity vel, double grav)
{
    g = grav;
    h = height.to(Length::M);
    v = vel.to(Velocity::MS);
    calcT();
    calcS();
}

HorizontalThrow(Length height, Length scope, double grav)
{
    g = grav;
    h = height.to(Length::M);
    s = scope.to(Length::M);
    calcT();
    calcV();
}

HorizontalThrow(Length scope, Time time, double grav)
{
    g = grav;
    s = scope.to(Length::M);
    t = time.to(Time::S);
    calcH();
    calcV();
}

HorizontalThrow(Time time, Velocity vel, double grav)
{
    g = grav;
    t = time.to(Time::S);
    v = vel.to(Velocity::MS);
    calcH();
    calcS();
}
