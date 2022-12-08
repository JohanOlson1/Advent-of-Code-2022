#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> calories{};

int day1task1() {
    std::ifstream myfile("../input.txt");
    std::string myline{};
    int currentSum{ 0 };
    
    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(myfile) {
            std::getline(myfile, myline);
            if (myline == "") {
                calories.push_back(currentSum);
                currentSum = 0;
            } else {
                currentSum += std::stoi(myline);
            }
        }
    }
    else {
        std::cout << "Failed to load file\n";
    }
    std::sort(calories.begin(), calories.end(), std::greater<int>());
    return calories[0];
}

int day1task2() {
    return calories[0] + calories[1] + calories[2];
}

int main() {
    int SnackiestElfCalories{ day1task1() };
    std::cout << "The elf with the most calories has: " << SnackiestElfCalories << " calories\n";

    int topThreeSnackiestElves{ day1task2() };
    std::cout << "The three snackiest elfs have a total of: " << topThreeSnackiestElves << " calories\n";

    return 0;
}
