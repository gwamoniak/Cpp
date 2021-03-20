#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;


// new functional using bind and invoke

 constexpr int SumFunction(int a, int b) { return a+b ;};
struct Entity{
     
    void makeVect(int x,int y){
        vector Vec{x,y};
        for(auto item : Vec)    
        {cout << "Elements: "<< item << '\n';}
    }

};

int main()
{

// old:
auto plusOne = std::bind1st(std::plus<int>(), 1);
auto minusOne = std::bind2nd(std::minus<int>(), 1);
std::cout << plusOne(42) << ", " << minusOne(42) << '\n';

// use lambdas
auto lambdaOnePlus = [a=1](int b) { return a + b; };
auto lambdaMinusOne = [a=1](int b) { return b - a; };
std::cout << lambdaOnePlus(42) << ", " << lambdaMinusOne(10) << '\n';

// using bind:
using namespace std::placeholders;  // for _1, _2, _3...
auto bindPlusOne = std::bind(std::plus<int>(), 1, _1);
std::cout << bindPlusOne(42) << ',';
auto bindMinusOne = std::bind(std::minus<int>(), _1, 1);
std::cout << bindMinusOne(42) << '\n';

// using invoke
cout << invoke(SumFunction, 15, 25) << '\n';

Entity vec;
invoke(&Entity::makeVect, vec, 5,6);

 std::cin.get();
}