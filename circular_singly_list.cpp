#include <iostream>
using namespace std;
class Node{
public:
	int val;
	Node *Next;
	// Node *prev;

};



class circular_singly_linked_list{
	Node* head;
	Node* current;
	int length ;
public:
	circular_singly_linked_list();
	void add(int val);
	void insert(int val,int position);
	void printlist();
	void Delete(int val);
	Node* getlast();
	void Josephus();

};

circular_singly_linked_list::circular_singly_linked_list()
{
	head = NULL;
	current = NULL;
	length = 0;
}

void circular_singly_linked_list::add(int val)
{
	Node* temp = new Node;
	if(head == NULL)
	{
		head = new Node;
		head->val = val;
		head->Next = head;
		current = head;
		length++;
		return;

	}
	
	temp->val = val;
	current->Next = temp;
	temp->Next = head;
	current = current->Next;
	length++;
	return;


}


void circular_singly_linked_list::insert(int val,int position)
{	
	
	if(head == NULL && position == 1)
	{
		head = new Node;
		head->val = val;
		head->Next = head;
		current = head;
		length++;
		return ;
	}
	
	Node *n = NULL;
	n =  getlast(); 
	Node *temp = new Node;
	if(head->Next != NULL && position == 1)
	{	
		temp->val = val ;
		temp->Next = head;
		head = temp; // set head again at first position
		n->Next = head;
		length++;
		return;
	}

	current = head;
	for(int i = 1; i < ( position-1 ); i++)
	{
		current = current->Next;
	}
	temp->val = val;
	temp->Next = current->Next;
	current->Next = temp;
	return;





}


void circular_singly_linked_list::printlist()

{
	if(head->Next == head)
	{
		cout <<"[ " << head->val << " ]";
		return;
	}

	current = head;
	cout <<"[ ";
	cout << current->val <<" ";
	current = current->Next;
	while (current != head)
	{
		cout << current->val << " ";
		current = current->Next;
	}
	cout << " ]";

}

Node* circular_singly_linked_list::getlast()
{
	current = head;
	while(current->Next != head)
	{
		current = current->Next;

	}
	return current;

}

void circular_singly_linked_list::Delete(int val)

{
	Node *temp = head->Next;
	if(length == 0)
	{
		cout << "list is empty "<< endl;
		return;

	}

	if(head->val == val && head->Next == head)
	{
		delete head;
		head = NULL;
		length--;

	}
	if(head->val == val && head->Next != head)
	{
		temp = head;
		Node* n = NULL;
		n = getlast();
		head= head->Next;
		delete temp;
		temp =NULL;
		n->Next = head;
		length--;
		return ;


	}
	current = head;
	while(current->Next != head)
	{
		
		if(temp->val == val)
		{
			current->Next= temp->Next;
			delete temp;
			temp = NULL;
			length--;

			return;
		}
		current = current->Next;
		temp = temp->Next;
	}
}
// 1,2,3,4,5

void circular_singly_linked_list::Josephus()
{
	Node *del;
	current = head;
	Node *temp = head->Next;
	while(length != 1)
	{
		for(int  i = 0; i < 2; i++)
		{
			current = current->Next;
			temp = temp->Next;
			del = temp;

		}
		current->Next = temp->Next;
		current = current->Next;
		temp = current->Next;
//		del = temp;
		cout << "I am deleted " << del->val << endl;
		cin.get();
		delete del;
		del = NULL;
		length--;
	}
	head->Next = head;
	cout << "leader is " << current->val << endl;

}




int main()
{
	circular_singly_linked_list d;
	d.add(1);
	d.add(2);
	
	d.add(3);
	d.add(4);
	
	d.add(6);
	d.add(7);
	d.add(8);
	d.add(9);
	d.add(10);
	d.printlist();
	cout << endl;
	d.insert(5,5);
	cout <<"after inserting 5 at fifth position " << endl;
	// d.printlist();

	d.Delete(5);
	cout << endl << "after deleting 5 list is " << endl;
	d.printlist();
	d.Josephus();
	d.printlist();


}








