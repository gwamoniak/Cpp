// using [[nodiscard]]
//The [[nodiscard]] attribute can be used to indicate that the return value of a function shouldn't be ignored
// when you do a function call. If the return value is ignored, the compiler should give a warning on this. 

#include <iostream>
#include <vector>


struct Vector{

    [[nodiscard("You should call clear()")]] bool empty() const; // return true if empty
    void clear();
};

[[nodiscard]] int Compute() { return 0; }

// very useful for enum Errors

enum class [[nodiscard]] ErrorCode {
    OK,
    Fatal,
    System,
    FileIssue
};

int main()
{

    Vector vec;
    //vec.empty(); // it will show the note
    vec.clear();
    Compute(); // giving warning
    return 0;
}