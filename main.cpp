#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int getScore();
void displayScore(const int arr[], int size);
int findMaxScore(const int arr[], int size);
int findMinScore(const int arr[], int size);

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];
	int maxScore, minScore;

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++) {
		scores[i] = getScore();
	}
	
	displayScore(scores, CAPACITY);

	maxScore = findMaxScore(scores, CAPACITY);
	minScore = findMinScore(scores, CAPACITY);

	// lab 3 test
	cout << "\nMin: " << minScore << "\nMax: " << maxScore;
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
int findMaxScore(const int arr[], int size) {
	int maxValue = arr[0];

	for (int i = 1; i < size; i++) {
		maxValue = max(maxValue, arr[i]);
	}

	return maxValue;
}
int findMinScore(const int arr[], int size) {
	int minValue = arr[0];

	for (int i = 1; i < size; i++) {
		minValue = min(minValue, arr[i]);
	}

	return minValue;
}
