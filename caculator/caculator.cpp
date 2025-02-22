#include <iostream>
#include <stdexcept>
#include "../Data/Data.h"

class Calculator {
public:
    template <typename T, typename U>
    auto add(T a, U b) -> typename std::common_type<T, U>::type {
        return a + b;
    }

    template <typename T, typename U>
    auto sub(T a, U b) -> typename std::common_type<T, U>::type {
        return a - b;
    }

    template <typename T, typename U>
    auto mul(T a, U b) -> typename std::common_type<T, U>::type {
        return a * b;
    }

    template <typename T, typename U>
    auto div(T a, U b) -> typename std::common_type<T, U>::type {
        if (b == 0) {
            throw std::runtime_error("Error: Division by zero!");
        }
        return a / b;
    }
};

void readUserInput(Data &data) {
    std::string input;
    std::cout << "Enter a number (int, float, double, or complex as 'a+bi'): ";
    std::cin >> input;

    try {
        if (input.find('+') != std::string::npos || input.find('i') != std::string::npos) {
            double real, imag;
            sscanf(input.c_str(), "%lf+%lfi", &real, &imag);
            data.setValue(std::complex<double>(real, imag));
        } else if (input.find('.') != std::string::npos) {
            double val = std::stod(input);
            data.setValue(val);
        } else {
            int val = std::stoi(input);
            data.setValue(val);
        }
    } catch (...) {
        throw std::invalid_argument("Invalid number format!");
    }
}

int main() {
    Calculator calc;
    Data num1, num2;
    char op;

    try {
        readUserInput(num1);
        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> op;
        readUserInput(num2);

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
    return 0;
}