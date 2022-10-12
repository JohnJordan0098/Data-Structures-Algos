class Solution {
public:
    string robotWithString(string s) {
       vector<int> last(26, -1);
        for(int i = 0; i < s.size(); i++) last[s[i]-'a'] = i;
        
        string ans;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            stk.push(s[i]);
            while(stk.size()){
                bool exist = false;
                for(int ch = 0; ch < stk.top()-'a'; ch++){
                    if(i < last[ch]){
                        exist = true;
                        break;
                    }
                }
                if(exist) break;
                ans.push_back(stk.top());
                stk.pop();
            }
        }
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};