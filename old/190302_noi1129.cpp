#include <iostream>
using namespace std;

int n, m, cell[101][101], idx[101][101];
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

void dfs(int r, int c, int id) {
  if (r < 0 || r >= n || c < 0 || c >= m) {
    return;
  }
  if (idx[r][c] > 0 || cell[r][c] == 0) {
    return;
  }
  idx[r][c] = id;
  for (int i = 0; i < 4; ++i) {
    dfs(r + dr[i], c + dc[i], id);
  }
}

int main() {
  cin >> n >> m;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < m; ++j) {
      cell[i][j] = str[j] - 48;
      idx[i][j] = 0;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (cell[i][j] > 0 && idx[i][j] == 0) {
        dfs(i, j, ++cnt);
      }
    }
  }
  cout << cnt << endl;
  return 0;
}