class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<pair<string,int>>vp1;
        for(int i=0;i<nums.size();i++) vp1.push_back({nums[i],i});
        sort(vp1.begin(),vp1.end());
        for(auto q : queries)
        {
            int k = q[0];
            int trim = q[1];
            vector<pair<string,int>>vp;
            int c = 0;
            for(string s : nums)
            {
                string a;
                for(int i=s.length()-1;i>s.length()-trim-1;i--) a+= s[i];
                reverse(a.begin(),a.end());
                vp.push_back({a,c});
                c++;
            }
            sort(vp.begin(),vp.end());
            if(vp[k-1].first.size()==0) ans.push_back(vp1[k-1].second);
            else
            ans.push_back(vp[k-1].second);
        }
        return ans;
    }
};



/*

Logic: A simple brute force with a simple edge case

*/
