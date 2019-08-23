#include <iostream>
using namespace std;

struct node {
	int var;
	node* next;
	node(int x) : var(x), next(NULL) {}
};

struct list {
	node* head;
	node* tail;
	int size;

	list() { head = NULL; size = 0; tail = NULL; }
	void push_back(int x) {
		node* newNode = new node(x);

		if(!size)
		{
			tail = newNode;
			head = newNode;
			size++;
			return;
		}
		tail->next = newNode;
		tail = tail->next;
		++size;
		
	}
};

int main()
{


	return 0;
}