#include <cstdio>
#include <vector>
#include <ctime>
#define LOCA
typedef std::vector<int> V;
const int maxn = 805;
const int BASE = 100000000;

inline void print(const V& n) {
    printf("%d", n.back());
    int sn = n.size();
    for (int i = sn - 2; i >= 0; i--) {
        printf("%08d", n[i]);
    }
}

inline void addTo(const V& a, const V& b, V& c) {
#ifdef LOCAL
    printf("Before adding, a: "); print(a); printf(", b: "); print(b); printf(", c: "); print(c); printf(".\n");
#endif
    int sa = a.size(), sb = b.size();
    int len = sa > sb ? sa : sb;
    c.resize(len);
    for (int i = 0; i < len; i++) {
        int t = 0;
        if (i < sa) t += a[i];
        if (i < sb) t += b[i];
        c[i] += t;
    }
#ifdef LOCAL
    printf("\n\n");
    print(c);
    printf("\n\n");
#endif
    for (int i = 0; i < len - 1; i++) {
        c[i+1] += c[i] / BASE;
        c[i] %= BASE;
    }
    while (c.back() >= BASE) {
#ifdef LOCAL
        printf("%s, old size: %d, old back: %d\n", "pushed!!", c.size(), c.back());
#endif
        c.push_back(c.back() / BASE);
        c[c.size() - 2] %= BASE;
    }
#ifdef LOCAL
    printf("After adding, a: "); print(a); printf(", b: "); print(b); printf(", c: "); print(c); printf(".\n\n");
#endif
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        printf("%d", 1);
        return 0;
    }
    int r = n + m - 1, c = n;
    std::vector<V> s[r];
    for (int i = 0; i < r; i++) {
        s[i].resize(c);
        for (int j = 0; j < c; j++) {
            s[i][j].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        s[i][i][0] = 1;
        s[i+1][i][0] = i+1;
    }
    for (int i = 0; i < m; i++) s[i][0][0] = 1;
    /* for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", s[i][j][0]);
        printf("\n");
    } */
    for (int j = 2; j < m; j++) {
        for (int i = 1; i < n; i++) {
#ifdef LOCAL
            printf("x: %d, y: %d\n", x, y);
#endif
            addTo(s[i+j-1][i-1], s[i+j-1][i], s[i+j][i]);
        }
    }
    /* printf("\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", s[i][j][0]);
        printf("\n");
    } */
    // printf("After adding, i: %d, j: %d, s: ", i, j); print(s[i][j]); printf(".\n");
#ifdef LOCAL
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d ", s[i][j].size());
    printf("\n");
#endif
    print(s[r-1][c-1]);
    printf("\nTime: %d.\n", clock());
    return 0;
}