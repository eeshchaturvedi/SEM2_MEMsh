#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string journeyDate;
    int capacity;

public:
    // Function to initialize members
    void initialize() {
        trainNumber = 0;
        trainName = "None";
        source = "None";
        destination = "None";
        journeyDate = "01-01-2000";
        capacity = 0;
    }

    // Function to input data
    void inputData() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // Clear buffer

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Journey Date (DD-MM-YYYY): ";
        getline(cin, journeyDate);

        cout << "Enter Capacity: ";
        cin >> capacity;
    }

    // Function to display data
    void displayData() const {
        cout << "\nTrain Information:\n";
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Journey Date: " << journeyDate << endl;
        cout << "Capacity: " << capacity << " passengers" << endl;
    }
};

int main() {
    Train t;
    t.initialize();   // Optional initialization
    t.inputData();    // Input train details
    t.displayData();  // Display train details

    return 0;
}
