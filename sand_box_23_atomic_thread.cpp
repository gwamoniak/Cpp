#include <thread>
#include <atomic>
#include <chrono>
#include <vector> 
#include <iostream> 
#include <cassert>

using namespace std::chrono_literals;
// small example of using threads and atomics

int main()
{
    std::vector<double> dailyPrice = { 100.3, 101.65, 103.03 , 97.98 ,
                                        103.00 ,101.45, 98,72 };

    std::atomic<double> average = 0.0;
    std::atomic_flag stillBusy = true;

    //calculate average
    std::thread thread {
        [&dailyPrice,&average,&stillBusy](){
            auto avg = average.load();
            for(auto price: dailyPrice)
            {
                std::this_thread::sleep_for(2ms);
                avg += price;
            }
            avg /= dailyPrice.size();
            average.store(avg);
            stillBusy.clear();

            std::this_thread::sleep_for(2s);
        }
    };

    while(stillBusy.test_and_set())
    {
        std::cout << "......" << std::endl; // progress bar
        std::this_thread::sleep_for(2ms);
    }

    std::cout << "Average value: " << average << std::endl;

    assert(thread.joinable());
    thread.join();

    return 0;
}
