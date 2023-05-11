#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool addReservations(int n);
    bool cancelReservations(int n);
    ~FlightBooking();
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = (reserved > 0) ? reserved : 0;
    this->reserved = (this->reserved > 1.05 * capacity) ? 1.05 * capacity : this->reserved; // Overbooking limit 105%
}

void FlightBooking::printStatus()
{
    double percentage = (double)reserved / capacity * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats taken" << endl;
}

bool FlightBooking::addReservations(int n)
{
    int newReserved = reserved + n;
    if (newReserved > capacity * 1.05) {
        cout << "Cannot perform this operation" << endl;
        return false;
    }
    reserved = newReserved;
    return true;
}

bool FlightBooking::cancelReservations(int n)
{
    int newReserved = reserved - n;
    if (newReserved < 0) {
        cout << "Cannot perform this operation" << endl;
        return false;
    }
    reserved = newReserved;
    return true;
}

FlightBooking::~FlightBooking()
{
    cout << "Flight " << id << " deleted" << endl;
}

int main() {
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();
    while (true) {
        string command;
        cout << "Enter command: ";
        cin >> command;
        if (command == "add") {
            int n;
            cin >> n;
            booking.addReservations(n);
            booking.printStatus();
        }
        else if (command == "cancel") {
            int n;
            cin >> n;
            booking.cancelReservations(n);
            booking.printStatus();
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
