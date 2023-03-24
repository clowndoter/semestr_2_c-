#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int SIZE = 5;
    int matrix[SIZE][SIZE];
    int *ptr = &matrix[0][0];
    int even_count = 0, odd_count = 0;

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(ptr + i * SIZE + j) = rand() % 50;
            if (*(ptr + i * SIZE + j) % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }
    }

    cout << "Array elements: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << *(ptr + i * SIZE + j) << " ";
        }
        cout << endl;
    }

    cout << "Elements on the main diagonal: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i * SIZE + i) << " ";
    }
    cout << endl;

    cout << "Elements on the secondary diagonal: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i * SIZE + (SIZE - 1 - i)) << " ";
    }
    cout << endl;

    cout << "Number of even elements: " << even_count << endl;
    cout << "Number of odd elements: " << odd_count << endl;

    return 0;
}
