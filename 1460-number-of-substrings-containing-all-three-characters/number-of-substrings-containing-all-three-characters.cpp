class Solution {
public:
    int numberOfSubstrings(string s) {
        // vector<int> count(3,0);
        // int l=0,ans=0;
        // for(int r=0;r<s.size();r++){
        //     count[s[r]-'a']++;
        //     while(count[0] && count[1] && count[2])
        //         count[s[l++]-'a']--;
        //     ans+=l;
        // }
        // return ans;

        int ans=0;
        vector<int> lastSeen(3,-1);
        for(int i=0;i<s.size();i++){
            lastSeen[s[i]-'a']=i;
            int mostLastSeen=min({lastSeen[0],lastSeen[1],lastSeen[2]}); //mostLastSeen is becoming l analogically(l+1)
            ans+=mostLastSeen+1;    //0 to mostLastSeen (including) 

        }
        return ans;
    }
};