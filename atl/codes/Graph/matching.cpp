const int N = 1007;
int X, Y, m, trace[N], matchX[N], matchY[N];
vector <int> adj[N];
int FindPath() {
    fill(trace, trace + N + 1, 0);
    queue <int> q;
    for (int u = 1; u <= X; ++u) {
        if (matchX[u] == 0)
            q.push(u);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!trace[v] && matchX[u] != v) {
                trace[v] = u;
                if (matchY[v] == 0) return v;
                q.push(matchY[v]);
            }
        }
    }
    return 0;
}
void Enlarge(int u) {
    while (1) {
        int prev = trace[u];
        int near = matchX[prev];
        matchX[prev] = u;
        matchY[u] = prev;
        u = near;
        if (u == 0) break;
    }
}
void Read() {
    scanf("%d %d %d", &X, &Y, &m);
    int u, v;
    while(m--){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
}
void Solve() {
    fill(matchX, matchX + 1 + X, 0);
    fill(matchY, matchY + 1 + Y, 0);
    int cnt = 0;
    for (int u = 1; u <= X; ++u) {
        for (int v : adj[u]) {
            if (matchY[v] == 0) {
                matchX[u] = v;
                matchY[v] = u;
                break;
            }
        }
    }
    while (1) {
        int fin = FindPath();
        if (fin) Enlarge(fin);
        if (fin == 0) break;
    }
    for (int u = 1; u <= X; ++u) {
        if (matchX[u] != 0) ++cnt;
    }
    printf("%d\n", cnt);
}


