#include <simplex.h>

#define DEBUG_LEVEL 2

#if DEBUG_LEVEL > 0
#include <iostream>
#endif

Simplex::Simplex(int m, int n) : basic_rep_(m, std::vector<double>(n, 0.0)) {}

Simplex::Simplex(BasicRep basic_rep) : basic_rep_(basic_rep) {}

void Simplex::initialize(BasicRep basic_rep)
{
    basic_rep_ = basic_rep;
}

void Simplex::solve()
{
#if DEBUG_LEVEL > 0
    std::cout << "========== Starting Solve ==========\n";
#endif
    while (!isDone()) {
#if DEBUG_LEVEL > 1
        printBR(basic_rep_);
#endif
        int inputVar = inputBasicVar();
        int outputVar = outputBasicVar(inputVar);

        rotate(inputVar, outputVar);
    }
#if DEBUG_LEVEL > 0
    std::cout << "========== Done Solve! ==========\n";
#endif
#if DEBUG_LEVEL > 1
    printBR(basic_rep_);
#endif
}

double Simplex::getMin() const
{
    return basic_rep_[0].back();
}

bool Simplex::isDone() const
{
    for (std::size_t i = 0; i < basic_rep_[0].size(); ++i) {
        if (basic_rep_[0][i] > 0 && i != 0) {
            return false;
        }
    }
    return true;
}

int Simplex::inputBasicVar() const
{
    double max{0};
    int ret_itr{0};
    int itr{0};

    for (auto &&var : basic_rep_[0]) {
        if (var > max && itr != 0 &&
            itr != static_cast<int>(basic_rep_[0].size() - 1)) {
            max = var;
            ret_itr = itr;
        }
        itr++;
    }

    return ret_itr;
}

int Simplex::outputBasicVar(int column) const
{
    double min{10000};
    int ret_itr{0};
    int itr{0};

    for (auto &&bv : basic_rep_) {
        double minVar{bv.back() / bv[column]};
        if (minVar < min && itr != 0 && minVar > 0) {
            min = minVar;
            ret_itr = itr;
        }
        itr++;
    }

    return ret_itr;
}

void Simplex::rotate(int input, int output)
{
#if DEBUG_LEVEL > 0
    std::cout << "Rotating on " << output << ", " << input << "\n";
#endif
    double pivot{basic_rep_[output][input]};
    for (std::size_t i = 0; i < basic_rep_.size(); ++i) {
        double mul{-basic_rep_[i][input] / pivot};
        for (std::size_t j = 0; j < basic_rep_[i].size(); ++j) {
            if (static_cast<int>(i) == output) {
                basic_rep_[i][j] /= pivot;
            } else {
                basic_rep_[i][j] += mul * basic_rep_[output][j];
            }
        }
    }
}

#if DEBUG_LEVEL > 1

void printBR(const BasicRep &basic_rep)
{
    for (auto &&bv : basic_rep) {
        for (auto &&var : bv) {
            std::cout << var << " ";
        }
        std::cout << "\n";
    }
}

#endif
