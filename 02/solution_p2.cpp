#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_safe(const std::vector<int> &v) {
    bool inc = true, dec = true;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        int curr = v[i], succ = v[i + 1];

        if ((curr == succ) || (std::abs(curr - succ) > 3))
            return false;
        if (curr > succ)
            dec = false;
        if (curr < succ)
            inc = false;
        if (!inc && !dec)
            return false;
    }

    return inc || dec;
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