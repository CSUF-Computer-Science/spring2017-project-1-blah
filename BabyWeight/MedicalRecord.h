#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

#include "Baby.h"
#include "Name.h"

using namespace std;

class MedicalRecord {
public:
	MedicalRecord()
	{
		head = nullptr;
		count = 0;
		listed = false;
		namelist = new NameList;
	}

	~MedicalRecord()
	{
		delete namelist;
		Baby * temp = head;
		while (temp != nullptr)
		{
			head = temp->next;
			delete temp;
			temp = head;
		}
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
			throw invalid_argument("Could not open file" + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName()
	{
		return namelist->getHighestCountName();
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s)
	{
		return namelist->getNameNodeCount(s); // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return count;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight()
	{
		int numLow = 0;
		Baby * temp = head;
		while (temp != nullptr)
		{
			if (temp->getWeight() < 2500)
			{
				numLow++;
			}
			temp = temp->next;
		}
		return numLow;
	}

	// $BOOBS: temporary function for me													$BOOBS
	void print()
	{
		Baby * temp = head;
		while (temp != nullptr)
		{
			cout << temp->getName() << ' ' << temp->getWeight() << endl;
			temp = temp->next;
		}
		cout << "Num of Births: " << numberOfBirths() << endl;
		cout << "Num of sophias (numberOfBabiesWithName): " << numberOfBabiesWithName("Emma") << endl;
		cout << "Most popular name: " << mostPopularName() << endl;
		cout << "Number of babies born in low weight: " << numberOfBabiesWithLowBirthWeight() << endl;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby &b) {
		// make the node and put it in the linked list
		listed = false;
		Baby * temp;
		temp = new Baby(b);
		temp->next = head;
		head = temp;
		count++;
		namelist->processName(b.name);
	}
	//$BOOBS: My variables, may tweak later													$BOOBS
	Baby * head;
	int count;
	bool listed;
	NameList * namelist;
};
