#include <bits/stdc++.h>
using namespace std;

/// Red-Black tree is a self balancing binary search tree.
/// Difference between AVL tree and Red-Black tree is: Thought AVL tree
/// is also self balanced binary search tree. For balancing we need to 
/// rotate tree. We don't know how many rotations are needed to balance
/// the tree. It maybe one or multiple rotations. But for Red-Black tree
/// it needs maximum two rotation to balance the tree.


// Searching is faster in AVL tree bacause it is strictly height balanced
// but insertion and deletion is faster in red-black tree 


// AVL tree is subset of Red-Black Tree
// but if a tree is RBT then it is not true that that would be an AVL tree

// AVL tree is strictly height balanced
// Red Black Tree is roughly height balanced

/// Properties of RBT: 
/*
 * 1. It is a self-balancing BST
 * 2. Every node is either Red or Black 
 * 3. Root is always Black
 * 4. Every leaf node which is NULL is Black
 * 5. If a node is Red then it's children's are Black
 * 6. Every path from a node to any of it's descendent NULL node has same
 *    number of black nodes.
 * 7. The height will be less than or equal to double of the shortest 
 *    depth of the tree
 */



/// Insertion in Red-Black Tree
/* => root node = black
 * => no two adjacent red nodes
 * => count number of black nodes in each path
 * 
 * i. If tree is empty, create new node as root node with color black
 * ii. If tree is not empty, create new node as leaf node with color red
 * iii. If parent of new node is black then exit.
 * iv. If parent of new node is Red, then check the color of parent's
 * 	   sibling of new node.
 * 	 a. if color is black or NULL then do suitable rotation and recolor.
 * 	 b. if color is red then recolor and also check if parent's parent of
 *      new node is not root node then recolor it and recheck.
 * 
 */ 




int main(){
	
	
	
	return 0;
}
