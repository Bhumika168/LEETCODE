class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long mx1=LONG_MIN;
        long mx2=LONG_MIN;
        long mx3=LONG_MIN;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(!st.count(nums[i])){
                if(nums[i]>mx1){
                    mx3=mx2;
                    mx2=mx1;
                    mx1=nums[i];
                }
                else if(nums[i]>mx2){
                    mx3=mx2;
                    mx2=nums[i];
                }
                else if(nums[i]>mx3){
                    mx3=nums[i];
                }
                st.insert(nums[i]);
            }
        }
        if(mx3==LONG_MIN){
            return mx1;
        }
        return mx3;

    }
};
