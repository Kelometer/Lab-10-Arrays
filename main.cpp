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
bool updateScore(int arr[], int size, int slotIndex, int newScore);

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];
	int maxScore, minScore, slotOption, newScore;

	bool validInput = false,
		scoreUpdated;

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++) {
		scores[i] = getScore();
	}
	
	displayScore(scores, CAPACITY);

	maxScore = findMaxScore(scores, CAPACITY);
	minScore = findMinScore(scores, CAPACITY);

	// Slot input validation
	while (!validInput) {
		cout << "Want to update a score? Pick a slot!\nSlot: ";
		if (cin >> slotOption) {
			validInput = true;
		}
		else {
			cout << "Not an integer!" << CAPACITY << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	
	validInput = false;
	// newScore input validation
	while (!validInput) {
		cout << "New Score: ";
		if (cin >> newScore) {
			validInput = true;
		}
		else {
			cout << "Not an integer!" << CAPACITY << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	scoreUpdated = updateScore(scores, CAPACITY, slotOption, newScore);

	if (scoreUpdated) {
		cout << "\nScore Updated!\nSlot " << slotOption << ": " << scores[slotOption] << endl;
	}
	else {
		cout << "\nSlot " << slotOption << " out of 1-" << CAPACITY << " range, no score update!" << endl;
	}

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

	cout << endl;
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
bool updateScore(int arr[], int size, int slotIndex, int newScore) {
	if (slotIndex < 1 || slotIndex > size) {
		return false;
	}
	else {
		arr[slotIndex] = newScore;
		return true;
	}
}
