class Solution {
    void solve(vector<int> & nums, int start,vector<vector<int>>& v){
       if(start == nums.size()-1){
        v.push_back(nums);
        return ;
       }
     unordered_set<int> st;
       for(int i=start;i<nums.size();i++){
        if(st.find(nums[i]) == st.end()){
            st.insert(nums[i]);
            swap(nums[start],nums[i]);
            solve(nums,start+1,v);
            swap(nums[start],nums[i]);
        }
       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        solve(nums,0,v);
        return v;
    }
};
