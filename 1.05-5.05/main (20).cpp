#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() {
    
    if (numerator % denominator == 0) {
        return to_string(numerator / denominator);
    }

    string sign = "";
    if (numerator < 0 != denominator < 0) {
        sign = "-";
    }
    string result="";
    int whole = abs(numerator) / abs(denominator);
    int remainder = abs(numerator) % abs(denominator);
    if(whole==0){
     result = sign;
    }else{
     result = sign + to_string(whole);
    }
    if (remainder != 0) {
        result += " " + to_string(remainder) + "/" + to_string(denominator);
    }

    return result;
}

double Fraction::toDouble() {
    return (double)numerator / (double)denominator;
}

int main() {
    int num, den;
    char slash;
    cin >> num >> slash >> den;
    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    
    return 0;
}
