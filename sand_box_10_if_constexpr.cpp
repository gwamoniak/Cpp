#include <iostream>
#include <initializer_list>
#include <string_view>
//
#include <stdexcept>
#include <type_traits>
#include <utility>

// enum
enum class Values
{
    value1,
    value2,
    value3,     
    value4
};

// loop helper
constexpr std::initializer_list<Values> Values_loop{Values::value1,Values::value2,Values::value3,Values::value4};

// avoid default in switch
std::string_view get_value(Values value)
{
    switch(value)
    {
        case Values::value1: return "value1";
        case Values::value2: return "value2";
        case Values::value3: return "value3";
    }
    // unhandled enum value compiler warning now
    return "Unknown";
}

// c++17 if constexpr

template <typename Numerator, typename Denominator>
auto divide(Numerator numerator, Denominator denominator )
{
    //Checks whether T is an integral or floating point type.
    if constexpr((std::is_integral_v<Numerator> && std::is_integral_v<Denominator>)
        || (std::is_floating_point_v<Numerator> && std::is_floating_point_v<Denominator>))
    {
        if(denominator == 0 ||denominator == 0.0 )
        {
            throw std::runtime_error("cannot divide by zero!"); 
        }
    }

  return numerator / denominator;   
}

int main()
{
    // you can loop now
    for(auto val : Values_loop)
    {
        // do stuff with val
        std::cout << get_value(val)<< '\n';
    }
  
    std::cout<< divide(6.78,1.7) << '\n'; 
    //auto div = divide(3,0); //uncomment to check the runtime error 
        
    std::cin.get();
}