#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    int weight;
};

void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old "<< endl;
    cout <<"And also he weight "<< person->weight << "kg." << endl;
}

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.weight = 75;

    cout << "Meet " << person.name << endl;
    print(&person);

    return 0;
}
