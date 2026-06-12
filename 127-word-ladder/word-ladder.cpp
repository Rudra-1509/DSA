class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(!s.count(endWord))   return 0;
        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                string cur=q.front();q.pop();
                if(cur == endWord)      return ans;
                for(int i=0;i<cur.size();i++){
                    char ch=cur[i];
                    for(int j=0;j<26;j++){
                        cur[i]='a'+j;
                        if(s.count(cur)){
                            q.push(cur);
                            s.erase(cur);
                        }
                    }
                    cur[i]=ch;
                }
            }
        }
        return 0;
    }

};