#include <bits/stdc++.h>
using namespace std;


//Time: O(ElogE) or O(ElogV)
///Sorting takes O(ElogE)
///Union and find takes O(logV)
//So overall Time Complexity is: O(ElogE + ElogV)
///Edges can be at most V^2. So, logV and logE same

//So overall: Time: O(ElogE) or O(ElogV)

//E: Edges
//V: Vertecs/nodes

class UnionFind{
	private:
		int n;
		vector<int> parent, rank;
		
	public:
		UnionFind(int n){
			this->n = n;
			parent = vector<int> (n);
			rank = vector<int> (n, 0);
			
			for(int i=0;i<n;i++){
				parent[i] = i;
				rank[i] = 0;
			}
		}
		
		int find(int x){
			if(x!=parent[x]){
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		
		void Union(int x, int y){
			int root1 = find(x);
			int root2 = find(y);
			
			if(root1!=root2){
				if(rank[root1]<rank[root2]){
					parent[root1] = root2;
				}
				else if(rank[root1]>rank[root2]){
					parent[root2] = root1;
				}
				else {
					parent[root2] = root1;
					rank[root1]++;
				}
			}
		}
	};


class KruskalMST{
	private:
		int mst_weight = 0;
		int nodes, edges ;
		
	public:
		KruskalMST(int nodes){
			this->nodes = nodes;
			this->edges = nodes-1;
		}
		
		void calculateMST(vector<pair<int, pair<int, int>>> &kmst){
			
			UnionFind uf(nodes);
			
			sort(kmst.begin(), kmst.end());
			
			int cnt = 0;
			for(auto& i: kmst){
				int x = i.second.first;
				int y = i.second.second;
				int w = i.first;
				
				int root1 = uf.find(x);
				int root2 = uf.find(y);
				
				if(root1!=root2){
					cnt++;
					cout<<x<<" "<<y<<endl;
					mst_weight+= w;
					
					uf.Union(x, y);
					if(cnt==edges){
						cout<<"Minimum weight: "<<mst_weight<<endl;
						return;
					}
				}
			}
		}
		
	};




int main(){
	
	vector<pair<int, pair<int, int>>> kmst;
	
	int nodes, edges, node1, node2, weight;
	
	scanf("%d%d", &nodes, &edges);
	
	for(int i=0;i<edges;i++){
		scanf("%d%d%d", &node1, &node2, &weight);
		
		kmst.push_back({weight, {node1, node2}});
	}
	
	KruskalMST solve(nodes);
	
	solve.calculateMST(kmst);
	
	
	return 0;
}
/*
input:
nodes, edges
node1, node2, weight:

9 14

0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

output:
		  6 - 7
          2 - 8
          5 - 6
          0 - 1
          2 - 5
          2 - 3
          0 - 7
          3 - 4
          
          Weight of MST is 37

*/
