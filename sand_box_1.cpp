#include <iostream>
#include <cstddef>
#include <vector>
#include <array>
#include <numeric>
#include <string_view>
#include <initializer_list>


using namespace std;

// generate Pi and using it

constexpr double calculate_pi()
{
    return 22/7;
}

constexpr auto pi = calculate_pi();

// copy Elision

struct S{
    // not allowed to be copied or moved
    S() = default;
    S(S&&) = delete;
    S(const S &) = delete;
};

auto s_factory() {
    return S{}; // working in C++17
}

// maps

template<typename Map>
void print_map(const Map &map, const string_view key_desc = "key",
                            const string_view value_desc = "value")
{
    // lambda
    const auto print_key_value = [&](const auto &data){
        const auto &[key, value] = data;
        puts(format("{}: '{}' {}: '{}'",key_desc,key,value_desc,value).c_str());
    };

    for_each(begin(map),end(map),print_key_value);
 
 //   for(const auto &[key, value] : map) // structured binding
 //  {
 //      puts(format("{}: '{}' {}: '{}'",key_desc,key,value_desc,value).c_str());
 //  } 
}

// playing with template
template <typename Value_type>
struct Data {
  Data(const size_t size) : data(new Value_type[size]){}
  ~Data() {delete [] data ;}
  Value_type *data;
  
};

//C++17
template<typename AT, typename ... Params>
auto get_data(const AT &a1, const Params & ... params)
{
    return array{a1, params...}; // auto deduced size/type

}

template<typename First, typename ... T>
auto sum(const First &first, const T & ... t)
{
    auto result = first;
    (void)initializer_list<double>{ (result +=t, 0.0) ...};
    return result;
}

// C++11/C++14
template <typename Value_type>
vector<Value_type> get_data1(const Value_type &v1, const Value_type &v2, const Value_type &v3) {
  vector<Value_type> d;
  d.emplace_back(v1); d.emplace_back(v2); d.emplace_back(v3);
  return d;
  
}

template <typename Value_type>
Value_type sum_data1(const vector<Value_type> &d)
{
  return accumulate(d.begin(),d.end(),Value_type());
  
}

int main() 
{
    
    const auto radius = 2.3;
    const auto area = pi * radius * radius;
    cout << area << endl;
    array a{3.5,3.8,2.3};
    sum(a); 
    return sum_data1(get_data1(2.2,4.1,6.4));
    
    return 0;
}