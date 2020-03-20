#include <iostream>

template<typename T>
void FillRand(T* array, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		array[i] = T (rand() % 1000) / 10;
	}
	return;
}
template<typename T>
void Print(T* array, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return;
}
template<typename T>
void Sort(T* array, const int SIZE) {
	T temp;
	for (int i = 0; i < SIZE; i++) {
		for (int c = i+1; c < SIZE; c++) {
			if (array[i] > array[c]) {
				temp = array[c];
				array[c] = array[i];
				array[i] = temp;
			}
		}
	}
	return;
}
const int ROWS = 10;
const int COLS = 10;

template<typename T>
void FillRand(T* array, const int rows, const int cols) {
	for (int i = 0; i < ROWS; i++) {
		for (int c = 0; c < COLS; c++) {
			array[i][c] = (rand() % 1000);
			array[i][c] /= 10;
		}
	}
	return;
}

template<typename T>
void Print(T* array, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int c = 0; c < cols; c++) {
			std::cout << array[i][c] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return;
}

template<typename T>
void Sort(T* array, const int ROWS, const int COLS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			for (int k = i; k < ROWS; k++) {
				for (int l = k == i ? j + 1 : 0; l < COLS; l++) {
					if (array[k][l] < array[i][j]) {
						array[i][j] = array[i][j] + array[k][l];
						array[k][l] = array[i][j] - array[k][l];
						array[i][j] = array[i][j] - array[k][l];
					}
				}
			}
		}
	}
	return;
}


void main() {
	const int SIZE = 10;
	int arrayInt[SIZE] = {};
	double arrayDb[SIZE] = {};
	int arrayToInt[ROWS][COLS] = {};
	double arrayToDb[ROWS][COLS] = {};

	FillRand(arrayInt, SIZE);
	Print(arrayInt, SIZE);
	Sort(arrayInt, SIZE);
	Print(arrayInt, SIZE);

	FillRand(arrayDb, SIZE);
	Print(arrayDb, SIZE);
	Sort(arrayDb, SIZE);
	Print(arrayDb, SIZE);

	FillRand(arrayToInt, ROWS, COLS);
	Print(arrayToInt, ROWS, COLS);
	Sort(arrayToInt, ROWS, COLS);
	Print(arrayToInt, ROWS, COLS);

	FillRand(arrayToDb, ROWS, COLS);
	Print(arrayToDb, ROWS, COLS);
	Sort(arrayToDb, ROWS, COLS);
	Print(arrayToDb, ROWS, COLS);
}