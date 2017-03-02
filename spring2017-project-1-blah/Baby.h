#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
		// Heyo
	};

	Baby(string s, int w) { // constructor, takes in a name and a weight, and copies it
		name = s;
		weight = w;
	}

	Baby & operator=(Baby & b) // Operator overload to avoid shallow copy
	{
		name = b.getName();
		weight = b.getWeight();
		return *this;
	}

	// a "getter" method
	int getWeight() {
		return weight;	// returns weight
	}

	// a "getter" method
	const string & getName() {
		return name;	// Returns name
	}

private:
	// Variables
	string name;
	int weight;

	//friend class MedicalRecord;
};