class Solution {
    set<vector<int>>check;
    void solve(int index,vector<int> & nums,vector<vector<int>> & ans){

        if(index == nums.size()-1){
            if(!check.count(nums)){
                check.insert(nums);
            ans.push_back(nums);
            }
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
   
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);

        return ans;
    }
};