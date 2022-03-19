#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range
    double total = 0;
    for (Car c : cars) {
        total += c.price();
    }

    std::cout << "The average price is: $" << total/cars.size() << "\n";


    auto maxPriceIt = std::max_element(cars.begin(), cars.end(), [](const Car& lhs, const Car& rhs) {
        return lhs.price() < rhs.price();
        });
    //find max index from beginning
    auto max = std::distance(cars.begin(), maxPriceIt);


    auto minPriceIt = std::min_element(cars.begin(), cars.end(), [](const Car& lhs, const Car& rhs) {
        return lhs.price() < rhs.price();
        });
    //find min index from beginning
    int min = std::distance(cars.begin(), minPriceIt);

    double range = cars[max].price() - cars[min].price();
    std::cout << "The range is: $" << range << "\n";
}
