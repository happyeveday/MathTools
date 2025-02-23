// caculator.h

#ifndef CACULATOR_H
#define CACULATOR_H

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

#endif