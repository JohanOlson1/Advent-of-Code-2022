#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
int addToPrioritySum(char shared_item);
int task1(const std::string my_line);
int task2(const std::string my_line,std::vector<std::string> &elf_group);
void getPrioritySum(std::ifstream &my_file, std::pair<int, int> &priority_sum);
std::pair<int, int> day3(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day3.txt"};
    std::pair<int, int> day3_answers = day3(input_file_path);

    std::cout << "Task 1: " << day3_answers.first << "\n";
    std::cout << "Task 2: " << day3_answers.second << "\n";
    return 0;
}

// Function definiton
int addToPrioritySum(char shared_item) {
    // ASCII Upper case letters int: 65 - 90, we want start at 27
    // ASCii Lower case letters int: 97 - 122, we want 1 - 26
    int upper_case_conversion{ 38 }; // 65 - 38 = 27
    int lower_case_conversion{ 96 }; // 97 - 96 = 1

    int letter_case = (shared_item < lower_case_conversion); // 1 - upper, 0 - lower

    switch(letter_case) {
        case 0: shared_item -= lower_case_conversion; break;
        case 1: shared_item -= upper_case_conversion; break;
    }

    return shared_item;
}

int task1(const std::string my_line) {
    int string_length = my_line.length();
    char shared_item_task1;

    for(int first_index{ 0 }; first_index < string_length/2; ++first_index) {
        for (int second_index{ string_length/2 }; second_index < string_length; ++second_index)
        if (my_line[first_index] == my_line[second_index]) {
            shared_item_task1 = my_line[first_index];
            break;
        }
    }

    return addToPrioritySum(shared_item_task1);
}

int task2(const std::string my_line,std::vector<std::string> &elf_group) {
    char shared_item_task2;

    for (int element1 : elf_group[0]) {
        for (int element2 : elf_group[1]) {
            for (int element3 : elf_group[2]) {
                if (element1 == element2 && element1 == element3) {
                    shared_item_task2 = element1;  // Ugly as hell but first thought
                }
            }
        }
    } 

    return addToPrioritySum(shared_item_task2);
}

void getPrioritySum(std::ifstream &my_file, std::pair<int, int> &priority_sum) {
    std::string my_line;
    char shared_item_task1{};
    char shared_item_task2{};
    int count{ 0 };
    std::vector<std::string> elf_group{}; 

    while(my_file.good()) {
        std::getline(my_file, my_line);

        priority_sum.first += task1(my_line);

        elf_group.push_back(my_line);
        ++count;
        if (count == 3) {
            priority_sum.second += task2(my_line, elf_group); // Only perform algorithm once three elves have been loaded
            elf_group.clear(); // Clear for new elves
            count = 0;
        }
    }
}

std::pair<int, int> day3(const std::string input_file_path) {
    std::ifstream my_file(input_file_path);
    std::pair<int, int> priority_sum{0, 0};

    if (my_file.is_open()) {
        std::cout << "Input file opened\n";
        getPrioritySum(my_file, priority_sum);
    } else {
        std::cout << "Failed to load input file\n";
    }

    return priority_sum;
}
