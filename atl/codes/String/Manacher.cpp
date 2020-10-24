#include <bits/stdc++.h>
using namespace std;

int manacher(string s)
{
	int n=s.size()*2-1;
	vector <int> f=vector <int>(n, 0);
	string a=string(n, '.');
	for (int i=0;i<n;i+=2)
		a[i]=s[i/2];
	int l=0, r=-1, center, res=0, j=0;
	for (int i=0; i<n; i++)
  {
    if (i>r)
      j=1;
    else
      j=min(f[l+r-i],r-i)+1;
		while (i-j>=0 && i+j<n && a[i-j]==a[i+j])
      j++;
		j--;
		f[i]=j;
		if (i+j>r)
    {
			r=i+j;
			l=i-j;
		}
		int len=(f[i]+i%2)/2*2+1-i%2;
		if (len>res)
    {
			res=len;
			center=i;
		}
	}
	return res;
}

string st;
int main()
{
  cin>>st;
  cout<<manacher(st);
}
