// Point_equalityOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// check out LearnQtGuide: https://www.youtube.com/channel/UCUYUFiuJ5XZ3JYtbq5dXRKQ

#include <iostream>
#include "point.h"

int main()
{
	Point point1(20.0, 20.0);
	Point point2(34.0, 34.0);
	std::cout << "point1 " << (point1) << std::endl;
	std::cout << "point2 " << (point2) << std::endl;


	std::cout << std::boolalpha;
	std::cout << "point1 == point2 " << (point1 == point2) << std::endl;
	std::cout << "point1 != point2 " << (point1 != point2) << std::endl;
	std::cout << "12.5 == point2 " << (12.5 == point2) << std::endl;
	std::cout << "12.5 != point2 " << (12.5 != point2) << std::endl;
}

