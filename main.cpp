#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

bool validateInput(int input);
int getScore();
void displayScore(const int arr[], int size);
int findMaxScore(const int arr[], int size);
int findMinScore(const int arr[], int size);
bool updateScore(int arr[], int size, int slotIndex, int newScore);
int countAboveThreshold(const int arr[], int size, int threshold);

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];
	int maxScore, minScore, slotOption, newScore, reqThreshold = 8, valuesAboveThreshold;
	bool scoreUpdated;

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++) {
		scores[i] = getScore();
	}
	
	displayScore(scores, CAPACITY);

	maxScore = findMaxScore(scores, CAPACITY);
	minScore = findMinScore(scores, CAPACITY);

	cout << "Max Score: " << maxScore << "\nMin Score: " << minScore << '\n' << endl;

	// Slot input validation
	while (true) {
		cout << "Want to update a score? Pick a slot!\nSlot: ";
		cin >> slotOption;
		if (validateInput(slotOption))
			break;
	}
	
	// newScore input validation
	while (true) {
		cout << "New Score: ";
		cin >> newScore;
		if (validateInput(newScore))
			break;
	}

	scoreUpdated = updateScore(scores, CAPACITY, slotOption, newScore);

	if (scoreUpdated) {
		cout << "\nScore Updated!\nSlot " << slotOption << ": " << scores[slotOption] << endl;
	}
	else {
		cout << "\nSlot " << slotOption << " out of 1-" << CAPACITY << " range, no score update!" << endl;
	}
	
	valuesAboveThreshold = countAboveThreshold(scores, CAPACITY, reqThreshold);

	cout << "\nThreshold Test\nScores above " << reqThreshold << ": " << valuesAboveThreshold << endl;

	return 0;
}

bool validateInput(int input) {
	if (!cin.fail()) {
		return true;
	}
	else {
		cout << "Not an integer!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
int getScore() {
	static int scoreIter = 1;
	int userScore;

	while (true) {
		cout << "Enter Score " << scoreIter << ": ";
		cin >> userScore;
		if (validateInput(userScore)) {
			scoreIter++;
			return userScore;
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
int countAboveThreshold(const int arr[], int size, int threshold) {
	int aboveThreshold = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] > threshold)
			aboveThreshold++;
	}

	return aboveThreshold;
}
