#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 505;
const int INF = 1 << 30;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int s[maxn][maxn], vis[maxn][maxn], d[maxn][maxn];
int n, m, r2, c2;

int danger(int r, int c) {
    int d = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '+') {
                d = std::min(d, abs(i-r)+abs(j-c));
            }
        }
    }
    return d;
}

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return INF;
    d[r][c] = std::max(d[r][c], danger(r, c));
    if (vis[r][c]) return d[r][c];
    if (r == r2 && c == c2) return d[r][c];
    for (int i = 0; i < 4; i++) {
        int r1 = r+dr[i], c1 = c+dc[i];
        vis[r1][c1] = 1;
        d[r][c] = std::min(d[r][c], dfs(r1, c1));
        vis[r1][c1] = 0;
    }
    return d[r][c];
}

int main() {
    memset(vis, 0, sizeof(vis));
    memset(d, -1, sizeof(d));
    int ch, r0, c0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            ch = getchar(), s[i][j] = ch;
            if (ch == 'V') r0 = i, c0 = j;
            else if (ch == 'J') r2 = i, c2 = j;
        }
    }
    int ans = dfs(r0, c0);
    printf("%d", ans);
    return 0;
}