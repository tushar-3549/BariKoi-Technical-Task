#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int vis[10001], in[10001], low[10001];
set<int> ans;
int timer;

void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int cnt = 0;
    for (int child : v[node])
    {
        if (child == par) continue;
        if (vis[child] == 1)
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            cnt++;
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && par != -1)
            {
                ans.insert(node);
            }
        }
    }
    if (par == -1 && cnt > 1) ans.insert(node);
}

int main()
{
    int n, e, x, y;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        vis[i] = 0;
    }
    timer = 1;
    ans.clear();
    while (e--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, -1);
        }
    }
    // Num of critical nodes
    cout << ans.size() << endl;

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
