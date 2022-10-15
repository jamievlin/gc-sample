#include <iostream>
#include <memory>

#include "gcservice/gcservice.h"

class Something
{
public:
    Something (int const& va)
        : a(va),
        b(va + 100)
    {

    }

    void print()
    {
        std::cout << a << " " << b;
    }
private:
    int a, b;
};

int main(int argc, char* argv[])
{
    for (int i = 0; i < 10000000; ++i)
    {
        auto* something = gcservice::allocateClassGC<Something>(155);
        something->print();
    }
}