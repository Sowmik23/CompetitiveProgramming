#include<bits/stdc++.h>
using namespace std;
int minofmax(vector<int> arr, int n, int k)
{
    int mini=1e7;
    std::deque<int>  Qi(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for ( ; i < n; ++i)
    {
           mini=min(mini,arr[Qi.front()]);
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
     mini=min(mini,arr[Qi.front()]);
     return mini;
}
int main()
{
 int n,q;
 cin>>n>>q;
 vector<int> arr(n);
 for(int i=0;i<n;i++)
    cin>>arr[i];
 while(q--)
 {
     int k;
     cin>>k;
     cout<<minofmax(arr,n,k)<<"\n";
 }
}
