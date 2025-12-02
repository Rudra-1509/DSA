class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || x==0)    return x;  
        if(n==0)    return 1;
        long power=n;
        double ans=1;
        if(n<0){
            power=-power;x=1/x;
        }
        while(power>0){
            if(power & 1)   ans*=x;
            x*=x;
            power=power>>1;
        }
        return ans;
    }
};