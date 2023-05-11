#include <iostream>
#include <map>
#include <string>

using namespace std;

class GymMember {
public:
    string name;
    int monthsValid;
};

int main() {
    map<int, GymMember> gymMembers;
    string command, name;
    int id, n;
    
    while (true) {
        cin >> command;
        
        if (command == "create") {
            cin >> id >> name;
            if (id == 0) {
                cout << "Cannot perform this operation. ID cannot be 0." << endl;
            } else if (gymMembers.count(id) == 1) {
                cout << "Cannot perform this operation. ID already exists." << endl;
            } else if (gymMembers.size() == 10) {
                cout << "Cannot perform this operation. Maximum number of members reached." << endl;
            } else {
                GymMember member;
                member.name = name;
                member.monthsValid = 0;
                gymMembers[id] = member;
                cout << "Member " << id << " : " << name << ", subscription valid for 0 months" << endl;
            }
        } else if (command == "delete") {
            cin >> id;
            if (gymMembers.count(id) == 0) {
                cout << "Cannot perform this operation. ID does not exist." << endl;
            } else {
                gymMembers.erase(id);
            }
        } else if (command == "extend") {
            cin >> id >> n;
            if (gymMembers.count(id) == 0) {
                cout << "Cannot perform this operation. ID does not exist." << endl;
            } else {
                gymMembers[id].monthsValid += n;
                cout << "Member " << id << " : " << gymMembers[id].name << ", subscription valid for " << gymMembers[id].monthsValid << " months" << endl;
            }
        } else if (command == "cancel") {
            cin >> id;
            if (gymMembers.count(id) == 0) {
                cout << "Cannot perform this operation. ID does not exist." << endl;
            } else {
                gymMembers[id].monthsValid = 0;
                cout << "Member " << id << " : " << gymMembers[id].name << ", subscription valid for 0 months" << endl;
            }
        } else if (command == "quit") {
            break;
        } else {
            cout << "Cannot perform this operation. Invalid command." << endl;
        }
    }
    
    return 0;
}