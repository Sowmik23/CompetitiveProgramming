
// You are given n activities with their start and finish times. 
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time.


#include <bits/stdc++.h>
using namespace std;

struct Activity{
	int start, finish;
};

bool comp(Activity a1, Activity a2){
	return a1.finish<a2.finish;
}

void printMaxActivities(Activity arr[], int n){
	sort(arr, arr+n, comp);

	int i = 0;
	cout<<"These activities are selected: "<<endl;
	cout<<arr[i].start<<" "<<arr[i].finish<<endl;

	for(int j=1;j<n;j++){
		if(arr[j].start>=arr[i].finish){
			cout<<arr[j].start<<" "<<arr[j].finish<<endl;
			i = j;
		}
	}
};



int main(){

	Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};

    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);


	/*///Approach: 01 (maybe better approach)
	vector<pair<int, int>> tasks;
	pair<int, int> pa;
	int n , start, end;
	cin>>n;

	for(int i=0;i<n;i++){
		scanf("%d%d", &start, &end);
		pa = make_pair(start, -1);
		tasks.push_back(pa);
		pa = make_pair(end, 1);
		tasks.push_back(pa);
	}

	sort(tasks.begin(), tasks.end());
	int mx = 0, cnt=0;
	for(auto i: tasks){
		//cout<<i.first<<" "<<i.second<<endl;
		mx = max(mx, cnt-=i.second);
	}

	cout<<mx<<endl;
	*/


	return 0;
}
/*
example test case:
7
3 7
2 4
5 8
6 9
1 11
10 12
0 3
4


ans : 3
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

ans: 4
*/
