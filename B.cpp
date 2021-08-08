//最长不下降子序列nlogn  Song 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int d[100005];
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        memset(d,0,sizeof(d));
        d[1]=obstacles[0];
        int len = 1;
        vector <int> ans;
        ans.push_back(1);
        int n = obstacles.size()-1;
        for (int i=1;i<=n;i++){
            if (obstacles[i]>=d[len]) d[++len]=obstacles[i],ans.push_back(len);
            else{
                int j = upper_bound(d+1,d+len+1,obstacles[i])-d;
                d[j]=obstacles[i];
                ans.push_back(j);
            }
            
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector <int> vec = {3,1,5,6,4,2};
    s.longestObstacleCourseAtEachPosition(vec);
}