#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F
    for (Car c : cars) {
        if (c.price() < 10000.0
            || (c.vin().compare(0, 1, "A") == 0)
            || (c.vin().compare(0, 1, "B") == 0)
            || (c.vin().compare(0, 1, "C") == 0)
            || (c.vin().compare(0, 1, "D") == 0)
            || (c.vin().compare(0, 1, "E") == 0)
            || (c.vin().compare(0, 1, "F") == 0)) {

            taggedCars.push_back(Tag<Car>(true, c));
        }
        else {
            taggedCars.push_back(Tag<Car>(false, c));

        }
        
    }

    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened
    std::partition(taggedCars.begin(), taggedCars.end(), [](Tag<Car> c) {return c.isTagged(); });
    std::cout << "Tagged Cars: " << taggedCars << "\n";
}
