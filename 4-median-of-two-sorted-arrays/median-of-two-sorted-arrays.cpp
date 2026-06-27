class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int l=0,r=m;
        while(l<=r){
            int mid1=l+(r-l)/2; //left half size
            int mid2=(m+n+1)/2-mid1;    //right half size
            int l1=mid1>=1 ? nums1[mid1-1] : INT_MIN;
            int r1=mid1<m ? nums1[mid1]: INT_MAX;
            int l2=mid2>=1 ? nums2[mid2-1]: INT_MIN;
            int r2=mid2<n ? nums2[mid2]: INT_MAX;
            if(l1>r2)           r=mid1-1;
            else if(l2>r1)      l=mid1+1;
            else{
                if((m+n) & 1)   return (float)(max(l1,l2));
                else            return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        return 0.0;
    }
};