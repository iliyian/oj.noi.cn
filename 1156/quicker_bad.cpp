#include <cstdio>
#include <ctime>
#include <cstring>
#include <vector>
typedef vector<int> N(100);
const int maxn = 805;
const int BASE = 100000000;

inline int size(const N& n) {for (int i = 0;; i++) if (n[i] == 0) return i;}

void print(N& n) {
    printf("%d", n[size(n) - 1]);
    for (int i = size(n) - 2; i >= 0; i--) {
        printf("%08d", n[i]);
    }
}

void addTo(N& a, N& b, N& c) {
    int sa = size(a), sb = size(b), sc = size(c);
    int len = sa > sb ? sa : sb;
    for (int i = 0; i < len; i++) {
        int t = 0;
        if (i < sa) t += a[i];
        if (i < sb) t += b[i];
        c[i] += t;
    }
    for (int i = 0; i < sc - 1; i++) {
        c[i+1] += c[i] / BASE;
        c[i] %= BASE;
    }
    while (c[sc-1] >= BASE) {
        c[sc] = c[sc-1] / BASE;
        c[sc-2] %= BASE;
    }
}

int main() {
    int n, m;
    N s[maxn][maxn];
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        printf("%d", 1);
        return 0;
    }
    int r = n + m - 1, c = n;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            memset(s[i][j], 0, sizeof(s[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        s[i][i][0] = 1;
        s[i+1][i][0] = i+1;
    }
    for (int i = 0; i < m; i++) s[i][0][0] = 1;
    for (int j = 2; j < m; j++) {
        for (int i = 1; i < n; i++) {
            int x = i+j, y = i;
            addTo(s[x-1][y-1], s[x-1][y], s[x][y]);
        }
    }
    print(s[r-1][c-1]);
    printf("\nTime: %d.\n", clock());
    return 0;
}