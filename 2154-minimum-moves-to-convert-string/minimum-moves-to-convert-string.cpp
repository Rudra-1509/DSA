class Solution {
public:
    // int minimumMoves(string s) {
    //     int l=0,r=0,count=0;
    //     while(l<s.size()){
    //         while(l<s.size() && s[l]=='O'){
    //             l++;r++;
    //         }
    //         int existsX=0,lim=r+3;
    //         while(r<lim && r<s.size()){
    //             if(s[r]=='X')       existsX=1;
    //             r++;  
    //         }
    //         if(existsX) count++;
    //         l=r;
    //     }
    //     return count;
    // }
    int minimumMoves(string s) {
        int ans=0,i=0;
        while(i<s.size()){
            if(s[i]=='X'){
                i+=3;
                ans++;
            }
            else i++;
        }
        return ans;
    }
    
};