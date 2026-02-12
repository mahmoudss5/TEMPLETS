
// define the struct as a global var or mark it as a  static  in your solve function .....
struct Sack {
    static const int MAXN = 100005;
    vector<int> adj[MAXN];
    int col[MAXN];
    int sz[MAXN];
    int big[MAXN];
    int freq[MAXN], mx = 0;
    ll sum[MAXN], ans[MAXN];

    void get_sz(int u, int p) {
        sz[u] = 1;
        big[u] = -1;
        int max_sz = -1;

        for (int v: adj[u]) {
            if (v != p) {
                get_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > max_sz) {
                    max_sz = sz[v];
                    big[u] = v;
                }
            }
        }
    }

    void add(int u, int p, int x, int skipped_child) {
        if (freq[col[u]] > 0) {
            sum[freq[col[u]]] -= col[u];
        }
        freq[col[u]] += x;
        if (freq[col[u]] > 0)sum[freq[col[u]]] += col[u];

        if (x == 1)mx = max(mx, freq[col[u]]);
        for (int v: adj[u]) {
            if (v != p && v != skipped_child) {
                add(v, u, x, skipped_child);
            }
        }

    }


    void dfs(int u, int p, bool keep) {
        for (int v: adj[u]) {
            if (v != p && v != big[u]) {
                dfs(v, u, false); // light children,will be removed
            }
        }

        if (big[u] != -1) {
            dfs(big[u], u, true); // heavy children,will be kept
        }

        add(u, p, 1, big[u]);

        ans[u] = sum[mx];

        if (keep == false) { // if the node not heavy,remove it from the ds
            add(u, p, -1, -1);
            mx = 0;
        }
    }
};
