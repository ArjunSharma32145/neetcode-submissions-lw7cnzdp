class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        unordered_map<int,int> track;
        for(auto it : s1) track[it]++;
        unordered_map<int,int> freq;
        int left = 0;
        for(int i=0;i<n;i++){
          freq[s2[i]]++;
          if(i-left+1 == k){
            if(track == freq) return true;
            freq[s2[left]]--;
            if(freq[s2[left]] == 0) freq.erase(s2[left]);
            left++;
          }
          while((i-left+1) > k){
            freq[s2[left]]--;
            left++;
          }
        }
      return false;
    }
};
