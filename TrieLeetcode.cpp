
#include<bits/stdc++.h>
using namespace std;


class Trie {
public:
    struct trieNode {
        bool isEndofWord;
        trieNode *children[26];
        
    };
    trieNode* getNode(){
        trieNode *newNode= new trieNode();
        newNode->isEndofWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    
    trieNode *root;
    
    Trie() {
        root=getNode();    
    }
    
    void insert(string word) {
        trieNode * crawler=root;
        for(char ch:word){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isEndofWord=true;
    }
    
    bool search(string word) {
         trieNode * crawler=root;
        for(char ch:word){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
        
        if(crawler->isEndofWord==true)return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
         trieNode * crawler=root;
        int ct=0;
        for(char ch:prefix){
            ct++;
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
               return false;
            }
            crawler=crawler->children[idx];
        }
        if(ct==prefix.length())return true;
        return false;
    }
};


