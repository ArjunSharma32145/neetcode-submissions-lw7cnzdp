class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string lol = "";
        int lolsize = 0;
        for(int i=0;i<n;i++){
          int l = i;
          int r = i;
          // odd length
          while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1 > lolsize){
              lol = s.substr(l,r-l+1);
              lolsize = r-l+1;
            }
            l--;
            r++;
          }
          // even length
          l = i;
          r=i+1;
          while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1 > lolsize){
              lol = s.substr(l,r-l+1);
              lolsize = r-l+1;
            }
            l--;
            r++;
          }
        }
        return lol;
    }
};
