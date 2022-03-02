#include <utility>
#include <vector>
#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;



template <typename T>
void allocate_memory(const T& input)
{
    auto ptr{std::make_unique<T>(input)};
}

constexpr size_t get_size()
{
    auto val1 = 5;
    auto val2 = 4;
    return val1 * val2;

};

constexpr auto size = get_size();

int main()
{
    
    const std::vector<int> vec{2,5,7,6,18};
    const auto Count = std::count_if(std::begin(vec),std::end(vec),
     [value = [](){return 10;}()](const auto i){return i < value;}
    );
    std::cout << Count << std::endl;
    allocate_memory(6.8);

    std::array<int,size> arr; // doesnt work in C++17

    return 0;
}
