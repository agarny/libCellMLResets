#include <fstream>

void printHeaders(std::ofstream &file);
void printValues(std::ofstream &file, double voi, const double *states, const double *constants, const double *computedConstants, const double *algebraic);
