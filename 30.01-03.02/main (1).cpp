#include <iostream>

using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);
    
    int *ptr = vector; 
    int max_val = *ptr;


    for (int i = 0; i < n; i++) {
        if (*(ptr + i) > max_val) {
            max_val = *(ptr + i);
        }
    }

    cout << "The maximum element in the array is: " << max_val << endl;
    return 0;
}
