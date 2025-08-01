class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int left=0,right=m;
        while(left<=right){
            int mid1=left+(right-left)/2;
            int mid2=(m+n+1)/2-mid1;
            int l1=(mid1-1>=0)?nums1[mid1-1]:INT_MIN;
            int l2=(mid2-1>=0)?nums2[mid2-1]:INT_MIN;
            int r1=(mid1<m)?nums1[mid1]:INT_MAX;
            int r2=(mid2<n)?nums2[mid2]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else    return max(l1,l2);
            }
            else if(l1>r2)      right=mid1-1;
            else                left=mid1+1;
        }
        return 0.0;
    }
};