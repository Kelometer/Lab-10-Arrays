#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

bool validInput(int input);
int getScore();
void displayScore(const int arr[], int size);
int findMaxScore(const int arr[], int size);
int findMinScore(const int arr[], int size);
bool updateScore(int arr[], int size, int slotIndex, int newScore);
int countAboveThreshold(const int arr[], int size, int threshold);

int main() {
	const int CAPACITY = 6;
	int scores[CAPACITY];
	int maxScore, minScore, slotOption, newScore, valuesAboveThreshold,
		reqThreshold = 8;
	bool scoreUpdated;

	cout << "Arcade Leaderboard\n" << endl;

	for (int i = 0; i < CAPACITY; i++)
		scores[i] = getScore();
	
	displayScore(scores, CAPACITY);
	
	maxScore = findMaxScore(scores, CAPACITY);
	minScore = findMinScore(scores, CAPACITY);

	cout << "Min and Max Value Test\nfindMaxScore(scores, CAPACITY) completed\nfindMinScore(scores, CAPACITY) completed\n" << endl;
	cout << "Max Score: " << maxScore << "\nMin Score: " << minScore << '\n' << endl;
	
	cout << "Update Score Test" << endl;

	// slotOption validation
	while (true) {
		cout << "Want to update a score? Pick a slot!\nSlot: ";
		cin >> slotOption;
		if (validInput(slotOption))
			break;
	}
	
	// newScore input validation
	while (true) {
		cout << "New Score: ";
		cin >> newScore;
		if (validInput(newScore))
			break;
	}

	scoreUpdated = updateScore(scores, CAPACITY, slotOption, newScore);

	cout << "\nupdateScore(scores, CAPACITY, slotOption, newScore) completed" << endl;

	if (scoreUpdated)
		cout << "\nScore Updated!\nSlot " << slotOption << ": " << scores[slotOption-1] << endl;
	
	else 
		cout << "\nSlot " << slotOption << " out of 1-" << CAPACITY << " range, no score update!" << endl;
	
	valuesAboveThreshold = countAboveThreshold(scores, CAPACITY, reqThreshold);

	cout << "\nThreshold Test\ncountAboveThreshold(scores, CAPACITY, reqThreshold = " << reqThreshold << ") completed" << endl;
	cout << "\nScores above " << reqThreshold << ": " << valuesAboveThreshold << endl;

	cout << "\nNEW Leaderboard" << endl;
	displayScore(scores, CAPACITY);

	return 0;
}

/* Checks if the last cin command failed, clears cin buffer on fail 
   Itended for use with while loops to control user input. */
bool validInput(int input) {
	if (!cin.fail()) 
		return true;
	else {
		cout << "Not an integer!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}

// gets a valid score from the user, also iterates to correctly display the slot number
int getScore() {
	static int scoreIter = 1;
	int userScore;

	while (true) {
		cout << "Enter Score " << scoreIter << ": ";
		cin >> userScore;
		if (validInput(userScore)) {
			scoreIter++;
			return userScore;
		}
	}
	
	return 0; // dummy value
}

// displays the slot number and the integer at that memory location
void displayScore(const int arr[], int size) {
	cout << left << setw(7) << "\nSlot" << setw(7) << "Score" << endl;

	for (int i = 0; i < size; i++)
		cout << i + 1 << setw(5) << ":" << arr[i] << endl;

	cout << endl;
}

// finds the maxScore using max()
int findMaxScore(const int arr[], int size) {
	int maxValue = arr[0];

	for (int i = 1; i < size; i++)
		maxValue = max(maxValue, arr[i]);

	return maxValue;
}

// finds the mixScore using min()
int findMinScore(const int arr[], int size) {
	int minValue = arr[0];

	for (int i = 1; i < size; i++) 
		minValue = min(minValue, arr[i]);

	return minValue;
}

// returns true if the requested slotIndex exists, false otherwise
bool updateScore(int arr[], int size, int slotIndex, int newScore) {
	if (slotIndex < 1 || slotIndex > size)
		return false;
	else {
		arr[slotIndex-1] = newScore;
		return true;
	}
}

// increments aboveThreshold if arr[i] is above the threshold
int countAboveThreshold(const int arr[], int size, int threshold) {
	int aboveThreshold = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] > threshold)
			aboveThreshold++;
	}

	return aboveThreshold;
}
