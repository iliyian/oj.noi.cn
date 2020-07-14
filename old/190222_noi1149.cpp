#include <iostream>
using namespace std;

int n, tot = 0, **vis;

void search(int cur) {
  if (cur == n)
    ++tot;
  else
    for (int i = 0; i < n; ++i) {
      if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
        vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
        search(cur + 1);
        vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
      }
    }
}

int main() {
  cin >> n;
  vis = new int *[3];
  for (int i = 0; i < 3; ++i) {
    vis[i] = new int[10000];
    for (int j = 0; j < 10000; ++j) {
      vis[i][j] = 0;
    }
  }
  search(0);
  cout << tot << endl;
  return 0;
}