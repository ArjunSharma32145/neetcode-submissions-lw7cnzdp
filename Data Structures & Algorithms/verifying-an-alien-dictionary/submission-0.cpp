class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1) return true;
        // so first lets find rank of new alpha
        unordered_map<char,int> mpp;
        for(int i=0;i<order.size();i++){
            mpp[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++){
           string w1 = words[i];
           string w2 = words[i+1];
           int k =0;
           while(k<w1.size() && k<w2.size()){

            if(w1[k] != w2[k]){
                if(mpp[w1[k]] > mpp[w2[k]]) return false;
                else break;
            }
            k++;
           }

           // now if checking both the prefix and second one finished first thats wrong
           while( k == w2.size() && w1.size() > w2.size()) return false;
           
        }
        return true;
    }
};