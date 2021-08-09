#include <bits/stdc++.h>
using namespace std;

// Method-01: Just like how to solve this problem for converting
/// 				a sorted array into a balanced BST. BUt here in this
/// case it will take O(n*logn) as in linked list we can not access mid
/// value in O(1).
/// Time: O(n*logn)


// Method-02(Tricky): constructs the tree from leaves to root. 
/// The idea is to insert nodes in BST in the same order as they appear 
/// in Linked List so that the tree can be constructed in O(n) time 
/// complexity. We first count the number of nodes in the given Linked 
/// List. Let the count be n. After counting nodes, we take left n/2 
/// nodes and recursively construct the left subtree. After left subtree
/// is constructed, we allocate memory for root and link the left subtree
/// with root. Finally, we recursively construct the right subtree and 
/// link it with root.  
/// Time: O(n)


struct Node {
	int val;
	Node* next;
};


class LinkedList{
	//Node* root = NULL;

public:
	void insert(Node** head, int val){
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = NULL;
		
		if(head==NULL){
			*head = tmp;
			return;
		} 
		
		tmp->next = *head;
		*head = tmp;
	}
	
	int countListLength(Node* head){
		int cnt = 0;
		Node* curr = head;
		while(curr!=NULL){
			cnt++;
			curr = curr->next;
		}
		return cnt;
	}
		
	
	void printList(Node* head){
		cout<<"The sorted LinkedList is: ";
		Node* curr = head;
		while(curr!=NULL){
			cout<<curr->val<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}
};

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* listToBSTUtil(Node** head, int n){
	if(n<=0){
		return NULL;
	}
	
	///recursively construct left subtree
	TreeNode* left = listToBSTUtil(head, n/2);
	
	///allocate memory for root and connect root with left subtree
	TreeNode* root = new TreeNode((*head)->val);
	root->left = left;
	
	///also change head pointer of linkedlist for parent recursive call
	*head = (*head)->next;
	
	///now recursively construct right subtree and connect it with root
	root->right = listToBSTUtil(head, n-n/2-1);
	
	return root;
}

TreeNode* sortedListToBST(Node* head){
	LinkedList lst;
	int n = lst.countListLength(head);
	
	return listToBSTUtil(&head, n);
}

void preOrder(TreeNode* root){
	if(root==NULL) return ;
	cout<<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	
	LinkedList ll;
	Node* head = NULL;
	
	ll.insert(&head, 1);
	ll.insert(&head, 2);
	ll.insert(&head,3);
	
	ll.printList(head);
	
	TreeNode* root = sortedListToBST(head);
	
	//test
	cout<<"After making BST: ";
	preOrder(root);
	
	return 0;
}
