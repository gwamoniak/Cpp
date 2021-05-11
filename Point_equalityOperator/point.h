#pragma once
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
	friend std::ostream& operator << (std::ostream& out, const Point& p);
public:
	Point() = default;

	Point(double x, double y)
		:mX{x},mY{y}{}
	Point(double x_y)
		: Point{ mX,mY } {}
	~Point() = default;
	bool operator==(const Point& other) const;

private:
	double mX{};
	double mY{};
	double length() const;
};

inline std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << "Point [ x: " << p.mX << ", y :" << p.mY <<  "length: " <<p.length() << " ]";
}


#endif

