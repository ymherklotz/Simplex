#include <simplex.h>

#include <iostream>

int main()
{
    BasicRep br{
        {1, 1, 1, 0, 0, 0, 0},
        {0, 2, 1, 1, 0, 0, 11},
        {0, 1, 3, 0, 1, 0, 18},
        {0, 1, 0, 0, 0, 1, 4},
    };

    Simplex s{br};

    s.solve();

    std::cout << "Result: " << s.getMin() << "\n";
}
