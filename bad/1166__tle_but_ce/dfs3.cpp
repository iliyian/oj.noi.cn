#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 505;
const int INF = 100000;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int s[maxn][maxn], vis[maxn][maxn];
int n, m, ans = 0, r2, c2;

bool cmp(int& a, int& b) {
    if (a < 0) return false;
    if (b < 0) return true;
    return a / 10 > b / 10;
}
//the bigger, the safer, the better.
//no zeros.

int danger(int r, int c) {
    if (vis[r][c] || r < 0 || r >= n || c < 0 || c >= m) return -INF;
    int d = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '+')
                d = std::min(d, abs(i-r)+abs(j-c));
    return d;
}

/**
 * dg is the smallest dangerous value for this path from (r0, c0) to (r, c).
 * the smallest dg for a path stand for its standard dg.
 */
void dfs(int r, int c, int dg) {
    if (vis[r][c] || r < 0 || r >= n || c < 0 || c >= m) return;
    if (r == r2 && c == c2) {
        ans = std::max(ans, dg);
        return;
    }
    int a[4];
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int r1 = r+dr[i], c1 = c+dc[i];
        int ndg = danger(r1, c1);
        a[i] = ndg*10 + i;
    }
    std::sort(a, a+4, cmp);
    bool f = false;
    int& m = a[0];          //only the best should be chosen.
    if (dg <= m/10) f = true;   //dg is still useful.
    for (int i = 0; i < 4; i++) {
        // if (a[i] < 0) continue; //overload.
        if (a[i] / 10 == m / 10) {
            int r1 = r+dr[a[i] % 10], c1 = c+dc[a[i] % 10];
            dfs(r1, c1, f ? dg : (m / 10));
        }
    }
    vis[r][c] = 0;
}

int main() {
    memset(vis, 0, sizeof(vis));
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
    dfs(r0, c0, danger(r0, c0));
    printf("%d", ans);
    return 0;
}