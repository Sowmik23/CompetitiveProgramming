#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int m, n;
	cin>>m>>n;
	
	double x[n][m+1], y[n];
	
	//take input
	for(int i=0;i<n;i++){
		x[i][0] = 1;
		for(int j=1;j<=m;j++){
			cin>>x[i][j];
		}
		cin>>y[i];
	}
	
	//determine x transpose x
	double XtransposeX[m+1][m+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			XtransposeX[i][j] = 0;
			
			for(int k=0;k<n;k++){
				XtransposeX[i][j]+=x[k][i]*x[k][j];
			}
		}
	}
	
	double xtx_1[m+1][m+1];
	int row[m+1];
	for(int i=0;i<=m;i++){
		row[i] = i;
		for(int j=0;j<=m;j++){
			xtx_1[i][j] = 0;
		}
		xtx_1[i][i]=1;
	}
	
	for(int i=0;i<=m;i++){
		if((i<m)&&(fabs(XtransposeX[row[i]][i])<=0.0000001)){
			for(int j=i+1;j<=m;j++){
				if(fabs(XtransposeX[row[j]][i])>0.0000001){
					int k = row[i];
					row[i] = row[j];
					row[j] = k;
					break;
				}
			}
		}
		double a = XtransposeX[row[i]][i];
		for(int j=0;j<=m;j++){
			XtransposeX[row[i]][j]/=a;
			xtx_1[row[i]][j]/=a;
		}
		XtransposeX[row[i]][i] = 1;
		for(int j=i+1;j<=m;j++){
			a = XtransposeX[row[j]][i];
			for(int k=0;k<=m;k++){
				XtransposeX[row[j]][k] -=XtransposeX[row[i]][k]*a;
				xtx_1[row[j]][k] -= xtx_1[row[i]][k]*a;
			}
		}
	}

	
	for(int i=m;i>0;i--){
		for(int j=0;j<i;j++){
			double a = XtransposeX[row[j]][i];
			for(int k=0;k<=m;k++){
				XtransposeX[row[j]][k] -=XtransposeX[row[i]][k]*a;
				xtx_1[row[j]][k] -= xtx_1[row[i]][k]*a;
			}
		}
	}
	
	double xtxxt[m+1][n];
	for(int i=0;i<=m;i++){
		for(int j=0;j<n;j++){
			xtxxt[i][j] = 0;
			for(int k=0;k<=m;k++){
				xtxxt[i][j]+=xtx_1[row[i]][k]*x[j][k];
			}
		}
	}
	
	
	double b[m+1];
	for(int i=0;i<=m;i++){
		b[i] =0;
		for(int k=0;k<n;k++){
			b[i]+=xtxxt[i][k]*y[k];
		}
	}
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		double res = b[0];
		for(int j=1;j<=m;j++){
			double a;
			cin>>a;
			res+=b[j]*a;
		}
		cout<<setprecision(3)<<fixed<<res<<endl;
	}
	
	
	
	return 0;
}
