#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
void addCaloriesToVector(std::ifstream &my_file, std::vector<int> &calories_of_elves);
std::pair<int, int> day1(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day1.txt"};
    std::pair<int, int> day1_answers = day1(input_file_path);

    std::cout << "Task 1: " << day1_answers.first << " calories\n";
    std::cout << "Task 2: " << day1_answers.second << " calories\n";

    return 0;
}

// Function defintion
void addCaloriesToVector(std::ifstream &my_file, std::vector<int> &calories_of_elves) {
    std::string my_line{};
    int calorie_count{ 0 };

    while(my_file) {
        std::getline(my_file, my_line);
        if (my_line != "") {
            calorie_count += std::stoi(my_line);
        } else {
            calories_of_elves.push_back(calorie_count); // Add elfs calories to vector
            calorie_count = 0;
        }
    }
}

std::pair<int, int> day1(const std::string input_file_path) {
    std::ifstream my_file(input_file_path);
    std::vector<int> calories_of_elves{};

    if (my_file.is_open()) {
        std::cout << "Input file opened\n";
        addCaloriesToVector(my_file, calories_of_elves); 
    } else {
        std::cout << "Failed to load input file\n";
    }
    
    std::sort(calories_of_elves.begin(), calories_of_elves.end(), std::greater<int>()); // Put largest int first in vector

    return std::make_pair(calories_of_elves[0], calories_of_elves[0] + calories_of_elves[1] + calories_of_elves[2]);
}
