class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int anssize = 0;
        for(int i=0;i<n;i++){
          // evenlength palind
          int r = i+1;
          int size = 0;
          int l = i;
          while(l>=0 && r<n && s[l] == s[r]){
              size +=2;
              if(size > anssize){
                anssize = size;
                ans = s.substr(l,size);
              }
              l--;
              r++;
          }
          // oddlength palind
          r = i;
          l =i;
          size = 0;
          while(l>=0 && r<n && s[l] == s[r]){
            size = r-l+1;
            if(size > anssize){
              anssize = size;
              ans = s.substr(l,size);
            }
            l--;
            r++;
          }
        }
        return ans;
    }
};
