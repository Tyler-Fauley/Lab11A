//Lab 11

#include <iostream>
#include <string>

using namespace std;

const int ROWS = 8;
const int COLUMNS = 13;
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][COLUMNS], int column);
char D, C, B, A, X, O;
int seatNum;
char seatChar;

char seats[ROWS][COLUMNS] =
{
{'D','D','D','D','D','D','D','D','D','D','D','D',' '},
{'C','C','C','C','C','C','C','C','C','C','C','C',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ','1','1','1','1'},
{'1','2','3','4','5','6','7','8','9','0','1','2','3'},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{'B','B','B','B','B','B','B','B','B','B','B','B','B'},
{'A','A','A','A','A','A','A','A','A','A','A','A','A'},
};

int main() {
	int thisRow;
	int seatIndex;
	while (true) {
		cout << endl;
		displaySeatColumn(seats, COLUMNS);
		cout << endl;
		cout << "Enter a seat or Q to quit: ";
		cin >> seatNum >> seatChar;
		if (cin.fail()) {
			break;
		}
		if (seatNum == 13 && seatChar == 'D') {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			continue;
		}
		if (seatNum == 13 && seatChar == 'C') {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			continue;
		}
		if (seatNum > 13) {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			continue;
		}
		if (seatChar != 'A' && seatChar != 'B' && seatChar != 'C' && seatChar != 'D') {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			continue;
		}
		thisRow = findRowIndex(seatNum);
		seatIndex = findSeatIndex(seatChar);
		if (seats[seatIndex][thisRow] == 'X') {
			cout << "Seat is already taken, please choose a different seat" << endl;
		}
		seats[seatIndex][thisRow] = 'X';
	}
	return 0;
}

int findRowIndex(int thisRow) {
	return thisRow - 1;
}

int findSeatIndex(char thisSeat) {
	int seatIndex;
	if (thisSeat == 'A') {
		seatIndex = 7;
		return seatIndex;
	}
	else if (thisSeat == 'B') {
		seatIndex = 6;
		return seatIndex;
	}
	else if (thisSeat == 'C') {
		seatIndex = 1;
		return seatIndex;
	}
	else if (thisSeat == 'D') {
		seatIndex = 0;
		return seatIndex;
	}
}

void displaySeatColumn(char seats[][COLUMNS], int column) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
}
