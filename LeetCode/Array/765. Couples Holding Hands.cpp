#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int merge(vector<int> v, int l, int mid, int r){
        
        int n1 = mid-l+1;
        int n2 = r-mid;
        vector<int> left(n1+2), right(n2+2);
        
        for(int i=0;i<n1;i++) left[i] = v[l+i];
        for(int i=0;i<n2;i++) right[i] = v[mid+1+i];
        
        int i=0, j=0, k=l;
        int inversion = 0;
        
        while(i<n1 and j<n2){
            if(left[i]<=right[j]){
                v[k] = left[i];
                i++;
            }
            else {
                v[k] = right[j];
                j++;
                inversion += (mid-i+1);
            }
            k++;
        }
        while(i<n1){
            v[k] = left[i];
            i++;
            k++;
        }
        while(j<n2){
            v[k] = right[j];
            j++;
            k++;
        }
        
        return inversion;
    }
    
    
    int mergeSort(vector<int> v, int l, int r){
		int mid, inversion_cnt = 0;
		if(l<r){	
			mid = (l+r)/2;
	   
			inversion_cnt += mergeSort(v, l, mid);
			inversion_cnt += mergeSort(v, mid+1, r);
			inversion_cnt += merge(v, l, mid, r);
		}
		return inversion_cnt;
    }
    
    int minSwapsCouples(vector<int>& row) {
       int n = row.size();
        
        int cnt = mergeSort(row, 0, n-1); 
        printf("%d\n", cnt);
        
        return cnt;
    }
};


int main(){
	
	Solution s;
	
	vector<int> v= {1, 20, 6, 4, 5};
	
	s.minSwapsCouples(v);
	
	return 0;
}
