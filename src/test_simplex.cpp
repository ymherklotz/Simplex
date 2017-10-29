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

    // s.initialize({{1, -20, -9, 0, 0, 10.5, -70.5, 0, 0},
    //               {0, -2, 4, 1, 0, 0.5, -4.5, 0, 0},
    //               {0, -0.5, 0.5, 0, 1, 0.25, -1.25, 0, 0},
    //               {0, 1, 0, 0, 0, 0, 0, 1, 1}});

    // s.solve();

    std::cout << "Result: " << s.getMin() << "\n";
}
