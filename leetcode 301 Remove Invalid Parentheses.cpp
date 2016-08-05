class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                cnt++;
            }else if(s[i] == ')'){
                cnt--;
                if(cnt < 0){
                    right++;
                    cnt = 0;
                }
            }
        }
        left = cnt;
        // cout << left << " " << right << endl;
        string cur;
        unordered_set<string> us;
        dfs(s, 0, cur, left, right, 0, us);
        // cout << us.size() << endl;
        return vector<string>(begin(us), end(us));
    }
    
    void dfs(string& s, int idx, string & cur, int left, int right, int cnt, unordered_set<string> & us){
        if(left < 0 || right < 0 || cnt < 0)    return;
        if(idx == s.size()){
            if(cnt == 0 && left == right && left == 0){
                us.insert(cur);
            }
            return;
        }
        // cout << cur << endl;
        char ch = s[idx];
        if(ch == '('){
            cur.push_back(ch);
            dfs(s, idx + 1, cur, left, right, cnt + 1, us);
            cur.pop_back();
            
            dfs(s, idx + 1, cur, left - 1, right, cnt, us);
        }else if(ch == ')'){
            if(cnt > 0){
                cur.push_back(ch);
                dfs(s, idx + 1,cur, left, right, cnt - 1, us);
                cur.pop_back();
            }
            
            dfs(s, idx + 1, cur, left, right - 1, cnt, us);
        }else{
            cur.push_back(ch);
            dfs(s, idx + 1, cur, left, right, cnt, us);
            cur.pop_back();
        }
    }
};