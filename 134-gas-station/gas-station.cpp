class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++)
            temp[i]=gas[i]-cost[i];
        for(int i=0;i<n-1;i++)
            temp[i+1]+=temp[i];
        if(temp[n-1]<0) return -1;
        int mini=0;
        for(int i=1;i<n;i++){
            if(temp[i]<temp[mini])
                mini=i;
        }
        return (mini+1)%n;
    }
};