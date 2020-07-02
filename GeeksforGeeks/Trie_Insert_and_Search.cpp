
//Trie data structure
//BST search cost O(M*logn)
//M= max string len
//Trie search O(M)

#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	struct TrieNode *children[26];
	
	bool isEndofWord;
};

struct TrieNode *getNode(void){
	struct TrieNode *pNode = new TrieNode;
	
	pNode-> isEndofWord = false;
	
	for(int i=0;i<26;i++){
		pNode->children[i] = NULL;
	}	
	return pNode;
}


void insert(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	
	for(int i=0; i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
		{
			pCrawl->children[index] = getNode();
		}
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndofWord = true;
}


bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
		{
			return false;
		}
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl !=NULL and pCrawl->isEndofWord);
}



int main()
{
	string data[] = {"the", "k", "Sowmik", "Sarker","name", "etc."};
	
	int n = sizeof(data)/sizeof(data[0]);
	
	struct TrieNode *root = getNode();
	
	for(int i=0;i<n;i++)
	{
		insert(root, data[i]);
	}
	
	//search
	if(search(root, "the")==true) {
		cout<<"Yes\n";
	}
	else {
		cout<<"No\n";
	}
	search(root, "SOWMIK")? cout<<"Yes\n" : cout<<"No\n";
	
	
	return 0;
}
