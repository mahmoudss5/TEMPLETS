


  while (!pq.empty()) {
          auto x = pq.top();
          pq.pop();
          int node = x.second;
          ll cost = x.first;
          if (vis[node]) continue;
          vis[node] = true;
          depth[node] = cost;
          for (auto [a, b]: adj[node]) {
              if (!vis[a]) {
                  pq.push({cost+b, a});
              }
          }
      }