class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])    st.pop();
            if(st.empty())  mpp[nums2[i]]=-1;
            else    mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int num:nums1){
            if(mpp.count(num)) res.push_back(mpp[num]);
            else    res.push_back(-1);
        }
        return res;
    }
};