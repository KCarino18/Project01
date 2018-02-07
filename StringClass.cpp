/*
    NAME: Kyle Carino
    Version: 1.0.0
    Email: <ksc44@zips.uakron.edu>
*/
#include <iostream>
#include <cstring>

using namespace std;

class StringClass
{
public:
	StringClass(void);//sets to null
	StringClass(const char* input);//takes in string to create the object
	StringClass(const StringClass & S);//Copy constructor
	~StringClass(void);//Destructor

    friend bool operator < (const StringClass& S1, const StringClass& S2);
						 // overloads the < operator and are now able to compare two values
    friend ostream& operator << (ostream & OS,const StringClass &S);//able to use cout with string
    friend istream& operator >> (istream & IS,StringClass &S);//able to use cin with string
    StringClass& operator = (const StringClass& S);//sets the string equal to something else
    friend  bool operator ==(const StringClass& S1, const StringClass& S2);// checks if both strings are equal

private:
	char* nstring;
	short nlength;
};

StringClass::StringClass()
{
    nlength = 1;
    nstring = new char[nlength];
    nstring[nlength-1] = '\0';
}

StringClass::StringClass(const char *input)
{
    nlength = strlen(input)+1 ;
    nstring = new char[nlength];
    for(int i = 0; i < (nlength - 1); i++)
        {
        nstring[i] = input[i];
        }
    nstring[(nlength-1)] = NULL;
}

StringClass::StringClass(const StringClass& S)
{
    nlength = S.nlength;
    nstring = new char[nlength];
    for(int i = 0; i < (nlength - 1); i++)
        {
        nstring[i] = S.nstring[i];
        }

    if(nstring[nlength - 1] != '\0')
        {
            nstring[nlength -1] = '\0';
        }
}

StringClass::~StringClass()
{
    delete[] nstring;
}

bool operator == (const StringClass & S1, const StringClass & S2)
{
	if(S1.nlength == S2.nlength)
	{
		short counter1 = S1.nlength;
		int counter2 = 0;
		int i = 0;
		while(i != counter1)
		{
			if(S1.nstring[i] != S2.nstring[i]){counter2++;}
			i++;
		}
		cout << i << " " << counter2 << endl;
		if(counter2 != 0)
            {
                return false;
            }
		else
            {
                return true;
            }
	}
	else
        {
            return false;
        }
}

bool operator < (const StringClass& S1, const StringClass& S2)
{
	if(S1.nlength < S2.nlength)
	{
	    return true;
	}
	if ( S1.nlength == S2.nlength && S1.nstring < S2.nstring)
	{
	    return true;
	}
	return false;
}

ostream& operator <<(ostream & OS, const StringClass& S)
{
    OS << S.nstring;
    return OS;
}

istream& operator >>(istream & IS,StringClass& S)
{
    char* input = new char[100];
    IS.getline(input,100);

    int i = 0;
    while(input[i] != '\0')
    {
        i++;
    }
    S.nlength = i+1;
    delete[]S.nstring;
    S.nstring = new char[(i+1)];
    for(int j = 0; j < (i) ; j++)
    {
        S.nstring[j] = input[j];
    }
    S.nstring[i] = '\0';
    delete[]input;
    return IS;
}

StringClass& StringClass::operator =(const StringClass &S)
{
    nlength = S.nlength;
    delete[] nstring;
    nstring = new char[nlength];
    for(int i = 0 ; i < (nlength -1);i++)
    {
        nstring[i] = S.nstring[i];
    }
    nstring[(nlength -1)] = '\0';
    return *this;
}



int main ()
{
    return 0;
}

