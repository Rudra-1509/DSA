class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0,n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[i]<heights[st.top()])){
                int ind=st.top();st.pop();
                int h=heights[ind];
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int w=nse-pse-1;
                ans=max(ans,w*h);
            }
            st.push(i);
        }
        return ans;
    }
};