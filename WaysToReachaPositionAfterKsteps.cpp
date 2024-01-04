#define ll long long int
class Solution {
public:
    int mod = 1e9+7;
    int f(int s,int e,int k,vector<vector<int>>&dp)
    {
        if(k==0)
        {
            if(s==e)
            {
                return 1;
            }
            return 0;
        }
        if(dp[s+1000][k]!=-1) return dp[s+1000][k];
        ll forward = f(s+1,e,k-1,dp);
        ll backward = f(s-1,e,k-1,dp);
        return dp[s+1000][k] = (forward+backward)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(4000,vector<int>(k+10,-1));
        return f(startPos,endPos,k,dp)%mod;
    }
};
