#include <bits/stdc++.h>
using namespace std;


#define MAX_LEVEL 6
const float P = 0.5;


//class Skip_List {
//public:	
	struct Node{
		int val;
		Node** forward;
		
		Node(int level, int &val){
			//cout<<level<<" "<<val<<endl;
			
			forward = new Node* [level+1];
			memset(forward, 0, sizeof(Node*)*(level+1));
			this->val = val;
		}
		
		~Node(){
			delete []forward;
		}
	};
	
	struct skiplist{
		Node* head;
		int val;
		int level;
		
		skiplist(){
			head = new Node(MAX_LEVEL, val);
			level = 0;
		}
		~skiplist(){
			delete head;
		}
		
		void insert_element(int &);
		void delete_element(int &);
		bool search_element(int &);
		void display();
	};
	
//};

float frand(){
	return (float) rand()/RAND_MAX;
}

int random_level(){
	static bool first = true;
	if(first){
		srand((unsigned) time(NULL));
		first = false;
	}
	
	int lev = (int)(log(frand())/log(1.-P));
	return lev <MAX_LEVEL ? lev : MAX_LEVEL;
}


void skiplist::insert_element(int &value){
	Node* x = head;
	Node* update[MAX_LEVEL + 1];
	memset(update, 0, sizeof(Node*)*(MAX_LEVEL+1));
	
	for(int i=level;i>=0;i--){
		while(x->forward[i]!=NULL and x->forward[i]->val<value){
			x = x->forward[i];
		}
		update[i] = x;
	}
	
	x = x->forward[0];
	if(x==NULL or x->val!=value){
		int lev = random_level();
		
		if(lev>level){
			for(int i=level+1;i<=lev;i++){
				update[i] = head;
			}
			level = lev;
		}
		
		x = new Node(lev, value);
		
		for(int i=0;i<=lev;i++){
			x->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = x;
		}
	}
}


bool skiplist::search_element(int &value){
	Node* x = head;
	for(int i=level;i>=0;i--){
		while(x->forward[i]!=NULL and x->forward[i]->val<value){
			x = x->forward[i];
		}
	}
	x = x->forward[0];
	
	return x!=NULL and x->val==value;
}

void skiplist::delete_element(int &value){
	Node* x = head;
	Node* update[MAX_LEVEL+1];
	memset(update, 0, sizeof(Node*)*(MAX_LEVEL+1));
	
	for(int i=level;i>=0;i--){
		while(x->forward[i]!=NULL and x->forward[i]->val<value){
			x = x->forward[i];
		}
		update[i] = x;
	}
	
	x = x->forward[0];
	if(x->val==value){
		for(int i=0;i<=level;i++){
			if(update[i]->forward[i]!=x) break;
			update[i]->forward[i] = x->forward[i];
		}
		
		delete x;
		while(level>0 and head->forward[level]==NULL) level--;
	}
}

void skiplist::display(){
	for(int i=level;i>=0;i--){
		const Node* x = head->forward[i];
		while(x!=NULL){
			cout<<x->val;
			x = x->forward[0];
			if(x!=NULL){
				cout<<" -> ";
			}
		}
		cout<<endl;
	}
}


int main(){
	
	skiplist sl;
	
	int n = 2;
	sl.insert_element(n);
	
	n = 3;
	sl.insert_element(n);
	n = 6;
	sl.insert_element(n);
	n = 7;
	sl.insert_element(n);
	n = 4;
	sl.insert_element(n);
	n = 5;
	sl.insert_element(n);
	
	
	sl.display();
	
	n = 1;
	sl.search_element(n)==true ? cout<<n<<" Exists." : cout<<n<<" Not Found";
	cout<<endl;
	
	n = 5;
	sl.delete_element(n);
	
	sl.display();
	
	
	return 0;
}
