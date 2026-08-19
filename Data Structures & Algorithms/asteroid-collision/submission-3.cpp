class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<bool,int>> st;
        bool direction = false;
        if(asteroids[0] > 0 ) direction = true;
        st.push({direction,asteroids[0]});
        for(int i=1;i<asteroids.size();i++){
            direction = false;
            if(asteroids[i] > 0) direction = true;
            if(st.empty()){
                st.push({direction,asteroids[i]});
                continue;
            }
            bool flag = true;
            while(!st.empty()){
                if(st.top().first == true && direction == false){
                      if(abs(st.top().second) > abs(asteroids[i])){
                        flag = false;
                        break;
                      }
                      else if(abs(st.top().second) == abs(asteroids[i])){
                        flag = false;
                        st.pop();
                        break;
                      }
                      else{
                        st.pop();
                      }
                }
                else {
                    break;
                }
            }
            if(flag) st.push({direction,asteroids[i]});
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top().second);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};