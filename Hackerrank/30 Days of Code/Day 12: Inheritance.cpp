#include <bits/stdc++.h>
using namespace std;

class Person {
	protected:
		string firstName, lastName;
		int id;
	
	public:
		Person(string firstName, string lastName, int id){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = id;
		}
		
		void printPerson(){
			cout<<"Name: "<<lastName<<", "<<firstName<<endl;
			cout<<"ID: "<<id<<endl;
		}
};

class Student : public Person {
	private:
		vector<int>testScores;
	
	public:
		Student(string firstName, string lastName, int id, vector<int> scores):
			Person(firstName, lastName, id){
			this->testScores = scores;
		}
		char calculate(){
			int sum = 0;
			int sz = testScores.size();
			for( auto i: testScores){
				//cout<<i<<endl;
				sum+=i;
			}
			sum = sum/sz;
			//cout<<"jfklsdjf "<<sum<<" jlfjslf"<<endl;
			char res= checkRange(sum, 90, 101) ? 'O' : 
				checkRange(sum, 80, 90) ? 'E':
				checkRange(sum, 70, 80) ? 'A':
				checkRange(sum, 55, 70) ? 'P':
				checkRange(sum, 40, 55) ? 'D': 'T';
			return res;
		}
	private:
		bool checkRange(int sum, int mn, int mx){
			return (sum>=mn and sum<mx);
		}
};	


int main(){
	string firstName, lastName;
	int id;
	int totalScore;
	
	cin>>firstName>>lastName>>id;
	cin>>totalScore;
	
	vector<int>scores;
	
	int x;
	for(int i=0;i<totalScore;i++){
		cin>>x;
		scores.push_back(x);
	}
	
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout<<"Grade: "<<s->calculate()<<endl;
	
	
	return 0;
}
