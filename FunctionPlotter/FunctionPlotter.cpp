// FunctionPlotter.cpp
#include "FunctionPlotter.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

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

    // 调用 Python 绘图脚本
    system("python3 plot_function.py");
}
