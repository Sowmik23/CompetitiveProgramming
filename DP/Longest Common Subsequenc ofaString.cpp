#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int ans[1005][1005];

int dp(int a,int b)
{
    if(a<0 || b<0 ) return 0;
    if(ans[a][b]!=-1) return ans[a][b];

        if(str1[a]==str2[b])
        {
            return ans[a][b]=dp(a-1,b-1)+1;
        }
        return ans[a][b] = max(dp(a,b-1),dp(a-1,b));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    //printf("sfjdslkfjsdfdsff\n");
    //while(scanf("%s%s",&str1,&str2)==2)
    while(getline(cin,str1))
    {
        memset(ans,-1,sizeof(ans));

        getline(cin,str2);
        //cin>>str2;
        int l1=str1.size();
        int l2=str2.size();

        printf("%d\n",dp(l1-1,l2-1));
    }

    return 0;
}
