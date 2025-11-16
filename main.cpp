#include<iostream>
using namespace std;


template <typename T>
class GenericArray {
	private:
		T* data;
		int length;
	public:
		GenericArray() {
			data = nullptr;
			length = 0;
		}

		~GenericArray() {
			delete[] data;
		}

		void addElement(T element) {
			T* newData = new T[length + 1];
			for (int i = 0; i < length; i++) {
				newData[i] = data[i];
			}
			newData[length] = element;
			delete[] data;
			data = newData;
			length++;
		}
		

		T at(int param) const{
			if (param < 0 || param >= length) {
				throw out_of_range("Index out of range");
			}
			return data[param];
		}

		int size() const {
			return length;
		}

		T sum() const {
			T total = T();
			for (int i = 0; i < length; i++) {
				total += data[i];
			}
			return total;
		}

		int max() const {
			if (length == 0) {
				throw runtime_error("Array is empty");
			}
			int maxVal = static_cast<int>(data[0]);
			for (int i = 1; i < length; i++) {
				int currentVal = static_cast<int>(data[i]);
				if (currentVal > maxVal) {
					maxVal = currentVal;
				}
			}
			return maxVal;
		}

		int min() const {
			if (length == 0) {
				throw runtime_error("Array is empty");
			}
			int minVal = static_cast<int>(data[0]);
			for (int i = 1; i < length; i++) {
				int currentVal = static_cast<int>(data[i]);
				if (currentVal < minVal) {
					minVal = currentVal;
				}
			}
			return minVal;
		}

		T* slice(T begin, T end) const{
			if(begin < 0 || end > length || begin >= end) {
				throw out_of_range("Invalid slice indices");
			}

			int newSize = end - begin;
			T* newArr = new T[newSize];

			for(int i = 0; i < newSize; i++) {
				newArr[i] = data[begin + i];
			}

			return newArr;
		}
};
	



int main() {
	GenericArray<int> int_array;

	int_array.addElement(0);
	int_array.addElement(2);
	int_array.addElement(4);
	int_array.addElement(6);
	int_array.addElement(8);

	cout << "size of array is " << int_array.size() << endl;
	cout << "sum of the array is " << int_array.sum() << endl;
	cout << "maximum and minimum of array: "
		<< int_array.max() << "   " << int_array.min() << endl;

	int* sliced_array = int_array.slice(2, 4);

	cout << "Sliced: ";
	for (int i = 0; i < 3; i++) {
		cout << sliced_array[i] << " ";
	}
	cout << endl;

	delete[] sliced_array;
	return 0;
}