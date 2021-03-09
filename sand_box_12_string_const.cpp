#include <iostream>
#include <string>

//inconsistence in string constructors

const std::string str = "New C++";

int main()
{
    std::string s1 {"New C++", 3}; // "New" - take pointer
    std::string s2 {str, 3};       // "C++" - take a string and skip
    
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";

    //what is this craziness?
    std::cout << std::string('a',3) << "\n";



    std::cin.get();
}