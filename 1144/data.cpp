#include <cstdio>
#include <cstdlib>
#include <ctime>
const int maxn = 1000000;
const int maxai = 1000;

int main() {
    srand(time(NULL));
    int n = rand() * rand() % maxn;
    printf("%d\n", n);
    while (n--) {
        printf("%d ", rand() % maxai);
    }
    return 0;
}