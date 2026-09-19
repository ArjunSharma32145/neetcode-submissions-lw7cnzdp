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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // whenever you king see intervals just sort them by end time
        sort(intervals.begin(),intervals.end(),[](Interval & a,const Interval & b){
        return a.end < b.end;
        });
        int finish = -1;
      for(auto it : intervals){
        if(it.start < finish) return false;
        finish = it.end;
      }
      return true;
    }
};
