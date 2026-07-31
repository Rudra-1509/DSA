class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3,0);
        int l=0,ans=0;
        for(int r=0;r<s.size();r++){
            count[s[r]-'a']++;
            while(count[0] && count[1] && count[2])
                count[s[l++]-'a']--;
            ans+=l;
        }
        return ans;
    }
};