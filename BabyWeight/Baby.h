#pragma once
#include <string>

using namespace std;

// class that contains information related to a single name and its birth count
class Baby {
public:
	Baby() {  // default constructor
		next = nullptr;
		count = 0;
	};

	Baby(const string & n) { // constructor
		name = n;
		count = 1;
		next = nullptr;
	}

	Baby(const Baby & b)
	{
		name = b.name;
		count = b.count;
		next = nullptr;
	}

	// a "getter" method
	int addCount()
	{
		count++;
	}

	// a "getter" method
	const string & getName() {
		return name;
	}

private:
	string name;
	int count;
	Baby * next;

	friend class MedicalRecord;
};