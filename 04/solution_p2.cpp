#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool has_xmas(const std::vector<std::vector<char>> &mat, size_t i, size_t j) {
    std::string main = {mat[i][j], mat[i+1][j+1], mat[i+2][j+2]};
    std::string sec = {mat[i][j+2], mat[i+1][j+1], mat[i+2][j]};

    return (main == "MAS" || main == "SAM") && (sec == "MAS" || sec == "SAM");
}

int main(int argc, char **argv) {
    (void)argc;

    vector<vector<char>> matrix;
    string line;
    std::ifstream infile(argv[1]);

    while (std::getline(infile, line)) {
       matrix.push_back(vector<char>(line.begin(), line.end()));
    }

    int occurences = 0;
    for (size_t i = 0; i < matrix.size() - 2; ++i) {
        for (size_t j = 0; j < matrix[i].size() - 2; ++j) {
            if (has_xmas(matrix, i, j)) {
                ++occurences;
            }
        }
    }

    std::cout << occurences << '\n';
}
