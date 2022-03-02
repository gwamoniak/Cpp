#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory_resource>



constexpr double  pow(const double x, std::size_t y)
{
    return y!= 1 ? x*pow(x,y-1) :x;
}

int main()
{

    auto out = pow(3.0,6);

    std::cout << out << '\n';

    return 0;
}
