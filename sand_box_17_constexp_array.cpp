#include <iostream>
#include <array>
#include <numeric>

using namespace std;

//constexpr Allocations

template <std::size_t N>
constexpr int SumArray() {
    std::array<int, N> arr { 0 };
    for (std::size_t i = 0; i < arr.size(); ++i)
        arr[i] = i+1;
    // acumulate is not a constexpr  cannot be used in that way in C++17
    //auto sum  = std::accumulate(begin(arr), end(arr), 0);
    int sum = 0;
    for (const auto& elem : arr)
        sum += elem;
    return sum;
}

// sum trick very fast
constexpr int SumTrick(unsigned int n) {
    return (n*(1+n))/2;
}

int main() {
    static_assert(SumArray<10>() == SumTrick(10));
    static_assert(SumArray<11>() == SumTrick(11));
    static_assert(SumArray<23>() == SumTrick(23));
    
    cout << SumTrick(20) << " : " << SumArray<20>();

    std::cin.get();
}

