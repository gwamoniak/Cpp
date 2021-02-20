#include <iostream>
#include <string>
#include <utility>

// multiple destructors
template<typename Contained>
struct Optional
{

union{Contained data;};
bool initialized = false;

    constexpr Optional &operator=(Contained &&data)
    {
        this->data = std::move(data);
        initialized = true;
        return *this;
    }

    ~Optional()
    {
        if (initialized)
        {
            data.~Contained();
        }
    }

};

// nodiscard 
//If the return value is ignored, the compiler should give a warning on this. 

struct [[nodiscard]]  Entity 
{
     const float x = 1, y = 1;
};

constexpr Entity get_XY() 
{
    return Entity();
}

int main()
{

    Optional<int> obj;
    obj = 5;
    //
    auto[x,y] = get_XY();
    std::cout << x << ":" << y << '\n';
    
    std::cin.get();
}