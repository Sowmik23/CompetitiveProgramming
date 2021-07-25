#include <bits/stdc++.h>
using namespace std;


struct Node{
	string val;
	Node* next;
	
	Node(string val, Node* next){
		this->val = val;
		this->next = next;
	}
};

class LinkedList{
	Node *head;
	
	public:
	LinkedList(){
		this->head = nullptr;
	}
	
	void insertIntoLinkedList(string value){
		this->head = new Node(value, this->head);
	}
	
	bool searchList(string value){
		Node* current = this->head;
		while(current!=nullptr){
			if(current->val == value) return true;
			current = current->next;
		}
		return false;
	}
	
	bool deleteValue(string value){
		Node* current = this->head;
		Node* prev;
		if(this->head==nullptr) return false;
		while(current!=nullptr){
			if(current->val==value){
				
		}
	}
};


class HashTable{
	LinkedList** data;
	int length;
	
	public:
	HashTable(int size){
		this->length = size;
		this->data = new LinkedList*[size];
		for(int i=0;i<size;i++){
			this->data[i] = new LinkedList();
		}
	}
	
	void insert(string value){
		int idx = abs(hashFunction(value))%this->length;
		this-data[idx]->insertIntoLinkedList(value);
	}
	
	bool search(string value){
		int idx = abs(hashFunction(value))% this->length;
		return data[idx]->searchList(value);
	}
	
	bool deleteVal(string value){
		int idx = abs(hashFunction(value))%this->length;
		return data[idx]->deleteValue(value);
	}
	
	
	private:
	int hashFunction(string value){
		int hash = 7;
		for(int i=0;i<value.length();i++){
			hash = hash * 31 + value[i];
		}
		return hash;
	}
	
	int jenkins_hash(string value){
		int hash = 0;
		
		for(int i=0;i<value.length();i++){
			hash +=(value[i] & 0xFF);
			hash +=(hash << 10);
			hash ^=(hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		
		return hash;
	}  
};


int main(){
	
	
	
	
	return 0;
}
