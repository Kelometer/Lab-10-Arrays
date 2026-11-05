#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int getScore();

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++) {
		scores[i] = getScore();
	}
	
	return 0;
}

int getScore() {
	int userScore;
	bool validInput = false;

	while (!validInput) {
		cout << "Enter Score: ";
		
		if (cin >> userScore) {
			validInput = true;
			return userScore;
			cout << endl;
		}
		else {
			cout << "Not an integer. Try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
