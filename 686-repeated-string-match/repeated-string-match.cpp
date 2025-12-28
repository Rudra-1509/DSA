class Solution {
public:
    bool robinKarp(string text,string pattern){
        int m=text.size(), n=pattern.size();
        if(n>m) return false;
        const long long base=31;
        const long long MOD=1e9+7;

        long long thash=0,phash=0,p=1;

        for(int i=0;i<n;i++){
            phash=(phash*base+(pattern[i]-'a'+1))%MOD;
            thash=(thash*base+(text[i]-'a'+1))%MOD;
            if(i<n-1) p=(p*base)%MOD;
        }
        if(thash==phash && text.substr(0,n)==pattern)    return true;
        for(int i=n;i<m;i++){
            thash=(thash-((text[i-n]-'a'+1)*p)%MOD + MOD)%MOD;
            thash=(thash*base+(text[i]-'a'+1))%MOD;

            if(thash==phash && text.substr(i-n+1,n)==pattern)    return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string s="";
        int count=0;
        while(s.size() < b.size()){
            s+=a;
            count++;
        }
        if(robinKarp(s,b))    return count;
        s+=a;count++;
        if(robinKarp(s,b))    return count;
        return -1;
    }
};