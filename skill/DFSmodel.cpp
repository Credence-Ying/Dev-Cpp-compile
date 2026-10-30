#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1005;          // 最多多少个节点

vector<int> g[MAXN];            // 邻接表：g[u] 存的是 u 的所有邻居
bool vis[MAXN];                 // 标记数组：vis[u] = true 表示 u 已经访问过了

// dfs：从节点 u 出发，深度优先搜索
void dfs(int u) {
    // 第一步：访问当前节点
    vis[u] = true;              // 标记：u 已经来过了
    cout << u << " ";           // 输出一下（或者做你想做的事）
    
    // 第二步：遍历所有邻居
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];        // v 是 u 的一个邻居
        if (!vis[v]) {          // 如果 v 还没去过
            dfs(v);             // 就去 v 那里继续深搜（递归）
        }
    }
    
    // 第三步：函数结束 = 回溯（自动退回到上一层）
    // 这里不用写额外代码，函数 return 就是回溯了
}

int main() {
    int n, m;                   // n 个节点，m 条边
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);      // u 的邻居加个 v
        g[v].push_back(u);      // v 的邻居加个 u（无向图，双向都要加）
    }
    
    dfs(1);                     // 从节点 1 开始深搜
    
    return 0;
}