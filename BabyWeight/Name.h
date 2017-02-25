#pragma once

#include <string>
using std::string;

class NameNode
{
private:
	NameNode * next;
	string name;
	int count;

	friend class NameList;
public:
	NameNode()
	{
		next = nullptr;
	}

	NameNode(string n, NameNode * head)
	{
		next = head;
		name = n;
		count = 1;
	}

	void add()
	{
		count++;
	}

	int getCount()
	{
		return count;
	}

	string getName()
	{
		return name;
	}

};

class NameList
{
private:
	NameNode * head;
	int count;

public:
	NameList()
	{
		head = nullptr;
		count = 0;
	}

	~NameList()
	{
		NameNode * temp = head;
		while (temp != nullptr)
		{
			head = temp->next;
			delete temp;
			temp = head;
		}
	}

	void processName(const string & n)
	{
		NameNode * temp = head;
		if (temp == nullptr)
		{
			NameNode * newName = new NameNode(n, head);
			head = newName;
			count++;
		}
		else
		{
			while (temp != nullptr)
			{
				if (temp->name == n)
				{
					temp->count++;
					break;
				}
				else if (temp->next == nullptr)
				{
					NameNode * newName = new NameNode(n, head);
					head = newName;
					count++;
				}
				temp = temp->next;
			}
		}
	}

	int getNameNodeCount(const string & n)
	{
		NameNode * temp = head;
		while (temp != nullptr)
		{
			if (temp->name == n)
			{
				return temp->getCount();
			}
			temp = temp->next;
		}
		return 0;
	}

	string getHighestCountName()
	{
		NameNode * temp = head;
		NameNode * highest = head;
		while (temp != nullptr)
		{
			if (temp->count > highest->count)
			{
				highest = temp;
			}
			temp = temp->next;
		}
		return highest->getName();
	}

	int getCount()
	{
		return count;
	}
};