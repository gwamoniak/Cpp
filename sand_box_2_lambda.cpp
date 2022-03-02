#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename ... T>
auto add_stuff(T... t)
{
    return (t + ...);
}

auto add = [](const auto& lhs, const auto& rhs){

    return lhs + rhs;

};

bool is_palindrom(const string& input)
{
   return equal(input.begin(),input.begin() + input.size()/2, input.rbegin());
}

auto print(const string& input){
        cout << input << (is_palindrom(input) ? " is a plaindrom" : " is not palindrom")
        << endl; 
}

int main()
{
    
    auto Add = add_stuff(1,2,3,4);
    puts(to_string(Add).c_str());
    cout << add(3,5) << '\n';
    cout << Add << '\n';
    print("radar");
    // lambda test
    auto val = 10;
    auto lambda = [val](const auto i) mutable { return 5 + i + ++val; };
    puts(to_string(lambda(3)).c_str());

    return 0;
}
