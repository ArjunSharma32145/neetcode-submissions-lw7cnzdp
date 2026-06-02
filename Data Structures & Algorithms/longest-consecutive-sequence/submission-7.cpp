class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> store(nums.begin(),nums.end());
        int ans = 0;
       for(auto it : store){
        if(store.count(it-1)) continue;
        int streak = 1;
        int check = it+1;
        while(store.count(check)){
            streak++;
            check++;
        }
        ans = max(ans,streak);
       }
       return ans;
    }
};
