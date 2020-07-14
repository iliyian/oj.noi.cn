#include <cstdio>
#include <cstdlib>
#include <ctime>
const int maxr = 1005;
const int maxn = 100;

int main() {
    srand(time(NULL));
    int r = rand() % maxr;
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", rand() % maxn);
        }
        printf("\n");
    }
    return 0;
}