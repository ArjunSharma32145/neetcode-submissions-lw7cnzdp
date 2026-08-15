class Solution {
public:
    void check(string strs,int & ones,int & zeroes){
        for(auto it : strs){
            if(it == '0') zeroes++;
            else ones++;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int p = strs.size();
        vector<vector<vector<int>>> dp(p+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // so for the base case i dont need to do anythinf as if any one zero it will be zero only
        for(int i=0;i<=p;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(i == 0) continue;
                    int ones = 0;
                    int zeroes = 0;
                    check(strs[i-1],ones,zeroes);
                    int take = 0;
                    if(zeroes <= j && ones <= k){
                        take = dp[i-1][j- zeroes][k-ones] + 1;
                    }
                    int nottake= dp[i-1][j][k];
                    dp[i][j][k] = max(take,nottake);
                }
            }
        }
        return dp[p][m][n];
    }
};