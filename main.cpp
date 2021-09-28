#include <iostream>
#include <string>
#include <utility>
#include <memory>

using namespace std;

template <typename T>
class queue {
public:
	using size_type = int;

	queue(size_type sz=16)
		: _size{ sz }
	{
		if (!sz)
			throw exception("queue의 생성자에는 0이 올수 없습니다");
		elem = new T[sz];
	}

	void enqueue(const T& new_data);
	T dequeue();

	bool isFull() const {
		return front == (reor + 1) % _size;
	}
	bool isEmpty() const {
		return front == reor;
	}
	size_type size() const {
		return _size;
	}

	~queue() {
		cout << "소멸자\n";
		delete[] elem;
	}
	
protected:
	void reserve(size_type new_size);
private:
	T* elem = nullptr;
	size_type front = 0;
	size_type reor = 0;
	size_type _size;
};

template <typename T>
void queue<T>::enqueue(const T& new_data) {
	if (isFull())
		reserve(_size * 2);
	reor = (reor + 1) % _size;
	elem[reor] = new_data;
}

template <typename T>
T queue<T>::dequeue() {
	if (isEmpty())
		throw exception(" queue is empty");
	front = (front + 1) % _size;
	return elem[front];
}

template <typename T>
void queue<T>::reserve(size_type new_size) {
	unique_ptr<T> new_elem{ new T[new_size] };
	
	size_type i = 0;
	while (!isEmpty()) {
		front = (front + 1) % _size;
		new_elem.get()[++i] = elem[front];
	}

	front = 0;
	reor = i;
	_size = new_size;
	delete[] elem;
	elem = new_elem.release();
}

int main()
try {
	queue<int> a(3);

	a.enqueue(1);
	a.enqueue(2);
	a.enqueue(3);
	
	cout << a.dequeue();
	cout << a.dequeue();
	cout << a.dequeue();
	cout << a.dequeue();
}
catch (exception e) {
	cout << e.what() << endl;
}