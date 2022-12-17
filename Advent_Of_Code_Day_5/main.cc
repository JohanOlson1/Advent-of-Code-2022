#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void task1(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks) {
    for (int count = 0; count < N_to_mv; ++count) {
        Stacks[stack_dest].push_back(Stacks[stack_src].back());
        Stacks[stack_src].pop_back();
    }
} 

void task2(int N_to_mv, int stack_src, int stack_dest, std::vector<std::string> &Stacks) { //RBTWJWMCF
    std::string temp;
    for (int count = 0; count < N_to_mv; ++count) {
        temp.push_back(Stacks[stack_src].back());
        Stacks[stack_src].pop_back();
    }
    for (int count = N_to_mv - 1; count >= 0; --count) {
        Stacks[stack_dest].push_back(temp[count]);
    }
} 

void day5() {
    std::ifstream myfile("../input_day5.txt");
    std::string myline{};

    std::vector<std::string> raw_input;
    std::vector<std::string> Stacks{ 9 };
    int stack{ 0 };

    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(std::getline(myfile, myline) && !myline.empty()) { // Read the data into an vector of strings
            raw_input.push_back(myline);
        }

        int height = raw_input.size();
        int length = raw_input[0].size();
        int stack{ 0 };
        for (int index = 1; index <= length; index += 4) { // Read over the data s.t. we get a vector or each stack with the content in correct order
            for (int heigh{height - 1}; heigh >= 0; --heigh) {
                if( raw_input[heigh][index] != ' ') {
                    Stacks[stack].push_back(raw_input[heigh][index]);
                }
            }
            ++stack;
        }

        std::vector<std::string> Stacks2 = Stacks; // Duplicate the Stacks for the two different tasks

        int N_to_mv;
        int stack_src;
        int stack_dest;
        while(myfile.good()) { // Perform operation based on inputs until end file
            std::getline(myfile, myline, ' ');
            std::getline(myfile, myline, ' ');
            N_to_mv = std::stoi(myline);

            std::getline(myfile, myline, ' ');
            std::getline(myfile, myline, ' ');
            stack_src = std::stoi(myline) - 1;

            std::getline(myfile, myline, ' ');
            std::getline(myfile, myline);
            stack_dest = std::stoi(myline) - 1;

            task1(N_to_mv, stack_src, stack_dest, Stacks); 
            task2(N_to_mv, stack_src, stack_dest, Stacks2); 
        }

        std::cout << "In task 1 the top creates are: ";
        for (int count = 0; count < Stacks.size(); ++ count) { // Display result task1
            std::cout << Stacks[count].back();
        }
        std::cout << "\n";

        std::cout << "In task 2 the top creates are: ";
        for (int count = 0; count < Stacks.size(); ++ count) { // Display result task 2
            std::cout << Stacks2[count].back();
        }
        std::cout << "\n";
    } else {
        std::cout << "Failed to open file\n"; 
    }
}

int main() {
    day5();

    return 0;
}
