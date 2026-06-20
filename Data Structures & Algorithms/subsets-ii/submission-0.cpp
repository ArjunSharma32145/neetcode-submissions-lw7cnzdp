class Solution {
    void solve(int index,vector<int> & nums,vector<int> & temp,vector<vector<int>> & ans){

        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        //lena hai
        temp.push_back(nums[index]);
        solve(index+1,nums,temp,ans);
        temp.pop_back();

        //nhi lena
        while(index +1 <nums.size() && nums[index] == nums[index+1]) index++;
        solve(index+1,nums,temp,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;
        
    }
};
