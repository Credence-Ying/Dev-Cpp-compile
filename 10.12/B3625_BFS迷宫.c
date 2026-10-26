#include <stdio.h>
#include <stdbool.h>

int n, m;
char map[505][505];          // 地图：'#'墙 '.'路
bool vis[505][505];          // true = 这个格子"排过队了"
int qx[255025], qy[255025];  // 队列！不用struct，两个数组分别存x和y
int head = 0, tail = 0;      // head=队首，tail=队尾下一个空位

int dx[4] = {-1, 1, 0, 0};   // 上下左右对应的x变化
int dy[4] = {0, 0, -1, 1};   // 上下左右对应的y变化

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", map[i] + 1);       // 从map[i][1]开始存，下标和题目一致

    // ① 起点先排队，并立刻打标记
    qx[tail] = 1; qy[tail] = 1; tail++;
    vis[1][1] = true;

    while (head < tail) {              // ② head追上tail = 队伍空了
        int x = qx[head];              // 取队首
        int y = qy[head];
        head++;                        // 出队：队首指针后移一位

        if (x == n && y == m) {        // 取出来的正好是终点！
            printf("Yes");
            return 0;
        }

        for (int i = 0; i < 4; i++) {  // ③ 四个邻居挨个看
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m   // 在地图内
                && map[nx][ny] == '.'                      // 不是墙
                && !vis[nx][ny]) {                         // 没排过队
                vis[nx][ny] = true;    // 【立刻标记】
                qx[tail] = nx;         // 排到队尾
                qy[tail] = ny;
                tail++;
            }
        }
    }

    printf("No");                      // 队伍空了也没见到终点
    return 0;
}
