class Solution {
public:
    double myPow(double x, long long n) {
        if(x==1 || x==0)    return x;  
        if(n==0)    return 1;
        double ans=1;
        if(n<0){
            n=-n;x=1/x;
        }
        while(n>0){
            if(n & 1)   ans*=x;
            x*=x;
            n=n>>1;
        }
        return ans;
    }
};