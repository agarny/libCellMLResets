#include <fstream>

bool fuzzyCompare(double pNb1, double pNb2);

void printHeaders(std::ofstream &file);
void printValues(std::ofstream &file, double voi, const double *states, const double *constants, const double *computedConstants, const double *algebraic);
