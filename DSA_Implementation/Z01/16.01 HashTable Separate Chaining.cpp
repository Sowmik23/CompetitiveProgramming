#include <bits/stdc++.h>
using namespace std;


struct Node {
	int key;	//int
	string value; //string
	Node* next;
	
	Node(){
		this->key = 0;
		this->value = "";
		this->next = NULL;
	}
	Node(int Key, string Value){
		this->key = Key;
		this->value = Value;
		this->next = NULL;
	}
	Node(Node const &data){
		this->key = data.key;
		this->value = data.value;
		this->next = data.next;
	}
};


class HashTableSeparateChaining {
	
	private:
		int size; //declared size of the table
		int cnt; //current size of the table
		///loadFactor = cnt/size;
		Node** table;
		
	public:
		//constructors
		HashTableSeparateChaining(){};
		HashTableSeparateChaining(int sze){
			this->size = sze;
			this->cnt = 0;
			
			table = new Node* [size]; //allocate first dimension of the table
			for(int i=0;i<size;i++){
				table[i] = NULL;
			}
		}
		
		void insert(int key, string value){
			Node tmp = Node(key, value);
			Node* newNode = new Node(tmp);
			
			cnt++;
			if(cnt>size){  //consider the load factor
				resizeTable(); //if(n/m>1) double the table size
			}
			
			int index = hashFunction(key);
		
			if(table[index]==NULL){ //list: empty
				table[index] = newNode; //list: 5->NULL
			}
			else {
				Node* next = table[index]->next;  //list: 5->7->2->NULL
				table[index]->next = newNode;  //list: 5->3->7->2->NULL
				newNode->next = next;
			}
		}
		
		void Delete(int key){
			
			int index = hashFunction(key);
			Node* curr = table[index];
			Node* prev = NULL;
			
			while(curr!=NULL and curr->key!=key){
				prev = curr;
				curr = curr->next;
			}
			
			//3 cases
			//case-01: data not found
			if(curr==NULL){
				cout<<"Data not found"<<endl;
				return;
			}
			else {
				//case-02: data found at first node
				//eg: list: 5->2->9->NULL, want to delete 5
				if(prev==NULL){
					table[index] = curr->next; //list: 2->9->NULL
				}
				else {
					//case-03: data found at other position
					//list: 5->2->9->NULL, delete 2
					prev->next = curr->next; //after delete, list: 5->9->NULL
				}
				delete curr;  //free memory
				curr = 0;
			}
			
			cnt--;
			if(cnt<size/4){ //consider load factor
				shrinkTable(); //if(n/m<4) then shrink table
			}
		}
		
		string Search(int key){
			int index = hashFunction(key);
			Node* curr = table[index];
			
			while(curr!=NULL){
				if(curr->key==key) return curr->value;
				curr = curr->next;
			}
			return "Not found";
		}
			
		void displayTable(){
			
			for(int i=0;i<size;i++){
				cout<<"Slot "<<i<<": ";
				Node* curr = table[i];
				while(curr!=NULL){
					cout<<"("<<curr->key<<", "<<curr->value<<")->";
					curr = curr->next;
				}
				cout<<"NULL"<<endl;
			}
			cout<<endl;
		}
		
		//destructor
		~HashTableSeparateChaining(){
			//visit every node in table and release the memory of each node
			for(int i=0;i<size;i++){  
				Node* curr = table[i]; //first node of the list
				while(curr!=NULL){
					Node* prev = curr;
					curr = curr->next;
					delete prev;
					prev = 0;
				}
			}
			delete[] table;
		}
	
	
	private:
		int hashFunction(int key){  //Multiplication method
			double A = 0.6180339887;
			double frac = key*A - floor(key*A);
			
			return floor(this->size*frac);
		}
		
		void resizeTable(){
			int prevSize = this->size;
			this->size = size*2;
			
			reHashing(prevSize); //create new table with larger size
		}
		
		void reHashing(int prevSize){ 
			
			Node** newTable = new Node* [size]; //allocate memory for new table
			for(int i=0;i<size;i++){ //initialize
				newTable[i] = NULL;
			}
			
			for(int i=0;i<prevSize;i++){ //filling with previous data
				Node* curr = table[i];
				Node* prev = NULL;
				
				while(curr!=NULL){
					prev = curr->next;
					
					int index = hashFunction(curr->key);
					if(newTable[index]==NULL){
						newTable[index] = curr;
						newTable[index]->next = 0;
					}
					else {
						Node* tmp = newTable[index]->next;
						newTable[index]->next = curr;
						curr->next = tmp;
					}
					curr = prev;
				}
			}
			delete[] table;
			this->table = newTable;
		}
		
		void shrinkTable(){
			int prevSize = size;
			size = size/2;
			reHashing(prevSize); //create new table with new smaller size
		}
	};


int main(){
	
	HashTableSeparateChaining map(2);
	
	map.insert(1, "Sowmik");
	map.insert(2, "Sarker");
	map.insert(234, "A"); //table size will increase
	
	map.displayTable();

	map.insert(343, "B");
	map.insert(87, "C");
	map.insert(90, "D");
	map.insert(13, "E");
	map.insert(4656, "Bdd");
	map.insert(4354, "Cff");
	map.insert(904543, "Dfd");
	map.insert(12333, "Euy");
	
	map.displayTable();
	
	cout<<"Searching: key 904543: value: "<<map.Search(904543)<<endl;

	cout<<"Searching: key 1234: value: "<<map.Search(1234)<<endl;
	
	
	map.Delete(12333);
	map.Delete(1);
	map.Delete(0);
	cout<<endl<<"After deleting the table is: "<<endl;
	map.displayTable();
	
	return 0;
}
