#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	MedicalRecord();

	~MedicalRecord();

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename);

	// return the most frequently appearing name in the text file
	string mostPopularName();

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s);

	// return the number of baby records loaded from the text file
	int numberOfBirths();

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight();

	// $BOOBS: temporary function for me													$BOOBS
	void print();

private:
	// update the data structure with information contained in Baby object
	void addEntry(const string & n, const int & w);

	//$BOOBS: My variables, may tweak later													$BOOBS
	Baby * head;
	int count;
	int countLowWeight;
};
