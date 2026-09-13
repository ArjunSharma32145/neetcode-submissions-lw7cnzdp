class Solution {
public:
    string longestPalindrome(string s) {
        string ans ;
        int anslen = 0;
        for(int i=0;i<s.size();i++){
          // odd length palindrome
          int l = i;
          int r = i;
          while(l>=0 && r<s.size() && s[l] == s[r]){
            int len = r-l+1;
            if(len > anslen){
              anslen = len;
              ans = s.substr(l,anslen);
            }
            l--;
            r++;
          }
          // even length palindrome
          l = i;
          r = i+1;
          while(l>=0 && r<s.size() && s[l] == s[r]){
            int len = r-l+1;
            if(len > anslen ){
              anslen = len;
              ans = s.substr(l,anslen);
            }
            l--;
            r++;
          }
        }
        return ans;
    }
};
