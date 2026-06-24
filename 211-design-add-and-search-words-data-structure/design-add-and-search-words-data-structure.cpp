struct node{
    node* links[26];
    bool flag;
    node(){
        for(int i=0;i<26;i++)
            links[i]=nullptr;
        flag=false;
    }
    bool doesExist(char ch){
        return !!(links[ch-'a']);
    }
    void put(char ch){
        links[ch-'a']=new node();
    }
    node* next(char ch){
        return links[ch-'a'];
    }
    void endWord(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    node* root;
    bool dfs(string& word,int ind,node* cur){
        if(ind==word.size())    return cur->isEnd();
        if(word[ind]!='.'){
            if(!cur->doesExist(word[ind]))  return false;
            return dfs(word,ind+1,cur->next(word[ind]));
        }    
        for(int i=0;i<26;i++){
            if(cur->doesExist('a'+i))
                if(dfs(word,ind+1,cur->next('a'+i))) return true;
        }
        return false;
    }

public:
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node* cur=root;
        for(int i=0;i<word.size();i++){
            if(!cur->doesExist(word[i]))
                cur->put(word[i]);
            cur=cur->next(word[i]);
        }
        cur->endWord();
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */