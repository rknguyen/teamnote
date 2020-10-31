//Trả về xâu xoay của s có thứ tự từ điển nhỏ nhất
string minmove(string s)
{
	int n=s.length();
	int x, y, i, j, u, v;
	for (x=0,y=1; y<n; y++)
  {
		i=u=x;
		j=v=y;
		while (s[i]==s[j])
    {
			u++, v++, i++, j++;
			if (i==n)
        i=0;
			if (j==n)
        j=0;
			if (i==x)
        break;
		}
		if (s[i]<=s[j])
      y=v;
		else
    {
			x=y;
			if (u>y)
        y=u;
		}
	}
  string ans="";
  for (int i=x;i<=n-1;i++)
    ans+=s[i];
  for (int i=0;i<x;i++)
    ans+=s[i];
  return ans;
}
