class Solution {
public:
    void helper(int start,int end,vector<int>& nums,vector<string>& res){
        if(start==end)
            res.push_back(to_string(nums[start]));
        else{
            string s=to_string(nums[start]);
            s+="->";
            s+=to_string(nums[end]);
            res.push_back(s);
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)  return {};
        vector<string>  res;
        int start=0,end=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]!=nums[i]+1){
                helper(start,end,nums,res);
                start=i+1;end=i+1;
            }
            else    end++;
        }
        helper(start,end,nums,res);
        return res;
    }
};