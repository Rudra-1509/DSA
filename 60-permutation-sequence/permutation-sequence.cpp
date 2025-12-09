class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact=1;
        for(int i=1;i<n;i++){
            numbers.push_back(i);
            fact*=i;
        }
        numbers.push_back(n);
        k--;
        string ans="";
        while(1){
            ans+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+(k/fact));
            if(numbers.size()==0)    break;
            k=k%fact;
            fact/=numbers.size();
        }
        return ans;
    }
};