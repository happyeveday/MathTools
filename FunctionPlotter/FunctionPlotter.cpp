// FunctionPlotter.cpp

#include "FunctionPlotter.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


void FunctionPlotter::setFunction(const std::string& func) {
    function = func;
}

void FunctionPlotter::generatePlot(double xMin, double xMax, int numPoints) {
    std::ofstream file("function_data.txt");
    if (!file) {
        std::cerr << "Error: Cannot open file to write function data.\n";
        return;
    }

    file << function << "\n" << xMin << "\n" << xMax << "\n" << numPoints;
    file.close();

    plt::save("function_plot.png");

    system("python plot_function.py");
}
