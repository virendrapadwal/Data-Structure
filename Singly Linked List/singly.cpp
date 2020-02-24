#include<iostream>
using namespace std;
class node{
	 public:
	 	int data;
	 	node *next;
	 	node()
			{
				data = 0;
				next = NULL;
			}
};
class sll{
	public:
	node *head;
	sll(){
		head = NULL;
	}
	
node *createnode(int d)
{

					node *temp = new node();
 				temp->data = d;
 
					return temp;
}	

	void insert(int d)
	{
		if(head == NULL)
		{
					node *ptr = createnode(d);
					head  = ptr;
					//cout<<"Head node created!";
			
		}
		else
		{
									node *ptr = head;
									while( ptr->next !=NULL)
									{
														ptr = ptr->next;
									}
									node *temp = createnode(d);
									ptr->next = temp;
		}
		
	}
	
	void display()
	{
							if(head == NULL)
							{
															cout<<"List is empty!";
							}
							else
							{
															cout<<"\nSingly Linked List :\n";
															node *root = head;
															while(root != NULL)
															{
																				cout<<root->data<<"-->";
																				root = root->next;
																}
			
								}
	}
	
	void updation(int s,int d)
	{
	  				node *ptr = head;
	  				while(ptr->data != s)
							{
								ptr = ptr->next;
							}
							ptr->data = d;
							cout<<"\nNode is successfully updated\n";
	
	}
	
	
	void insert_after(int s,int d)
	{
								node *temp = createnode(d);
		
								node *ptr = head;
								while(ptr->data != s)
								{
									
   											ptr = ptr->next;							
								}
   
   					node *t = ptr->next;
   					ptr->next = temp;
   					temp->next = t;
								cout<<"\nNode  "<<d<<" after "<<s<<" is successfully Inserted  \n";
	}
	
	void insert_before(int s,int d)
	{
		node *temp = createnode(d);
	
		if(head->data == s)
		{
									node * ptr = head;
									temp->next = ptr;
			 					head = temp; 
		}
		else
		{
		
									 		
		 									node *ptr = head;
		 									node *prev;
												while(ptr->data != s)
												{
																prev = ptr;			
   													ptr = ptr->next;
												}
					
												prev->next = temp ;
												temp->next = ptr;
	}
												cout<<"\nNode "<<d<<" before "<<s<<" is successfully Inserted  \n";
}
	
	void deletion(int s)																																								//deletion is most important part in linked list
	{
		node *prev;
				if(head->data == s)                                     //deletion of head node
				{
					  node *ptr = head;
					   head = ptr->next;
					  delete ptr;
				}	
				else 
				{
				      node *ptr = head;
				      while(ptr->data != s)
										{
											   prev = ptr;
														ptr = ptr->next;
							
										}
										if(ptr->next == NULL)      //it means node to be deleted is tail node
										{
											prev->next = NULL;
											delete ptr;
										}
										else
										{
											node *temp  = ptr->next;
											prev->next = ptr->next;
											delete ptr;
										}          
		
				}
				cout<<s<<" is Successfully Deleted!";
	}
};
int main()
{
sll s;
int choice,data,newdata;
								do
								{
									cout<<"\nSingly Linked list Operation"<<endl;
									cout<<"\n1.Creation Of List\n2.Update Node Of List\n3.Insert Node After Particular Node"<<endl;
         cout<<"4.Insert Node Before Particular Node\n5.Deletion Of Node\n6.Display List\n0.Exit"<<endl;
         cout<<"\nEnter Choice : ";
									cin>>choice;
         
         switch(choice)
									{
										case 1:
											      int n;
											      cout<<"Enter Number of Nodes"<<endl;
											      cin>>n;
											      for(int i = 0; i<n; i++)
																	{
																		cout<<"Enter data of Node\n";
																		cin>>data;
																		s.insert(data);
																	}
																	break;
																	
									case 2:
										       cout<<"\nEnter Old data of node and new data of node : \n";
										       cin>>data>>newdata;
										       s.updation(data,newdata);
									        break;
									        
									case 3:
										      cout<<"\nEnter The data of the node after which node to be inserted\n";
										      cin>>data;
										      cout<<"\nEnter the data of node to be inserted after "<<data<<" node \n";
										      cin>>newdata;
										      s.insert_after(data,newdata);
										      break;
										      
										case 4:
										      cout<<"\nEnter The data of the node before which node to be inserted\n";
										      cin>>data;
										      cout<<"\nEnter the data of node to be inserted before "<<data<<" node \n";
										      cin>>newdata;
										      s.insert_before(data,newdata);	      
										      break;
										      
										case 5:
											      cout<<"\nEnter the data of node to be deleted\n";
											      cin>>data;
											      s.deletion(data);
											      break;
											
									case 6:
																	s.display();
																	break;
																	
									default:
									 							cout<<"Invalid Output!";
																	break;																
													
									}
          
								}while(choice!=0);

return 0;
}
