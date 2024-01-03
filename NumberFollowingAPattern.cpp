class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        int num = 0;
        queue<pair<char,int>>q;
        int n = s.length();
        int c = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                q.push({s[i-1],c});
                c=1;
            }
            else c++;
        }
        q.push({s[n-1],c});
        set<int>st;
        for(int i=1;i<=9;i++)
        {
            st.insert(i);
        }
        string ans;
        bool f = false;
        while(!q.empty())
        {
            auto u = q.front();
            //cout<<u.first<<" "<<u.second<<" "<<st.size()<<"\n";
            q.pop();
            if(u.first=='I')
            {
                int start = *(st.begin());
                if(!f){
                    //cout<<start<<"\n";
                    ans += ('0'+start);
                    st.erase(start);
                    start++;
                }
                f = true;
                for(int i=0;i<u.second;i++)
                {
                    //cout<<start<<"\n";
                    ans += ('0'+start);
                    st.erase(start);
                    start++;
                }
            }
            else
            {
                int start = *(st.begin());
                start += u.second-1;
                if(f)
                {
                    int sz = ans.size();
                    int num = ans[sz-1]-'0';
                    //cout<<start<<"\n";
                    ans[sz-1] = ('0'+start);
                    st.insert(num);
                    st.erase(start);
                }
                else
                {
                    start++;
                    //cout<<start<<"\n";
                    ans += ('0'+start);
                    st.erase(start);
                }
                f = true;
                for(int i=0;i<u.second;i++)
                {
                    start--;
                    //cout<<start<<"\n";
                    ans+=('0'+start);
                    st.erase(start);
                }
            }
        }
        return ans;
    }
};
