class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>ds,int n,int k,int sum,int i,vector<int>&nums)
    {
        if(k==ds.size())
        {
            if(sum==n)
            {
                ans.push_back(ds);
                return;
            }
        }
        if(i==9) return;
        if(sum>n)return; 
        f(ans,ds,n,k,sum,i+1,nums);
        ds.push_back(nums[i]);
        sum += nums[i];
        f(ans,ds,n,k,sum,i+1,nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        int sum = 0;
        vector<vector<int>>ans;
        vector<int>ds;
        f(ans,ds,n,k,sum,0,nums);
        return ans;
    }
};
