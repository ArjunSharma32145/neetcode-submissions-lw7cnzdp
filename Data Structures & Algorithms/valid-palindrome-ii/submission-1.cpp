class Solution {
    bool palind(int left,int right,string & s){
        while(left<right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
       int n = s.size();
       int i=0;
       int j=n-1;
       while(i<j){
        if(s[i] != s[j]){
            bool oneway = palind(i+1,j,s);
            bool secway = palind(i,j-1,s);
            if( !oneway && !secway){
              return false;
            }
        }
        i++;
        j--;
       }
       return true;
    }
};