#include <cstdio>
#include <vector>
#include <iostream>
#define LOCA
const int maxn = 15;
//qq 1715428260

int lch[maxn], rch[maxn], op[maxn], cnt = 0;

int build_tree(std::vector<char>& v, int x, int y) {
    int t = cnt++;
    if (x+1 == y) {
        lch[t] = rch[t] = 0;
        return v[x];
    }
    char root = v[x];
    op[t] = root;
    int nc = 0, cc = 0, i;
#ifdef LOCAL
    printf("X: %d, Y: %d\n", x, y);
#endif
    for (i = x + 1;; i++) {
        if (v[i] == '-' || v[i] == '+') cc++;
        else nc++;
#ifdef LOCAL
        printf("T: %d, i: %d, nc: %d, cc: %d.\n", t,  i, nc, cc);
#endif
        if (nc == cc + 1) break;
    }
    lch[t] = build_tree(v, x+1, i+1);
    rch[t] = build_tree(v, i+1, y);
    return t;
}

void postSearch(int u) {
    if (u >= 48) {
        printf("%c ", (char)u);
    } else {
        postSearch(lch[u]);
        postSearch(rch[u]);
        printf("%c ", (char)op[u]);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    char c;
    std::vector<char> v;
    while (std::cin >> c) {
        v.push_back(c);
    }
    build_tree(v, 0, v.size());
#ifdef LOCAL
    printf("op: \n");
    for (int i = 0; i < maxn; i++) printf("%c ", op[i]);
    printf("\nlch: \n");
    for (int i = 0; i < maxn; i++) printf("%d ", lch[i]);
    printf("\nrch: \n");
    for (int i = 0; i < maxn; i++) printf("%d ", rch[i]);
#endif
    postSearch(0);
    return 0;
}