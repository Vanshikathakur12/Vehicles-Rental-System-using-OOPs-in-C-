#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Base class
class Vehicle {
protected:
    int vehicleID;
    string model;
    int rentalDays;
    double rentalRate;

public:
    // Constructor
    Vehicle(int id, string m, int days, double rate) {
        vehicleID = id;
        model = m;
        rentalDays = days;
        rentalRate = rate;
    }

    // Common vehicle details
    virtual void displayDetails() {
        cout << "\nVehicle ID: " << vehicleID << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Duration: " << rentalDays
             << " day(s)" << endl;
    }

    // Virtual function for rental calculation
    virtual double calculateRent() {
        return rentalDays * rentalRate;
    }

    virtual ~Vehicle() {}
};

// Derived class: Car
class Car : public Vehicle {
public:
    Car(int id, string m, int days)
        : Vehicle(id, m, days, 1500.0) {}

    // Function overriding
    double calculateRent() override {
        return rentalDays * rentalRate;
    }

    void displayDetails() override {
        cout << "\n--- CAR RENTAL DETAILS ---" << endl;
        Vehicle::displayDetails();
        cout << "Daily Rental Rate: Rs. "
             << rentalRate << endl;
        cout << "Total Rental Charges: Rs. "
             << calculateRent() << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
public:
    Bike(int id, string m, int days)
        : Vehicle(id, m, days, 500.0) {}

    // Function overriding
    double calculateRent() override {
        return rentalDays * rentalRate;
    }

    void displayDetails() override {
        cout << "\n--- BIKE RENTAL DETAILS ---" << endl;
        Vehicle::displayDetails();
        cout << "Daily Rental Rate: Rs. "
             << rentalRate << endl;
        cout << "Total Rental Charges: Rs. "
             << calculateRent() << endl;
    }
};

// Main function
int main() {
    int choice, id, days;
    string model;

    cout << "================================\n";
    cout << "     VEHICLE RENTAL SYSTEM\n";
    cout << "================================\n";

    cout << "1. Rent a Car\n";
    cout << "2. Rent a Bike\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Invalid choice! Please select 1 or 2.\n";
        return 1;
    }

    cout << "Enter Vehicle ID: ";
    if (!(cin >> id) || id <= 0) {
        cout << "Invalid vehicle ID!\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Vehicle Model: ";
    getline(cin, model);

    if (model.empty()) {
        cout << "Model cannot be empty!\n";
        return 1;
    }

    cout << "Enter Rental Duration (in days): ";
    if (!(cin >> days) || days <= 0) {
        cout << "Invalid duration! Days must be positive.\n";
        return 1;
    }

    // Create the selected vehicle object
    if (choice == 1) {
        Car car(id, model, days);
        car.displayDetails();
    } else {
        Bike bike(id, model, days);
        bike.displayDetails();
    }

    cout << "\nThank you for using our system!\n";

    return 0;
}
