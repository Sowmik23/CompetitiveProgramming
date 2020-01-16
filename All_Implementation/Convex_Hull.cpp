#include <bits/stdc++.h>

using namespace std;


struct Point{
	int x;
	int y;
};

Point p0;


int orientation(Point p, Point q, Point r)
{
	int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	
	if(val==0) return 0; //means colinear
	
	else if(val<0) return 2; //counterclock wise
	
	else return 1; //clockwise
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


vector<Point> ConvexHull(Point points[], int n)
{
	vector<Point> result;
	
	int min_y = points[0].y;
	int min = 0;
	
	for(int i=0;i<n;i++)
	{
		//finding the bottom most point
		int y = points[i].y;
		
		//pick the bottom-most or choose the left most point in case of tie
		if((y<min_y) || ((min_y==y) && points[i].x < points[min].x))
		{
			min_y = points[i].y;
			min = i;
		}
	}
	
	//keep bottom-most point at first position
	swap(points[0], points[min]);
	
	//sort n-1 points with respect to points[0] or first point.
	//a point p1 comes before p2 in sorted output if p2 has larger polar(counterclockwise direction) angle than p1
	p0 = points[0];
	qsort(&points[1], n-1, sizeof(Point), compare);
	
	int arrSize = 1;
	for(int i=1;i<n;i++)
	{
		//when the angle of ith and (i+1)th elements are same, remove points
		while(i<n-1 && orientation(p0, points[i], points[i+1]) ==0)
		{
			i++;
		}
		points[arrSize] = points[i];
		arrSize++;
	}
	
	if(arrSize < 3) 
	{
		return result;
	}
	
	
	//create an empty stack and push first three points to it.
	stack<Point> stk;
	
	stk.push(points[0]);
	stk.push(points[1]);
	stk.push(points[2]);
	
	//for another n-3 points
	for(int i=3;i<arrSize;i++)
	{
		//keep removing top while the angle formed by points next-to-top, top and points[i] makes a non left turn
		while(orientation(secondTop(stk), stk.top(), points[i]) !=2)
		{
			stk.pop();
		}
		stk.push(points[i]);
	}
	
	//now stack has only output points 
	while(!stk.empty())
	{
		//Point p = stk.top();
		//printf("( %d , %d )\n",p.x,p.y);
		result.push_back(stk.top());
		stk.pop();
	}
	return result;
}
 
int main()
{
	int total_points,x0,y0;
	
	scanf("%d",&total_points);
	
	Point points[total_points];
	
	
	for(int i=0;i<total_points;i++){
		scanf("%d",&x0);
		scanf("%d",&y0);
		points[i].x = x0;
		points[i].y = y0;
	}
	vector<Point>ans;
	vector<Point>::iterator it;
	
	ans = ConvexHull(points, total_points);
	
	printf("Boundary points of convex hull are: \n");
	
	for(it=ans.begin(); it!=ans.end();it++)
	{
		printf("( %d , %d )\n",it->x,it->y);
	}
	
	return 0;
}

/*
 * Sample input:
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
 
* Sample Output:
( 0 , 3 )
( 4 , 4 )
( 3 , 1 )
( 0 , 0 )
 * */
/*
Input:
17
0 0
0 1
1 0
1 1
0 2
1 2
2 0
2 1
2 2
3 0
3 1
3 2
4 0
4 1
4 2
5 0
5 1
Output:
( 0 , 2 )
( 4 , 2 )
( 5 , 1 )
( 5 , 0 )
( 0 , 0 )

*/


