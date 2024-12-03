#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using std::vector;
using std::string;

const std::regex MUL_FORMAT("mul\\(\\d+,\\d+\\)");

vector<string> find_instructions(const string &inp) {
    vector<string> matches;
    auto begin = std::sregex_iterator(inp.begin(), inp.end(), MUL_FORMAT);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        matches.push_back(it->str());
    }
    return matches;
}

int exec(const vector<string> &instructs) {
    int sum = 0;
    const std::regex NUMS("\\d+");

    for (const auto &inst : instructs) {
        vector<int> numbers;
        auto begin = std::sregex_iterator(inst.begin(), inst.end(), NUMS);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            numbers.push_back(std::stoi(it->str()));
        }

        if (numbers.size() == 2) {
            sum += numbers[0] * numbers[1];
        } 
    }

    return sum;
}

int main(int argc, char **argv) {
    (void)argc;

    std::ifstream infile(argv[1]);
    std::ostringstream buffer;
    buffer << infile.rdbuf();

    const string input = buffer.str();
    vector<string> instructions = find_instructions(input);

    std::cout << exec(instructions) << '\n';

    return EXIT_SUCCESS;
}