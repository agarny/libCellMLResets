/* The content of this file was generated using the C profile of libCellML 0.6.2. */

#pragma once

#include <stddef.h>

extern const char VERSION[];
extern const char LIBCELLML_VERSION[];

extern const size_t STATE_COUNT;
extern const size_t CONSTANT_COUNT;
extern const size_t COMPUTED_CONSTANT_COUNT;
extern const size_t ALGEBRAIC_COUNT;
extern const size_t RESET_COUNT;

typedef struct {
    char name[3];
    char units[14];
    char component[5];
} VariableInfo;

extern const VariableInfo VOI_INFO;
extern const VariableInfo STATE_INFO[];
extern const VariableInfo CONSTANT_INFO[];
extern const VariableInfo COMPUTED_CONSTANT_INFO[];
extern const VariableInfo ALGEBRAIC_INFO[];

double * createStatesArray();
double * createConstantsArray();
double * createComputedConstantsArray();
double * createAlgebraicArray();
double * createResetsArray();

void deleteArray(double *array);

void initialiseVariables(double *states, double *rates, double *constants, double *computedConstants, double *algebraic);
void computeComputedConstants(double *constants, double *computedConstants);
void computeRates(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic);
void computeVariables(double voi, double *states, double *rates, double *constants, double *computedConstants, double *algebraic);

int computeResets(double voi, double *states, double *constants, double *computedConstants, double *algebraic, double *resets);
void applyReset(double voi, double *states, double *constants, double *computedConstants, double *algebraic, int resetIndex);
