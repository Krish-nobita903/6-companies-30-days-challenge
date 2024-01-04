class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long int people = 0;
        int mod = 1e9+7;
        vector<long long int>dp(n+10,0);
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            long long int newpeople = dp[max(0,(int)(i-delay))];
            long long int forgetpeople = dp[max(0,(int)(i-forget))];
            people = (people+newpeople-forgetpeople+mod)%mod;
            dp[i] = people;
        }
        long long int ans = 0;
        for(int i=n-forget+1;i<=n;i++)
        {
            ans = (ans+dp[i])%mod;
        }
        return ans;
    }
};



/******

Logic::(DP cannot solve at first had to look at hints and all abit)

SO here as we move forward in dp array , we store in dp[i] the number of people who knows secret at that point and it is calculated using those who know , new people whi will get to know which is by dp[i-delay]
as people who joins on i-delay will be the one who will join now , and those who forget by dp[i-forget] so using these daat we calculate the dp array , and we sum from n-forget+1 with modulo to find the answer.

*******/
