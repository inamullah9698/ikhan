#include <iostream>
using namespace std;

const int size =10;
class Stack{
int *top;
int *array; // array is pointer here
 int check;
public:
Stack();
void push(int val);
int pop();
bool isfull();
bool isempty();

};

Stack::Stack()
{
array= new int[size]; // here we create dynamic array with array pointer 
top = NULL;
check = 0;
}

void Stack::push(int val)
{
	if(isfull())
	{
		cout << "stack is full can not push " << endl;
		return;
	}


	if(top == NULL)
	{
		top = array;
		*top = val;
		return;
	}
	
	else if(!isfull())
	{	
		top = top+1;
		*top = val;
		return;
	}

}

int Stack::pop()
{

	if(isempty())
	{

		cout << "can not pop stack is empty " << endl;
		exit(1); // exit is builtin function it terminate the program 
		
	}
	if (top == array )
	{
		int val = *top;
		top = NULL;
		return val;
		
		
	}
	if(!isempty())
	{	
		int val = *top;
		top = top-1;
		return val;
	}

}

bool Stack::isfull(){
if(top >= (array+size)-1)
{
	return true;
}
else
	return false;

}

bool Stack::isempty()
{
if(top == NULL)
{
return true;
}
return false;
}




int main()
{
	
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);
s.push(7);
s.push(8);
s.push(9);
s.push(10);  // now our stack is full we can not push more values if we do 

cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl;

cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl;
cout << s.pop() << endl; // we poped all values if we pop again function will show us error


return 0;
}
