#include <bits/stdc++.h>

using namespace std;


struct Point{
	long long int x;
	long long int y;
	
	Point(){
		
	}
	
	Point(const int & _x, const int & _y)
	{
		x = _x;
		y = _y;
	}
	
	bool operator < (const Point &p) const {
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
};

Point p0;


int orientation(Point p, Point q, Point r)
{
	int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	
	if(val==0) return 0; //means colinear
	
	else if(val<0) return 2; //counterclock wise
	
	else return 1; //clockwise
}


//same as orientation
bool ccw(const Point &p1, const Point &p2, const Point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)>=0;
}

//it returns square of distace between points p1 and p2
int squaredDistance(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

//it swap two point
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2 ;
	p2 = temp;
}


//compare points with respcet to first point
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *) vp1;
	Point *p2 = (Point *) vp2;
	
	//find orientation
	int Orin = orientation(p0, *p1, *p2);
	if(Orin == 0)
	{
		return (squaredDistance(p0, *p2) >= squaredDistance(p0, *p1)) ? -1 : 1;
	}
	
	return (Orin == 2) ? -1 : 1;
}

//find next-to-top in stack
Point secondTop(stack<Point> &stk)
{
	Point p = stk.top();
	stk.pop();
	Point res = stk.top();
	stk.push(p);
	return res;
}


vector<Point> ConvexHull(vector<Point> &p)
{
	sort(p.begin(), p.end());
	
	int n = p.size();
	int k=0;
	
	Point H[2*n];
	
	for(int i=0;i<n;i++)
	{
		while(k>=2 && !ccw(H[k-2], H[k-1], p[i])) k--;
		H[k++] = p[i];
	}
	
	for(int i=n-2,t=k;i>=0;i--)
	{
		while(k>t && !ccw(H[k-2], H[k-1], p[i])) k--;
		H[k++] = p[i];
	}
	

	return vector<Point> (H,H+k-1);
}
 
int main()
{
	int t,total_points,x0,y0;
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&total_points);
		
		//Point points[total_points];
		
		vector<Point> p,h;
		
		char ch;
		//int j=0;
		for(int i=0;i<total_points;i++){
			scanf("%d",&x0);
			scanf("%d",&y0);
			scanf(" %c",&ch);
			if(ch=='Y')
			{
				//points[j].x = x0;
				//points[j].y = y0;
				
				//printf("%d %d",x0,y0);
				p.push_back(Point(x0,y0));
				//j++;
			}
		}
		//total_points = j;
		
		
		h = ConvexHull(p);
		
		int ll = h.size();
		printf("%d\n",ll);
		
		for(int i=0;i<ll;i++)
		{
			printf("%lld %lld\n",h[i].x,h[i].y);
		}
		
		p.clear();
		
		if(t==0) break;
	}
	return 0;
}




