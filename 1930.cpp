    int countPalindromicSubsequence(string s) {
        if(s.size()<3){
            return 0;
        }
        set<char>left;
        map<char,int>right;
        set<pair<char,char>>res;
        int mid = 1;
        for(int i = 1 ; i < s.size() ; i++){
            right[s[i]]++;
        }
        left.insert(s[0]);
        while(mid < s.size()){
            right[s[mid]]--;
            for(auto x : left){
                if(right[x] > 0){
                    res.insert({x,s[mid]});
                }
            }
            left.insert(s[mid]);
            mid++;
        }
        return res.size();
    }