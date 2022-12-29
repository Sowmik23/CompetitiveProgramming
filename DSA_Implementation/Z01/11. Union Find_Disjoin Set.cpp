#include <bits/stdc++.h>
using namespace std;


class UnionFind{
	private:
		vector<int> parent;
		vector<int> rank;

		//total num of group
		int numComponents;
		//size of each components
		vector<int> sz;


	public:
		UnionFind(int n){
			parent = vector<int> (n);
			rank = vector<int> (n,0);
			sz = vector<int> (n);

			//initialize
			numComponents = n;

			for(int i=0;i<n;i++){
				parent[i] = i;
				sz[i] = 1;
			}
		}

		void Union(int x, int y){  //O(logn)
			int xset = find(x);
			int yset = find(y);

			//they are already in same set;
			if(xset==yset) return;

			//put smaller ranked item under bigger ranked item
			if(rank[xset]<rank[yset]){
				parent[xset] = yset;
				sz[yset]+=sz[xset];
			}
			else if(rank[xset]>rank[yset]){
				parent[yset] = xset;
				sz[xset]+=sz[yset];
			}
			else { //if rank are same , increment rank;
				parent[yset] = xset;
				sz[xset]+=sz[yset];
				rank[xset]++;
			}

			numComponents--;

			///another way if you want :)
			///merge smaller size component set under larger one
			/*if(sz[xset]<sz[yset]){
				sz[yset]+=sz[xset];
				parent[xset] = yset;
			}
			else {
				sz[xset]+=sz[yset]=;
				parent[yset] = xset;
			}*/
		}

		int find(int x){  //O(logn)
			if(x!=parent[x]){
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}

		bool isConnected(int x, int y){
			return find(x)==find(y);
		}

		//find the size of the group that the val contains
		int sizeOfGroup(int val){
			 return sz[find(val)];
		 }

		 int totalGroups(){
			 return numComponents;
		 }
	};


int main(){

	int m, n, a, b;
	cin>>m>>n;

	UnionFind ds(m);

	while(n--){
		cin>>a>>b;
		ds.Union(a, b);
	}

	if(ds.find(4)==ds.find(0)){
		cout<<"Yes, same set"<<endl;
	}
	else cout<<"No, different set"<<endl;

	if(ds.find(1)==ds.find(0)){
		cout<<"Yes, same set"<<endl;
	}
	else cout<<"No, different set"<<endl;

	cout<<"Size of 2: "<<ds.sizeOfGroup(2)<<endl;
	cout<<"No of groups: "<<ds.totalGroups()<<endl;

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
