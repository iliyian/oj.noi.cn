#include <cstdio>
#include <cstring>

int main() {
    char s[105];
    scanf("%s", &s);
    int slen = strlen(s);
    int ans = 1;
    for (int i = 0; i < slen; i++) {
        ans = ans * (s[i] - 'a' + 1) % 10007;
    }
    printf("%d", ans);
    return 0;
}