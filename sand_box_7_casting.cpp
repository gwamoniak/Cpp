#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

class Entity
{
    public:
    virtual void PrintHealth();
    virtual ~Entity() = default;

};


class Player : public Entity
{
    void PrintHealth() override;
};

std::tuple<std::string, int> CreatePerson()
{
    return {"Lewandowski",32}; 
}


int main()
{
    // dynamic cast
    Player* player = new Player();
    Entity* e = player;

    Player* p = dynamic_cast<Player*>(e);
    
    // tuple
    auto[name,age] = CreatePerson();
    std::cout << name << age << std::endl;
    
    // map
    std::unordered_map<std::string,int> ScoreMap{{"Lewandowski",5},{"Muller",3}};

    for(auto kv : ScoreMap)
    {
        auto& key = kv.first;
        auto& score = kv.second;
        std::cout << "key: " << key << " score: " << score << std::endl;
    }

    std::cin.get();
}
