class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        bool isMinus=false;
        //step1
        while(i<n && s[i]==' ') i++;
        //step2
        if(i<n && s[i]=='+'){
            i++;
        }
        else if(i<n && s[i]=='-'){
            isMinus=true;
            i++;
        }
        //step3
        long long num=0;
        while(i<n && isdigit(s[i])){
            int dig=s[i]-'0';
            //step4
            if(num>INT_MAX/10 || (num==INT_MAX/10 && dig>7))
                return isMinus? INT_MIN: INT_MAX;
            num=num*10+dig;
            i++;
        } 
        if(isMinus) num=-num;
        return (int)num;
    }
};