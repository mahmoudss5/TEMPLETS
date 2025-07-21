int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1, 0), vis(n + 1, 0), low(n + 1, 1e9);
    map<int, map<int, int>> is_bridge;

    function<void(int, int)> dfs = [&](int u, int p) {
        vis[u] = 1;
        depth[u] = depth[p] + 1;
        low[u] = depth[u];
        for (auto v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], depth[v]);
                continue;
            }
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > depth[u]) {
                is_bridge[u][v] = 1;
                is_bridge[v][u] = 1;
            }
        }
    };
    dfs(1, 0);

    vector<int> id(n + 1, 0);
    int cur_id = 1;

    function<void(int, int)> dfs2 = [&](int u, int p) {
        id[u] = cur_id;
        for (auto v : adj[u]) {
            if (v == p || is_bridge[u][v]) continue;
            if (id[v] == 0) dfs2(v, u);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (id[i] == 0) {
            dfs2(i, 0);
            ++cur_id;
        }
    }

    vector<int> tree[cur_id];
    for (int u = 1; u <= n; ++u) {
        for (auto v : adj[u]) {
            if (id[u] != id[v]) {
                tree[id[u]].push_back(id[v]);
            }
        }
    }
