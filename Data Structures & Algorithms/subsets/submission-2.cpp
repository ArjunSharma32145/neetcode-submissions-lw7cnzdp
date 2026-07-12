class Solution {
    void solve(int index,vector<int> & nums,vector<int> & temp,vector<vector<int>> & ans){
         if(index == nums.size()){
            ans.push_back(temp);
            return;
         }
         // lenge
         temp.push_back(nums[index]);
         solve(index+1,nums,temp,ans);
         temp.pop_back();

         // nhi lenge
         solve(index+1,nums,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};
