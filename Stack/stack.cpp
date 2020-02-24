#include<iostream>
#define max 10
using namespace std;
class Stack
{
	public:
		int arr[max]; //stack of size max * 2 bytes
		int top;
	
		Stack()
		{
		  top = -1;	
		}
		
		bool isempty()
		{
			if(top == -1)
			    return true;
			else
			    return false;
		} 
		
		bool isfull()
		{
			if(top == max-1)
			    return true;
			else 
			    return false;
		}
		 
		 int pop()
			{
				if(isempty())
				{
					cout<<"\nStack is Empty!";
				}
				else
				{
							cout<<"\nElement popped : "<<arr[top];
							top = top - 1;
			  }
			}
			
			void push(int x)
			{
				if(isfull())
				{
					cout<<"\nStack is Full!";
			}
			else
			{
			
				top = top + 1;
				arr[top] = x;
				cout<<endl<<x<<" is pushed in stack\n";
			}
			}
		
};
int main(){
	              //stack works on Last In First Out principle
	Stack s;
	s.push(10);  // 10
	s.push(20);  // 10,20
	s.push(30);  // 10,20,30
	s.push(40);  // 10,20,30,40
	s.push(50);  // 10,20,30,40,50
	s.pop();     	//10,20,30,40 --> 50 is popped
	s.pop();     // 10,20,30   --> 40 is popped
	s.pop();    	 // 30 
	s.pop();     // 20
	s.pop();     //10
	s.pop();     // stack is empty(top = -1)
	return 0;
}
