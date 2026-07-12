class Solution {
    void solve(int index,vector<int> & nums,int & sum,int & target,vector<int> & temp,vector<vector<int>> & ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(index == nums.size()) return;
        //lenge
        if(nums[index] + sum <= target){
            sum += nums[index];
            temp.push_back(nums[index]);
            solve(index,nums,sum,target,temp,ans);
            sum -= nums[index];
            temp.pop_back();
        }
        //nhi lenge
        solve(index+1,nums,sum,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(0,nums,sum,target,temp,ans);
        return ans;
    }
};
