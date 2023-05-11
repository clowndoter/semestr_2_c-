#include <iostream>
#include <string>

using namespace std;

class IPAddress {
protected:
    string address;

public:
    IPAddress() {}
    IPAddress(const string address) : address(address) {}
    IPAddress(const IPAddress& other) : address(other.address) {}   

    virtual void print() const {
        cout << address << endl;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool correct;

public:
    IPAddressChecked() {}
    IPAddressChecked(const string address, bool correct): IPAddress(address), correct(correct) {}
    IPAddressChecked(const IPAddressChecked& other): IPAddress(other), correct(other.correct) {}

    virtual void print() const {
        IPAddress::print();
        cout << (correct ? " - Correct" : " - Not Correct") << endl;
    }
};

int main() {
    string input1, input2, input3;
    cout << "Enter three IP addresses: ";
    cin >> input1 >> input2 >> input3;

    IPAddress ip1(input1);
    IPAddressChecked ip2(input2, false);
    IPAddressChecked ip3(input3, true);

    cout << "IP addresses:" << endl;
    ip1.print();
    ip2.print();
    ip3.print();

    return 0;
}