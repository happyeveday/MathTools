//main.cpp

#include <iostream>
#include "./FunctionPlotter/FunctionPlotter.h"

int main() {
    FunctionPlotter plotter;
    std::string userFunction;
    
    std::cout << "Enter a function (e.g., 3*x+7): ";
    std::cin >> userFunction;

    plotter.setFunction(userFunction);
    plotter.generatePlot(-10, 10, 100);  // 设定 x 轴范围 -10 到 10，100 个点

    std::cout << "Plot generated successfully. Check 'function_plot.png'." << std::endl;
    return 0;
}
