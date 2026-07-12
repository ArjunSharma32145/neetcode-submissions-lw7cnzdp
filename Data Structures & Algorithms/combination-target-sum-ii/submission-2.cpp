class Solution {
    void solve(int index,vector<int> & candidates,vector<int> & temp,vector<vector<int>> & ans, int & sum,int & target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size()) return ;

        //lenge
        if(candidates[index] + sum <= target){
            sum += candidates[index];
            temp.push_back(candidates[index]);
            solve(index+1,candidates,temp,ans,sum,target);
            sum -= candidates[index];
            temp.pop_back();
        }
     while(index+1 < candidates.size() && candidates[index] == candidates[index+1]) index++;
        //nhi lenge
        solve(index+1,candidates,temp,ans,sum,target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates,temp,ans,sum,target);
        return ans;
    }
};
