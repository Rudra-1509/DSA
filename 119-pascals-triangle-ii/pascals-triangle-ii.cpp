class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        long long term=1;
        for(int i=0;i<rowIndex;i++){
            term*=(rowIndex-i);
            term/=(i+1);
            res.push_back((int)term);
        }
        return res;
    }
};