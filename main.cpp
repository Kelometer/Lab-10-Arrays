#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int getScore();
void displayScore(const int arr[], int size);

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++) {
		scores[i] = getScore();
	}
	
	displayScore(scores,CAPACITY);

	return 0;
}

int getScore() {
	static int scoreIter = 1;
	int userScore;
	bool validInput = false;

	while (!validInput) {
		cout << "Enter Score " << scoreIter << ": ";
		
		if (cin >> userScore) {
			validInput = true;
			scoreIter++;
			return userScore;
			cout << endl;
		}
		else {
			cout << "Not an integer. Try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	
	return 0; // dummy value
}
void displayScore(const int arr[], int size) {
	cout << left << setw(7) << "\nSlot" << setw(7) << "Score" << endl;

	for (int i = 0; i < size; i++) {
		cout << i + 1 << setw(5) << ":" << arr[i] << endl;
	}
}
