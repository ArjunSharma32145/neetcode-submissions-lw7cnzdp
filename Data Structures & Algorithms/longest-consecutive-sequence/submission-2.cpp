class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> store(nums.begin(),nums.end());
        int res = 0;
        for(auto num : store){
              if(store.find(num-1) == store.end()){
                int streak =1;
                int check = num+1;
                while(store.find(check) != store.end()){
                    streak++;
                    check++;
                }
                res = max(res,streak);
              }
        }
        return res;
    }
};
