class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int l=0,r=m;
        while(l<=r){
            int i=(l+r)/2;
            int j=(m+n)/2 -i;
            int AL=(i>0)?  nums1[i-1] : INT_MIN;
            int AR=(i<m)? nums1[i]:INT_MAX;
            int BL=(j>0)?  nums2[j-1] : INT_MIN;
            int BR=(j<n)? nums2[j]:INT_MAX;

            if(AL<=BR && BL<=AR){
                if((m+n)%2==0)  return (max(AL,BL)+min(AR,BR))/2.0;
                else            return min(AR,BR);
            }
            else if(AL>BR){
                r=i-1;
            }
            else{
                l=i+1;
            }
        }
        return 0.0;
    }
};