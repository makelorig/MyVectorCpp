#include <iostream>
#define random(X,Y) X+rand()%(Y-X+1)
using namespace std;


template <typename T>
class MyVector {
private:
	int capacity = 10;
	int size = 0;
	T* array;

public:
	MyVector() {
		this->array = new T[capacity];
	}

	~MyVector() {
		delete[] array;
	}

	T& front() {
		return array[0];
	}

	T& back() {
		return array[size - 1];
	}

	T& at(int index) {
		if (index >= size || index < 0) return;
		return array[index];
	}

	bool empty() {
		if (this->size > 0) return false;
		return true;
	}

	int getSize() {
		return this->size;
	}

	void push_back(T elem) {
		increaseVector();
		this->array[this->size++] = elem;
	}

	void push_front(T elem) {
		insert(0, elem);
	}

	void insert(int index, T elem) {
		if (index >= size || index < 0) return;
		increaseVector();
		for (int i = size; i >= index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = elem;
		size++;
	}

	void clear() {
		this->capacity = 10;
		this->size = 0;
		delete[] this->array;
		this->array = new T[capacity];
	}


	void show() {
		for (int i = 0; i < size; i++) cout << array[i] << " ";
		cout << endl;
	}

	int max_size() {
		return INT_MAX;
	}

	void set(int index, T elem) {
		if (index >= size || index < 0) return;
		this->array[index] = elem;
	}

	void sort(bool reverce = false) {
		bool flag = true;
		for (int i = 0; i < this->size - 1; i++) {
			if (((reverce) ? this->array[i] < this->array[i + 1] : this->array[i] > this->array[i + 1])) {
				swap(this->array[i], this->array[i + 1]);
				flag = true;
			}
		}
	}
	class Iterator {
	private:
		T* ptr;

	public:

		Iterator(T* ptr) {
			this->ptr = ptr;
		}

		T& operator *() const {
			return *ptr;
		}

		Iterator& operator++() {
			++ptr;
			return *this;
		}

		Iterator& operator--() { 
			--ptr;
			return *this;
		}

		Iterator operator++(int) { 
			Iterator temp = *this;
			++ptr;
			return temp;
		}

		Iterator operator--(int) { 
			Iterator temp = *this;
			--ptr;
			return temp;
		}

		bool operator==(const Iterator& other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const Iterator& other) const {
			return this->ptr != other.ptr;
		}
		Iterator& operator +(int num) {
			Iterator iter = Iterator(this->ptr + num);
			return iter;
		}
		Iterator& operator -(int num) {
			Iterator iter = Iterator(this->ptr - num);
			return iter;
		}
		T& operator[](int index) {
			if (index >= size || index < 0) throw out_of_range("Index out of range");
			return array[index];
		}
	};
	typename MyVector<T>::Iterator erase(typename MyVector<T>::Iterator position) {
		if (position == this->end()) {
			throw out_of_range("Invalid operator");
			return position;
		}
		for (auto it = position; it != this->end() - 1; ++it) {
			*it = *(it + 1);
		}
		--size;
		return position;
	}

	Iterator begin() {
		return Iterator(array);
	}

	Iterator end() {
		return Iterator(array + size);
	}



private:
	void increaseVector(int count = 1) {
		if ((this->size + count) >= (this->capacity * 0.75)) {
			this->capacity *= 1.5;
			if (capacity < (size + count)) this->capacity += count;
			T* buf = new T[this->capacity];
			for (int i = 0; i < size; i++)
			{
				buf[i] = array[i];
			}
			delete[] array;
			array = buf;
		}
	}

};


int main()
{

	MyVector<int> vector;


	vector.push_back(1008);
	vector.push_back(1420);
	vector.push_back(random(1,100));
	vector.show();
	//vector.push_front(100);
	//vector.show();
	//MyVector<int>::Iterator it = vector.begin();
	//vector.erase(it);
	//vector.show();

	cout << endl;
	vector.sort();
	vector.show();

}