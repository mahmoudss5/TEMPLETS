struct TarjanSCC {
    bool directed;
    int n, timer, sccCount;
    vector<int> in, low, sccId;
    vector<bool> inStack, isArticulation;
    stack<int> st;
    vector<pair<int, int>> bridges;
    vector<vector<int>> graph, sccs, dag;

    explicit TarjanSCC(int n, bool directed = false) : directed(directed), n(n), timer(0), sccCount(0) {
        graph.resize(n);
        in = low = sccId = vector(n, -1);
        inStack = isArticulation = vector(n, false);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        if(!directed) graph[v].push_back(u);
    }

    void dfs(int u, int parent = -1) {
        in[u] = low[u] = ++timer;
        st.push(u), inStack[u] = true;

        int children = 0;
        for (int v : graph[u]) if(directed || v != parent) {
            if (in[v] == -1) {
                children++;
                dfs(v, u);

                if(low[v] > in[u]) bridges.emplace_back(u, v);
                if(parent != -1 && low[v] >= in[u]) isArticulation[u] = true;
                low[u] = min(low[u], low[v]);
            }
            else if(inStack[v])
                low[u] = min(low[u], in[v]);
        }
        if(parent == -1 && children > 1) isArticulation[u] = true;

        if (low[u] == in[u]) {
            sccs.emplace_back();
            int v;
            do {
                v = st.top(), st.pop(), inStack[v] = false;
                sccId[v] = sccCount;
                sccs.back().push_back(v);
            } while (v != u);
            ++sccCount;
        }
    }

    void init() { for(int i = 0; i < n; ++i) if(in[i] == -1) dfs(i); }

    void buildDAG() {
        dag.assign(sccCount, {});
        set<pair<int, int>> edgeSet;

        for (int u = 0, su, sv; u < n; ++u) {
            su = sccId[u];
            for(int v : graph[u]) {
                sv = sccId[v];
                if(su != sv && edgeSet.insert({su, sv}).second)
                    dag[su].push_back(sv);
            }
        }
    }
};
