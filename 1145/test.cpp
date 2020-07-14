#include <cstdio>
#include <algorithm>
#include <vector>
const int maxn = 1005;
int r;
std::vector<int> s[maxn], d[maxn], vis[maxn];

int dp(int i, int j) {
    if (i >= r || j >= r) return 0;
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    d[i][j] = std::max(dp(i+1, j), dp(i+1, j+1)) + s[i][j];
    return d[i][j];
}

int main() {
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        s[i].assign(r, 0);
        d[i].assign(r, 0);
        vis[i].assign(r, 0);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    printf("%d", dp(0, 0));
    return 0;
}