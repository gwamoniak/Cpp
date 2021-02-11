#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <random>
#include <map>
#include <future>

using namespace std;

// recursive lambda
constexpr auto fib = [](const auto fib, int input){

    if(input < 2)
    { return 1;}

    return fib(fib,input - 1) + fib(fib,input - 2);

};

auto get_record(const char* str)
{
    static int id = 0;
    std::map<int,std::string> temp;
    temp.emplace(++id,str);
    return temp.extract(temp.begin());
}

// generating random numbers

std::set<int> generate_sorted_random(const size_t num_elements)
{
    std::set<int> retval;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,num_elements -1);
    std::generate_n(std::inserter(retval,retval.end()),num_elements,[&](){ return dis(gen);});

    return retval;
}

int main()
{
    // equivalent Records = {{1,"Hello"},{2,"World"}};
    std:map<int, std::string> Records;
    Records.insert(get_record("Hello"));
    Records.insert(get_record("World"));
    std::cout << fib(fib,8) << '\n';
    
    auto gsr1 = std::async(std::launch::async,generate_sorted_random,100000);
    auto gsr2 = std::async(std::launch::async,generate_sorted_random,100000);
    std::cout << gsr1.get().size() << "___" << gsr2.get().size() << '\n';   


    return 0;
}