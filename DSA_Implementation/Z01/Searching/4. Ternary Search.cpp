#include <bits/stdc++.h>
using namespace std;


//Time: O(log3n);
//Auxiliary Space: O(1)


// Why binary search preferred over ternary search?
/// Ternary search does more comparisons than binary search in 
/// worst case.

// Why Merge Sort divides input array in two halves, why not in three or more parts?
/// Now if you do a three-way merge, you will divide the array by 3. 
/// The difference with the previous method is twofold:

/// The depth of division is now log3n.
/// During merge, instead of comparing 2 elements, you need to find 
/// the minimum of 3 elements.
/// Time: 2 * n * log3n
/// Note that 2 is multiplied because finding the minimum of three 
/// elements consists of 2 operations.


/// Asymptotically, these two are both Θ(nlogn). 
/// However, perhaps in practice the three-way merge sort would give 
/// better performance because of its log3n. Nevertheless, since log2n 
/// for n = 1000000 is a mere 20, and log3n for the same number is 12.5,
// I doubt this optimization would be really effective unless n is
// quite large.



int ternarySearch(vector<int> &nums, int l, int r, int target){
	
	if(l<=r){
		int mid1 = l+(r-l)/3;
		int mid2 = mid1+(r-l)/3;
		
		if(nums[mid1]==target) return mid1;
		if(nums[mid2]==target) return mid2;
		
		if(nums[mid1]>target) return ternarySearch(nums, l, mid1-1, target);
		if(nums[mid2]<target) return ternarySearch(nums, mid2+1, r, target);
		
		return ternarySearch(nums, mid1+1, mid2-1, target);
	}
	return -1;
}


int main(){
	
	vector<int> nums = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int target = 55;
	
	
	int res = ternarySearch(nums, 0, nums.size()-1, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	return 0;
}
