class Solution {
public:
    bool helper(string a, string b,unordered_map<string,bool>& mp){
        string key=a+' '+b;
        if(mp.find(key)!=mp.end())    return mp[key];
        if(a==b)        return mp[key]=true;
        if(a.size()<=1)  return mp[key]=false;
        int n=a.size();
        for(int i=1;i<=n-1;i++){
            bool res1=helper(a.substr(0,i),b.substr(n-i,i),mp) &&
                        helper(a.substr(i,n-i),b.substr(0,n-i),mp);//swap
            bool res2=helper(a.substr(0,i),b.substr(0,i),mp) &&
                        helper(a.substr(i,n-i),b.substr(i,n-i),mp);//no swap
            if(res1||res2)  return mp[key]= true;
        }
        return mp[key]= false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())    return false;
        if(s1==" " && s2==" ")    return true;
        unordered_map<string,bool> mp;
        return helper(s1,s2,mp);
    }
};