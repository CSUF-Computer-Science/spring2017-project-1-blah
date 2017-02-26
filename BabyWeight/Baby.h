#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
		// Heyo
	};

	Baby(string s, int w) { // constructor
		name = s;
		weight = w;
	}

	Baby & operator=(Baby & b) // Copy constructor (WHY DO THEY CALL IT A COPY CONSTRUCTOR!!!) It a damn operator overload!!!
	{
		name = b.getName();
		weight = b.getWeight();
		return *this;
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

	friend class MedicalRecord;
};