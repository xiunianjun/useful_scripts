#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Trie{
    int val;
    struct Trie* children[26];
    bool isEnd;
} Trie;


Trie* trieCreate() {
    Trie* t=(Trie*)malloc(sizeof(Trie));
    t->val=0;
    t->isEnd=false;
    for(int i=0;i<26;i++){
        t->children[i]=NULL;
    }
    return t;
}

void trieInsert(Trie* obj, char * word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->children[word[i]-'a']!=NULL){
            obj=obj->children[word[i]-'a'];
        }
        else{
            Trie* t=trieCreate();
            t->val=word[i];
            obj->children[word[i]-'a']=t;
            obj=t;
        }
    }
    obj->isEnd=true;
}

bool trieSearch(Trie* obj, char * word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->children[word[i]-'a']!=NULL){
            obj=obj->children[word[i]-'a'];
        }
        else{
            return false;
        }
    }
    return obj->isEnd;
}

bool trieStartsWith(Trie* obj, char * word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->children[word[i]-'a']!=NULL){
            obj=obj->children[word[i]-'a'];
        }
        else{
            return false;
        }
    }
    return true;
}

void trieFree(Trie* obj) {
    if(obj==NULL)   return;
    for(int i=0;i<26;i++){
        trieFree(obj->children[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
