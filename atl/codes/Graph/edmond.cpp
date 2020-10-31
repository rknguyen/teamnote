struct Edge {
    int u, v, cap, flow;
};
const int N = 1007;
vector <Edge> E;
vector <int> adj[N];
int n, m, s, t, trace[N];
void addEdge(int u, int v, int cap) {
    E.push_back(Edge({ v, u, 0, 0 }));
    E.push_back(Edge({ u, v, cap, 0 }));
    adj[u].push_back(E.size() - 1);
    adj[v].push_back(E.size() - 2);
}
int Edmonds_Karp(int s, int t) {
    fill(trace, trace + n, 0);
    int maxFlow = 0;
    do {
        fill(trace, trace + n + 1, 0);
        queue <int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int eid : adj[u]) {
                Edge ed = E[eid];
                int v = ed.v, c = ed.cap, f = ed.flow;
                if (!trace[v] && v != f && c > f) {
                    trace[v] = eid + 1;
                    q.push(v);
                }
            }
        }
        if (trace[t]) {
            int v = t, delta = (int) 1e9 + 7;
            while (v != s) {
                int eid = trace[v] - 1;
                delta = min(delta, E[eid].cap - E[eid].flow);
                v = E[eid].u;
            }
            v = t;
            while (v != s) {
                int eid = trace[v] - 1;
                E[eid].flow += delta;
                E[eid - 1].flow -= delta;
                v = E[eid].u;
            }
            maxFlow += delta;
        }
    }
    while(trace[t]);
    return maxFlow;
}
