#include <bits/stdc++.h>
using namespace std;


/* Content from : The DSA legend Abdul Bari Sir
 * 
 * 
 * Most importand and hard topic. it is useful in databases.
 * Things that are needed to understand B Tree and B+ Trees are:
 * 
 * i. Disk Structure
 * ii. How data is stored in Disk.
 * iii. What is indexing.
 * iv. What is multilevel indexing. 
 * v. M-way search trees.
 * vi. B-Trees
 * vii. Insertion and deletion in B-Trees
 * viii. B+ Trees.
 * 
 * 
 * i. Disks(logical structure) is divided into Tracks and Sectors. Intersection of tracks
 * and sectors are called blocks(for ex. 512 bytes). So any address in disk is located by
 * track no and sector no(block address).
 * 
 * For ex block size = 512 bytes.
 * so block is divided into 0.....511 bytes
 * Offset is address of particular byte.
 * So, to read each particular byte on disk you need to know track no, sector 
 * no and offset. 
 * 
 * **RAM is technology and the type of memory is main memory.
 * 
 * So, data can not be directly processed from disk. It needs to brought 
 * into main memory and then access. 
 * 
 * Organizing the data inside the main memory that is directly used by
 * program, that is data structure. 
 * 
 * And organizing the data in the disk so that it can be efficiently
 * utilized that is DBMS. 
 * 
 * 
 * Indexing: for accessing data from disk->blocks(database) quickly, we
 * need indexing. Keeping each row id and block pointer is call dense
 * indexing. 
 * 
 * Where you store index? -- also in disk, right?. So how much space the index 
 * will take?  - based on the column data type size which you indexing * number 
 * of records. 
 * 
 * So, What if index size also grows ? that means if it taks more more 
 * blocks ?
 * 
 * --ans is Multilevel indexing. it is sparse indexing. 
 * It will have one entry for one number of blocks in another index.
 * 
 * We need self managed multilevel indexing. Means if size of table increases
 * then multilevel indexing also increases and if decreases table size
 * then automatically deleted index table.
 *  
 * From this idea B Tree and B+ Tree comes. 
 * 
 * B Tree and B+ Tree are originating from M-way search tree.
 * 
 * M-way search tree: each node can have maximum M children(you studied this
 * in database course).
 * 
 * 
 * problem in M-way search tree is there is no control when inserting 
 * data. you can not insert data first node, then leaf. For ex. we need to
 * insert 10, 20 and 30 and suppose it is 10 way tree. So it will create
 * 3 node and each node have 1 value only. In this case this will take 
 * more time when searching. Like linear search.  
 * 
 * So, here problem is: there is no control when inserting data. there is
 * no guideline of creating data. 
 * 
 * B Tree:
 * So, there are some rules/guidelines for creating m-way search tree
 * and this is called B Trees.
 * 
 * So, B Trees are nothing but M-way search trees with some rules.	
 * So, what are the rules?
 * 
 * 1. Each node must cotain half of degree(degree means m-way) of 
 * children. if degree m then ceil(m/2) children must be in one node. Then
 * you can think of creating new node. Thus, you can control the
 * height of B Tree.
 * 2. Root can have minimum 2 children. 
 * 3. All leaf are at same level.  
 * 4. Creation process is bottom up.
 * 
 * So, B tree is important for creating multilevel indexing. 
 * and it has record pointer(to database) for every node. 
 * 
 * 
 * What is B+ tree?
 * -We will not have record pointer to every node. We have record
 * pointer only from leaf nodes. And every key have it's copy in 
 * leaf node. All leaf nodes are in the same level and they form a 
 * linked list. 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 





int main(){
	
	
	return 0;
}
