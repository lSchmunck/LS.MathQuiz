#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

// global variables for both funcions
string questions[100];
int qAmount = 0; //qAmount stand for "question amount" because "count" was too ambigious according to the intellisense.


void getQuestions() {

	string filepath = "Questions.txt";

	string line;
	ifstream ifs(filepath);
	while (getline(ifs, line))
	{
		//for the asking part
		questions[qAmount] = line;
		qAmount++;
	}
	ifs.close();

	
	
}

void askQuestion() {

	srand(time(NULL));
	string allResults = ""; //string to store the answers in for it to save to the QuizResults file.

	//asks the 3 random questions, and saves all answers together to the QuizResults file.
	for (int i = 0; i < 3; i++) {
		int randomNumber = rand() % qAmount;
		cout << questions[randomNumber] << " = ";

		int answer;
		cin >> answer;

		allResults += questions[randomNumber] + " = " + to_string(answer) + "\n";
	}

	string filepath = "QuizResults.txt";
	ofstream ofs(filepath);
	ofs << allResults;
	ofs.close();
}



int main()
{
	getQuestions();
	askQuestion();

	(void)_getch;
	return 0;
}