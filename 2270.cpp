    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pre;
        long long int s = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            s+=nums[i];
            pre.push_back(s);
        }
        int ans = 0;
        for(int i = 0 ; i < pre.size()-1 ; i++){
            if(pre[i] >= pre.back() - pre[i]){
                ans+=1;
            }
        }
        return ans;
    }