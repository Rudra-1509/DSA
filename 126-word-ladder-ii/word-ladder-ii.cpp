class Solution {
public:
    unordered_map<string,vector<string>> mpp;
    vector<vector<string>> res;
    vector<string> path;

    void dfs(string word,string beginWord){
        path.push_back(word);
        if(word==beginWord){
            vector<string> temp=path;
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        for(string& parent: mpp[word])
            dfs(parent,beginWord);
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(!s.count(endWord))   return {};

        queue<string> q;
        unordered_map<string,int> dist;

        q.push(beginWord);
        dist[beginWord]=0;
        bool found=false;
        
        while(!q.empty() && !found){
            int sz=q.size();
            unordered_set<string> currentLev;
            while(sz--){
                    string cur=q.front();q.pop();
                    string parent=cur;
                    for(int i=0;i<cur.size();i++){
                        char old=cur[i];
                        for(char ch='a'; ch<='z'; ch++){
                            if(ch==old)     continue;
                            cur[i]=ch;
                            if(!s.count(cur))   continue;
                            if(!dist.count(cur)){
                                dist[cur]=dist[parent]+1;
                                q.push(cur);
                                currentLev.insert(cur);
                                mpp[cur].push_back(parent);
                            }
                            else if(dist[cur]==dist[parent]+1){
                                mpp[cur].push_back(parent);
                            }
                            if(cur==endWord)    found=true;
                        }
                        cur[i]=old;
                    }
                }
                for(auto& word: currentLev)
                        s.erase(word);
        }
        if(!found)  return {};
        dfs(endWord,beginWord);
        return res;
    }   
};