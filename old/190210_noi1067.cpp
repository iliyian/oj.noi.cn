#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int m, n, r, s;
    cin >> m >> n;
    vector<vector<int>> A, B;
    A.resize(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            A[i].push_back(x);
        }
    }

    cin >> r >> s;
    B.resize(r);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            int x;
            cin >> x;
            B[i].push_back(x);
        }
    }

    int min = 2100000000, minx, miny;
    for (int i = 0; i < m - r + 1; ++i) {
        for (int j = 0; j < n - s + 1; ++j) {
            int sum = 0;
            for (int a = 0; a < r; ++a) {
                for (int b = 0; b < s; ++b) {
                    sum += abs(A[i + a][j + b] - B[a][b]);
                }
            }
            if (sum < min) {
                min = sum;
                minx = i;
                miny = j;
            }
        }
    }

    for (int i = minx; i < minx + r; ++i) {
        for (int j = miny; j < miny + s; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}