    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v;
        string aph = "abcdefghijklmnopqrstuvwxyz";
        vector<int>diff(s.size()+1,0);
        for(int i = 0 ; i < s.size() ; i++ ){
            v.push_back(s[i]-96);
        }
        for(int i = 0 ; i < shifts.size() ; i++ ){
            int left = shifts[i][0];
            int right = shifts[i][1];
            if(shifts[i][2] == 0){
                diff[left] -= 1;
                diff[right+1] += 1;
            }else{
                diff[left] += 1;
                diff[right+1] -= 1;
            }
        }
        for(int i = 1 ; i < diff.size() ; i++){
            diff[i] = diff[i-1]+diff[i];
        }
        for(int i = 0 ; i < v.size() ; i++){
            v[i]+=diff[i];
        }
  string ans = "";
    for (int i = 0; i < v.size(); i++) {
        int normalized_index = (v[i] - 1) % 26;
        if (normalized_index < 0) { 
            normalized_index += 26;
        }
        ans += aph[normalized_index];
    }
    return ans;
    }