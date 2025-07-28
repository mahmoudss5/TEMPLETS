// #define pii pair<int, int>
// #define F first
// #define S second

vector<int> ans(N, -1);
priority_queue<pii, vector<pii>, greater<pii>> s;

void dijkstra(int i){
    s.push({0, i}); // {totalCost, node}
    while (!s.empty()){
        pii p = s.top(); s.pop();
        int node = p.S, nodecost = p.F;
        if(ans[node] != -1) continue;
        ans[node] = nodecost;
        for(pii edge: v[node]) if (ans[edge.F] == -1) {
            s.push({nodecost + edge.S, edge.F});
        }
    }
}
