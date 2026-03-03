#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void getQuestions() {

	string filepath = "Questions.txt";

	string line;
	ifstream ifs(filepath);
	while (getline(ifs, line))
	{
		string question = line;
	}
	ifs.close();


}


int main()
{
	getQuestions();

	

	(void)_getch;
	return 0;
}