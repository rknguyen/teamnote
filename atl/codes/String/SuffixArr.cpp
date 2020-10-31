vector<int> SuffArr(string s)
{
      s += '$';
      int n = s.size();
      vector<int> c(n), p(n);
      {
            vector<pair<int, int > > a(n);
            for(int i=0; i<n; ++i) a[i] = make_pair(s[i], i);
            sort(a.begin(), a.end());
            c[a[0].second] = 0;
            for(int i=1; i<n; ++i)
                  c[a[i].second] = c[a[i-1].second] + (a[i].first != a[i-1].first);
      }
      for(int k = 0; (1 << k) < n; ++k){
            vector<pair<pair<int, int>, int> > a(n);
            for(int i=0; i<n; ++i) {
                  a[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) % n]), i);
            }
            sort(a.begin(), a.end());
            c[a[0].second] = 0;
            for(int i=1; i<n; ++i)
                  c[a[i].second] = c[a[i-1].second] + (a[i].first != a[i-1].first);
            for(int i=0; i<n; ++i) p[i] = a[i].second;
      }
      return p;
}
