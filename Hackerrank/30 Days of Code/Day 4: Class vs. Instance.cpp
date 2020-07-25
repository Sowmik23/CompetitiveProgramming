#include <bits/stdc++.h>
using namespace std;


class Person {
	public:
		int age;
		Person(int initialAge);
		void amIOld();
		void yearPasses();
	};
	
	Person:: Person(int initialAge) {
		if(initialAge<0) {
			cout<<"Age is not valid, setting age to 0."<<endl;
			age = 0;
		}
		else age = initialAge;
	}
	
	void Person::amIOld(){
		if(age<13) cout<<"You are young."<<endl;
		else if(age>=13 and age<18) cout<<"You are a teenager."<<endl;
		else cout<<"You are old."<<endl;
	}
	
	void Person::yearPasses(){
		age = age + 1;
	}

int main(){
	
	int t, age;
	cin>>t;
	while(t--){
		cin>>age;
		
		Person p1(age);
		p1.amIOld();
		for(int j=0;j<3;j++) {
			p1.yearPasses();
		}
		p1.amIOld();
		cout<<endl;
	}
	
	return 0;
}
