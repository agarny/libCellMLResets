/* The content of this file was generated using the C profile of libCellML 0.6.2. */

#include "model.h"

#include <math.h>
#include <stdlib.h>

const char VERSION[] = "0.6.0";
const char LIBCELLML_VERSION[] = "0.6.2";

const size_t STATE_COUNT = 6;
const size_t CONSTANT_COUNT = 0;
const size_t COMPUTED_CONSTANT_COUNT = 0;
const size_t ALGEBRAIC_COUNT = 0;
const size_t RESET_COUNT = 6;

const VariableInfo VOI_INFO = {"t", "dimensionless", "main"};

const VariableInfo STATE_INFO[] = {
    {"S1", "dimensionless", "main"},
    {"S2", "dimensionless", "main"},
    {"S3", "dimensionless", "main"},
    {"S4", "dimensionless", "main"},
    {"S5", "dimensionless", "main"},
    {"S6", "dimensionless", "main"},
};

const VariableInfo CONSTANT_INFO[] = {
};

const VariableInfo COMPUTED_CONSTANT_INFO[] = {
};

const VariableInfo ALGEBRAIC_INFO[] = {
};

double * createStatesArray()
{
    double *res = (double *) malloc(STATE_COUNT*sizeof(double));

    for (size_t i = 0; i < STATE_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

double * createConstantsArray()
{
    double *res = (double *) malloc(CONSTANT_COUNT*sizeof(double));

    for (size_t i = 0; i < CONSTANT_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

double * createComputedConstantsArray()
{
    double *res = (double *) malloc(COMPUTED_CONSTANT_COUNT*sizeof(double));

    for (size_t i = 0; i < COMPUTED_CONSTANT_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

double * createAlgebraicArray()
{
    double *res = (double *) malloc(ALGEBRAIC_COUNT*sizeof(double));

    for (size_t i = 0; i < ALGEBRAIC_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

double * createResetsArray()
{
    double *res = (double *) malloc(RESET_COUNT*sizeof(double));

    for (size_t i = 0; i < RESET_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

void deleteArray(double *array)
{
    free(array);
}

void initialiseVariables(double *states, double *rates, double *constants, double *computedConstants, double *algebraic)
{
    states[0] = 1.0;
    states[1] = 1.0;
    states[2] = 1.0;
    states[3] = 1.0;
    states[4] = 1.0;
    states[5] = 1.0;
}

void computeComputedConstants(double *constants, double *computedConstants)
{
}

void computeRates(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic)
{
    rates[0] = 0.1;
    rates[1] = 0.1;
    rates[2] = 0.1;
    rates[3] = 0.069;
    rates[4] = 0.069;
    rates[5] = 0.069;
}

void computeVariables(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic)
{
}

int computeResets(double voi, double *states, double *constants, double *computedConstants, double *algebraic, double *resets)
{
    resets[0] = states[0] - 2.0;
    resets[1] = states[1] - 2.123;
    resets[2] = states[2] - 2.169;
    resets[3] = states[3] - 2.0;
    resets[4] = states[4] - 2.123;
    resets[5] = states[5] - 2.169;

    return 0;
}

void applyReset(double voi, double *states, double *constants, double *computedConstants, double *algebraic, int resetIndex)
{
    if (resetIndex == 0) {
        states[0] = 1.0;
    }

    if (resetIndex == 1) {
        states[1] = 1.0;
    }

    if (resetIndex == 2) {
        states[2] = 1.0;
    }

    if (resetIndex == 3) {
        states[3] = 1.0;
    }

    if (resetIndex == 4) {
        states[4] = 1.0;
    }

    if (resetIndex == 5) {
        states[5] = 1.0;
    }
}
