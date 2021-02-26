#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <list>
#include <string>

template<typename T, typename... Args>
void push_back(T& vec, Args&&... args)
{
   (vec.push_back(args), ...);
}

std::string to_roman(unsigned int value)
{
   std::vector<std::pair<unsigned int, char const*>> roman
   {
      { 1000, "M" },{ 900, "CM" },
      { 500, "D" },{ 400, "CD" },
      { 100, "C" },{ 90, "XC" },
      { 50, "L" },{ 40, "XL" },
      { 10, "X" },{ 9, "IX" },
      { 5, "V" },{ 4, "IV" },
      { 1, "I" }
   };

   std::string result;
   for (auto const & kvp : roman)
   {
      while (value >= kvp.first)
      {
         result += kvp.second;
         value -= kvp.first;
      }
   }

   return result;
}

int main()
{
   std::vector<int> v;
   push_back(v, 1, 2, 3, 4);
   std::copy(std::begin(v), std::end(v), 
             std::ostream_iterator<int>(std::cout, " "));

   std::list<int> l;
   push_back(l, 1, 2, 3, 4);   
   std::copy(std::begin(l), std::end(l), 
             std::ostream_iterator<int>(std::cout, "  \n"));

for(int i = 1; i <= 100; ++i) 
   {
      std::cout << i << "\t" << to_roman(i) << std::endl;   
   }

   int number = 2021;
   std::cout << to_roman(number) << '\n';
}