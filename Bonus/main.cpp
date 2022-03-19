#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> createElevationMap();

int main() {
    auto range = createElevationMap();
    // test case (should be 16)
    //std::vector<int> range = {1,0,3,6,0,1,1,0,1,0,0,1,0,1,2,1};

    std::cout << "Elevation Map: " << range << "\n";
    // TODO: print out the amount of trapped water after it rains

    auto peak = std::max_element(range.begin(), range.end());
    
    int water = 0;
    int start = 0;
    int last = 0;
    //goes up a level of elevation 
    for (int elevation = 1; elevation < *peak; elevation++) {
        //finds index first instance of (elevation) level
        for (int index = 0; index <= range.size(); index++) {
            if (range[index] >= elevation) {
                start = index;
                break;
            }
        }
        //finds index of last element with less elevation
        for (int index = range.size()-1; index > 0; index--) {
            if (range[index] >= elevation) {
                last = index;
                break;
            }
        }
        //finds elevation between first and last index of selected elevation and adds water if height at index is lower than said elevation
        for (int i = start; i <= last; i++) {
            if (range[i] < elevation) {
                water += 1;
            }
        }
     
    }

    std::cout << "Water: " << water << "\n";
}
    

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() { 
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}

