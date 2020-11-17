#include <bits/stdc++.h>
using namespace std;


int main(){
	int t, n, x;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//int arr[n+3];
		vector<int> vec;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			//scanf("%d",&arr[i]);
			vec.push_back(x);
		}
		
		//sort(vec.begin(), vec.end());
		
		int len = vec.size();
		
		int flag = 0;
		for(int i=0;i<len-1;i++){
			if(vec[i]!=vec[i+1]) {
				flag = 1;
				break;
			}
		}
		if(flag==0) {
			printf("-1\n");
		}
		else {
			int idx, mx = -1;
			for(int i=0;i<len-1;i++){
				if(vec[i]>vec[i+1]){
					//vec[i] = vec[i]+1;
					if(mx<vec[i]){
						mx = vec[i];
						idx = i;
					}
				}
				else if(vec[i]<vec[i+1]){
					if(mx<vec[i+1]){
						mx = vec[i+1];
						idx = i+1;
					}
				}
			}
				//	vec.erase(vec.begin() + (i+1));
					//len = vec.size();
				//}
				//else if(vec[i]<vec[i+1]){
					//idx = i+1;
					//vec[i+1]+=1;
					//vec.erase(vec.begin() + i);
					//len = vec.size();
				//} 
			//}
			cout<<idx+1<<endl; //" "<<vec.size()<<endl;
		}
		
	}
	
	
	return 0;
}
