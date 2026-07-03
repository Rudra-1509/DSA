class Solution {
public:
    unordered_map<string,vector<string>> parents;
    unordered_map<string,int> distances;
    vector<string> path;
    vector<vector<string>> res;
    void dfs(string word,const string& beginWord){
        path.push_back(word);
        if(word==beginWord){
            vector<string> temp=path;
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
            path.pop_back();
            return;
        }
        for(auto par:parents[word])
            dfs(par,beginWord);
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.empty() || !s.count(endWord))  return {};
        queue<string> q;
        q.push(beginWord);
        distances[beginWord]=0;
        bool found=false;
        while(!q.empty() && !found){
            vector<string> curLevel;
            int sz=q.size();
            while(sz--){
                string cur=q.front();q.pop();
                if(cur==endWord)        found=true;
                curLevel.push_back(cur);
                string newWord=cur;
                for(int i=0;i<cur.size();i++){
                    for(char c='a';c<='z';c++){
                        if(c==cur[i])   continue;
                        newWord[i]=c;
                        if(!s.count(newWord))   continue;
                        if(!distances.count(newWord)){
                            parents[newWord].push_back(cur);
                            distances[newWord]=distances[cur]+1;
                            q.push(newWord);
                        }
                        else if(distances[newWord]==distances[cur]+1)
                            parents[newWord].push_back(cur);
                    }
                    newWord[i]=cur[i];
                }
            }
            for(auto& w:curLevel)       s.erase(w);
        }

        if(!found)  return {};
        dfs(endWord,beginWord);
        return res;
    }   
};