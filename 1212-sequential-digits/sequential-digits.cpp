class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s="123456789";
        int n=s.size();
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                string subst=s.substr(i,len);
                int num=stoi(subst);
                if(low<=num && num<=high)
                    res.push_back(num);
            }
        }
        return res;
    }
};