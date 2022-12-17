#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
void getScoresTask1(const int &string_value, int &score);
void getScoresTask2(const int &string_value, int &score);
void calculateScores(std::ifstream &my_file, std::pair<int, int> &scores);
std::pair<int, int> day2(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day2.txt"};
    std::pair<int, int> day2_answers = day2(input_file_path);

    std::cout << "Task 1: " << day2_answers.first << "\n";
    std::cout << "Task 2: " << day2_answers.second << "\n";
    return 0;
}

// Function definition
void getScoresTask1(const int &string_value, int &score) { // This is a pretty ugly solution, but comp. efficient?
    switch (string_value) {
        case 1: score += 4; break;
        case 2: score += 8; break;
        case 3: score += 3; break;
        case 11: score += 1; break;
        case 12: score += 5; break;
        case 13: score += 9; break;
        case 21: score += 7; break;
        case 22: score += 2; break;
        case 23: score += 6; break;
        default: std::cout << "Incorrect case\n"; break;
    }
}

void getScoresTask2(const int &string_value, int &score) {
    switch (string_value) {
        case 1: score += 3; break;
        case 2: score += 4; break;
        case 3: score += 8; break;
        case 11: score += 1; break;
        case 12: score += 5; break;
        case 13: score += 9; break;
        case 21: score += 2; break;
        case 22: score += 6; break;
        case 23: score += 7; break;
        default: std::cout << "Incorrect case\n"; break;
    }
}

void calculateScores(std::ifstream &my_file, std::pair<int, int> &scores) {
    char mychar1{};
    char mychar2{};
    int string_value{};

    while(my_file >> mychar1 >> mychar2) {
        string_value = 10*mychar1 + mychar2 - 737;
        getScoresTask1(string_value, scores.first);
        getScoresTask2(string_value, scores.second);
    }
}

std::pair<int, int> day2(const std::string input_file_path) {
    std::ifstream my_file(input_file_path);
    std::pair<int, int> scores{0, 0};

    if (my_file.is_open()) {
        std::cout << "Input file opened\n";
        calculateScores(my_file, scores);
    } else {
        std::cout << "Failed to load input file\n";
    }
    return scores;
}
