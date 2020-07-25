#include <bits/stdc++.h>
using namespace std;

//substring search


vector<int> sort_cyclic_shifts(string const& s) {
	int n = s.size();
	const int alphabet = 256;
	
	
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	
	for(int i=0;i<n;i++) cnt[s[i]]++;
	for(int i=1;i<alphabet;i++) cnt[i] += cnt[i-1];
	for(int i=0;i<n;i++) p[--cnt[s[i]]] = i;
	
	c[p[0]] = 0;
	int classes = 1;
	for(int i=1;i<n;i++){
		if(s[p[i]]!=s[p[i-1]]) classes++;
		c[p[i]]= classes - 1;
	}
	
	
	vector<int>pn(n), cn(n);
	for(int h=0;(1<<h)<n;h++) {
		for(int i=0;i<n;i++){
			pn[i] = p[i] - (1<<h);
			if(pn[i]<0) pn[i] +=n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		
		for(int i=0;i<n;i++) cnt[c[pn[i]]]++;
		for(int i=1;i<classes;i++) cnt[i] +=cnt[i-1];
		for(int i=n-1;i>=0;i--) p[--cnt[c[pn[i]]]] = pn[i];
		
		cn[p[0]]=0;
		classes = 1;
		for(int i=1;i<n;i++){
			pair<int, int>cur = { c[p[i]], c[(p[i] + (1<<h))%n]};
			pair<int, int>prev = {c[p[i-1]], c[(p[i-1] + (1<<h))%n]};
			if(cur!=prev) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	
	return p;
}


vector<int>suffix_array_construction(string s){
	s +="$";
	vector<int> sorted_shifts = sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	
	return sorted_shifts;
}


int main(){
	string str;
	cin>>str;
	
	vector <int> k = suffix_array_construction(str);
	
	int len = k.size();
	/*
	cout<<len;
	
	for(auto i : k){
		cout<<" "<<i;
	}
	cout<<endl;
	*/
	
	int n;
	string x;
	
	cin>>n;
	while(n--){
		cin>>x;
		
		int m = x.size();
		bool flag = false;
		
		//binary search
		int low = 0, high=len-1, mid;
		while(low<=high){
			mid = (low+high)/2;
			
			char xx[m+1];
			strcpy(xx, x.c_str());
			char yy[len];
			strcpy(yy, str.c_str());
			
			int res = strncmp(xx, yy+k[mid], m);
			//cout<<res<<endl;
			
			if(res==0) {
				flag=true;
				break;
			}
			if(res>0) low = mid+1;
			else high = mid - 1;
		}
		if(flag==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}

