#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
	int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)
	int width;
	int height;

public:
	Matrix() {
		width = SIZE;
		height = SIZE;
	}
	// 1. Read values from stdin into a matrix
	void readFromStdin() {
		string fName;
		cin >> fName;
		ifstream InputFile(fName);

		string fileData;
		int i, j = 0;
		while (getline(InputFile, fileData)) {
			const char del = ' ';
			string entry;
			stringstream ss(fileData);

			while (getline(ss, entry, del)) {
				data[i][j] = stoi(entry);
				j++;
			}

			i++;
			j = 0;
		}
	}

	// 2. Display a matrix
	void display() const {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j != 0) {
					cout << "\t";
				}
				cout << data[i][j];
			}
			cout << endl;
		}
	}

	// 3. Add two matrices (operator overloading for +)
	Matrix operator+(const Matrix& other) const {
		Matrix M;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				M.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return M;
	}

	// 4. Multiply two matrices (operator overloading for *)
	Matrix operator*(const Matrix& other) const {
		Matrix M;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				M.data[i][j] = 0;
				for (int k = 0; k < width; k++) {
					M.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return M;
	}

	// 5. Compute the sum of matrix diagonal elements
	int sumOfDiagonals() const {
		if (width != height) {
			throw "There is no main diagonal of this matrix!";
		}

		int sum = 0;
		for (int i = 0; i < width; i++) {
			sum += data[i][i];
		}
		return sum;
	}

	// 6. Swap matrix rows
	void swapRows(int row1, int row2) {
		int temp;
		for (int i = 0; i < width; i++) {
			temp = data[row1][i];
			data[row1][i] = data[row2][i];
			data[row2][i] = temp;
		}
	}
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter input file for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter input file for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
