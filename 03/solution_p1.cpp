#include <iostream>
#include <regex>
#include <vector>

using std::vector;
using std::string;

const std::regex MUL_FORMAT("mul\\(\\d+,\\d+\\)");
const string input("xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))");

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
    int s;
    for (int x : vec) {
        s += x;
    }
    return s;
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<string> matches;

    auto begin = std::sregex_iterator(input.begin(), input.end(), MUL_FORMAT);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        matches.push_back(it->str());
    }

    std::cout << "Matches found:\n";

    for (const auto &match : matches) {
        std::cout << match << '\n';
    }

    std::cout << "Products:\n";
    vector<int> products = get_products(matches);
    for (int product : products) {
        std::cout << product << '\n';
    }

    std::cout << "Sum: " << sum(products) << '\n';

    return EXIT_SUCCESS;
}

