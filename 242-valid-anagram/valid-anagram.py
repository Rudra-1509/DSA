from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mpp=Counter(s)
        for ch in t:
            if not ch in mpp:
                return False
            mpp[ch]-=1
            if mpp[ch]==0:
                del mpp[ch]
        
        return not mpp