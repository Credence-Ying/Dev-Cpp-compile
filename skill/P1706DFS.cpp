#include <iostream>
#include <cstdio>    // 用 printf 输出更方便控制格式
using namespace std;

const int MAXN = 15;   // n 最大是 9，开 15 足够了

int a[MAXN];           // 存当前排列，a[i] 表示第 i 位放的是哪个数
bool vis[MAXN];        // 标记数组：vis[x] = true 表示数字 x 已经被用过了
int n;                 // 总共有几个数（全局变量，方便 dfs 里直接用）

// dfs：当前正在填第 pos 个位置
void dfs(int pos) {
    // ---------- 终止条件：所有位置都填完了 ----------
    if (pos > n) {                  // 如果位置已经填到 n+1 了，说明 n 个位置都填满了
        for (int i = 1; i <= n; i++) {
            printf("%5d", a[i]);    // 每个数字占 5 个字符宽度（题目要求）
        }
        printf("\n");               // 换行
        return;                     // 返回 = 回溯，回到上一层换一个数试试
    }
    
    // ---------- 枚举：这个位置可以放哪个数 ----------
    for (int i = 1; i <= n; i++) {  // 从 1 到 n 一个个试
        if (!vis[i]) {              // 如果数字 i 还没被用过
            // ① 选它
            vis[i] = true;          // 标记：i 被用掉了
            a[pos] = i;             // 第 pos 个位置放 i
            
            // ② 往下一层走（填下一个位置）
            dfs(pos + 1);           // 递归，去填 pos+1 的位置
            
            // ③ 回溯：换一个数之前，要把刚才的标记撤掉
            vis[i] = false;         // 恢复：i 又可以用了
            // a[pos] 不用特意恢复，下次循环会被新的值覆盖掉
        }
    }
}

int main() {
    cin >> n;
    
    dfs(1);   // 从第 1 个位置开始填
    
    return 0;
}