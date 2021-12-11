

#include<iostream>
#include<string.h>
using namespace std;
#define TRUE 1                                   
#define FALSE 0                                   /0

struct node                                       
{
	int data;                                    
	struct node *next;                         
}*head;                                          

node *create()                                   
{
	node *temp=NULL,*New;                        
	int val,flag;                     
	char ans='y';                                
	flag=TRUE;                                   
	do                                           
	{
		cout<<"\n Enter the Roll Number of student: ";  
		cin>>val;
		New = new node;                         
		if(New==NULL)                          
		{
			cout<<"\n Memory not allocated";
		}
		New->data=val;                          
		New->next=NULL;                         
		if(flag==TRUE)                          
		{
			head=New;                          
			temp=head;                        
			flag=FALSE;                        
		}
		else
		{
			temp->next=New;                   
			temp=New;                          
		}
		cout<<"\n Do you want to enter more Student(y/n): ";  
		cin>>ans;
	}while(ans=='y'||ans=='Y');                  
	return head;                                 
}

void display(node *head)                          
{
	struct node*temp;                            
	temp=head;                                  
	if(temp==NULL)                             
	{
		cout<<"\n List is empty";              
		return;
	}
	while(temp!=NULL)                           
	{
		cout<<"\n"<<temp->data<<"\n";           
		temp=temp->next;                        
	}
}

int set_union(node *head,node *head1)                  
{
	node *p,*q;                                 
	int found=0,count=0;                         
	p=head;                                      
	while(p!=NULL)                               
	{
		cout<<p->data<<endl;                    
		p=p->next;                              
		count++;                                
	};
	for(q=head1;q!=NULL;q=q->next)              
	{
		found=0;                                
		for(p=head;p!=NULL;p=p->next)
		{
			if(q->data==p->data)               
			{
				found=1;                      
				break;
			}
		}
		if(found!=1)                            
		{
			cout<<q->data<<endl;              
			count++;                           
		}
	}
	return count;                                
}

void set_intersect(node *head1,node *head2)               
{
	node *p,*q;                                  
	int found=0;                                 
	for(q=head2;q!=NULL;q=q->next)              
	{
		found=0;                                
		for(p=head1;p!=NULL;p=p->next)
		{
			if(q->data==p->data)              
			{
				found=1;                      
				break;
			}
		}
		if(found==1)                            
		{
			cout<<q->data<<endl;               
		}
	}
}

void sub1(node *head1,node *head2)                
{
	node *p,*q;                                  
	int found=0;                                 
	for(p=head1;p!=NULL;p=p->next)               
	{
		found=0;                                
		for(q=head2;q!=NULL;q=q->next)
		{
			if(p->data==q->data)               
			{
				found=1;                      
				break;
			}
		}
		if(found!=1)                            
		{
			cout<<p->data<<endl;              
		}
	}
}

void sub2(node *head1,node *head2)              
{
	node *p,*q;                                  
	int found=0;                                 
	for(q=head2;q!=NULL;q=q->next)            
	{
		found=0;                                
		for(p=head1;p!=NULL;p=p->next)
		{
			if(p->data==q->data)               
			{
				found=1;                      
				break;
			}
		}
		if(found!=1)                            
		{
			cout<<q->data<<endl;               
		}
	}
}

int main()
{
	node *head,*head1;                          
	int ch,m,count;                            
	head=head1=NULL;                             
	cout<<"\nEnter the no of Students : ";       
	cin>>m;
	head=NULL;
	while(1)
	{
	     //Menu
	     cout<<"\n1 Create list of student according to their like";
	     cout<<"\n2 Display the list of students";
	     cout<<"\n3 Students like either vanilla or butterscotch";
	     cout<<"\n4 Students like both vanilla & butterscotch";
	     cout<<"\n5 Students like vanilla only";
	     cout<<"\n6 Students like only butterscotch";
	     cout<<"\n7 Students like neither vanilla nor butterscotch";
	     cout<<"\n8 Exit";
	     cout<<"\nEnter Choise:-  ";
	     cin>>ch;
	     switch(ch)
		     {
			     case 1:
			     cout<<"\nStudents like vanilla ";
			     head=create();                                    
			     cout<<"\nStudents like butterscotch ";
			     head1=create();                                   
			     break;
			
			     case 2:
			     cout<<"\nStudents who like vanilla \n";
			     display(head);                                   
			     cout<<"\nStudents who like butterscotch \n";
			     display(head1);                                   
			     break;
	
			     case 3:
			     cout<<"\n Students like ither vanilla or butterscotch \n";
			     count=set_union(head,head1);                            
			     break;
	
			     case 4:
			     cout<<"\n Students like both vanilla & butterscotch \n";
			     set_intersect(head,head1);                                
			     break;
			
			     case 5:
			     cout<<"\n Students like vanilla only \n";
			     sub1(head,head1);                                
			     break;
			
			     case 6:
			     cout<<"\n Students like butterscotch only \n";
			     sub2(head,head1);                                 
			     break;
	
			     case 7:
			     cout<<"\n Students like neither vanilla nor butterscotch=   "<<m-count;
			     break;
			
			     case 8:
			     exit(1);
			     break;

			     default:
			     cout<<"Enter right choice";
			     break;
		     }
	}
	return 0;
}
