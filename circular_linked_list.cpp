#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* next;
};

class linkedList
{
private:
	node* tail;
public:
	linkedList()
	{
		tail = NULL;
	}

	void display()
	{
		system("cls");
		cout << "\n--------------------------------------------------\n";
		if (!isEmpty())
		{
			node* temp = tail->next;
			do
			{
				cout << temp->data << "\t";
				temp = temp->next;
			} while (temp != tail->next);
		}
		cout << "\n--------------------------------------------------\n";
	}
	void insert(int value)
	{
		node* temp = new node;

		temp->data = value;
		tail = temp;
		temp->next = tail;
	}
	void addNodeStart(int value)
	{
		if (isEmpty())
			insert(value);
		else
		{
			node* temp = new node;

			temp->data = value;
			temp->next = tail->next;
			tail->next = temp;
		}
	}
	void addNodePos(int pos, int value)
	{
		if (pos == 1)
			addNodeStart(value);
		else if (pos == size() + 1)
			addNodeEnd(value);
		else
		{
			node* temp = new node;
			temp->data = value;
			node* pre = tail->next;
			node* cur = tail->next;

			for (int i = 1; i < pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			temp->next = cur;
			pre->next = temp;
		}
	}
	void addNodeEnd(int value)
	{
		if (isEmpty())
			insert(value);
		else
		{
			node* temp = new node;

			temp->data = value;
			temp->next = tail->next;
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNodeStart()
	{
		if (tail->next == tail)
		{
			delete (tail);
			tail = NULL;
		}
		else
		{
			node* temp = tail->next;
			tail->next = temp->next;
			delete (temp);
		}
	}
	void deleteNodePos(int pos)
	{
		if (pos == 1)
			deleteNodeStart();
		else if (pos == size())
			deleteNodeEnd();
		else
		{
			node* pre = tail->next;
			node* cur = tail->next;

			for (int i = 1; i < pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			delete (cur);
		}
	}
	void deleteNodeEnd()
	{
		if (tail->next == tail)
		{
			delete (tail);
			tail = NULL;
		}
		else
		{
			node* temp = tail->next;
			while (temp->next != tail)
			{
				temp = temp->next;
			}
			temp->next = tail->next;
			delete (tail);
			tail = temp;
		}
	}
	void search(int value)
	{
		vector<int> p;
		int position = 1;
		node* temp = tail->next;

		while (position != size() + 1)
		{
			if (temp->data == value)
				p.push_back(position);

			temp = temp->next;
			position++;
		}
		if (p.size() == 0)
			cout << "Element not found" << endl;
		else
		{
			cout << "Element is at position: ";
			while (p.size() != 0)
			{
				cout << p.front();
				if (p.size() > 1)
					cout << ", ";

				p.erase(p.begin());
			}
			cout << endl;
		}
	}
	void reverse()    
	{
		std::vector<int> r;
		node* temp = tail->next;
		do
		{
			r.push_back(temp->data);
			temp = temp->next;
		} while (temp != tail->next);

		while (r.size() != 0)
		{
			temp->data = r.back();
			r.erase(r.end() - 1);
			temp = temp->next;
		}
	}
	void clear()
	{
		while (!isEmpty())
		{
			deleteNodeStart();
		}
	}
	int size()
	{
		int count = 0;

		if (!isEmpty())
		{
			node* temp = tail->next;
			while (temp != tail)
			{
				count++;
				temp = temp->next;
			}
			count++;
		}
		return count;
	}
	bool isEmpty()
	{
		return (tail == NULL);
	}
	~linkedList()
	{
		clear();
	}
};

int main()
{
	linkedList c;
	int choice, val, pos;
	bool run = true;
	while (run)
	{
		cout << "\n1. Add element to start" << "\n2. Add element to position" << "\n3. Add element to  end" << "\n4. Delete first element";
		cout << "\n5. Delete element from position" << "\n6. Delete last element" << "\n7. Find an element" << "\n8. See list size";
		cout << "\n9. Reverse the list" << "\n10. Clear the list" << "\n11. Exit the program\n";
		cout << "Choose an action: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> val;
			c.addNodeStart(val);
			c.display();
			break;
		case 2:
			cout << "Enter the element to be inserted: ";
			cin >> val;
			cout << "Enter elements position: ";
			cin >> pos;
			if (pos < 1 || pos > c.size() + 1)
			{
				system("cls");
				cout << "Invalid position!" << endl;
			}
			else
			{
				c.addNodePos(pos, val);
				c.display();
			}
			break;
		case 3:
			cout << "Enter the element to be inserted: ";
			cin >> val;
			c.addNodeEnd(val);
			c.display();
			break;
		case 4:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				c.deleteNodeStart();
				c.display();
			}
			break;
		case 5:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				cout << "Enter position: ";
				cin >> pos;
				if (pos < 1 || pos > c.size())
				{
					system("cls");
					cout << "Invalid position!" << endl;
				}
				else
				{
					c.deleteNodePos(pos);
					c.display();
				}
			}
			break;
		case 6:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				c.deleteNodeEnd();
				c.display();
			}
			break;
		case 7:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				cout << "Enter the element to be found: ";
				cin >> val;
				c.display();
				c.search(val);
			}
			break;
		case 8:
			system("cls");
			cout << "\nList size is: " << c.size() << endl;
			break;
		case 9:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				c.reverse();
				c.display();
				cout << "List is reversed" << endl;
			}
			break;
		case 10:
			if (c.isEmpty())
			{
				system("cls");
				cout << "\nList is empty" << endl;
			}
			else
			{
				c.clear();
				c.display();
				cout << "List is cleared" << endl;
			}
			break;
		case 11:
			run = false;
			break;
		default:
			system("cls");
			cout << "\nIncorrect Choice" << endl;
		}
	}
	return 0;
}
