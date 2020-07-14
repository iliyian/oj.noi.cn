#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
const int maxn = 3005;
//果然可以用二元组表示三元组

struct Dot {
    Dot(int a, int b, int c) {
        this->now = a;
        this->pre = b;
        this->d = c;
    }
    int now, pre, d = 0;
};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    std::queue<Dot> q;
    std::vector<int> G[n+1], L[n+1];
    for (int i = 1; i <= n; i++) {
        G[i].assign(n+1, 0);
        L[i].assign(n+1, 0);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 2;
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        L[a][b] = c;
    }
    q.push(Dot(1, 1, 0));
    int ans = maxn, cnt = 0;
    while (!q.empty()) {
        Dot u = q.front(); q.pop();
        // printf("Time %2d: now: %d, pre: %d, d: %d\n", ++cnt, u.now, u.pre, u.d);
        if (u.now == n) {
            ans = std::min(ans, u.d);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (G[u.now][i] && L[u.pre][u.now] != i) {
                G[u.now][i]--;
                G[i][u.now]--;
                q.push(Dot(i, u.now, u.d+1));
            }
        }
    }
    printf("%d", ans);
    return 0;
}