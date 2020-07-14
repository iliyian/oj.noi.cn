#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 505;
const int INF = 1 << 30;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int vis[maxn][maxn], d[maxn][maxn], s[maxn][maxn];
int n, m, r2, c2;

int danger(int r, int c) {
    int d = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '+')
                d = std::min(d, abs(i-r)+abs(j-c));
    return d;
}

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 0;
    int dg = 0;
    vis[r][c] = 1;
    d[r][c] = danger(r, c);
    for (int i = 0; i < 4; i++) {
        int r1 = r+dr[i], c1 = c+dc[i];
        if (vis[r1][c1]) continue;
        dg = std::max(dg, dfs(r1, c1));   //不同路径要选择最安全的
    }
    vis[r][c] = 0;
    d[r][c] = std::min(d[r][c], dg);      //同一路径最不安全的地方代表整体
    return d[r][c];
}

int main() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
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