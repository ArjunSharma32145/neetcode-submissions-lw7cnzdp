/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int count = 0;
        int ans= 0;
        vector<int> start;
        vector<int> end;
        for(auto it : intervals){
          start.push_back(it.start);
          end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
      int i=0;
      int j = 0;
      while(i<start.size()){
        if(start[i] < end[j]){
          count++;
          ans = max(count,ans);
          i++;
        }
        else{
          count--;
          j++;
        }
      }
      return ans;
    }
};
