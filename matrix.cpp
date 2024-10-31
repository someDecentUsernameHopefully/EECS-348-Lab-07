#include <cstdlib>

template <typename T>
class Matrix {
	public:

		Matrix(unsigned int width, unsigned int height) {
			this.values = malloc(sizeof(T) * width * height);
		}

		T SetValue(unsigned int i, unsigned int j, T value) {
			// Returns the old value of the entry
			T toReturn = this.GetValue(i, j);
			this.values[i * this.width + j] = value;
			return toReturn;
		}

		T GetValue(unsigned int i, unsigned int j) {
			return this.values[i * this.width + j];
		}

		~Matrix() {
			free(this.values);
		}

		unsigned int width;
		unsigned int height;
	private:
		T* values;
};