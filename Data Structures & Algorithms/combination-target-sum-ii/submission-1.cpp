class Solution {

    void solve(int index,vector<int> & candidates,int target,vector<vector<int>> & ans,vector<int> & temp,int & sum){

        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size()) return;

        //lena hai
        if(candidates[index] <= target && sum <= target){
            sum += candidates[index];
            temp.push_back(candidates[index]);
            solve(index+1,candidates,target,ans,temp,sum);
            sum -= candidates[index];
            temp.pop_back();
        }

        //nhi lena
        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]) index++;
        solve(index+1,candidates,target,ans,temp,sum);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        solve(0,candidates,target,ans,temp,sum);
        return ans;
    }
};
