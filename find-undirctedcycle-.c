bool hasCycleDFS(int v, int parent) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, v))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}
