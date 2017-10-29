#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>

typedef std::vector<std::vector<double>> BasicRep;

class Simplex
{
public:
    Simplex(int m, int n);
    Simplex(BasicRep basic_rep);

    void initialize(BasicRep basic_rep);
    void solve();
    double getMin() const;
private:
    BasicRep basic_rep_;

    bool isDone() const;
    int inputBasicVar() const;
    int outputBasicVar(int column) const;
    void rotate(int input, int output);
};

extern void printBR(const BasicRep &basic_rep);

#endif
