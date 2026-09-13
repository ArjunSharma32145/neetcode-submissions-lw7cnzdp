class Solution {
    bool exist(string check,vector<string> & wordDict){
        for(auto it : wordDict){
            if(check == it) return true;
        }
        return false;
    }
    bool solve(int index,string s,vector<string> & wordDict,vector<int> & dp){
        if(index == s.size()) return true;

        if(dp[index] != -1) return dp[index];
        string check ;
        for(int i=index;i<s.size();i++){
            check += s[i];
            if(exist(check,wordDict)){
                if(solve(i+1,s,wordDict,dp)) return dp[index] = true;
            }
        }
        return dp[index]= false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,wordDict,dp);
    }
};
