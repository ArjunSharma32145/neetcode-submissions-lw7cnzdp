class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        func(0,target,nums,ans,ds);
        return ans;

    }
    void func(int i,int target,vector<int> & nums, vector<vector<int>> & ans,vector<int> & ds){
            if(target==0){
                ans.push_back(ds);
                     return;
            }
            if(i==nums.size()) return;
            if(nums[i]<= target){
                ds.push_back(nums[i]);
                func(i,target-nums[i],nums,ans,ds);
                ds.pop_back();
            }
            func(i+1,target,nums,ans,ds);
        
    }
};
