#include <iostream>
#include <string>
#include <vector>

class Car {
private:
    std::string make;
    std::string model;
    bool available;

public:
    Car(const std::string& make, const std::string& model) : make(make), model(model), available(true) {}

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool availability) {
        available = availability;
    }
};

class CarRentalSystem {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void displayAvailableCars() const {
        std::cout << "Available Cars:" << std::endl;
        std::cout << "----------------" << std::endl;

        for (const Car& car : cars) {
            if (car.isAvailable()) {
                std::cout << "Make: " << car.getMake() << ", Model: " << car.getModel() << std::endl;
            }
        }

        std::cout << "----------------" << std::endl;
    }

    bool rentCar(const std::string& make, const std::string& model) {
        for (Car& car : cars) {
            if (car.getMake() == make && car.getModel() == model) {
                if (car.isAvailable()) {
                    car.setAvailability(false);
                    std::cout << "You have rented the car successfully." << std::endl;
                    return true;
                } else {
                    std::cout << "The car is already rented. Please choose another car." << std::endl;
                    return false;
                }
            }
        }

        std::cout << "Car not found. Please check the make and model." << std::endl;
        return false;
    }

    bool returnCar(const std::string& make, const std::string& model) {
        for (Car& car : cars) {
            if (car.getMake() == make && car.getModel() == model) {
                if (!car.isAvailable()) {
                    car.setAvailability(true);
                    std::cout << "You have returned the car successfully." << std::endl;
                    return true;
                } else {
                    std::cout << "The car is not currently rented." << std::endl;
                    return false;
                }
            }
        }

        std::cout << "Car not found. Please check the make and model." << std::endl;
        return false;
    }
};

int main() {
    CarRentalSystem carRentalSystem;

    // Add cars to the rental system
    carRentalSystem.addCar(Car("Toyota", "Camry"));
    carRentalSystem.addCar(Car("Honda", "Accord"));
    carRentalSystem.addCar(Car("Ford", "Mustang"));
    carRentalSystem.addCar(Car("Chevrolet", "Cruze"));

    int choice;
    std::string make, model;

    do {
        std::cout << "Car Rental System" << std::endl;
        std::cout << "1. Display available cars" << std::endl;
        std::cout << "2. Rent a car" << std::endl;
        std::cout << "3. Return a car" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                carRentalSystem.displayAvailableCars();
                break;
            case 2:
                std::cout << "Enter the make and model of the car you want to rent: ";
                std::cin >> make >> model;
                carRentalSystem.rentCar(make, model);
                break;
            case 3:
                std::cout << "Enter the make and model of the car you want to return: ";
                std::cin >> make >> model;
                carRentalSystem.returnCar(make, model);
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 4);

    return 0;
}
