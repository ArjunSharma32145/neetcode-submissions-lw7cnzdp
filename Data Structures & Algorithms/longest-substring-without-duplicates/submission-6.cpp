class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> freq;
        int l =0;
        int window = 0;
        for(int j=0;j<s.size();j++){
            while(l<=j && freq.count(s[j])){
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;

            }
            freq[s[j]]++;
          window = max(window,j-l+1);
            
        }
        return window;
    }
};
