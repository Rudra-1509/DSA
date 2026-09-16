#from collections import DefaultDict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mpp={}
        left,ans=0,0
        for right in range(len(s)):
            mpp[s[right]]=mpp.get(s[right],0)+1
            while mpp[s[right]]>1:
                mpp[s[left]]-=1
                if mpp[s[left]]==0:
                    del mpp[s[left]]
                left+=1
            ans=max(ans,right-left+1)

        return ans