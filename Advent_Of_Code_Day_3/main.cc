#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int day3() {
    std::ifstream myfile("../input.txt");
    std::string myline{};
    int string_length{};
    char shared_item{};
    int priority_sum{ 0 };
    
    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(myfile.good()) { // Apparently skipping .good() makes it wait one turn to check eof, like some idiot made it
            std::getline(myfile, myline);
            string_length = myline.length();

            for(int first_index{ 0 }; first_index < string_length/2; ++first_index) {
                for (int second_index{ string_length/2 }; second_index < string_length; ++second_index)
                if (myline[first_index] == myline[second_index]) {
                    shared_item = myline[first_index];
                    break;
                }
            }
            if (shared_item < 91) { // Chars are treated as ASCII Numbers, convert upper and lowercase appropiately
                priority_sum += (int)shared_item - 38;
            } else{
                priority_sum += (int)shared_item - 96;    
            }
        }
    }
    else {
        std::cout << "Failed to load file\n";
    }
    return priority_sum;
}

int day3task2() {
    std::ifstream myfile("../input.txt");
    std::string myline{};
    int string_length{};
    char shared_item{};
    int priority_sum{ 0 };
    
    if (myfile.is_open()) {
        std::cout << "File Opened\n";
        while(myfile.good()) { // Apparently skipping .good() makes it wait one turn to check eof, like some idiot made it
            int count{ 0 };
            std::vector<std::string> elf_group{};
            while(count < 3) {
                std::getline(myfile, myline);
                elf_group.push_back(myline);
                ++count;
            }

            for (int element1 : elf_group[0]) {
                for (int element2 : elf_group[1]) {
                    for (int element3 : elf_group[2]) {
                        if (element1 == element2 && element1 == element3) {
                            shared_item = element1;  // Ugly as hell but first thought
                        }
                    }
                }
            }   

            if (shared_item < 91) { // Chars are treated as ASCII Numbers, convert upper and lowercase appropiately
                priority_sum += (int)shared_item - 38;
            } else{
                priority_sum += (int)shared_item - 96;    
            }
        }
    }
    else {
        std::cout << "Failed to load file\n";
    }
    return priority_sum;
}

int main() {
    int priority_sum{ day3() };
    int group_sum{ day3task2() };

    std::cout << "The priority sum is: " << priority_sum << "\n";
    std::cout << "The group sum is: " << group_sum << "\n";
    return 0;
}
// 7766