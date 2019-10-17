#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct FunctionParts {
    FunctionParts(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else if (operation == '-'){
            return source_value - value;
        } else if (operation == '*') {
            return source_value * value;
        } else if (operation == '/'){
            return source_value / value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else if (operation == '-'){
            operation = '+';
        } else if (operation == '*') {
            operation = '/';
        } else if (operation == '/'){
            operation = '*';
        }
    }
    private:
    char operation;
    double value;
};

struct Function
{
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for (const FunctionParts& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionParts& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }
    private:
    vector<FunctionParts> parts;
};


