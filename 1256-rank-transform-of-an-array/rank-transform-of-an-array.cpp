class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n);
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
            temp.push_back({arr[i],i});
        sort(temp.begin(),temp.end());
        int rank=0,prev=INT_MIN;
        for(int i=0;i<n;i++){
            auto& [num,ind]=temp[i];
            if(prev!=num)
                rank++;
            prev=num;
            res[ind]=rank;
        }
        return res;   
    }
};