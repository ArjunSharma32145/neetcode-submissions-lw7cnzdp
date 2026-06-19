class Solution {
    void solve(int index,vector<int> & nums,int target,int & sum,vector<int> & temp,vector<vector<int>> & ans){
        if(sum == target){
          ans.push_back(temp);
          return;
        }
        if(index == nums.size()) return;

        //lena hai
        if(sum <=target){
        sum += nums[index];
        temp.push_back(nums[index]);
        solve(index,nums,target,sum,temp,ans);
        sum -= nums[index];
        temp.pop_back();
        }
        // nhi lena
        solve(index+1,nums,target,sum,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
      solve(0,nums,target,sum,temp,ans);
      return ans;
    }
};
