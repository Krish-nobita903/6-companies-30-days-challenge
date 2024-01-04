class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        vector<int>index;
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            vector<int>ds;
            for(int j=i;j<n;j++)
            {
                ds.push_back(nums[j]);
                st.insert(ds);
            }
        }
        int ans = 0;
        for(auto it : st)
        {
            int c = 0;
            for(auto x : it)
            {
                if(x%p==0) c++;
            }
            if(c<=k) ans++;
        }
        return ans;
    }
};
