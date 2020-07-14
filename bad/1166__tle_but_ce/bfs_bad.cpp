#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
const int maxn = 505;
const int INF = 1 << 30;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int s[maxn][maxn], n, m;

struct D {
    int r, c, d;
    bool operator < (const D& x) {
        return d > x.d;                            //越大越安全
    }
};

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

int main() {
    int ch, r0, c0, r2, c2, ans = INF;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            ch = getchar(), s[i][j] = ch;
            if (ch == 'V') r0 = i, c0 = j;
            else if (ch == 'J') r2 = i, c2 = j;
        }
    }
    std::queue<D> q;
    q.push(D{r0, c0, danger(r0, c0)});
    while (!q.empty()) {
        D u = q.front(); q.pop();
        D a[4];
        for (int i = 0; i < 4; i++) {
            int r1 = u.r+dr[i], c1 = u.c+dc[i];
            if (r1 == r2 && c1 == c2) {         //家就在身边，立刻走去
                ans = std::min(ans, u.d);       //更新答案
                continue;                       //下一个
            } else {
                a[i] = D{r1, c1, danger(r1, c1)};
            }
        }
        std::sort(a, a+4);                      //按危险值排序，走最小的几个
        int m = a[0].d;
        for (int i = 0; i < 4; i++) {
            if (m == a[i].d) {
                q.push(a[i]);
            }
        }
    }
    printf("%d", ans);
    return 0;
}