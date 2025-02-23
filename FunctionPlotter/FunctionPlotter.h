// FunctionPlotter.h
#ifndef FUNCTION_PLOTTER_H
#define FUNCTION_PLOTTER_H

#include <string>

class FunctionPlotter {
public:
    FunctionPlotter() = default;
    void setFunction(const std::string& func);
    void generatePlot(double xMin, double xMax, int numPoints);
    
private:
    std::string function;
};

#endif
