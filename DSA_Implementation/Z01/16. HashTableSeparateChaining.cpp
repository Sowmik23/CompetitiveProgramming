#include <bits/stdc++.h>
using namespace std;


template <class K, class V>

class Entry{
	
	template<class A, class B>
	friend ostream& operator <<(ostream &strm, const Entry<A, B> &entry){
		return strm<<entry.key<<" => "<<entry.value;
	}
	
	public:
		std::hash<K> H;
		long long int hash;
		K key;
		V value;
	
		Entry(K key, V value){
			this->key = key;
			this->value = value;
			this->hash = H(key);
		}
	
		bool equals(Entry<K, V> other){
			if(hash!=other.hash) return false;
			return key==other.key;
		}
		
		string toString(){
			return key+" => "+value;
		}
	};


template<class K, class V> 

class HashTableSeparateChaining{
	private:
		constexpr static int DEFAULT_CAPACITY = 3; //constexpr is used to initialize static variable in a class
		constexpr static double DEFAULT_LOAD_FACTOR = 0.75;
		
		double maxLoadFactor;
		int capacity, threshold, size = 0;
		vector<vector<Entry<K, V>>> table;
		hash<K> H;
		
		
	public:
		HashTableSeparateChaining(){
			//HashTableSeparateChaining(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR);
		}
		HashTableSeparateChaining(int capacity){
			this(capacity, DEFAULT_LOAD_FACTOR);
		}
		
		HashTableSeparateChaining(int capacity, double maxLoadFactor){
			if(capacity<0){
				//throw new 
				throw invalid_argument("Illegal capacity");
			}
			if(maxLoadFactor<=0 or maxLoadFactor==DBL_MAX){
				//throw new 
				throw invalid_argument("Illegal maxLoadFactor");
			}
			
			this->maxLoadFactor = maxLoadFactor;
			this->capacity = max(DEFAULT_CAPACITY, capacity);
			threshold = (int) (this->capacity)*maxLoadFactor;
			table = vector<vector<Entry<K, V>>> (capacity);
		}
		
		int Size(){
			return size;
		}
		
		bool empty(){
			return size==0;		
		}
		
		//clear all the contents of the hash-table
		void clear(){
			for(int i=0;i<capacity;i++){
				table[i].clear();
			}
			size = 0;
		}
		
		//wheather the key is in the hash table
		bool hasKey(K key){
			int bucketIndex = normalizeIndex(H(key));
			return bucketSeekEntry(bucketIndex, key) !=NULL;
		}
		
		bool containsKey(K key){
			return hasKey(key);
		}
		
		void put(K key, V value){
			insert(key, value);
		}
		
		void add(K key, V value){
			insert(key, value);
		}
		
		void insert(K key, V value){
			Entry<K, V> newEntry(key, value);
			//cout<<newEntry.hash<<endl;
			int bucketIndex = normalizeIndex(newEntry.hash);
			cout<<bucketIndex<<endl;
			bucketInsertEntry(bucketIndex, newEntry);
		}
		
		//get key's value 
		V* get(K key){
			int bucketIndex = normalizeIndex(H(key));
			Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);
			if(entry!=NULL) return entry->value;
			return NULL;
		}
		
		//remove key and return key's value
		V* remove(K key){
			int bucketIndex = normalizeIndex(H(key));
			return bucketRemoveEntry(bucketIndex, key);
		}
		
		// list of key in the hash table
		vector<K> keys(){
			
			vector<K> keys(Size());
			for(auto& bucket: table){
				if(bucket!=NULL){
					for(auto& entry : bucket){
						keys.push_back(entry.key);
					}
				}
			}
			
			return keys;
		}
		
		
		//list of values in the hash table
		vector<V> values(){
			
			vector<V> values(Size());
			for(auto& bucket: table){
				if(bucket!=NULL){
					for(auto& entry: bucket){
						values.push_back(entry.value);
					}
				}
			}
			
			return values;
		}
		
		void showAll(){
			cout<<"{"<<endl;
			for(int i=0;i<capacity;i++){
				if(table[i].size()){
					for(auto& entry : table[i]){
						//std::cout<< "entry" <<endl;
						std::cout << "\t" << entry << "\n";
					}
				}
			}
			cout<<"}"<<endl;
		}
	
	private:
		//converts a hash value to an index
		//basically removing negative sign(sign bit)
		//placing it in domain [0, capacity)
		int normalizeIndex(int key){
			return (key & 0x7FFFFFFF)%capacity;
		}
		
		//remove an entry from  given bucket if exists
		V* bucketRemoveEntry(int bucketIndex, K key){
			Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);
			
			
			if(entry!=NULL){
				vector<Entry<K, V>> &links = table[bucketIndex];
				auto& nodeToErase = find(links.begin(), links.end(), *entry);
				links.erase(nodeToErase);
				size--;
				return &(entry->value);
			}
			else return NULL;
		}
		
		
		//insert an entry in a given bucket only if the entry doesn't
		//already exist in the given bucket
		//but if it exits just update it
		void bucketInsertEntry(int bucketIndex, Entry<K, V> entry){
			cout<<&table[bucketIndex]<<endl;
			vector<Entry<K, V>> &bucket = table[bucketIndex];
			Entry<K, V> *existentEntry = bucketSeekEntry(bucketIndex, entry.key);
			
			if(existentEntry!=NULL){
				existentEntry->value = entry.value;
			}
			else {
				bucket.push_back(entry);
				if(size++>threshold) resizeTable();
			}
		}
		
		//finds and returns a particular entry in a given bucket
		//if it exists
		//else return null
		Entry<K, V>* bucketSeekEntry(int bucketIndex, K key){
			//cout<<bucketIndex<<" "<<key<<endl;
			//if(table[bucketIndex].empty()) return NULL;
			//cout<<"what"<<endl;
			
			//if(key==NULL) return NULL;
			vector<Entry<K, V>> bucket = table[bucketIndex];
			//if(bucket==NULL) return NULL;
			
			for(size_t i=0;i<table[bucketIndex].size();i++){
				cout<<table[bucketIndex][i]<<endl;
				Entry<K, V> *entry = &table[bucketIndex][i];
				cout<<*entry<<endl;
				if(entry->key==key){
					cout<<entry<<endl;
					return entry;
				}
			}
			
			return NULL;
		}
		
		
		//resize the table holding buckets of entries
		void resizeTable(){
			int oldCapacity = capacity;
			capacity = capacity*2;
			threshold = (int)(capacity*maxLoadFactor);
			
			vector<vector<Entry<K, V>>> newTable(capacity);
			int tableLength = oldCapacity;
			for(int i=0;i<tableLength;i++){
				if(table[i].size()){
					for(Entry<K, V> entry: table[i]){
						int bucketIndex = normalizeIndex(entry.hash);
						newTable[bucketIndex].push_back(entry);
					}
				}
				table[i].clear();
			}
			
			table = newTable;
		}
			
	};
		


int main(){
	
	HashTableSeparateChaining<std::string, std::string> map;
	map.insert("sowmik", "sarker");
	map.insert("Hash", "Table");
	
	map.showAll();
	
	
	return 0;
}
