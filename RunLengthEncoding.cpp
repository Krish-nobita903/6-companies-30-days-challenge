

/*You are required to complete this function */
string integertostring(int n)
{
    string ans;
    while(n!=0)
    {
        ans += (n%10)+'0';
        n /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string encode(string src)
{     
  //Your code here 
  string ans;
  char c = src[0];
  int cnt = 1;
  for(int i=1;i<src.length();i++)
  {
      if(src[i]==c) cnt++;
      else
      {
          ans += c;
          ans += integertostring(cnt);
          c = src[i];
          cnt = 1;
      }
  }
  ans += c;
  ans += integertostring(cnt);
  return ans;
}     
 
