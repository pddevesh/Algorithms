#define ALPHA 26
class Trie {
        Trie *children[ALPHA];
        bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
       for(int i=0;i<ALPHA;i++)
            children[i]=NULL;

        isEnd=false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        Trie *itr= this;
        int n=word.length();
        for(int i=0;i<n;i++){
            int key= word[i]-'a';
            if(itr->children[key]==NULL)
                itr->children[key]=new Trie();

            itr = itr->children[key];
        }
        itr->isEnd=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        Trie *itr=this;
        for(int i=0;i<word.length();i++){
            int key= word[i]-'a';
            if(itr->children[key]==NULL)
                    return false;
            itr=itr->children[key];
        }
        return itr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *itr=this;
        for(int i=0;i<prefix.length();i++){

            int key= prefix[i]-'a';
            if(itr->children[key]==NULL)
                    return false;
            itr=itr->children[key];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
