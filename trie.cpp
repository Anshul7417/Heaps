#include<iostream>
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
            }

        //assuming word will be in caps
            int index=Word[0]-'A';
            TrieNode* child;
        //present
            if( root -> children[index] != NULL) {
            child = root->children [index];
            }
            else {    //absent
            child = new TrieNode (Word[0]);
            root->children [index] = child;
            }

            //recursion
            insertUtil(child,Word.substr(1));
        }

        void insertWord(string Word){
            insertUtil(root, Word);
        }
};

int main()
{   
    Trie* t= new Trie();

    t->insertWord("abcd");
    
    return 0;
}