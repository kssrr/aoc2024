#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using std::vector;
using std::string;

const std::regex MUL_FORMAT("mul\\(\\d+,\\d+\\)");

vector<string> find_matches(const string &inp) {
    vector<string> matches;
    auto begin = std::sregex_iterator(inp.begin(), inp.end(), MUL_FORMAT);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        matches.push_back(it->str());
    }
    return matches;
}

vector<int> get_products(const vector<string> &matches) {
    vector<int> products;
    const std::regex NUMS("\\d+");

    for (const auto &match : matches) {
        vector<int> numbers;
        auto begin = std::sregex_iterator(match.begin(), match.end(), NUMS);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            numbers.push_back(std::stoi(it->str()));
        }

        if (numbers.size() == 2) {
            int prod = numbers[0] * numbers[1];
            products.push_back(prod);
        } 
    }
    
    return products;
}

int sum(const vector<int> &vec) {
    int s = 0;
    for (const int &x : vec) {
        s += x;
    }
    return s;
}

int main(int argc, char **argv) {
    (void)argc;

    std::ifstream infile(argv[1]);
    std::ostringstream buffer;
    buffer << infile.rdbuf();

    const string input = buffer.str();
    vector<string> matches = find_matches(input);
    vector<int> products = get_products(matches);

    std::cout << sum(products) << '\n';

    return EXIT_SUCCESS;
}