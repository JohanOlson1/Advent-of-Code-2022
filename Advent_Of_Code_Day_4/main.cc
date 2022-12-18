#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
int checkContain(const int low_large, const int high_large, const int low_small, const int high_small);
int checkOverlap(const int low_large, const int high_large, const int low_small, const int high_small);
std::pair<int, int> day4(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day4.txt"};
    std::pair<int, int> day4_answers = day4(input_file_path); 

    std::cout << "Task 1: " << day4_answers.first  << " contains\n";
    std::cout << "Task 2: " << day4_answers.second << " overlaps\n";
    return 0;
}

// Function definition
int checkContain(const int low_large, const int high_large, const int low_small, const int high_small) {
    if (low_large <= low_small && high_small <= high_large) {
        return 1;
    } else {
        return 0;
    }
}

int checkOverlap(const int low_large, const int high_large, const int low_small, const int high_small) {
    if ((low_large <= low_small && low_small <= high_large) || (low_small <= low_large && low_large <= high_small)) {
        return 1;
    } else {
        return 0;
    }
}

std::pair<int, int> day4(const std::string input_file_path) {
    std::ifstream my_file(input_file_path);
    std::string my_line{};
    int amount_of_contains{ 0 };
    int amount_of_overlaps{ 0 };
    int low_first{};
    int high_first{};
    int low_second{};
    int high_second{};
    int largest_interval{};

    if (my_file.is_open()) {
        std::cout << "Input file opened\n";
        while(my_file.good()) {
            std::getline(my_file, my_line, '-');
            low_first = std::stoi(my_line);
            std::getline(my_file, my_line, ',');
            high_first = std::stoi(my_line);
            std::getline(my_file, my_line, '-');
            low_second = std::stoi(my_line);
            std::getline(my_file, my_line);
            high_second = std::stoi(my_line);

            largest_interval = ((high_first - low_first) > (high_second - low_second)); // 1 the first is largest, 0 the second is largest
            switch (largest_interval) {
                case 1: amount_of_contains += checkContain(low_first, high_first, low_second, high_second); 
                        amount_of_overlaps += checkOverlap(low_first, high_first, low_second, high_second); break;
                case 0: amount_of_contains += checkContain(low_second, high_second, low_first, high_first);
                        amount_of_overlaps += checkOverlap(low_second, high_second, low_first, high_first); break;
            }
        }
    }
    else {
        std::cout << "Failed to load input file\n";
    }

  return std::make_pair(amount_of_contains, amount_of_overlaps);
}