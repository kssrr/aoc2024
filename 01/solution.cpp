#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    (void)argc;

    std::ifstream infile(argv[1]);
    std::vector<int> A, B;
    int a, b;

    while (infile >> a >> b) {
        A.push_back(a);
        B.push_back(b);
    }
    infile.close();

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int n = A.size(), diff;
    for (int i = 0; i < n; ++i) {
        diff += std::abs(A[i] - B[i]);
    }

    std::cout << diff << '\n';
}