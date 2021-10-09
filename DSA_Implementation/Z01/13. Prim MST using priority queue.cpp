#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

//Time: O(ElogV)
///Need to fix error


void PrimMST(vector<pair<int, int>> prim[], int nodes){
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	vector<int> key(nodes, INF);
	vector<int> parent(nodes, -1);
	vector<bool> inMST(nodes, false);
	
	int src = 0;
	int mst_weight  =0;
	
	pq.push({0, src});
	key[src] = 0;
	
	while(!pq.empty()){
		int top = pq.top().second;
		pq.pop();
		
		if(inMST[top]==true) continue; 
		
		inMST[top] = true;
		
		for(auto& i: prim[top]){
			int v = i.first;
			int weight = i.second;
			
			if(inMST[v]==false and key[v]>weight){
				key[v] = weight;
				mst_weight+=weight;
				pq.push({key[v], v});
				parent[v] = top;
			}
		}
	}
	
	//print the edges
	cout<<"MST weight: "<<mst_weight<<endl;
	for(int i=1;i<nodes;i++){
		cout<<parent[i]<<" - "<<i<<endl;
	}
}


int main(){
	
	int nodes, edges, n1, n2, weight;
	scanf("%d%d", &nodes, &edges);
	
	vector<pair<int, int>> primMST[nodes];
	
	for(int i=0;i<edges;i++){
		scanf("%d%d%d", &n1, &n2, &weight);
		
		primMST[n1].push_back({n2, weight});
		primMST[n2].push_back({n1, weight});
	}
	
	PrimMST(primMST, nodes);
	
	
	
	return 0;
}

/*
input:
nodes, edges
n1, n2, weight

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


*/
