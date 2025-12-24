class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<=k)  return {*max_element(nums.begin(),nums.end())};
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front()<i-k+1) dq.pop_front(); //kick out of window ele
            while(!dq.empty() && nums[dq.back()]<=nums[i])  dq.pop_back(); //maintain dec mon st
            dq.push_back(i);
            if(i>=k-1)  res.push_back(nums[dq.front()]);
        }
        return res;
    }
};