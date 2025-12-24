class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
            int curH=(i==n)? 0 : heights[i];
            while(!st.empty() && heights[st.top()]>=curH){
                int ele=st.top();st.pop();
                int nse=i;
                int pse=(st.empty())? -1: st.top();
                int area=heights[ele]*(nse-pse-1);
                ans=max(area,ans);
            }
            st.push(i);
        }
        return ans;
    }
};