#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void task1(const int &string_value, int &score) {
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

void task2(const int &string_value, int &score) {
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

void day2(int &score_task1, int &score_task2) {
    std::ifstream myfile("../input.txt");
    char mychar1{};
    char mychar2{};
    int string_value{};

    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(myfile) {
            myfile >> mychar1 >> mychar2;
            string_value = 10*mychar1 + mychar2 - 737;
            task1(string_value, score_task1);
            task2(string_value, score_task2);
        }
    }
    else {
        std::cout << "Failed to load file\n";
    }
    score_task1 -= 3;
    score_task2 -= 8;
}

int main() {
    int predicted_score_task1{ 0 };
    int predicted_score_task2{ 0 };

    day2(predicted_score_task1, predicted_score_task2);

    std::cout << "The predicted total score is: " << predicted_score_task1 << "\n";
    std::cout << "The predicted total score is: " << predicted_score_task2 << "\n";
    return 0;
}
