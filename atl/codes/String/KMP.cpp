//Hàm này trả về vị trí bắt đầu của những string b trong string a
void kmp(string a,string b)
{
  int n=a.length();
  int m=b.length();
  int i=1;
  int len=0;
  while (i<m)
  {
    if (b[i]==b[len])
    {
      len++;
      lps[i]=len;
      i++;
    }
    else
    {
      if (len!=0)
        len=lps[len-1];
      else
        i++;
      lps[i]=0;
    }
  }
  i=0;
  int j=0;
  int ans=0;
  while(i<n)
  {
    while (a[i]==b[j])
    {
      i++;
      j++;
      if (i>=n || j>=m)
        break;
    }
    if (j==m)
    {
      cout<<i-j+1<<" ";
      j=lps[j-1];
    }
    else
      if (j!=0)
        j=lps[j-1];
      else
        i++;
    if (i>=n)
      break;
  }
}
