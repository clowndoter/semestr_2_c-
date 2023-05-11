#include <iostream>
using namespace std;

const int DivideByZero = 111;

float internaldiv(float arg1, float arg2)
{
    if (arg2 == 0)
        throw DivideByZero;
    return arg1 / arg2;
}

float div(float arg1, float arg2) {
    return internaldiv(arg1, arg2);
}

int main(void) {
    float r, a, b;
    while (cin >> a) {
        cin >> b;
        try {
            r = div(a, b);
            cout <<"Result:"<< r << endl;
        }
        catch (const int& ex) {
            if (ex == DivideByZero)
                cout << "Your input is not valid, you can't divide by zero." << endl;
        }
        cout<<"-------------"<<endl;
    }
    return 0;
}
