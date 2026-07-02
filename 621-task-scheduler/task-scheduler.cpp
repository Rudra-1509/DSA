class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26,0);
        for(char& ch:tasks)
            frq[ch-'A']++;
        int maxfreq=*max_element(frq.begin(),frq.end());
        int maxCount=0;
        for(int& x:frq){
            if(x==maxfreq)   maxCount++;
        }
        int minFrameSize=(maxfreq-1)*(n+1)+maxCount;
        int ans=max(minFrameSize, (int)tasks.size());
        return ans;
    }
};