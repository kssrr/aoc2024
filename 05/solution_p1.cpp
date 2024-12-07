#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

bool safe(const std::unordered_map<int, std::vector<int>>& map, const std::vector<int>& update) {
    for (const auto& [key, values] : map) {
        auto keyp = std::find(update.begin(), update.end(), key);

        if (keyp != update.end()) {
            for (int value : values) {
                auto valuep = std::find(update.begin(), update.end(), value);
                if (valuep != update.end() && valuep < keyp) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char** argv) {
    (void)argc;

    std::ifstream infile(argv[1]);

    // reading inputs from file:
    std::vector<std::tuple<int, int>> tuples;
    std::vector<std::vector<int>> updates;
    std::string line;
    bool pairs = true;
    while (std::getline(infile, line)) {
        if (line.empty()) {
            pairs = false;
            continue;
        }

        if (pairs) {
            std::istringstream iss(line);
            std::string first, second;
    
            if (std::getline(iss, first, '|') && std::getline(iss, second))
                tuples.emplace_back(std::stoi(first), std::stoi(second));

        } else {
            std::istringstream cstream(line);
            std::vector<int> update;
            std::string num;
            while (std::getline(cstream, num, ',')) {
                update.push_back(std::stoi(num));
            }
            updates.push_back(update);
        }
    }

    // making lookup of rules:
    std::unordered_map<int, std::vector<int>> rules;
    for (const std::tuple<int, int>& tup : tuples) {
        rules[std::get<0>(tup)].push_back(std::get<1>(tup));
    }

    int sum = 0;
    for (const auto& update : updates) {
        if (safe(rules, update)) {
            sum += update[update.size() / 2];
        }
    }
    std::cout << sum << '\n';

    infile.close();
    return 0;
}
