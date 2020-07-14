#include <iostream>
using namespace std;

int n, m, **s, **idx, cnt;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y, int id) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    } else if (s[x][y] == 0 || idx[x][y] > 0) {
        return;
    }
    idx[x][y] = id;
    for (int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i], id);
    }
}

int main() {
    cin >> n >> m;
    s = new int *[n], idx = new int *[n];
    for (int i = 0; i < n; ++i) {
        s[i] = new int[m];
        idx[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
            idx[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] && !idx[i][j]) {
                dfs(i, j, ++cnt);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}