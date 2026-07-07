struct Node{
    Node* links[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++)   links[i]=nullptr;
        flag=false;
    }
    bool doesExist(char ch){
        return !!(links[ch-'a']);
    }
    void put(char ch){
        links[ch-'a']=new Node();
    }
    Node* next(char ch){
        return links[ch-'a'];
    }
    void endWord(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            if(!cur->doesExist(word[i]))
                cur->put(word[i]);
            cur=cur->next(word[i]);
        }
        cur->endWord();
    }
    
    bool search(string word) {
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            if(!cur->doesExist(word[i]))    return false;
            cur=cur->next(word[i]);
        }
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* cur=root;
        for(int i=0;i<prefix.size();i++){
            if(!cur->doesExist(prefix[i]))    return false;
            cur=cur->next(prefix[i]);
        }
        if(cur) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */