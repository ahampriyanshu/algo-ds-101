#include <iostream>

/*
Class DLList is Double Linked List without a sentinel node
Class Sentinel is Double Linked List using a sentinel node
If you want to know more about sentinel node, here is the explanation from Wikipedia
https://en.wikipedia.org/wiki/Sentinel_node#:~:text=The%20list%20starts%20out%20with,previous%20pointers%20point%20to%20itself.&text=In%20a%20non%2Dempty%20list,the%20tail%20of%20the%20list.

*/

/* DLL Class without a sentinel node */
template <typename T>
class DLL {
	struct Node {
		T m_data;
		Node* m_next;
		Node* m_prev;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			m_data = data;
			m_next = next;
			m_prev = prev;
		}
	};
	Node* m_front;
	Node* m_back;
public:
	DLL() {
		m_front = nullptr;
		m_back = nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~DLL();
};


template <typename T>
void DLL<T>::push_front(const T& data) {
	Node* nn = new Node(data, m_front);
	if (m_front != nullptr) {
		m_front->m_prev = nn;
	}
	else {
		m_back = nn;
	}
	m_front = nn;
}


template <typename T>
void DLL<T>::push_back(const T& data) {
	Node* nn = new Node(data, nullptr, m_back);
	if (m_back != nullptr) {
		m_back->m_next = nn;
	}
	else {
		m_front = nn;
	}
	m_back = nn;
}


template <typename T>
void DLL<T>::pop_front() {
	if (m_front != nullptr) {
		Node* rm = m_front;
		m_front = rm->m_next;
		if (m_front != nullptr) {
			m_front->m_prev = nullptr;
		}
		else {
			m_back = nullptr;
		}
		delete rm;
	}

}


template <typename T>
void DLL<T>::pop_back() {
	if (m_back != nullptr) {
		Node* rm = m_back;
		m_back = rm->m_prev;
		if (m_back != nullptr) {
			m_back->m_next = nullptr;
		}
		else {
			m_front = nullptr;
		}
		delete rm;
	}

}


template <typename T>
void DLL<T>::print() const {
	Node* curr = m_front;
	while (curr != nullptr) {
		std::cout << curr->m_data << " ";
		curr = curr->m_next;
	}
	if (!m_front) {
		std::cout << "empty list";
	}
	std::cout << std::endl;
}


template <typename T>
void DLL<T>::reversePrint() const {
	Node* curr = m_back;
	while (curr != nullptr) {
		std::cout << curr->m_data << " ";
		curr = curr->m_prev;
	}
	if (!m_back) {
		std::cout << "empty list";
	}
	std::cout << std::endl;
}


template <typename T>
DLL<T>::~DLL() {
	while (m_front) {
		Node* it = m_front;
		m_front = it->m_next;
		delete it;
	}
}

/* Sentinel Class using a sentinel node */
template <typename T>
class Sentinel {
	struct Node {
		T m_data;
		Node* m_next;
		Node* m_prev;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			m_data = data;
			m_next = next;
			m_prev = prev;
		}
	};
	Node* m_front;
	Node* m_back;
public:
	Sentinel() {
		m_front = new Node();
		m_back = new Node();
		m_front->m_next = m_back;
		m_back->m_prev = m_front;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data) {
	Node* nn = new Node(data, m_front->m_next, m_front);
	m_front->m_next->m_prev = nn;
	m_front->m_next = nn;
}


template <typename T>
void Sentinel<T>::push_back(const T& data) {
	Node* nn = new Node(data, m_back, m_back->m_prev);
	m_back->m_prev->m_next = nn;
	m_back->m_prev = nn;
}


template <typename T>
void Sentinel<T>::pop_front() {
	//if its an empty list... note that it means
	//front sentinel's next node is the back sentinel
	if (m_front->m_next != m_back) {
		Node* rm = m_front->m_next;
		Node* B = rm->m_next;
		m_front->m_next = B;
		B->m_prev = m_front;
		delete rm;
	}
}


template <typename T>
void Sentinel<T>::pop_back() {
	if (m_back->m_prev != m_front) {
		Node* rm = m_back->m_prev;
		rm->m_prev->m_next = m_back;
		m_back->m_prev = rm->m_prev;
		delete rm;
	}
}


template <typename T>
void Sentinel<T>::print() const {
	Node* curr = m_front->m_next;
	while (curr != m_back) {
		std::cout << curr->m_data << " ";
		curr = curr->m_next;
	}
	if (m_front->m_next == m_back) {
		std::cout << "empty list";
	}
	std::cout << std::endl;
}


template <typename T>
void Sentinel<T>::reversePrint() const {
	Node* curr = m_back->m_prev;
	while (curr != m_front) {
		std::cout << curr->m_data << " ";
		curr = curr->m_prev;
	}
	if (m_back->m_prev == m_front) {
		std::cout << "empty list";
	}
	std::cout << std::endl;
}


template <typename T>
Sentinel<T>::~Sentinel() {
	while (m_front != m_back) {
		Node* it = m_front;
		m_front = it->m_next;
		delete it;
	}
}

