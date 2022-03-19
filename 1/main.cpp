#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Initial: " << cars << "\n";

    // TODO: print out the cars in reverse order
    
    std::sort(cars.begin(), cars.end(), [](const Car& lhs, const Car& rhs) {
        return lhs.price() > rhs.price();
        });
    std::cout << "Reversed: " << "TODO" << "\n";
}
