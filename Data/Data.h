// Data.h

#ifndef DATA_H
#define DATA_H

#include <complex>
#include <iostream>
#include <type_traits>

class Data {
    public:
        enum Type {SHORT, INT, LONG, FLOAT, DOUBLE, COMPLEX, UNKNOWN } type;
        union {
            short int sVal;
            int iVal;
            long long int lVal;
            float fVal;
            double dVal;
        };
        std::complex<double> cVal;
    
        Data() : type(UNKNOWN) {}
    
        void setValue(short int val) {
            sVal = val;
            type = SHORT;
        }

        void setValue(int val) {
            iVal = val;
            type = INT;
        }

        void setValue(long long int val) {
            lVal = val;
            type = LONG;
        }
        
        void setValue(float val) {
            fVal = val;
            type = FLOAT;
        }
        
        void setValue(double val) {
            dVal = val;
            type = DOUBLE;
        }
        
        void setValue(std::complex<double> val) {
            cVal = val;
            type = COMPLEX;
        }
    
        // 获取不同类型的值
        template <typename T>
        T getValue() const {
            switch (type) {
                case SHORT: return static_cast<T>(sVal);
                case INT: return static_cast<T>(iVal);
                case LONG: return static_cast<T>(lVal);
                case FLOAT: return static_cast<T>(fVal);
                case DOUBLE: return static_cast<T>(dVal);
                case COMPLEX: return static_cast<T>(std::abs(cVal)); 
                default: throw std::runtime_error("Data type not set!");
            }
        }
    };

#endif