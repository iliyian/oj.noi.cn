#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define maxn 10009
#define wc 3

double toNumber(char* s, int x, int y) {
    int v[maxn], b = 0;
    double res = 0.0;
    memset(v, 0, sizeof(v));
    for (int i = x; i < y; i++) {
        if (s[i] == '.') v[i] = '.';
        else if (!isdigit(s[i])) return 0.0;
        else v[i] = s[i] - '0';
    }
    for (int i = x; i < y; i++) {
        if (s[i] == '.') b = 1;
        else {
            if (b) res += pow(0.1, b++) * v[i];
            else res = res * 10.0 + v[i];
        }
    }
    return res;
}

int w(char c) {
    switch (c) {
        case '+': case '-': return 0;
        case '*': case '/': return 1;
        case '^': return 2;
    }
    return -1;
}

double count(char* s, int x, int y) {
    // int c1 = -1, c2 = -1, c3 = -1;
    int p = 0;
    int c[wc];
    memset(c, -1, sizeof(c));
    double n = toNumber(s, x, y);
    if (n) return n;
    for (int i = x; i < y; i++) {
        int t;
        switch (s[i]) {
            case '(': p++; break;
            case ')': p--; break;/* 
            case '+': case '-': if (!p) c1 = i; break;
            case '*': case '/': if (!p) c2 = i; break;
            case '^': if (!p) c3 = i; break; */
            default: t = w(s[i]); if (!p && t >= 0) c[t] = i;
        }
    }
/*     if (c1 < 0) c1 = c2;
    if (c1 < 0) c1 = c3;
    if (c1 < 0) return count(s, x + 1, y - 1); */
    int i;
    for (i = 0; i < wc; i++) if (c[i] >= 0) break;
    if (c[i] < 0) return count(s, x + 1, y - 1);
    double a = count(s, x, c[i]);
    double b = count(s, c[i] + 1, y);
    switch (s[c[i]]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

int main() {
    char line[maxn];
    scanf("%s", &line);
    double ans = count(line, 0, strlen(line));
    printf("%.10f", ans);
    return 0;
}