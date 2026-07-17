class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //unordered_map<char,int> mpp;
        int left=0,ans=0,maxfrq=0,countT=0,countF=0;
        for(int right=0;right<answerKey.size();right++){
            // mpp[answerKey[right]]++;
            if(answerKey[right]=='T')   countT++;
            else                        countF++;
            // maxfrq=max(maxfrq,mpp[answerKey[right]]);
            // while(right-left+1-maxfrq>k)
            //     mpp[answerKey[left++]]--;
            while(min(countT,countF)>k){
                if(answerKey[left]=='T')   countT--;
                else    countF--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};