class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n  || heights[i]<heights[st.top()])){
                int ind=st.top();st.pop();
                int height=heights[ind];
                int nse=i;
                int pse=st.empty()? -1:st.top();
                int width=nse-pse-1;
                ans=max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};