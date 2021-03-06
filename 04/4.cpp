// 4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct poly
{
	int de;
	double co;
	poly *next;
};

poly *input(int n);
void show(const poly *p);
poly *add(poly  *a, poly  *b);

int main()
{
	poly *p, *q, *result;
	p = input(3);
	q = input(2);
	result = add(p, q);
	cout << "The result is:" << endl;
	show(result->next);
    return 0;
}

// Sort doing the input process
poly *input(int n)	// n: the number of terms;
{
	poly *search, *head, *p, *end;
	head = new poly;
	end = search = head;
	int de;
	double co;

	for (int i = 0; i < n; i++)
	{
		p = new poly;
		cout << "Term " << i + 1 << ":\n";
		cout << "Please input the coefficient:";
		cin >> co;
		cout << endl;
		cout << "Please input the degree:";
		cin >> de;
		cout << endl;
		p->co = co;
		p->de = de;	
		if (i == 0)	// First term;
		{
			head->next = p;
			end = p;
			p->next = NULL;
			continue;
		}		
		if (de > head->next->de) // Put the largest one in the first place;
		{
			p->next = head->next;
			head->next = p;
			continue;
		}

		while (search != NULL)	// Traver the list;
		{		
			if (search->de == p->de)	// Merge the terms with the same degree;
			{
				search->co += p->co;
				break;
			}
			if (search->next != NULL && search->de > p->de && search->next->de < p->de)	// Put the term between;
			{
				p->next = search->next;
				search->next = p;
				break;
			}

			search = search->next;	
		}
		if (search == NULL)	// Put the smallest one in the last place;
		{
			end->next = p;
			end = p;
			p->next = NULL;
		}
		search = head;
	}
	return head;
}

void show(const poly *p)
{
	if (p->co != 0)	// First term;
	{
		if (p->co == 1) cout << " + " << "x^" << p->de;
		else
		{
			if (p->co == -1) cout << " - " << "x^" << p->de;
			else cout << p->co << "x^" << p->de;
		}
	}
	p = p->next;
	while (p != NULL)	// Other terms;
	{
		if (p->co > 0)
		{
			if (p->co == 1) cout << " + " << "x^" << p->de;
			else cout << " + " << p->co << "x^" << p->de;
		}
		if (p->co < 0)
		{
			if (p->co == -1) cout << " - " << "x^" << p->de;
			else cout << p->co << "x^" << p->de;
		}
		p = p->next;
	}
}

poly *add(poly  *a, poly  *b)
{
	poly  *c, *p;
	if (a->de > b->de)	// Choice a linked list to start with;
	{
		c = a;
		a = a->next; 
	}
	else 
	{ 
		if (a->de == b->de) 
		{
			c = a;
			c->co += b->co;
			a = a->next;
			b = b->next;
		}
		else
		{ 
			c = b; 
			b = b->next;
		}		
	}
	p = c;
	while (a != NULL && b != NULL)
	{
		if (a->de > b->de) 
		{ 
			p->next = a;
			a = a->next; 
		}
		else 
		{ 
			if (a->de == b->de)
			{
				a->co += b->co;
				p->next = a;
				a = a->next;
				b = b->next;
			}
			else
			{
				p->next = b;
				b = b->next; 
			}
			
		}
		p = p->next;
	}
	if (a == NULL) p->next = b;
	else p->next = a;
	return c;
}

