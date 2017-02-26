#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		babyList = new Baby[1000000];
		count = 0;

	}

	// destructor
	~MedicalRecord() {
		delete[] babyList;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		string name[1000];	// The names
		int countPerName[1000];	// The number of babies with name, parallel with the name[] array
		for (int i = 1; i < 1000; i++)	// Starts at 1 because the first index (0) will have one name and baby initially
		{
			countPerName[i] = 0;
		}
		name[0] = babyList[0].getName();
		countPerName[0] = 1;
		int numOfNames = 1;		// Number of names in the array.
		for (int i = 1; i < count; i++)
		{
			bool namePlaced = false;
			for (int x = 0; x < numOfNames; x++)
			{
				if (babyList[i].getName() == name[x])
				{
					countPerName[x]++;
					namePlaced = true;
				}
			}
			if (namePlaced == false)
			{
				name[numOfNames] = babyList[i].getName();
				countPerName[numOfNames] = 1;
				numOfNames++;
			}
		}
		int popNameIndex= 0;
		int popNameCount = 0;
		for (int i = 0; i < numOfNames; i++)
		{
			if (countPerName[i] > popNameCount)
			{
				popNameCount = countPerName[i];
				popNameIndex = i;
			}
		}
		return name[popNameIndex]; // TO BE COMPLETED
	}
	// return the number of baby records loaded from the text file
	int numberOfBirths() {												// Done
		return count;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {							// Done
		int lowWeightCount = 0;
		for (int i = 0; i < count; i++)
		{
			if (babyList[i].getWeight() < 2500)
				lowWeightCount++;
		}
		return lowWeightCount;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {									// Done
		int numBabiesWithName = 0;
		for (int i = 0; i < count; i++)
		{
			if (babyList[i].getName() == s)
				numBabiesWithName++;
		}
		return numBabiesWithName;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {													// Done
		babyList[count] = b;
		count++;
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	Baby * babyList;
	int count;


};