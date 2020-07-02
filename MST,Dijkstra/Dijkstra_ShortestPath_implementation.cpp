/* When the the vertex cost positive(only) this algorithm determines 
 * shortest path between two vertex.
 * single source shortest path 
 */
 
 #include <bits/stdc++.h>
 using namespace std;

 vector<pair<int,int> >v1[100005];
 int parent[100005],dis[10005];
 
 void printpath(int a)
 {
	 if(parent[a]==-1) return ;
	 printpath(parent[a]);
	 cout<<" "<<a;
 }
 
 void bfs(int a)
 {
	 priority_queue<int,vector<int> ,greater<int> > pq;
	 pq.push(a);
	 dis[a]=0;
	 while(!pq.empty())
	 {
		 int top=pq.top();
		 pq.pop();
		 
		 vector<pair<int,int> >::iterator it;
		 for(it=v1[top].begin();it!=v1[top].end();it++)
		 {
			 int v=it->first;
			 int weight=it->second;
			 if(dis[v]>dis[top]+weight)
			 {
				 dis[v]=dis[top]+weight;
				 pq.push(v);
				 parent[v]=top;
			 }
		 }
	 }
 }
 
 int main()
 {
	 int n,m,x,y,z;
	 scanf("%d%d",&n,&m);
	 memset(dis,10000,sizeof(dis));
	 while(m--)
	 {
		 scanf("%d%d%d",&x,&y,&z);
		 v1[x].push_back({y,z});
		 v1[y].push_back({x,z});
	 }
	 
	 parent[0]=-1;   //as we determine 0 to all nodes shortest path
	 bfs(0);  //as we determine 0 to all nodes shortest path
	 
	 for(int i=0;i<n;i++)
	 {
		 cout<<0<<"->"<<i<<"	"<<dis[i]<<"	"<<0;
		 printpath(i);
		 cout<<endl;
	 }
	 
	 return 0;
 }
/* 
intput:

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

0->0	0	0
0->1	4	0 1
0->2	12	0 1 2
0->3	19	0 1 2 3
0->4	21	0 7 6 5 4
0->5	11	0 7 6 5
0->6	9	0 7 6
0->7	8	0 7
0->8	14	0 1 2 8
*/
 
 
