#include <bits/stdc++.h>
using namespace std;


///********************** Templates in C++ ***********************


/// Idea is to pass data type as a parameter so that we don’t need to 
/// write the same code for different data types


//How do templates works?
/// Templates are expanded at compiler time. This is like macros. The 
/// difference is the compiler does type checking before template 
/// expansion. The idea is simple, source code contains only function/class
/// but compiled code may contain multiple copies of same function/class.

/// Examples of function templates are sort(), max(), min(), printArray()


//Example: Function Templates

//One function works for all data types. This would work even for user
//defined types if operator '>' is overloaded.
template <typename T>
T getMax(T a, T b){
	return a>b ? a: b;
}



//Class Templates: 
/// class templates are useful when a class defines 
/// something that is independent of the data type. Can be useful for
/// classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 

template <typename T>
class Array {
	private:
		T *ptr;
		int size;

	public:
		Array(T arr[], int sz){
			ptr = new T[sz];
			size = sz;
			for(int i=0;i<sz;i++){
				ptr[i] = arr[i];
			}
		}
		
		void print(){
			for(int i=0;i<size;i++){
				cout<<*(ptr+i)<<" ";
			}
			cout<<endl;
		}
	};

//Can there be more than one arguments to templates?
/// Yes, like normal parameters, we can pass more than one data 
/// types as arguments to templates. 

template<class T, class U>
class A {
	T a;
	U b;	
public:
	A(){
		cout<<"Constructor is invoked"<<endl;
	}
};



//Can we specify default value for template arguments?
/// Yes, like normal parameters, we can specify default 
/// arguments to templates.

template<class T, class U = char>
class B {
	T x;
	U y;
public:
	B(){
		cout<<"B constructor invoked"<<endl;
	}
};


// What is the difference between function overloading and templates? 
/// Both function overloading and templates are examples of 
/// polymorphism feature of OOP. Function overloading is used when 
/// multiple functions do similar operations, templates are used when
/// multiple functions do identical operations.


// Template specialization
/// -special behavior for a particular data type. For Example:
/// A generic sort function
template <class T>
void sort(T arr[], int size)
{
    /// code to implement Quick Sort
}
 
/// Template Specialization: A function
/// specialized for char data type
template <>
void sort<char>(char arr[], int size)
{
    /// code to implement counting sort
}

//How does template specialization work? 
/// If a specialized version is present, compiler first checks with
/// the specialized version and then the main template. Compiler first
/// checks with the most specialized version by matching the passed
/// parameter with the data type(s) specified in a specialized version.



int main(){
	
	//function templates
	cout<<getMax<int>(2, 4)<<endl;
	cout<<getMax<double>(2.9, 4.5)<<endl;
	cout<<getMax<char>('a', 'b')<<endl;
	
	
	//class templates
	int array[5] = {1, 2, 3, 4, 5};
	Array<int>a(array, 5);
	a.print();
	
	
	//multiple templates 
	A<char, char> x;
	A<int, double> y;
	
	
	//default value for templates
	B<char> x1;
	
	
	return 0;
}
