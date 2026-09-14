class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto node = q.front().first;
            auto steps = q.front().second;
            if(node == endWord) return steps;
            q.pop();
            for(int i=0;i<node.size();i++){
                char original = node[i];
                for(char c = 'a';c<='z';c++){
                    node[i] = c;
                    if(st.count(node)){
                        q.push({node,steps+1});
                        st.erase(node);
                    }
                }
                node[i] = original;
            }
        }
        return 0; 
    }
};
