//Code By fancode343
//This algorithm was first coded in Java.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<string> numArrage(vector<string> numbers, string op, int indexIndentify, int i) {
    for (int change = i + 1; change < indexIndentify; change++) {
        numbers[change] = numbers[change + 1];
    }
    numbers[indexIndentify] = "";
    return numbers;
}

class Operator {
public:
    static string doubleToString(double equal) {
        if (equal == (long long)equal) {
            return to_string((long long)equal) + ".0";
        }
        string s = to_string(equal);
        size_t dot = s.find('.');
        if (dot != string::npos) {
            size_t lastNonZero = s.find_last_not_of('0');
            if (lastNonZero > dot) {
                s.erase(lastNonZero + 1);
            } else {
                s.erase(dot + 2);
            }
        }
        return s;
    }

    static string modulo(string a, string b) {
        double a1 = stod(a);
        double b1 = stod(b);
        double equal = fmod(a1, b1);
        string stringEqual = doubleToString(equal);
        return stringEqual;
    }
    static string add(string a, string b) {
        double a1 = stod(a);
        double b1 = stod(b);
        double equal = a1 + b1;
        string stringEqual = doubleToString(equal);
        return stringEqual;
    }
    static string subtract(string a, string b) {
        double a1 = stod(a);
        double b1 = stod(b);
        double equal = a1 - b1;
        string stringEqual = doubleToString(equal);
        return stringEqual;
    }
    static string multiply(string a, string b) {
        double a1 = stod(a);
        double b1 = stod(b);
        double equal = a1 * b1;
        string stringEqual = doubleToString(equal);
        return stringEqual;
    }
    static string divide(string a, string b) {
        double a1 = stod(a);
        double b1 = stod(b);
        double equal = (a1) / b1;
        string stringEqual = doubleToString(equal);
        return stringEqual;
    }
};

string calculate(string input) {
    string expression = input;
    vector<string> numbers(expression.length());
    for (int i = 0; i < (int)numbers.size(); i++) {
        numbers[i] = "";
    }
    string op = "";
    int expressionIndex = 0;
    if (expression[0] == '-') {
        numbers[0] += expression[0];
        expressionIndex++;
    }
    for (int i = 0; i < (int)numbers.size(); i++) {
        for (; expressionIndex < (int)expression.length(); expressionIndex++) {
            if ((expression[expressionIndex] == '+') ||
                (expression[expressionIndex] == '-') ||
                (expression[expressionIndex] == 'x') ||
                (expression[expressionIndex] == '%') ||
                (expression[expressionIndex] == '/')
            ) {
                op += expression[expressionIndex];

                if (expression[expressionIndex + 1] == '-') {
                    numbers[i + 1] += expression[expressionIndex + 1];
                    expressionIndex++;
                }
                if (expression[expressionIndex + 1] == '+') {
                    numbers[i + 1] += expression[expressionIndex + 1];
                    expressionIndex++;
                }

                expressionIndex++;
                break;
            }
            numbers[i] += expression[expressionIndex];
        }
    }

    int indexIndentify = (int)numbers.size() - 1;
    for (int i = 0; i < (int)op.length(); i++) {
        if (op[i] == 'x' || op[i] == '\xC3' || op[i] == '%') {
            if (op[i] == 'x') {
                numbers[i] = Operator::multiply(numbers[i], numbers[i + 1]);
                op = op.substr(0, i) + op.substr(i + 1);
                numbers = numArrage(numbers, op, indexIndentify, i);
                indexIndentify--;
                i--;
                continue;
            }
            if (op[i] == '/') {
                numbers[i] = Operator::divide(numbers[i], numbers[i + 1]);
                op = op.substr(0, i) + op.substr(i + 1);
                numbers = numArrage(numbers, op, indexIndentify, i);
                indexIndentify--;
                i--;
                continue;
            }
            if (op[i] == '%') {
                numbers[i] = Operator::modulo(numbers[i], numbers[i + 1]);
                op = op.substr(0, i) + op.substr(i + 1);
                numbers = numArrage(numbers, op, indexIndentify, i);
                indexIndentify--;
                i--;
                continue;
            }
        }
    }
    for (int i = 0; i < (int)op.length(); i++) {
        if (op[i] == '+' || op[i] == '-') {
            if (op[i] == '+') {
                numbers[i] = Operator::add(numbers[i], numbers[i + 1]);
                op = op.substr(0, i) + op.substr(i + 1);
                numbers = numArrage(numbers, op, indexIndentify, i);
                indexIndentify--;
                i--;
                continue;
            }
            if (op[i] == '-') {
                numbers[i] = Operator::subtract(numbers[i], numbers[i + 1]);
                op = op.substr(0, i) + op.substr(i + 1);
                numbers = numArrage(numbers, op, indexIndentify, i);
                indexIndentify--;
                i--;
                continue;
            }
        }
    }
    return numbers[0];
}

int main() {
    cout << "Welcome To my Calculator type STOP to end the program \n\nEX. 1/8+2x1";
    string userinput;
    while(userinput != "STOP"){
        cout << "\nEnter Number:  ";
        cin >> userinput;
        cout << "Answer: "+calculate(userinput);
    }
}
