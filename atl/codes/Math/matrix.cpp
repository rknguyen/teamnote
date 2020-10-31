struct Matrix {
    vector< vector<long long> > x;
    int m, n;
    Matrix(int m = 0, int n = 0) : m(m), n(n) {
        x.resize(m);
        for(int i=0; i<m; ++i){
            x[i].resize(n);
            for(int j=0; j<n; ++j) x[i][j] = 0;
        }
    }
    void print() {
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) cout << x[i][j] << ' ';
            cout << endl;
        }
    }
};
Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c(a.m, b.n);
    for(int i=0; i<c.m; ++i) 
        for(int j=0; j<c.n; ++j) {
        for(int k=0; k<a.n; ++k)
            c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
    }
    return c;
}
Matrix identity(int n) {
    Matrix res(n, n);
    for(int i=0; i<n; ++i) res.x[i][i] = 1;
    return res;
}

