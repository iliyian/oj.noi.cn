#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int **mat = new int *[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            if (i > 0) {
                mat[i][j] += mat[i - 1][j];
            }
            if (j > 0) {
                mat[i][j] += mat[i][j - 1];
            }
            if (i > 0 && j > 0) {
                mat[i][j] -= mat[i - 1][j - 1];
            }
        }
    }

    int q, a, b, c, d;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d;
        int sum = mat[c - 1][d - 1];
        if (a >= 2 && b >= 2) {//a, b不在边或角上
            sum += mat[a - 2][b - 2];
            sum -= mat[c - 1][b - 2];
            sum -= mat[a - 2][d - 1];
        } else {
            if (a >= 2 && b < 2) {//a没在边上，但是b在边上
                sum -= mat[c - 2][d - 1];
            } else if (a < 2 && b >= 2) {//a在边上， b没在边上
                sum -= mat[c - 1][b - 2];
            }
        }
        cout << sum << endl;
    }
    return 0;
}