class Solution {
    vector<int> dp;
    int solve(int index,string s){
        if(index >= s.size()) return 1;
        if(s[index] == '0') return 0;
        
        if(dp[index] != -1) return dp[index];
        int onejump = solve(index+1,s);

        int twojump = 0;
        if(index <s.size()-1 && (s[index] == '1' || s[index] == '2' && s[index+1] >= '0' && s[index+1]< '7')) twojump = solve(index+2,s);

        return dp[index] =  onejump + twojump;

    }
public:
    int numDecodings(string s) {
        int n= s.size();
        dp.resize(n,-1);
        return solve(0,s);
    }
};
