 vector<int> in(n), out(n);
     int timer = 1;
 
     function<void(int, int)> dfs = [&](int u, int p) {
         in[u] = timer++;
         for (int v : adj[u]) {
             if (v != p) dfs(v, u);
         }
         out[u] = timer - 1;
     };
 
