#include <iostream>
using namespace std;

int increment(int var){
    return ++var;
}

int increment(int var,int i){
    return var+i;
}

int main(void) {
	int var = 0;
	for(int i = 0; i < 10; i++){
		if(i % 2){
			var=increment(var);
		}
		else{
			var=increment(var,i);
		}
	}
	cout << var << endl;
	return 0;
}
