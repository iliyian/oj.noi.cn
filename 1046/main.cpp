#include <cstdio>
#include <cstring>

int main() {
  int n, board[100][100];
  scanf("%d", &n);
  memset(board, 0, sizeof(board));
  
  // int walk[][] = {
  //   {1, 0},

  //   {-1, 1},

  //   {0, 1},

  //   {1, -1},
  //   {1, -1},
  //   {1, -1},

  //   {1, 0},

  //   {-1, 1},
  //   {-1, 1},
  //   {-1, 1}
  // }

  int x = -1, y = 1, cnt = 0; // 当前输入的x, y, 和数字
  int nextX = 1, nextY = 0; // 下一步正常走法
  int flag = -1; // 下一步正常走法的方向， 1 为右上， -1 为右下

  for (;;) {
    // 根据flag,解释出下一步正常的dx和dy
    if (flag == 1) nextX = -1, nextY = 1;
    if (flag == -1) nextX = 1, nextY = -1;

    // 直接修改即可，边界及其他检测在后面
    x += nextX, y += nextY;

    // x < 0, 撞到了上面，开始向左下方向走
    if (x < 0) x = 0, flag = -1;
    // y < 0, 撞到了左边，开始往右边走
    if (y < 0) y = 0, flag = 1;

    // 撞到下面，此时需要确认下一个x,y的位置
    // 根据右下原则，y+1; x=n-1与x=0类似，调整至边界
    // 此时需要判断是否处于角，为了避免复杂的判断，在
    // board对应格子为空时才尝试写入，否则向右下方向
    // 继续延伸
    if (x >= n) {
      y += 1, x = n-1, flag = 1;
      if (board[x][y] != 0) y++;
    }
    if (y >= n) {
      x += 1, y = n-1, flag = -1;
      if (board[x][y] != 0) x++;
    }

    board[x][y] = ++cnt;

    if (cnt == n*n) break;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}