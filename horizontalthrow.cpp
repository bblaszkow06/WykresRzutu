#include "horizontalthrow.h"

HorizontalThrow::HorizontalThrow(double m_h, double m_v, double m_gravAccel)
{
	h = m_h;
	v = m_v;
	gravAccel = m_gravAccel;
	time = sqrt(2*h/gravAccel);
	scope = v*time;
}
