class Solution {
public:
    bool isPal(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r])   return false;
            l++;r--;
        }
        return true;
    }
    int maxProduct(string s) {
        int n=s.size(),ans=0;
        vector<pair<int,int>> palSub;
        for(int mask=0;mask<(1<<n);mask++){
            string sub="";
            for(int i=0;i<s.size();i++){
                if((1<<i) & mask)
                    sub+=s[i];
            }
            if(isPal(sub))  palSub.push_back({mask,(int)sub.size()});
        }
        for(int i=0;i<palSub.size();i++){
            for(int j=i+1;j<palSub.size();j++){
                if(!(palSub[i].first & palSub[j].first))
                    ans=max(ans,palSub[i].second*palSub[j].second);
            }
        }
        return ans;
    }
};