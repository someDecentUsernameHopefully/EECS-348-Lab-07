#include <iostream>
using namespace std;

class Matrix {
	public:

		Matrix(unsigned int size) {
			width = size;
			height = size;

			for (unsigned int i = 0; i < height * width; i++) {
				values[i] = 0;
			}
		}

		Matrix(unsigned int width, unsigned int height) {
			width = width;
			height = height;
			
			for (unsigned int i = 0; i < height * width; i++) {
				values[i] = 0;
			}
		}

		float SetValue(unsigned int i, unsigned int j, float value) {
			// Returns the old value of the entry
			float toReturn = GetValue(i, j);
			values[i * width + j] = value;
			return toReturn;
		}

		float GetValue(unsigned int i, unsigned int j) const {
			return values[i * width + j];
		}

		unsigned int Width() {
			return width;
		}

		unsigned int Height() {
			return height;
		}

		Matrix operator+(const Matrix& other) const {

			if (width != other.width || height != other.height) {
				throw "The sizes of these matrices are incompatible!";
			}

			Matrix result(width, height);
			for (unsigned int i = 0; i < height; i++) {
				for (unsigned int j = 0; j < width; j++) {
					float sum = values[i * width + j] + other.values[i * other.width + j];
					result.SetValue(i, j, sum);
				}
			}
			return result;
		}

		Matrix operator*(const Matrix& other) const {

			unsigned int dotDimension;
			if (width != other.height) {
				throw "The sizes of these matrices are incompatible!";
			}
			dotDimension = width;

			Matrix result(other.width, height);
			// Ugly O(n^3) time complexity
			for (unsigned int i = 0; i < result.height; i++) {
				for (unsigned int j = 0; j < result.width; j++) {
					float sum = 0;
					for (unsigned int k = 0; k < dotDimension; k++) {
						sum += values[k * width + j] * other.values[i * other.width + k];
					}
					result.SetValue(i, j, sum);
				}
			}
			return result;
		}

		void Print() const {
			for (unsigned int i = 0; i < height; i++) {
				for (unsigned int j = 0; j < width; j++) {
					if (j != 0) {
						std::cout << "\t";
					}
					std::cout << values[i * width + j];
				}
				std::cout << std::endl;
			}
		}
		
	protected:
		unsigned int width;
		unsigned int height;
		float values[];
};