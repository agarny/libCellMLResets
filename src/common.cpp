#include "common.h"

extern "C" {
#include "model.h"
}

bool fuzzyCompare(double pNb1, double pNb2)
{
    static constexpr double ONE_TRILLION = 1000000000000.0;

    return std::fabs(pNb1 - pNb2) * ONE_TRILLION <= std::fmin(std::fabs(pNb1), std::fabs(pNb2));
}

void printHeaders(std::ofstream &file)
{
    file << "voi";

    for (size_t i = 0; i < STATE_COUNT; ++i) {
        file << "," << STATE_INFO[i].name;
    }

    for (size_t i = 0; i < CONSTANT_COUNT; ++i) {
        file << "," << CONSTANT_INFO[i].name;
    }

    for (size_t i = 0; i < COMPUTED_CONSTANT_COUNT; ++i) {
        file << "," << COMPUTED_CONSTANT_INFO[i].name;
    }

    for (size_t i = 0; i < ALGEBRAIC_COUNT; ++i) {
        file << "," << ALGEBRAIC_INFO[i].name;
    }

    file << std::endl;
}

void printValues(std::ofstream &file, double voi, const double *states, const double *constants, const double *computedConstants, const double *algebraic)
{
    file << voi;

    for (size_t i = 0; i < STATE_COUNT; ++i) {
        file << "," << states[i];
    }

    for (size_t i = 0; i < CONSTANT_COUNT; ++i) {
        file << "," << constants[i];
    }

    for (size_t i = 0; i < COMPUTED_CONSTANT_COUNT; ++i) {
        file << "," << computedConstants[i];
    }

    for (size_t i = 0; i < ALGEBRAIC_COUNT; ++i) {
        file << "," << algebraic[i];
    }

    file << std::endl;
}
