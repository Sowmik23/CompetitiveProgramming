#include <bits/stdc++.h>
using namespace std;


struct student{
	int roll;
	double cgpa;
	string name;
};

bool cmp(student a, student b){
	if(a.cgpa==b.cgpa){
		return a.roll<b.roll;
	}
	return a.cgpa>b.cgpa;
}


int main(){
	int n = 10;
//	student students[n]; //this is array declaration
	vector<student> students(n);  //vector declaration
	
	for(int i=0;i<10;i++){
		students[i].roll = i+1;
		students[i].cgpa = ((float(rand())/float(4.0)+0.0)*100+0.5)/100; //generate random floating number
		students[i].name = "ABC"+to_string(i+1);
	}
	
//	sort(students, students+n, cmp); //if you use array declaration
	sort(students.begin(), students.end(), cmp); //if you use vector declaration
	
	cout<<"Roll: \tName: \tCGPA: "<<endl;
	for(int i=0;i<students.size();i++){
		cout<<students[i].roll<<"\t"<<students[i].name<<"\t"<<students[i].cgpa<<endl;
	}
	
	return 0;
}
