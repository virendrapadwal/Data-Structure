#include<iostream>
#define max 10     
using namespace std;
class queue
{
	public:
							int arr[max];
							int front,rear;
							
							queue()
							{
												front = -1;
												rear = -1;
							}

bool isempty()
{
	if(front == -1 && rear == -1)
								return true;
	else
		    return false; 
	
}

bool isfull()
{
	if(rear == max - 1)
	  return true;
	else
    return false;
					
}

void enqueue(int x)
{
					if(isfull())
					{
						cout<<"Queue is full!";
						return;
						}
						
					 if(isempty())
						{
							front = front + 1;
							rear = rear + 1;
							arr[rear] = x;
							
						}
						else 
						{
							rear  = rear + 1;
							arr[rear] = x;
						} 
						cout<<x<<"  is pushed inside the Queue!"<<endl;
}

int dequeue()
{

if(isempty())
{
 cout<<"Queue is empty!";
	return 0;	
}
else
{
	int x = arr[front];
	front = front + 1;
	cout<<x<<" is removed from queue!"<<endl;
}

}

int count()
{
	return rear-front+1;    
}

};
int main()
{
	queue q;
	q.enqueue(30);   //30
	q.enqueue(40);   //30,40
	q.enqueue(10);   //30,40,10
	q.enqueue(9);   //30,40,10,9
	q.enqueue(8);   //30,40,10,9,8
	q.enqueue(7);   //30,40,10,9,8,7
	q.enqueue(6);   //30,40,10,9,8,7,6
	q.enqueue(5);    //30,40,10,9,8,7,6,5
	q.enqueue(4);   //30,40,10,9,8,7,6,5,4
	q.enqueue(2);   //30,40,10,9,8,7,6,5,4,2
	cout<<"count: "<<q.count()<<endl; //10
	q.dequeue();    //40,10,9,8,7,6,5,4,2
	q.dequeue();     //10,9,8,7,6,5,4,2
		cout<<"count: "<<q.count()<<endl; //8
	return 0;
	
}
