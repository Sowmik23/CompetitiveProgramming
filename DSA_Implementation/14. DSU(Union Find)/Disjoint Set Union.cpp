#include <bits/stdc++.h>
using namespace std;


///Time: O(log n) : worst case: O(n)
///Memory: O(n)


vector<int> parent;
vector<int> Rank;


///create n single item sets
void makeSet(int n){
	for(int i=0;i<n;i++){
		parent[i] = i;
	}
}

///Find set of given item x
int find(int x){
	if(parent[x]!=x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Union(int x, int y){
	int xset = find(x);
	int yset = find(y);
	
	///if already in same set
	if(xset==yset) return;
	
	///put smaller ranked item under bigger ranked item
	if(Rank[xset] < Rank[yset]) {
		parent[xset] = yset;
	}
	else if(Rank[xset] > Rank[yset]){
		parent[yset] = xset;
	}
	else {
		///if ranks are same, then increment rank
		parent[yset] = xset;
		Rank[xset]++;
	}
}

int main(){
	
	int n, m, a, b;
	cin>>n>>m;
	
	parent = vector<int> (n); ///initialize size
	Rank = vector<int> (n, 0);
	
	makeSet(n);
	
	while(m--){
		cin>>a>>b;
		Union(a, b);
	}
	
	if(find(4)==find(0)){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	
	if(find(1)==find(0)){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	
	return 0;
}
/*input:
5 3
0 2
4 2
3 1
Output:
* Yes
* No
*/
