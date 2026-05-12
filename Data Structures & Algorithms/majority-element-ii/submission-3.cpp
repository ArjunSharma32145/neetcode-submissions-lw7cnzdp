class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
       //sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        int n = nums.size();
        int req = n/3;
        int check = INT_MIN;
        for(auto it : nums){
            if(check == it ) continue;
            mpp[it]++;
            if(mpp[it] > n/3 && find(ans.begin(),ans.end(),it) == ans.end()){
                ans.push_back(it);
                check = it;
            }
        }
        return ans;
    }
};