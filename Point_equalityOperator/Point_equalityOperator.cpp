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

