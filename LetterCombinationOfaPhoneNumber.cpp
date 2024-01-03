class Solution {
public:
void f(vector<string>&ans,string x,string &digits,int i,map<int,string>&mp)
{
    if(i==digits.length())
    {
        ans.push_back(x);
        return;
    }
    string a = mp[digits[i]-'0'];
    i++;
    for(int j=0;j<a.length();j++)
    {
        string s1 = x+a[j];
        f(ans,s1,digits,i,mp);
    }
}
    vector<string> letterCombinations(string digits) {
        map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string>ans;
        string x;
        if(digits.length()==0) return ans;
        f(ans,x,digits,0,mp);
        return ans;
    }
};
