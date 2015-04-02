#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void checkArgCount( int );
void readIn( ifstream &, string & );

int main( int argc, char *argv[] )
{
	try 
	{
		checkArgCount( argc );
		ifstream fin;
		fin.open( argv[1] );
		string s;
		readIn( fin, s );
		cout << s << endl;
	}
	catch ( runtime_error error )
	{
		cout << error.what() << endl;
	}
	return 0;
}

void checkArgCount( int ct )
{
	if ( ct < 2 )
		throw runtime_error( "Invalid number of arguments" );
		//if there is not a second argument, an exception is thrown
}

void readIn( ifstream &fin , string &s )
{
	string tmp;
	string sp( " " );
	fin >> s;
	fin >> tmp;
	if ( s.empty() )
		throw runtime_error( "Could not open file" );
		//if the file doesn't have any words in it and thus cannot logically be printed, an exception is thrown
	while ( !fin.eof() )
	{
		s += sp;
		s += tmp;
		fin >> tmp;
		//while the file has not ended, add a space and the next word to the string and read in a new word
	}
}
