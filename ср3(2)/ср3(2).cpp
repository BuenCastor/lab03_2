#include "stdafx.h"

using namespace std;

int main() {
	int size;
	cin >> size;
	auto **matrix = new int*[size];
	for (int i = 0; i < size; ++i) {
		matrix[i] = new int[size];
	}

	srand(clock() + time(0));
	int min = -100, max = 100;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			//            cin>>matrix[i][j];
			matrix[i][j] = min + rand() % (max - min + 1);;
		}
	}

	cout << "Before sort:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\t" << endl;
	}

	int Xmin = 0, Ymin = 0;
	for (int k = 0; k < size; ++k) {
		if (matrix[k][k]<matrix[Xmin][Ymin]) {
			Xmin = k;
			Ymin = k;
		}
	}

	cout << endl << "Min element: " << matrix[Xmin][Ymin] << endl << endl;

	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (matrix[j - 1][1] > matrix[j][1]) {
				for (int k = 0; k < size; ++k) {
					int x = matrix[j - 1][k];
					matrix[j - 1][k] = matrix[j][k];
					matrix[j][k] = x;
				}
			}
		}
	}

	cout << "After sort:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\t" << endl;
	}

	for (int i = 0; i < size; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	system("pause");
}
