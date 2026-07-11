class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto it : st){
            if(st.count(it-1)) continue;
            int streak =1;
            int check = it+1;
            while(st.count(check)){
                check++;
                streak++;
            }
            ans = max(ans,streak);
        }
        return ans;
    }
};
