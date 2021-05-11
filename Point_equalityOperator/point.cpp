#include <cmath>
#include "point.h"

double Point::length() const
{
	return sqrt(pow(mX - 0, 2) + pow(mY - 0, 2) * 1.0);
}

bool Point::operator==(const Point& other) const
{
	return (this->length() == other.length());
}

// in c++20 free != operator
//bool Point::operator!=(const Point& other) const
//{
//	return !(*this == other);
//}