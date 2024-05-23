#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int main()
{
    int n, e;
    cin >> n >> e;
    vector <pair<int, int>> g[n+1]; 
    vector<int> dist(n + 1, inf);
    vector <int> vis(n + 1, 0);
    while(e--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y,w});
    }
    int source;
    cin >> source;
    dist[source] = 0;

    set <pair<int,int>> st;
    st.insert({0, source});

    while(!st.empty())
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto child: g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if(v_dist + wt < dist[child_v])
            {
                dist[child_v] = v_dist + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance from " << source << " to " << i << " is ";
        if (dist[i] == inf)
          cout << "INF" << endl;
        else
          cout << dist[i] << endl;
    }

    return 0;
}
