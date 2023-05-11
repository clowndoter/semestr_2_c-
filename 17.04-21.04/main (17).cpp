#include <iostream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
private:
    int id;
    int capacity;
    int reserved;
};

void FlightBooking::printStatus()
{
    double percentage = ((double) reserved / capacity) * 100.0;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats taken" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}

int main() {
    int reserved = 0,
        capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    
    booking.printStatus();
    
    return 0;
}
