#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int **s = new int *[n];
    for (int i = 0; i < n; ++i) {
        s[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
        }
    }
    int q, x, y;
    cin >> q;
    char ch;
    while (q--) {
        cin >> ch >> x >> y;
        if (ch == 'Q') {
            cout << s[x - 1][y - 1] << endl;
        } else {
            int *t = s[x - 1];
            s[x - 1] = s[y - 1];
            s[y - 1] = t;
        }
    }
    return 0;
}