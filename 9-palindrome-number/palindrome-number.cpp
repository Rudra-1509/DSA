class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)    return true;
        if(x<0 || x%10==0)     return false;
        int x1=x;
        long long rev=0;
        while(x>0){
            int rem=x%10;
            x=x/10;
            rev=rev*10+rem;
        }
        return (int)rev==x1;
    }
};