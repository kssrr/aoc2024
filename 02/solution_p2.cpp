#include <cmath>
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

bool safe_with_caveats(std::vector<int> &v) {
    if (is_safe(v)) {
        return true;
    }

    /* Bruteforcing: try removing each element
    and see if that makes the vector safe:*/
    for (size_t i = 0; i < v.size(); ++i) {
        std::vector<int> modified = v;
        modified.erase(modified.begin() + i);

        if (is_safe(modified)) {
            return true;
        }
    }

    return false;
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

        if (safe_with_caveats(v))
            ++safe;
    }
    infile.close();

    std::cout << safe << '\n';

    return EXIT_SUCCESS;
}