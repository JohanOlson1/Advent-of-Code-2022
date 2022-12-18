#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
void task1(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks);
void task2(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks);
std::vector<std::string> readCrateDataToStacks(const std::vector<std::string> &raw_input);
void parseFileAndMoveCrates(std::ifstream &my_file, std::vector<std::string> &Stacks_task1, std::vector<std::string> &Stacks_task2);
std::pair<std::string, std::string> day5(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day5.txt"};
    std::pair<std::string, std::string> day5_answers = day5(input_file_path);

    std::cout << "Task 1: " << day5_answers.first << " are top crates\n";
    std::cout << "Task 2: " << day5_answers.second << " are top crates\n";

    return 0;
}

// Function defintion
void task1(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks) {
    for (int count = 0; count < N_to_mv; ++count) {
        Stacks[stack_dest].push_back(Stacks[stack_src].back());
        Stacks[stack_src].pop_back();
    }
} 

void task2(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks) {
    std::string temp;
    for (int count = 0; count < N_to_mv; ++count) {
        temp.push_back(Stacks[stack_src].back());
        Stacks[stack_src].pop_back();
    }
    for (int count = N_to_mv - 1; count >= 0; --count) {
        Stacks[stack_dest].push_back(temp[count]);
    }
}

std::vector<std::string> readCrateDataToStacks(const std::vector<std::string> &raw_input) {
    int height = raw_input.size();
    int length = raw_input[0].size();
    int stack_amount{ (length + 1)/4 };
    std::vector<std::string> Stacks{ static_cast<long unsigned int>(stack_amount) }; // Kinda ugly, atleast brace intialization warns us of this

    int stack{ 0 };
    for (int index = 1; index <= length; index += 4) { // Read over the data s.t. we get a vector of each stack with the content in correct order
        for (int heigh{height - 1}; heigh >= 0; --heigh) {
            if( raw_input[heigh][index] != ' ') {
                Stacks[stack].push_back(raw_input[heigh][index]);
            }
        }
        ++stack;
    }

    return Stacks;
}

void parseFileAndMoveCrates(std::ifstream &my_file, std::vector<std::string> &Stacks_task1, std::vector<std::string> &Stacks_task2) {
    int N_to_mv;
    int stack_src;
    int stack_dest;
    std::string my_line{};
    while(my_file.good()) { // Perform operation based on inputs until end file
        std::getline(my_file, my_line, ' ');
        std::getline(my_file, my_line, ' ');
        N_to_mv = std::stoi(my_line);

        std::getline(my_file, my_line, ' ');
        std::getline(my_file, my_line, ' ');
        stack_src = std::stoi(my_line) - 1;

        std::getline(my_file, my_line, ' ');
        std::getline(my_file, my_line);
        stack_dest = std::stoi(my_line) - 1;

        task1(N_to_mv, stack_src, stack_dest, Stacks_task1); 
        task2(N_to_mv, stack_src, stack_dest, Stacks_task2); 
    }
}

std::pair<std::string, std::string> day5(const std::string input_file_path) {
    std::pair<std::string, std::string> top_crates;
    std::ifstream my_file(input_file_path);

    std::string my_line{};
    std::vector<std::string> raw_input;

    if (my_file.is_open()) {
        std::cout << "File Opened\n";
        while(std::getline(my_file, my_line) && !my_line.empty()) { // Read the crate input data into a vector of strings
            raw_input.push_back(my_line);
        }

        std::vector<std::string> Stacks_task1 = readCrateDataToStacks(raw_input); 
        std::vector<std::string> Stacks_task2 = readCrateDataToStacks(raw_input); // Not a comp. expensive operation so can duplicate

        parseFileAndMoveCrates(my_file, Stacks_task1, Stacks_task2);

        for (int count = 0; count < Stacks_task1.size(); ++count) {
            top_crates.first.push_back(Stacks_task1[count].back());
            top_crates.second.push_back(Stacks_task2[count].back());
        }
    } else {
        std::cout << "Failed to open file\n"; 
    }

    return top_crates;
}
