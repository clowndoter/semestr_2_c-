#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    int n = 10;
    double *arr = new double[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = ((double) rand() / RAND_MAX) * 4 - 2; 
    }
    
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int pos_count = 0, neg_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos_count++;
        }
        else if (arr[i] < 0) {
            neg_count++;
        }
    }
    cout << "Positive numbers: " << pos_count << endl;
    cout << "Negative numbers: " << neg_count << endl;
    delete [] arr; 
    return 0;
}