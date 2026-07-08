class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left=0,right=0,n=word.size();
        while(right<n && word[right]!=ch)   right++;
        if(right==n)    return word;
        while(left<right)   swap(word[left++],word[right--]);
        return word;
    }
};