struct Node{
    Node* links[26];
    bool flag;

    Node(){
        flag=false;
        for(int i=0;i<26;i++)   
            links[i]=nullptr;
    }

    bool doesExist(char ch){
        return (!!links[ch-'a']);
    }

    void put(char ch){
        links[ch-'a']=new Node();
    }

    Node* next(char ch){
        return links[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag=true;
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
            if(! cur->doesExist(word[i]))
                cur->put(word[i]);
            cur=cur->next(word[i]);
        }
        cur->setEnd();
    }
    
    bool search(string word) {
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            if(cur->doesExist(word[i])){
                cur=cur->next(word[i]);
            }
            else return false;
        }
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* cur=root;
        for(int i=0;i<prefix.size();i++){
            if(cur->doesExist(prefix[i]))
                cur=cur->next(prefix[i]);
            else    return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */