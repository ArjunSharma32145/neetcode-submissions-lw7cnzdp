class Solution {
    void solve(int index,vector<int> & nums,vector<vector<int>> & ans){

        if(index == nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            //change
            swap(nums[index],nums[i]);
            solve(index+1,nums,ans);
            //undo change
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};
