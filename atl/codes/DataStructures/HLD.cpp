void hld(int u)
{
    if (ChainHead[nChain] == 0) ChainHead[nChain] = u;
    Chain[u] = nChain;
    pos[u] = ++nPos;
    sop[nPos] = u;
 
    int nxt = -1;
    for(auto v: a[u]) if (v != par[u]){
        if (nChild[v] > nChild[nxt] || nxt == -1) nxt = v;
    }
    if (nxt != -1) hld(nxt);
    for(auto v: a[u]){
        if (v != nxt && v != par[u]) {
            ++nChain;
            hld(v);
        }
    }
}
