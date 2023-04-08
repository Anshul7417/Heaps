#include<iostream>
#include<string>
using namespace std;

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


class Trie{
    public:
        TrieNode* root;

        Trie(){
            root=new TrieNode('\0');
        }
        //base case
        void insertUtil(TrieNode* root, string Word){
            if(Word.length()==0){
                root->isTerminal=true;
                return;
            }

        //assuming word will be in caps
            int index=Word[0]-'A';
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

        void insertWord(string Word){
            insertUtil(root, Word);
        }

        bool searchUtil(TrieNode * root, string word){
            if(word.length()==0){
                return root->isTerminal;
            }

            int index = word[0]-'A';
            TrieNode * child;

            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }


        bool search(string word){
            return searchUtil(root, word);
        }



        void removeUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        return removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
        removeUtil(root, word);
}

};

int main()
{   
    Trie* t= new Trie();

    t->insertWord("abcd");

    cout<<"Present or not"<<t->search("abcd");
    
    return 0;
}