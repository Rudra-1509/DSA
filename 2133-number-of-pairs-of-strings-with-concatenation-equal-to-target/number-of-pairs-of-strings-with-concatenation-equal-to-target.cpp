class Solution {
public:
    string minusSubstring(string main,string subs,int d){
        int i,j,m=main.size(),n=subs.size();
        if(d==1){
            i=0;j=0;
        }
        else{
            i=m-1;j=n-1;
        }
        while(i>=0 && j>=0 && i<m && j<n){
            if(main[i]!=subs[j])    return "#";
            i+=d;j+=d;
        }
        // if(j!=n)
        if(d==1)
            return main.substr(i,m-i);
        else
            return main.substr(0,i+1);
    }

    int numOfPairs(vector<string>& nums, string target) {
        int count=0;
        unordered_map<string,int> mpp;
        for(string& num:nums){
            if(num[0]==target[0])          count+=mpp[minusSubstring(target,num,1)];
            if(num.back()==target.back())  count+=mpp[minusSubstring(target,num,-1)];
            mpp[num]++;
        }
        return count;
    }
};