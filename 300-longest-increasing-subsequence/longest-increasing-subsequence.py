from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails=[]
        for x in nums:
            if not tails or x> tails[-1]:
                tails.append(x)
            else:
                index=bisect_left(tails,x)
                tails[index]=x

        return len(tails)
