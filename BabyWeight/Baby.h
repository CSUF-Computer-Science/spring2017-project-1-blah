#pragma once
#include <string>

using namespace std;

/*
* LIST OF CHANGES:
*	1. In constructor (line 25), did the basics of assigning the passed in values into the class, respecitively.
*	2. Added copy constructor (line 30), *cough* operator overload *cough*. Basically the same as the constructor, passes in the values respectively.
*	(If you don't know what "operator overload", watch a youtube vid about it. We're expected to know them)
*	3.
*
*
*
*/


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
		return weight;
	}

	// a "getter" method
	const string & getName() {
		return name;
	}

private:
	string name;
	int weight;

	friend class MedicalRecord;
};