#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

const int N = 4;

void gui(){ // work
	cout << "Menu" << endl << endl;
	cout << "1. Input" << endl;
	cout << "2. Ouput" << endl;
	cout << "3. Multiply all of matrix by 4" << endl;
	cout << "4. Sum of primary diagonal" << endl;
	cout << "5. Max element of each col and row" << endl;
	cout << "6. Averages values of each col and row" << endl;
	cout << "7. Average square" << endl;
	cout << "8. Exit" << endl << endl;
	cout << "x. Reset" << endl;
	cout << "r. Input random" << endl;
}

void pause_clear() {
    system("pause");
    system("cls");


}

// it`s just for developer
void auto_input_plus(int a[N][N]) {
	int k = 0;
	for(int j = 0; j < N; ++j)
		for(int i = 0; i < N; ++i)
			a[i][j] = ++k;
	k = 0;
}

void input_random(int a[N][N]) { // work
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i)
			cout << a[i][j] << " ";

		for (int i = 0; i < N; ++i)
			a[i][j] = rand()/250000000;
		cout << " " << "-->" << " ";

		for (int i = 0; i < N; ++i)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void input(int a[N][N]) { // work

	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i) {
				cin >> a[i][j];
				if (!int(a[i][j]))
					exit(1); // :::::))))))
		}

	pause_clear();

	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i)
			cout << a[i][j] << " ";
	cout << endl;
	}

}

void output(int a[N][N]) { // work
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void multiply(int a[N][N]) { // work
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			a[i][j] = (a[i][j])*N;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void sum_of_diagonal(int a[N][N], int& zero) {

	for(int i = 0; i < N; ++i)//00 01 02 03
		zero += a[i][i];

	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) { //10 11 12 13
			if (j == i)
				cout << a[i][j] << " ";
			else
				cout << "0" << " ";
		}
		cout << endl;
	}
	cout << zero << endl;
	zero = 0;
}

void MaxElementOfEachColAndRow(int a[N][N], int temp_a[N][N], int zero) {
	int temp = zero;

	for(int j = 0; j < N; ++j)
		for(int i = 0; i < N; ++i)
			temp_a[i][j] = a[i][j];

	for(int k = 0; k < N; ++k)
		for(int j = 0; j < N - 1; ++j)
			for(int i = 0; i < N - 1; ++i)
				if (temp_a[i][k] > temp_a[i + 1][k]) { // 00 10 20 30
					temp = temp_a[i][k];
					temp_a[i][k] = temp_a[i + 1][k];
					temp_a[i + 1][k] = temp;
				}

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			cout << a[i][j] << " ";
		}
		cout << "(" << temp_a[N - 1][j] << ")" << endl;
	}

	cout << endl; // work

	for(int j = 0; j < N; ++j)
		for(int i = 0; i < N; ++i)
			temp_a[i][j] = a[i][j]; // array = temp_array

	cout << endl;
	//for(int j = 0; j < N; ++j) {
		//for(int i = 0; i < N; ++i) {
			//cout << temp_a[i][j] << " ";
		//}
	//cout << endl;
	//}
	cout << endl;

	for(int k = 0; k < N; ++k)
		for(int j = 0; j < N - 1; ++j)
			for(int i = 0; i < N - 1; ++i)
				if (temp_a[i][k] > temp_a[i + 1][k]) { // 00 10 20 30
					temp = temp_a[i][k];
					temp_a[i][k] = temp_a[i + 1][k];
					temp_a[i + 1][k] = temp;
				} //


	cout << endl;
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			cout << a[j][i] << " ";
		}
	cout << endl;
	}
		for(int i = 0; i < N; ++i) {
			cout << "(" << temp_a[N - 1][i] << ")";
		}
	cout << endl;
	//ГАТОВА
}

void AverageValusesOfEachColAndRow(int a[N][N]) {
	double zero = 0.0;
	cout.precision(1);

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {

			cout << a[i][j] << " ";
			zero += a[i][j];
		}
		zero = zero/N;
		cout << "(" << fixed << zero << ")" << endl;
		zero = 0.0;
	}

	cout << endl;

	double zero_a[N];
	for(int j = 0; j < N; ++j) {
			for(int i = 0; i < N; ++i) {

				cout << a[i][j] << " ";
				zero += a[j][i];
			}
			cout << endl;
			zero_a[j] = zero/N;
			zero = 0.0;
		}

	for(int i = 0; i < N; ++i)
		cout << "(" << fixed << zero_a[i] << ")  ";
	cout << endl;

}
//добавить скобки выше
void AverageSquare(int a[N][N]) {
	int sum = 0;
	for(int j = 0; j < N; ++j)
		for(int i = 0; i < N; ++i)
			sum += pow(a[i][j], 2);

	cout << sqrt(sum/N) << endl;

}

void reset(int a[N][N]) {
	for(int j = 0; j < N; ++j)
	for(int i = 0; i < N; ++i)
		a[i][j] = 0;
}

int main() {
	srand(time(NULL));
	int a[N][N] = {0}, temp_a[N][N] = {0}, zero = 0;//, clear[N][N] = {0}; // CREATE A 4X4 MATRIX
	char chose = '0';

	do {
	gui();
	cin >> chose;

	system ("cls");
	switch(chose) {
		case '1':
			input(a);
			pause_clear();
			continue;
		case '2':
			output(a);
			pause_clear();
			continue;
		case '3':
			multiply(a);
			pause_clear();
			continue;
		case '4':
			sum_of_diagonal(a, zero);
			pause_clear();
			continue;
		case '5':
			MaxElementOfEachColAndRow(a, temp_a, zero);
			pause_clear();
			continue;
		case '6':
			AverageValusesOfEachColAndRow(a);
			pause_clear();
			continue;
		case '7':
			AverageSquare(a);
			pause_clear();
			continue;
		case '8':
			exit(0);
			break;
		case 'x':
			reset(a);
			continue;
		case 'r':
			input_random(a);
			pause_clear();
			continue;
		case 'd':
			auto_input_plus(a);
			pause_clear();
			continue;
	}

	}while(chose != '8');

	getchar();
	return 0;
}
