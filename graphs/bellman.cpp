int n, m;
vector<pair<int, pii>> adj;
ll mn = oo; 
ll dis[N];

int bellman() {
    for (int i = 0; i < n; i++) {
        for (auto j: adj){
            int from = j.F, to = j.S.F, w = j.S.S; //  S=second F= FIRST      j  is a pair
            if (dis[to] > dis[from] + w) {
                dis[to] = dis[from] + w;
                mn = min(mn, dis[to]);
                if (i == n - 1) return 1; // if in the last iteration we found a new shortest  path that mean there is a neg cycle 
            }
        }
    }
    return 0;
}
