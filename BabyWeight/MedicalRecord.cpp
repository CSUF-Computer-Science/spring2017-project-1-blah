#include "MedicalRecord.h"

// Done
MedicalRecord::MedicalRecord()
{
	head = nullptr;
	count = 0;
	countLowWeight = 0;
}


// Not Started
MedicalRecord::~MedicalRecord()
{


}

// Done untouched
void MedicalRecord::buildMedicalRecordfromDatafile(string filename) {
	ifstream myfile(filename);
	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		int weight;
		while (myfile >> name >> weight) {
			// cout << name << " " << weight << endl;
			addEntry(name, weight);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file" + filename);
}

string MedicalRecord::mostPopularName()
{
	return "blah";//namelist->getHighestCountName();
}

int MedicalRecord::numberOfBabiesWithName(string s)
{
	return 2;//namelist->getNameNodeCount(s); // TO BE COMPLETED
}

//Done untouched.
int MedicalRecord::numberOfBirths() {
	return count;
}

int MedicalRecord::numberOfBabiesWithLowBirthWeight()
{
	return 0;
}

// Done, not tested.
void MedicalRecord::addEntry(const string & n, const int & w) {
	// make the node and put it in the linked list
	if (head == nullptr)
	{
		head = new Baby(n);
		count++;
	}
	else
	{
		Baby * temp = head;
		bool addedToOther = false;
		while (temp != nullptr)
		{
			if (temp->getName() == n)
			{
				temp->addCount();
				temp = nullptr;
				addedToOther = true;
			}
			temp = temp->next;
		}
		if (addedToOther == false)
		{
			temp = new Baby(n);
			temp->next = head;
			head = temp;

		}
	}
	count++;
}





void MedicalRecord::print()
{
	Baby * temp = head;
	while (temp != nullptr)
	{
		cout << temp->getName() << endl;
		temp = temp->next;
	}


	cout << "Num of Births: " << numberOfBirths() << endl;
//	cout << "Num of sophias (numberOfBabiesWithName): " << numberOfBabiesWithName("Emma") << endl;
//	cout << "Most popular name: " << mostPopularName() << endl;
//	cout << "Number of babies born in low weight: " << numberOfBabiesWithLowBirthWeight() << endl;
}