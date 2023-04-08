/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};


class Trie {
        TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
            root=new TrieNode('\0');

    }


    void insertUtil(TrieNode* root, string Word){
            if(Word.length()==0){
                root->isTerminal=true;
                return;
            }

        //assuming word will be in caps
            int index=Word[0]-'a';
            TrieNode* child;
        //present
            if( root -> children[index] != NULL) {
            child = root->children [index];
            }
            else {    //absent
            child = new TrieNode(Word[0]);
            root->children [index] = child;
            }

            //recursion
            insertUtil(child,Word.substr(1));
        }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode * root, string word){
            if(word.length()==0){
                return root->isTerminal;
            }

            int index = word[0]-'a';
            TrieNode * child;

            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }


      bool prefixUtil(TrieNode * root, string word){
            if(word.length()==0){
                return true;
            }

            int index = word[0]-'a';
            TrieNode * child;

            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                return false;
            }

            return prefixUtil(child, word.substr(1));
        }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};