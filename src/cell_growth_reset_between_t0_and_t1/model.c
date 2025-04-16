/* The content of this file was generated using the C profile of libCellML 0.6.2. */

#include "model.h"

#include <math.h>
#include <stdlib.h>

const char VERSION[] = "0.6.0";
const char LIBCELLML_VERSION[] = "0.6.2";

const size_t STATE_COUNT = 1;
const size_t CONSTANT_COUNT = 0;
const size_t COMPUTED_CONSTANT_COUNT = 0;
const size_t ALGEBRAIC_COUNT = 0;
const size_t RESET_CONDITIONS_COUNT = 1;

const VariableInfo VOI_INFO = {"t", "dimensionless", "main"};

const VariableInfo STATE_INFO[] = {
    {"S", "dimensionless", "main"},
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

double * createResetConditionsArray()
{
    double *res = (double *) malloc(RESET_CONDITIONS_COUNT*sizeof(double));

    for (size_t i = 0; i < RESET_CONDITIONS_COUNT; ++i) {
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
}

void computeComputedConstants(double *constants, double *computedConstants)
{
}

void computeRates(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic)
{
    rates[0] = 0.1;
}

void computeVariables(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic)
{
}

int isNearlyZero(double value)
{
    return fabs(value) <= 1e-7;
}

int sign(double value)
{
    if (value > 0.0) {
        return 1;
    }

    if (value < 0.0) {
        return -1;
    }

    return 0;
}

int applyResets(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic, double *resetConditions)
{
    double resetConditions0 = states[0] - 2.123;

    if (isNearlyZero(resetConditions0)) {
        states[0] = 1.0;

        resetConditions[0] = NAN;

        return 1;
    }

    if (!isnan(resetConditions[0]) && (sign(resetConditions0) != sign(resetConditions[0]))) {
        //---GRY--- TEMPORARILY APPLY THE RESET. IDEALLY, THE SOLVER WOULD USE THE CHANGE OF SIGN IN THE RESET CONDITION
        //          TO FINE TUNE THE TRIGGERING OF THE RESET.

        states[0] = 1.0;

        resetConditions[0] = NAN;

        return 2;
    }

    resetConditions[0] = resetConditions0;

    return 0;
}
