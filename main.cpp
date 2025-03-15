// main.cpp

#include <iostream>
#include <fstream>  // 添加此行以包含 std::ifstream
#include "calculator/calculator.h"
#include "Data/Data.h"
#include "FunctionPlotter/FunctionPlotter.h"

void runCalculator() {
    Calculator calc;
    Data num1, num2;
    char op;

    try {
        calc.readUserInput(num1);
        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> op;
        calc.readUserInput(num2);

        double result;
        switch (op) {
            case '+':
                result = calc.add(num1.getValue<double>(), num2.getValue<double>());
                break;
            case '-':
                result = calc.sub(num1.getValue<double>(), num2.getValue<double>());
                break;
            case '*':
                result = calc.mul(num1.getValue<double>(), num2.getValue<double>());
                break;
            case '/':
                result = calc.div(num1.getValue<double>(), num2.getValue<double>());
                break;
            default:
                throw std::invalid_argument("Invalid operator! Use +, -, *, /.");
        }

        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Invalid input: " << e.what() << std::endl;
    }

    std::cout << "Program continues..." << std::endl;
}

void runFunctionPlotter() {
    FunctionPlotter plotter;
    std::string userFunction;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter a function (e.g., 3*x+7): ";
        std::cin >> userFunction;

        
            plotter.setFunction(userFunction);
            plotter.generatePlot(-10, 10, 100);

            // 检查生成的图像文件是否存在
            std::ifstream plotFile("function_plot.png");
            if (plotFile) {
                validInput = true;
                plotFile.close();
                std::cout << "Plot generated successfully. Check 'function_plot.png'." << std::endl;
            } else {
                std::cerr << "生成失败！" << std::endl;
            }
        
    }
}

int main() {

      try {
        std::cout << "Program started." << std::endl;
        // 程序其他代码...
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
    int choice;
    std::cout << "Select mode:\n";
    std::cout << "1. Calculator\n";
    std::cout << "2. Function Plotter\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        runCalculator();
    } else if (choice == 2) {
        runFunctionPlotter();
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }
    return 0;
}
