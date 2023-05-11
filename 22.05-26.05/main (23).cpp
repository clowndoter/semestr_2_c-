#include <iostream>
using namespace std;

int main(void) {
    int a = 8, b = 0, c = 0;
    cin >> b;
    try {
        if (b == 0) {
            throw "you can't divide by zero.";
        }
        c = a / b;
    } catch (const char* exception) {
        cout << "Your input is not valid,"<< exception << endl;
        return 1;
    }
    cout << c << endl;
    return 0;
}
