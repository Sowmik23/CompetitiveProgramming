#include <bits/stdc++.h>

using namespace std;


class Student {
	private:
		int age, standard;
		string first_name, last_name;
	
	public:
		Student(){
			age = 0;
			standard = 0;
			first_name = "";
			last_name = "";
		}
		void set_age(int ag){
			age = ag;
		}
		
		void set_standard(int std){
			standard = std;
		}
		
		void set_first_name(string firstname){
			first_name = firstname;
		}
		void set_last_name(string lastname){
			last_name = lastname;
		}
		
		int get_age(){
			return age;
		}
		int get_standard(){
			return standard;
		}
		string get_first_name(){
			return first_name;
		}
		string get_last_name(){
			return last_name;
		}
		
		string to_string(){
			stringstream ss;
			char ch=',';
			ss<<age<<ch<<first_name<<ch<<last_name<<ch<<standard;
			return ss.str();
		}
};



int main(){
	
	int age, standard;
	string first_name, last_name;
	
	cin>>age>>first_name>>last_name>>standard;
	
	Student st;
	st.set_age(age);
	st.set_standard(standard);
	st.set_first_name(first_name);
	st.set_last_name(last_name);
	
	cout<<st.get_age()<<endl;
	cout<<st.get_last_name()<<", "<<st.get_first_name()<<endl;
	cout<<st.get_standard()<<endl;
	cout<<endl;
	cout<<st.to_string()<<endl;
	
	
	return 0;
}
