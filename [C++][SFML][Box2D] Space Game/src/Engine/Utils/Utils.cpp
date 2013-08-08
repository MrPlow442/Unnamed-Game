#include "Utils.h"

// Converts degrees to radians
float32 util::degToRad(float deg)
{
	return deg * DEGTORAD;
}

// Converts radians to degrees
float util::radToDeg(float rad)
{
	return rad * RADTODEG;
}