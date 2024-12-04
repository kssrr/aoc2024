#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(int argc, char **argv) {
    (void)argc;

    vector<vector<char>> mat;
    string line;
    std::ifstream infile(argv[1]);

    while (std::getline(infile, line)) {
       mat.push_back(vector<char>(line.begin(), line.end()));
    }

    int occurences = 0;
    for (size_t i = 0; i < mat.size() - 2; ++i) {
        for (size_t j = 0; j < mat[i].size() - 2; ++j) {
            std::string main = {mat[i][j], mat[i+1][j+1], mat[i+2][j+2]};
            std::string sec = {mat[i][j+2], mat[i+1][j+1], mat[i+2][j]};
            if ((main == "MAS" || main == "SAM") && (sec == "MAS" || sec == "SAM")) {
                ++occurences;
            }
        }
    }

    std::cout << occurences << '\n';
}
