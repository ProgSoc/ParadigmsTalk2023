#include <iostream>
#include <string>

// Define an interface "Vehicle" with a pure virtual function "drive".
class Vehicle {
public:
    virtual void drive() = 0;
};

// Define a base class "Car" that inherits from "Vehicle."
class Car : public Vehicle {
public:
    Car(const std::string& make, const std::string& model) : make(make), model(model) {}

    // Implement the "drive" method for the "Car" class.
    void drive() override {
        std::cout << "Driving the " << make << " " << model << " car." << std::endl;
    }

    // Encapsulation: private members accessible only through methods.
    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

private:
    std::string make;
    std::string model;
};

// Define a derived class "ElectricCar" that inherits from "Car."
class ElectricCar : public Car {
public:
    ElectricCar(const std::string& make, const std::string& model, int batteryCapacity)
        : Car(make, model), batteryCapacity(batteryCapacity) {}

    // Polymorphism: Override the "drive" method to provide a specialized implementation.
    void drive() override {
        std::cout << "Driving the electric " << getMake() << " " << getModel() << " car with a " << batteryCapacity << " kWh battery." << std::endl;
    }

    // Static member: Common to all instances of the class.
    static int electricCarsCount;

    // Static method: Access and modify the static member.
    static void incrementElectricCarsCount() {
        electricCarsCount++;
    }

    // Instance member: Specific to each instance of the class.
    int getBatteryCapacity() const {
        return batteryCapacity;
    }

private:
    int batteryCapacity;
};

// Initialize the static member outside of the class.
int ElectricCar::electricCarsCount = 0;

int main() {
    ElectricCar tesla("Tesla", "Model S", 100);
    ElectricCar bmw("BMW", "i3", 50);

    // Abstraction: Users don't need to know the internal details of the "ElectricCar" class.
    tesla.drive();
    bmw.drive();

    // Inheritance: ElectricCar is a Car, which is a Vehicle.
    std::cout << "Number of electric cars: " << ElectricCar::electricCarsCount << std::endl;

    return 0;
}
