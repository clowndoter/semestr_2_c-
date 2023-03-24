#include <iostream>
#include <ctime>

using namespace std;

bool isPrime(int number) {
    // Перевірка на від'ємність та на 0 та 1
    if (number < 2) {
        return false;
    }
    // Перевірка чи число є простим
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


int main(void) {
    
    for(int i=0;i<=21;i++){
    cout<<i<<" - "<<isPrime(i)<<endl;
    }
  return 0;
}
