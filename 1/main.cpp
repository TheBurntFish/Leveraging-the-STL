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
    // Added greater than operator overload to Car
    std::sort(cars.begin(), cars.end(), std::greater<Car>());
    std::cout << "Reversed: " << "TODO" << "\n";
}
