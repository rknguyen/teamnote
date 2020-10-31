//Chia xâu con S thành những xâu con có thứ tự từ điển nhỏ nhất dpt O(n)
void lyndon(string s)
{
	int n=s.length();
	int i=0;
	while (i<n)
	{
		int j=i+1;
		int k=i;
		while (j<n && s[k]<=s[j])
		{
			if (s[k]<s[j])
				k=i;
			else
				k++;
			j++;
		}
		while (i <= k)
		{
			cout<<s.substr(i,j-k)<<endl;
			i+=j-k;
		}
	}
	cout<<endl;
}
