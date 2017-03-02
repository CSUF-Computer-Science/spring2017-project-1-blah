#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		babyList = new Baby[1000000];	// The list of babies. The max amount of babies is 1,000,000
		count = 0;	// Keep track of births

	}

	// destructor
	~MedicalRecord() {
		delete[] babyList;	// Delete
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
		/*
		* Steps:
		*	1. Make two parallel arrays, the countPerName[] is respective to name[] by their index. i.e, basically the name at name[0] has a count of countPerName[0]
		*	2. Use a for loop to fill every slot in countPerName with 0, you gotta make sure it has all 0.
		*	3. We're filling the first name, it's easier to do it here and now instead of inside the loop.
		*	4. Make a variable to keep track of the number of names used up so far, here it is called numOfNames
		*	5. numOfNames is initalized with 1, instead of 0, because we filled one name at the start,
		*	6. Take a breather because it is about to get worse.
		*	7. A for loop to go through every single baby.
		*	8. In the for loop we make a bool called namePlaced = false, this will determine if the baby's name is already taken. It is used shortly after, stay tune
		*	9. A for loop to go through the names listed AT THE MOMENT, it will compare the baby's name to the names in the name[] array.
		*	10. If we find the baby's name in the name[] array, it increments the countPerName respectively.
		*	11. namePlaced is equal to true if it if found
		*	12. If the baby's name was not listed already, namePlaced *wink* *wink*, we add a new name.
		*	12a. We're at line 95.
		*	13. Add the name to the end
		*/
		string name[1000];	// The names: There can only be a max of 1000 names, it's stated in the prompt
		int countPerName[1000];	// The number of babies with name, parallel with the name[] array
		for (int i = 1; i < 1000; i++)	// Starts at 1 because the first index (0) will have one name and baby initially
		{
			countPerName[i] = 0;
		}
		name[0] = babyList[0].getName();	// First name is listed
		countPerName[0] = 1;	// One Baby with the first name, obviously
		int numOfNames = 1;		// Number of names in the name[]
		for (int i = 1; i < count; i++)	// Loops trough all babies
		{
			bool namePlaced = false;
			for (int x = 0; x < numOfNames; x++)	//This checks if the baby has his name already listed in name[]
			{
				if (babyList[i].getName() == name[x])
				{
					countPerName[x]++;	// If it is listed, we increment the count of that name
					namePlaced = true;
					break;
				}
			}
			if (namePlaced == false)	// If we didn't find the name
			{
				name[numOfNames] = babyList[i].getName();	// We write the name at the end
				countPerName[numOfNames] = 1;	// One baby with that name
				numOfNames++;	// number of names increases.
			}
		}
		int popNameIndex= 0;	// Keeps track of the popular name's index from name[]
		int popNameCount = 0;	// This keeps track of the count of the pop name
		for (int i = 0; i < numOfNames; i++)	// For loop going through all the names
		{
			if (countPerName[i] > popNameCount)	// If we find a more popular name
			{
				popNameCount = countPerName[i];	// We keep record of the new pop name
				popNameIndex = i;
			}
		}
		return name[popNameIndex]; //cout the new popular name.
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return count;	// Returns count, which kept track of the births
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {			
		int lowWeightCount = 0;	// 0 babies are below weight at the start
		for (int i = 0; i < count; i++)	// Loop going through the babylist
		{
			if (babyList[i].getWeight() < 2500)	// if we find an underweight baby, we record it
				lowWeightCount++;
		}
		return lowWeightCount; // return it
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {		// Remember the function on top, numberOfBabiesWithLowBirthWeight()? YOU MEMBER!!						
		int numBabiesWithName = 0;				// Well basically this function is the same crap, just changed the variable names and instead of checking their wieght,
		for (int i = 0; i < count; i++)			// I instead checked if their name is the same as 's'.
		{
			if (babyList[i].getName() == s)
				numBabiesWithName++;
		}
		return numBabiesWithName;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {		// Add a new baby!
		babyList[count] = b;	// Copy baby into babyList, operator overload
		count++;				// baby count increases
	}

	// VARIABLES
	Baby * babyList;	// babyList, dynamic
	int count;			// Incrementor


};