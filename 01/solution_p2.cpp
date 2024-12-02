
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

    int n_A = A.size(), n_B = B.size(), res;
    for (int i = 0; i < n_A; ++i) {
        int counter = 0;
        int num = A[i];
        for (int j = 0; j < n_B; ++j) {
            if (num == B[j]) {
                counter += 1;
            }
        }
        res += (num * counter);
    }

    std::cout << res << '\n';
}