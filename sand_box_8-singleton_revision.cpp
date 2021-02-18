#include <iostream>
#include <string>

// Singleton revision
class Singleton
{
    public:
    Singleton *GetInstance()
    {
        if(p_instance == nullptr)
        {
            try
            {
                p_instance = new Singleton;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: "<< e.what() << std::endl;
            }
        }
        return p_instance;
    }
    
    void print(){
        std::cout << "It is working!" << std::endl;
    }

    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;



    private:
    Singleton(){};
    static Singleton* p_instance;

};

Singleton* Singleton::p_instance = nullptr;



int main()
{
    Singleton *singleton = singleton->GetInstance();
    singleton->print();

    std::cin.get();
}