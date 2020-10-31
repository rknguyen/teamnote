const int maxn = 1e6 + 5, N = 1e6;
int p[maxn], x, test;
int phiEuler(int x) {
    if (p[x] == x) return x - 1;
    int res = 1;
    while (x != 1) {
        int y = p[x], re = 1;
        while (x % y == 0) {
            x /= y;
            re *= y;
        }
        re /= y;
        res = res*re*(y-1);
    }
    return res;
}
void prepare()
{
    for(int i=1; i<=N; ++i) p[i] = i;
    for(int i=1; i<=N; ++i) if (1LL*i*i > N) break;
    else if (p[i] == i) {
        for(int j=i; j<=N/i; ++j) p[i*j] = i;
    }
}
