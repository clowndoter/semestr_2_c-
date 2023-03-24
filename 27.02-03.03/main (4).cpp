#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int size = 3;
    
    int **arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }
    
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    
    cout << "Display array: "<<endl;
        for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "Elements on main diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i][i] << " ";
    }
    cout << endl;
    
    cout << "Elements on secondary diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i][size-i-1] << " ";
    }
    cout << endl;
    
    int even = 0, odd = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }
    cout << "Number of even elements: " << even << endl;
    cout << "Number of odd elements: " << odd << endl;
    
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
