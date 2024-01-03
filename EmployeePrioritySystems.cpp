class Solution {
public:
    int intval(string s)
    {
        int ans = 0;
        int min = s[3]-'0';
        min+= (10*(s[2]-'0'));
        int hour = (s[1]-'0')+((s[0]-'0')*10);
        hour*=60;
        ans = hour+min;
        return ans;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>>logs;
        for(int i=0;i<access_times.size();i++)
        {
            int time = intval(access_times[i][1]);
            logs[access_times[i][0]].push_back(time);
        }
        vector<string>ans;
        for(auto it : logs)
        {
            auto x = it.second;
            sort(x.begin(),x.end());
            for(int i=0;i<x.size();i++)
            {
                int c = 0;
                for(int j=i;j<i+3;j++)
                {
                    if(j==x.size()) break;
                    if(x[j]-x[i]<60)
                    {
                        c++;
                    }
                }
                if(c>=3)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};


/*


Logic: 
Here we have first created a function named intval which basically converts the time from hour minutes to a linear 1440 minutes time for linear better operation
Then we use a map data structure with map of string of vector<int> where to each access time string we will record the time 
after all the logs , we will sort the vector int , then we will check if given employee is highaccess or not and then pushback the employee.


*/
