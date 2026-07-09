class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        int curDay=0,courseTaken=0;
        priority_queue<int> pq;
        for(auto& course:courses){
            int dur=course[0],deadline=course[1];
            if(curDay+dur<=deadline){
                curDay+=dur;
                courseTaken++;
                pq.push(course[0]);
            }
            else{
                if(!pq.empty() && dur>pq.top()) continue;
                if(!pq.empty() && curDay+dur>deadline){
                    int longest=pq.top();
                    pq.pop();
                    curDay-=longest;
                    curDay+=dur;
                    pq.push(dur);
                }
            }
        }
        return courseTaken;
    }
};