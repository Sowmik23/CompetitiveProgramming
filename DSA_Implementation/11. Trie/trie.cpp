#include <bits/stdc++.h>
using namespace std;


class TrieNode{
	map<char, TrieNode*> table;
	bool isWord;
	
	public:
	TrieNode(){
		isWord = false;
	}
	bool haveRecord(char ch){
		return table.find(ch) != table.end();
	}
	bool haveNoRecord(){
		return table.empty();
	}
	TrieNode* followChar(char ch){
		return table.find(ch)->second;
	}
	void addRecord(char ch, TrieNode *n){
		table[ch] = n;
	}
	void deleteRecord(char ch){
		auto it = table.find(ch);
		if(it!=table.end()) {
			table.erase(it);
		}
	}
	bool getIsWord(){
		return this->isWord;
	}
	bool setIsWord(bool isWord){
		this->isWord = isWord; 
	}
};


class Trie{
	TrieNode* root;
	
	public:
	Trie(){
		this->root = new TrieNode();
	}
	
	void insert(string str){
		TrieNode* n = root;
		for(int i=0;i<str.size();i++){
			if(!n->haveRecord(str[i])){
				n->addRecord(str[i], new TrieNode());
			}
			n = n->followChar(str[i]);
		}
		n->setIsWord(true);
	}
	
	bool search(string str){
		TrieNode *n = root;
		for(int i=0;i<str.size();i++){
			if(!n->haveRecord(str[i])){
				return false;
			}
			n = n->followChar(str[i]);
		}
		return n->getIsWord();
	}
	
	bool deleteStr(string str){
		TrieNode *n = root;
		TrieNode **path = new TrieNode*[str.size()];
		int pathLength = 0;
		
		for(int i=0;i<str.size();i++){
			if(!n->haveRecord(str[i])){
				return false; //str is not is trie so can not be deleted
			}
			n = n->followChar(str[i]);
			path[pathLength] = n;
			pathLength++;
		}
		n->setIsWord(false);
		
		//delete nodes that are not needed
		int inputIdx = str.size() - 1; //from end to 0
		for(int i=pathLength-2;i>=0;i--){
			if(n->haveNoRecord() and (!n->getIsWord())) {
				//node can be deleted
				n = path[i];
				n->deleteRecord(str[inputIdx]);
				inputIdx--;
			}else break; //node can not be deleted
		}
		return true;
	}
};


int main(){
	
	
	
	
	
	return 0;
}
