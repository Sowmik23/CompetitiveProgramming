#include <bits/stdc++.h>
using namespace std;


/* Among hashing algorithms any type of probing(linear or quadratic)
 * is typically significantly faster than chaining. 
 * Because in chaining there is a cache related issue.
 * 
 * Here used Linear probbing
 */

const int TABLE_SIZE = 10;

class HashEntry {
	public:
	int key;
	int val;
	 HashEntry(int key, int val){
		 this->key = key;
		 this->val = val;
	 }
 };

class HashMap{
	private:
	HashEntry **table;
	
	public:
	HashMap(){
		table = new HashEntry *[TABLE_SIZE];
		for(int i=0;i<TABLE_SIZE;i++){
			table[i] = NULL;
		}
	}
	
	int HashFunc(int key){
		return key%TABLE_SIZE;
	}
	
	void insert(int key, int val){
		int hash = HashFunc(key);
		cout<<hash<<endl;
		while(table[hash]!=NULL and table[hash]->key!=key){
			hash = HashFunc(hash + 1);
		}
		
		if(table[hash]!=NULL){
			delete table[hash];
		}
		
		table[hash] = new HashEntry(key, val);
	}
	
	int search(int key){
		int hash = HashFunc(key);
		while(table[hash] !=NULL and table[hash]->key !=key){
			hash = HashFunc(hash + 1);
		}
		if(table[hash] ==NULL) {
			return -1;
		}
		return table[hash]->val;
	}
	
	void remove(int key){
		int hash = HashFunc(key);
		while(table[hash]!=NULL){
			if(table[hash]->key ==key){
				break;
			}
			hash = HashFunc(hash+1);
		}
		if(table[hash]==NULL) {
			printf("Nothing found at that key %d\n", key);
			return ;
		}
		delete table[hash];
		printf("Value deleted successfully\n");
	}
	
	void printTable(){
		for(int i=0;i<TABLE_SIZE;i++){
			if(table[i]!=NULL){
				printf("Slot[%d] : [key: %d ,val: %d] \n", i, table[i]->key, table[i]->val);
			}
		}
	}
	
	~HashMap(){
		for(int i=0;i<TABLE_SIZE;i++){
			if(table[i]!=NULL){
				delete table[i];
			}
		}
		delete []table;
	}
};

int main(){
	
	HashMap map;
	
	//int key, val;
	map.insert(43, 5435);
	map.insert(45, 5645);
	map.insert(23, 545);
	map.insert(76, 35);
	map.insert(21, 335);
	map.insert(12, 53335);
	map.insert(75, 54545);
	map.insert(98, 54434);
	map.insert(89, 5432);
	map.insert(90, 512);
	
	map.printTable();
	
	int data = map.search(43);
	cout<<data<<endl;
	
	
	return 0;
}
