#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

auto day4() {
    std::ifstream myfile("../input.txt");
    std::string myline{};
    int amount_of_contains{ 0 };
    int amount_of_overlaps{ 0 };
    int low_first{};
    int high_first{};
    int low_second{};
    int high_second{};

    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(myfile.good()) {
            std::getline(myfile, myline, '-');
            low_first = std::stoi(myline);
            std::getline(myfile, myline, ',');
            high_first = std::stoi(myline);
            std::getline(myfile, myline, '-');
            low_second = std::stoi(myline);
            std::getline(myfile, myline);
            high_second = std::stoi(myline);

            if ((high_first - low_first) >= (high_second - low_second)) {
                if (low_first <= low_second && high_first >= high_second) {
                    ++amount_of_contains;
                }
            } else {
                if (low_second <= low_first && high_second >= high_first) {
                    ++amount_of_contains;
                }
            }
            
            if ((high_first - low_first) >= (high_second - low_second)) {
                if ((low_first <= low_second && low_second <= high_first) || (low_second <= low_first && low_first <= high_second)) {
                    ++amount_of_overlaps;
                }
            } else {
                if ((low_second <= low_first && low_first <= high_second) || (low_first <= low_second && low_second <= high_first)) {
                    ++amount_of_overlaps;
                }
            }
        }
    }
    else {
        std::cout << "Failed to load file\n";
    }
  struct retVals {        // Declare a local structure 
    int i1, i2;
  };
  return retVals {amount_of_contains, amount_of_overlaps}; // Return the local structure
}

int main() {
    auto [amount_of_contains, amount_of_overlaps] = day4(); // structured binding declaration

    std::cout << "Amount of containments: " << amount_of_contains << "\n";
    std::cout << "Amount of containments: " << amount_of_overlaps << "\n";
    return 0;
}
