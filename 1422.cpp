    int maxScore(string s) {
       int n = s.size();
        // cout<<zeros<<" 1)"<<ones;
        vector<int> zero_left;
        int zero_sum = 0;
        for(int i = 0; i < s.size() ;i++){
            if(s[i] == '0'){
                zero_sum += 1;
            }
            zero_left.push_back(zero_sum);
        }
        vector<int> one_right;
        int one_sum = 0;
        for(int i = s.size()-1; i >= 0 ;i--){
            if(s[i] == '1'){
                one_sum += 1;
            }
            one_right.push_back(one_sum);
        }
        int ans = 0;
        int left = 0;
         while(left < s.size()-1){
            ans = max(ans,zero_left[left]+one_right[n-left-2]);
            left++;
         }
         return ans;
    }