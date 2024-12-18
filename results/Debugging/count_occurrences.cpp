#include <iostream>
#include <fstream>
#include <string>
#include <regex>

//Compile with
//g++ -o count_occurrences count_occurrences.cpp
//run with
//./count_occurrences word

int main(int argc, char* argv[]) {
    // Check if the user provided a word to search for
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <SearchWord>" << std::endl;
        return 1;
    }

    // Get the search word from the command line
    std::string search_word = argv[1];

    // Open the file
    std::ifstream infile("multithread_errors.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open the file!" << std::endl;
        return 1;
    }

    // Create a regex pattern to match the whole word
    std::regex word_pattern("\\b" + search_word + "\\b");
    int word_count = 0;

    // Read the file line by line
    std::string line;
    while (std::getline(infile, line)) {
        // Use regex to search for the word in the current line
        std::sregex_iterator it(line.begin(), line.end(), word_pattern);
        std::sregex_iterator end;

        // Count all matches in this line
        word_count += std::distance(it, end);
    }

    infile.close();

    // Output the result
    std::cout << "Number of occurrences of '" << search_word << "': " << word_count << std::endl;

    return 0;
}

