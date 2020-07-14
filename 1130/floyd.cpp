#include <cstdio>
#include <vector>
#include <algorithm>
const int INF = 3005;
//感觉改一下似乎可以

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    std::vector<int> G[n+1], L[n+1][n+1], d[n+1];
    for (int i = 1; i <= n; i++) {G[i].assign(n+1, 0); d[i].assign(n+1, INF);}
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            L[i][j].assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
        d[a][b] = d[b][a] = 1;
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        L[a][b][c] = INF;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++)
                if (!L[i][k][j])
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%4d ", d[i][j]);
        printf("\n");
    }
    printf("%d", d[1][n]);
    return 0;
}