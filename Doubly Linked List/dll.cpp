#include<iostream>
using namespace std;
class node
{
	public:
		      int data;
		      node *next;
		      node *prev;
		      
		      node(int x)
								{
									data = x;
									next = prev = NULL;
								}
};

class dll
{
	public:
						  node *head;
								
								dll()
								{
								   head = NULL;
							 }
					
		node *createnode(int x)
		{
			node *temp = new node(x);
			return temp;
		}
		
	void insert(int s)
	{
		node *temp = createnode(s);
		if(head == NULL)
		{
			head = temp;
			head->prev = NULL;
			head->next = NULL;
		}
		else
		{
		 node *ptr = head;
		 while(ptr->next != NULL)
			{
				//q = ptr;
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->prev = ptr; 
		}
	}	
	
	int insert_at_start(int s)
	{
		node *ptr = head;  //storing  node head in ptr
		node *q = createnode(s); //creating new node q
		q->next = ptr;  //next node to q is ptr
		ptr->prev = q;  //previous node to ptr is q
		head = q;     // q is now head
	}
	void display()
	{
		node *ptr = head;
		node *q;
		cout<<"\nDisplaying List:  "<<endl;
		while(ptr != NULL)
		{
					q = ptr;
					cout<<ptr->data<<"-->";
					ptr = ptr->next;
		}
	
			cout<<"\nReverse displaying List : "<<endl;
			ptr = q;
	 	while(ptr != NULL)
			{
					cout<<ptr->data<<"-->";
					ptr = ptr->prev;
			}
 }
 
 int delete_node(int s)
	{
		
		 node *ptr,*q,*p;
		 ptr = head;
		 
		 if(ptr->data == s)  // head node to be deleted
			{
				 head = ptr->next; //next node of head is now head
				 head->prev = NULL; //making previous of current head to null
				 delete ptr;
				 return 1;
			}
		 
		 while(ptr->data != s)
			{
				q = ptr;
				ptr = ptr->next;
			}
			if(ptr->next == NULL)  //if node is present at end of list
			{
				q->next = NULL;
				ptr->prev = NULL;
				delete ptr;
				return 1;
			}
			
			p = ptr->next;  //collecting node next to the node to be deleted
		 q->next = p;    // now next node to q is p
		 p->prev = q;   //value containing prev of p is q
		 delete ptr;     //free the ptr memory location
	  return 1;
	}
	
	void update_node(int s, int d)
	{
		node *ptr = head;
		int flag = 0;
		while(ptr != NULL)
		{
			if(ptr->data == s)
			{
      ptr->data = d;
						flag = 1;
						break;		
			}	
			ptr = ptr->next;
		}
		if(flag == 0)
		     cout<<"\nNode not found!"<<endl;
		else
		     cout<<"\nNode updated successfully!"<<endl;
	}
	
	void insert_after(int s,int d)
	{
		node *p;
				node *q = createnode(d);
		node *ptr = head;
		while(ptr->data != s)
		{
			ptr = ptr->next;
		}
		p = ptr->next;

   p->prev = q;
   q->next = p;
	  ptr->next = q;
	  q->prev = ptr;
	  cout<<"\nInsertion Successful!";
	}
	
	void insert_before(int s,int d)
	{
		node *p;
				node *q = createnode(d);
		node *ptr = head;
		while(ptr->data != s)
		{
			ptr = ptr->next;
		}
		p = ptr->prev;

   q->prev = p;
   p->next = q;
	  q->next = ptr;
	  ptr->prev = q;
	  cout<<"\nInsertion Successful!";
	}
};
int main()
{
	dll d;
	int choice,n,data,source;
	do
			{
				  cout<<"\n1.Crete Doubly Linked List\n2.Display List\n3.Insert At End\n4.Insert At Start\n5.Delete Node\n6.Update Node";
				  cout<<"\n7.Insert After Particular Node\n8.Insert Before Particular Node\n0.Exit";
				  cout<<"\n\nEnter choice"<<endl;
						cin>>choice;
						switch(choice)
						{
							case 1:
								      cout<<"\nEnter number of nodes";
	             cin>>n;
	             for(int i=0; i<n; i++)
														{
															cout<<"\nEnter data of node";
															cin>>data;
															d.insert(data);
		
														}
														break;
							case 2:
								       d.display();
								       break;
							case 3:
							  	     cout<<"\nEnter the data of node to be inserted at last! : ";
															cin>>data;
															d.insert(data);
															break;
							case 4:
							        cout<<"\nEnter the data of node to be inserted at start :  ";
															cin>>data;
															d.insert_at_start(data);
															break;
							case 5:
							        cout<<"\nEnter the data of node to be deleted!";
															cin>>data;
															if(d.delete_node(data))
															    cout<<"\nNode deleted!";
															break;
															
							case 6:
							        cout<<"\nEnter old data of node and new data to update!";
															cin>>source>>data;
															d.update_node(source,data);																		   								  
															break;
							case 7:
								       cout<<"\nEnter data of node and new node to insert after!";
								       cin>>source>>data;
								       d.insert_after(source,data);
								       break;
							case 8:
							        cout<<"\nEnter data of node and new node to insert before!";
															cin>>source>>data;
															d.insert_before(source,data);
															break;
							   
						}
			}while(choice!=0);
	
		return 0;
}
