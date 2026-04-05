class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
            if(mpp[it]>1) return it;
        }
        return -1;
    }
};
