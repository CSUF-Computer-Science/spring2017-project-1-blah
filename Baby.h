#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
		weight = 0;
		next = nullptr;
	};

	Baby(string s, int w) { // constructor
		name = s;
		weight = w;
		next = nullptr;
	}

	Baby(const Baby & b)
	{
		name = b.name;
		weight = b.weight;
		next = nullptr;
	}

	// a "getter" method
	int getWeight() {
		return weight; // TO BE COMPLETED
	}

	// a "getter" method
	const string & getName() {
		return name; // TO BE COMPLETED
	}

private:
	string name;
	int weight;
	Baby * next;

	friend class MedicalRecord;
};