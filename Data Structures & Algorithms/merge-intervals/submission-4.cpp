class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int p = 0;
        for(int i=1;i<intervals.size();i++){
           if(intervals[i][0] <= ans[p][1]){
            ans[p][1] = max(intervals[i][1],ans[p][1]);
            continue;
           }
           ans.push_back(intervals[i]);
           p++;
        }
        return ans;
    }
};
