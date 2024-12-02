#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_safe(const std::vector<int> &v) {
    bool inc = true, dec = true;
    for (size_t i = 1; i < v.size(); ++i) {
        int diff = v[i] - v[i - 1];
        if (std::abs(diff) > 3 || diff == 0)
            return false;
        inc &= diff > 0;
        dec &= diff < 0;
        if (!inc && !dec) 
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    (void)argc;

    std::string line;
    int safe = 0;
    std::ifstream infile(argv[1]);

    while (std::getline(infile, line)) {
        std::istringstream instream(line);
        std::vector<int> v;
        int x;

        while (instream >> x)
            v.push_back(x);

        if (is_safe(v))
            ++safe;
    }
    infile.close();

    std::cout << safe << " safe\n";

    return EXIT_SUCCESS;
}