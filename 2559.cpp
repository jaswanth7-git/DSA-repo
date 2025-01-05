vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> pre;
    unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    for (int i = 0; i < words.size(); i++) {
        if (mp.count(words[i][0]) && mp.count(words[i][words[i].size() - 1])) {
            count += 1;
        }
        pre.push_back(count);
    }
    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        
        if (left == 0) {
            ans.push_back(pre[right]);
        } else {
            ans.push_back(pre[right] - pre[left - 1]);
        }
    }
    
    return ans;
}