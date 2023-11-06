#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
/*
int main()
{
	cout << "case 1" << endl;
	cout << "Hello world!" << endl;
	cout << "how are you doing" << endl;
	int age(34);
	string name = "rima hanna";
	cout << "my name is " << name << ", my age is " << age << endl;

	int& referenceTo(age);
	cout << "the reference value is: " << referenceTo << endl;

	cout << endl;
	// ---------------------------------------------

	cout << "case 2" << endl;
	int a = 5;
	int b = a; //dans ce cas b est une copie de a

	a = 10;
	cout << "a = " << a << " et b = " << b << endl;
	cout << endl;
// ---------------------------------------------

	cout << "case 3" << endl;
	int c = 5;
	int& d = c; //dans ce cas d est une refernce a c

	c = 10;
	cout << "c = " << c << " et d = " << d << endl;
	cout << endl;

// ----------------------------------------------

	cout << "case 4" << endl;
	int e = 5;
	int& f = e; //dans ce cas f est une refernce a e

	e = 10;
	f = 20; // if i also modify f it will modify e
	cout << "e = " << e << " et f = " << f << endl;
	cout << endl;

// ------------------------------------------------

	cout << "case 5" << endl;
	int ageUtilizateur(0);
	cout << "quel age vous avez ?" << endl;
	cin >> ageUtilizateur; // cin will get only the first name before space
	cout << "vous avez " << ageUtilizateur << "ans" << endl;

	cin.ignore(); // we use cin.ignore so it doesn't interfere with the getline 
					//	bellow
	cout << endl;

// -------------------------------------------------

	// in case i want a string with many strings and spaces, i use getline:
	cout << "case 6" << endl;	
	cout << "ton nom utilizateur est ?" << endl;
	string nomUtilizateur("any name");
	getline(cin, nomUtilizateur);
	cout << "ur name is " << nomUtilizateur << endl;
	cout << endl;

// ------------------------------------------------

	cout << "case 7" << endl;
	int aNumber = 5;
	aNumber = 6;
	cout << "and the value will be : " << aNumber << endl;
	cout << endl;

// --------------------------------------------------
	// attention a l'incrementation le ++ ou est mis
	// if i want to increment better use ++a or a + 1
	cout << "case 8" << endl;
	int al = 5;
	int bl = 5;
	
	int cl = al++;
	int dl = ++bl;
	int el = cl + 1; // be carefull al++ won't give the same result as al + 1;

	cout << "cl = " << cl << endl; // cl will be equale to 5 won't increment
	cout << "dl = " << dl << endl; // dl will be equale to 6
	cout << "el = " << el << endl;
	cout << endl;

	// --------------------------------------------------------
	// condition
	cout << "case 9" << endl;
	bool adulte(true);

	if (adulte) // || if (adulte)
		cout << "vous etes adulte" << endl;
	cout << endl;

	// -------------------------------------------------------
	// boucle
	cout << "case 10" << endl;
	int i = 1;
	while (i <= 10)
	{
		cout << i << endl;
		++i; // i++
	}
	cout << endl;

	// -------------------------------------------------------
	// declare a variable table
	cout << "case 11" << endl;
	vector<int> table(5,3); // a table of 5 integer with the value of 3 in each
	table.push_back(8); // add an integer the 6th with the value of 8 in it 
	table.pop_back(); // we arraise the last table
	table.pop_back(); // we arraise the last table

	table.size(); // it will countain the size of the table
	cout << table.size() << endl;


	return 0;
}
*/

///////////////////////////////////////////////////////////

/*
void carre(int& a)
{
	a = a * a;
}

int main()
{
	int nombre(2);
	carre(nombre);
	carre(nombre);
	cout << nombre << endl;

	return 0;

}
*/



/////////////////////////////////////////////////////////////
/*
// write in another file
int main()
{
	string const fileName("rima@DESKTOP-NNJ596G:/Repo42/C++/C++Modules00/score.txt");
	ofstream theFlow(fileName.c_str()); // to open and write in the file

	    if(theFlow)    
    {
        theFlow << "Bonjour, je suis une phrase écrite dans un fichier." << endl;
        theFlow << 42.1337 << endl;
        int age(36);
        theFlow << "J'ai " << age << " ans." << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
	ofstream theFlow(fileName.c_str(), ios::app); //app: append to addto the file at the end of it

	////// should be in another main
	ifstream theFlow(fileName.c_str()); // to read from the file
	if(theFlow)
	{
		string line;
		getline(theFlow, line); // to read a full line
		theFlow.ignore; // to change mode from reading a string to reading a number
		// getline return a bool: true if it can't continu reading and false
		// if it can't, so if we want to read a full file we use it with a loop

		double number;
		theFlow >> number; // read a double number from the file
		theFlow.ignore; // to change mode from reading a number to reading a word

		string word;
		theFlow >> word; // read one word form the file
		theFlow.ignore; // to change mode from reading a word to reading a character

		char a;
		theFlow.get(a); // read one letter from the file and it will be stocked in the variable

		theFlow.close(theFlow); // to close the file if needed to
	}
    return 0;
}
*/


/*
*	create string:
			string nameString;
	size of the string:
			nameString.size();
	erase what is written in the string;
			nameString.erase();
	a subster of a string:
			nameString.substr(index of start, number of characters(it isn't obligatory then he will substr till the end))

*/

