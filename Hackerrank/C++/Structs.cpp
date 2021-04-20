#include <bits/stdc++.h>

using namespace std;


struct Student {
	int age;
	string first_name, last_name;
	int standard;
};



int main(){
	
	Student st;
	cin>>st.age>>st.first_name>>st.last_name>>st.standard;
	cout<<st.age<<" "<<st.first_name<<" "<<st.last_name<<" "<<st.standard<<endl;
	
	
	
	return 0;
}
