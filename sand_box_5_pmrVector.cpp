#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory_resource>



std::vector<int> make_vector()
{
    return {1,3,5,7};
}


int main()
{

    auto vec = make_vector();

    if(const auto itr = std::find(vec.begin(),vec.end(),3); itr!= vec.end() )
    {
            *itr = 6;
    }

    std::byte memory_res[2048];
    std::pmr::monotonic_buffer_resource rsrc(memory_res,sizeof(memory_res));
    std::pmr::vector<int> testVector{{2,5,8,6},&rsrc};

    return 0;
}
