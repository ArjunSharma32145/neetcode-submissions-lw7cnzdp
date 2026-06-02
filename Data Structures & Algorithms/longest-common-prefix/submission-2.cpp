class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 1) return strs[0];
        string check = strs[0];
        vector<int> common;
        for(int i=1;i<strs.size();i++){
            string cont = strs[i];
            int k=0;
            int j=0;
            int count = 0;
            while(k<check.size() && j<cont.size()){
                if(check[k] == cont[j]){
                  count++;
                  k++;
                  j++;
                }
                else break;
            }
            common.push_back(count);

        }
        int size = 1e9;
        for(auto it : common) size= min(size,it);
        for(int i=0;i<size;i++){
            ans += check[i];
        }
        return ans;
    }
};