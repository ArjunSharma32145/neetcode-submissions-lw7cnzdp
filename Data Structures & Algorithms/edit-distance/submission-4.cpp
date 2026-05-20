class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // so this dp represent then min no of ops with m size word1 and n size word2
// base case if lets say word1 empty then we need length of word2 ops or vice versa to remove lenth of word and if both empty then 0 ops
for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i == 0) dp[i][j] = j;
        if(j == 0) dp[i][j] = i;
    }
}
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(word1[i-1] == word2[j-1]){
            dp[i][j] = dp[i-1][j-1];
        }
        else{
            int insert = dp[i][j-1] + 1;
            int del = dp[i-1][j] +  1;
            int replace = dp[i-1][j-1] + 1;
            dp[i][j] = min(insert,min(del,replace));
        }
    }
  }
  return dp[m][n];
    }
};
