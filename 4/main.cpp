#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers
    auto result = false;
    
    // Go through each integer
    for (int val : values) {
        int count = 0;
        if (val == 2) return true;
        //rule out 0 and 1 and evens (2 already dealt with)
        if (val > 2 && val % 2 != 0) {
            
            //prime only divisble by 1 and itself
            //skips 1 so (count + 1) should only trigger when val == i
            for (int i = 3; i <= val; i += 2) {
                if (val % i == 0) {
                    count++;
                }
                
            }
            if (count == 1) return true;

        }
    }

    return result;
}
