#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function forward declaration
int processCharsUntilUniqueLength(std::ifstream &my_file, std::string &input_string, const int unique_sequence_length);
std::pair<int, int> processChars(std::ifstream &my_file);
std::pair<int, int> day6(const std::string input_file_path);

int main() {
    const std::string input_file_path{"../input_day6.txt"};
    std::pair<int, int> day6_answers = day6(input_file_path);

    std::cout << "Task 1: " << day6_answers.first << " characters processed until 4 unqiue in a row\n";
    std::cout << "Task 2: " << day6_answers.second << " characters processed until 14 unqiue in a row\n";

    return 0;
}

// Function defintion
int processCharsUntilUniqueLength(std::ifstream &my_file, std::string &input_string, const int unique_sequence_length) {
    char input_char;
    int unique_stop_count = (unique_sequence_length*unique_sequence_length - unique_sequence_length)/2; // (n^2 - n)/2 unique are needed

    int count_unique{ 0 };
    int first_index;
    int second_index;
    while(count_unique != unique_stop_count && my_file.good()) { // We stop when we can count the above uniques, which imply all chars in sequence are unique
        count_unique = 0;
        my_file >> input_char;
        input_string.push_back(input_char);

        for (int i = 0; i < unique_sequence_length - 1; ++i) {
            first_index = input_string.length() - 1 - i;
            for (int j = 1 + i; j < unique_sequence_length; ++j) {
                second_index = input_string.length() - 1 - j;
                if (input_string[first_index] != input_string[second_index]) { // Each time there is no duplicate, increment uniques
                    ++count_unique;
                }
            }
        }
    }
    return input_string.length();
}

std::pair<int, int> processChars(std::ifstream &my_file) {
    std::pair<int, int> chars_processed{};
    std::string input_string;

    int unique_sequence_length_task1{ 4 };
    int unique_sequence_length_task2{ 14 };

    char input_char;
    for (int i = 0; i < unique_sequence_length_task1 - 1; ++i) { // Read in first 3 characters before starting
        my_file >> input_char;
        input_string.push_back(input_char);
    }

    chars_processed.first = processCharsUntilUniqueLength(my_file, input_string, unique_sequence_length_task1);
    chars_processed.second = processCharsUntilUniqueLength(my_file, input_string, unique_sequence_length_task2);

    return std::move(chars_processed);
}

std::pair<int, int> day6(const std::string input_file_path) {
    std::pair<int, int> chars_processed;
    std::ifstream my_file(input_file_path);

    if (my_file.is_open()) {
        std::cout << "File Opened\n";
        chars_processed = processChars(my_file);
    } else {
        std::cout << "Failed to open file\n"; 
    }

    return chars_processed;
}
