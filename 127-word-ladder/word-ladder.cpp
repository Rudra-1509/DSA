class Solution {
public:
    void generate_and_insert(queue<string>& q,unordered_set<string>& s,unordered_set<string>& vis,string cur){
        int n=cur.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                string newWord=cur;
                newWord[i]='a'+j;
                if(newWord!=cur && !vis.count(newWord) && s.count(newWord)){
                    q.push(newWord);
                    vis.insert(newWord);
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=false;
        unordered_set<string> s,vis;
        s.insert(beginWord);
        for(string word: wordList){
            s.insert(word);
            if(word==endWord)   flag=true;
        }
        if(!flag)   return 0;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int i=0;i<sz;i++){
                string cur=q.front();q.pop();
                if(cur==endWord)    return ans;
                generate_and_insert(q,s,vis,cur);
            }
        }
        return 0;
    }

};