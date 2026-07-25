class Solution {
public:
    int maxProduct(int n) {
        int l1=n%10; n/=10;
        int l2=n%10; n/=10;
        int first=max(l1,l2);
        int second=min(l1,l2);
        while(n){
            int digit=n%10;
            n/=10;
            if(digit>first){
                second=first;
                first=digit;
            }
            else if(digit>second){
                second=digit;
            }
        }
        return first*second;
    }
};