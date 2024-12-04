#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int count(const vector<char> &in, const string &seq) {
    int count = 0;
    auto it = in.begin();
    while (it != in.end()) {
        it = std::search(it, in.end(), seq.begin(), seq.end());
        if (it != in.end()) {
            ++count;
            ++it;
        }
    }
    return count;
}

vector<vector<char>> transpose(const vector<vector<char>> &mat) {
    vector<vector<char>> out(mat[0].size(), vector<char>(mat.size()));
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            out[i][j] = mat[j][i];
        }
    }
    return out;
}

vector<vector<char>> diagonals(const vector<vector<char>> &mat) {
    vector<vector<char>> diagonals;
    
    size_t rows = mat.size();
    size_t cols = mat[0].size();

    // primary diagonals
    for (int d = 1 - int(rows); d < int(cols); ++d) {
        vector<char> diag;
        for (size_t i = 0; i < rows; ++i) {
            int j = d + int(i);
            if (j >= 0 && j < int(cols)) {
                diag.push_back(mat[i][j]);
            }
        }
        diagonals.push_back(diag);
    }

    // secondary diagonals
    for (int d = 0; d < int(rows + cols - 1); ++d) {
        vector<char> diag;
        for (size_t i = 0; i < rows; ++i) {
            int j = d - int(i);
            if (j >= 0 && j < int(cols)) {
                diag.push_back(mat[i][j]);
            }
        }
        diagonals.push_back(diag);
    }

    return diagonals;
}

vector<vector<char>> flatten(const vector<vector<char>> &mat) {
    auto trans = transpose(mat);
    auto diags = diagonals(mat);
    vector<vector<char>> grid;
    for (const auto &row : mat) {
        grid.push_back(row);
    }
    for (const auto &row : trans) {
        grid.push_back(row);
    }
    for (const auto &row : diags) {
        grid.push_back(row);
    }
    return grid;
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
    vector<vector<char>> search_grid = flatten(matrix);
    for (const auto &row : search_grid) {
        occurences += count(row, "XMAS");
        occurences += count(row, "SAMX");
    }

    std::cout << occurences << '\n';
}
