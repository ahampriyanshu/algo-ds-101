#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
} * head[100], *curr /*points to the current node*/;

/*initialize hash table i.e., head[] with null*/
void init()
{
	for (int i = 0; i < 100; i++)
		head[i] = NULL;
}

/*
* given the data and hash
* add a new Node with given data in the hash table
*/
void add(int x, int h)
{
	struct Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if (!head[h])
	{
		head[h] = temp;
		curr = head[h];
	}
	else
	{
		curr = head[h];
		while (curr->next)
			curr = curr->next;
		curr->next = temp;
	}
}

/*
* given the mod
* prints the hash table in console
*/
void display(int mod)
{
	struct Node *temp;
	int i;
	for (i = 0; i < mod; i++)
	{
		if (!head[i])
		{
			cout << "Key " << i << " is empty" << endl;
		}
		else
		{
			cout << "Key " << i << " has values = ";
			temp = head[i];
			while (temp->next)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data;
			cout << endl;
		}
	}
}

/*return hash*/
int get_hash(int x, int mod)
{
	return x % mod;
}

/*
* given the data and hash
* finds the Node in the hash table
*/
void find(int x, int h)
{
	struct Node *temp = head[h];
	if (!head[h])
	{
		cout << "Element not found";
		return;
	}
	while (temp->data != x && temp->next)
		temp = temp->next;
	if (temp->next)
		cout << "Element found";
	else
	{
		if (temp->data == x)
			cout << "Element found";
		else
			cout << "Element not found";
	}
}

int main(void)
{
	init();
	int choice, x /*buffer to store user input in each switch case*/;
	int  mod /*size of the hash table*/, h;
	cout << "Enter the size of Hash Table. = ";
	cin >> mod;
	bool loop = true;
	while (loop)
	{
		cout << endl;
		cout << "PLEASE CHOOSE -" << endl;
		cout << "1. Add element." << endl;
		cout << "2. Find element." << endl;
		cout << "3. Generate Hash." << endl;
		cout << "4. Display Hash table." << endl;
		cout << "5. Exit." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to add = ";
			cin >> x;
			h = get_hash(x, mod);
			h = fabs(h);
			add(x, h);
			break;
		case 2:
			cout << "Enter element to search = ";
			cin >> x;
			h = get_hash(x, mod);
			find(x, h);
			break;
		case 3:
			cout << "Enter element to generate hash = ";
			cin >> x;
			cout << "Hash of " << x << " is = " << get_hash(x, mod);
			break;
		case 4:
			display(mod);
			break;
		default:
			loop = false;
			break;
		}
		cout << endl;
	}
	/*add(1,&head1);
	add(2,&head1);
	add(3,&head2);
	add(5,&head1);
	display(&head1);
	display(&head2);*/
	return 0;
}