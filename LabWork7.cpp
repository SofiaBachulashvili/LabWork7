#include <vector>
#include <iostream>
#include <locale.h>
using namespace std;

struct Node { 
	int data;
	Node* next; 
	Node* prev;
};

class Double_Linked_List {
public:
	Double_Linked_List();
	Double_Linked_List(int data);

	bool add_element(int data);
	bool find_element(int data);
	bool find_position(int position);
	bool insert_element(int data, int position);
	bool delete_element(int value);
	void Write_list();
	void sorted_list();

	~Double_Linked_List(); 

private: 
	Node* first;
	Node* last;
};

Double_Linked_List::Double_Linked_List() {
	first = nullptr;
	last = nullptr;
};

Double_Linked_List::Double_Linked_List(int data) {
	Node* nd = new Node{ data, nullptr, nullptr}; 
	first = nd;
	last = nd;
	last->next = nullptr;
};

bool Double_Linked_List::find_position(int position) {
	Node* current_el = first;
	int counter = 0;
	while (current_el != nullptr) {
		++counter;
		if (counter == position) {
			return 1;
		}
		current_el = current_el->next;
	}
	return false;
}


bool Double_Linked_List::find_element(int data) {
	if (last != nullptr) {
		Node* current_el = first;
		while (current_el != nullptr) {
			if (current_el->data == data) return true;
			current_el = current_el->next;
		}
	}
	return false;
};

bool Double_Linked_List::add_element(int data) {
	Node* nd = new Node{ data, nullptr, nullptr };
	if (first == nullptr) {
		first = nd;
		last = nd;
	}
	else {
		nd->prev = last;
		last->next = nd;
		last = nd;
	}
	nd->next = nullptr;
	return true;
};

bool Double_Linked_List::insert_element(int data, int position) {
	if (!this->find_position(position)) {
		return false;
	}
	Node* nd = new Node{ data, nullptr, nullptr };
	if (position == 1) {
		nd->next = first;
		first = nd;
	}
	else {
		Node* current_el = first;
		for (int i = 1; i < position - 1; ++i) {
			current_el = current_el->next;
		}
		nd->next = current_el->next;
		nd->prev = current_el;
		current_el->next = nd;
	}
	return true;
};

bool Double_Linked_List::delete_element(int value) {
	if (first == nullptr) {
		return false;
	}

	Node* current_el = first;
	Node* previous_el = nullptr;

	while (current_el != nullptr) {
		if (current_el->data == value) {
			if (current_el == first) {
				Node* nd = first;
				first = first->next;
				delete nd;
			}
			else if (current_el == last) {
				Node* nd = last;
				last = previous_el;
				last->next = nullptr;
				delete nd;
			}
			else {
				Node* nd = current_el;
				previous_el->next = current_el->next;
				delete nd;
			}
			return current_el->data;
		}
		previous_el = current_el;
		current_el = current_el->next;
	}
	return false;
};


void Double_Linked_List::Write_list() {
	Node* current_el = first;
	cout << "\tLIST\t";
	while (current_el != NULL) {
		cout << current_el->data << " ";
		current_el = current_el->next;
	}
	cout << "\n\n";
	return;
}

void Double_Linked_List::sorted_list() {
	Node* nd = new Node;
	Node* left = first;
	Node* right = first->next;
	while (left->next) {
		while (right) {
			if ((left->data) > (right->data)) {
				nd->data = left->data;
				left->data = right->data;
				right->data = nd->data;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
	return;
}


Double_Linked_List::~Double_Linked_List() {
	if (last != nullptr) {
		Node* current_el = first;
		while (current_el != nullptr) {
			Node* nd = new Node{ 0, current_el->next };
			delete current_el;
			first = first->next; 
			current_el = first;
		}
	}
}



int main() {
	setlocale(LC_ALL, "rus");
	Double_Linked_List LIST;
	LIST.add_element(8);
	LIST.add_element(3);
	LIST.add_element(55);
	LIST.add_element(76);
	LIST.add_element(11);
	cout << "Initial";
	LIST.Write_list();

	cout << " LIST.find_element(1) : " << LIST.find_element(1) << "\n\n";

	cout << " LIST.find_position(1) : " << LIST.find_position(5) << "\n\n";

	cout << " LIST.insert_list(22, 3) : " << LIST.insert_element(22, 3) << "\n";
	LIST.Write_list();

	cout << " sorted_list() : " << "\n";
	LIST.sorted_list();
	LIST.Write_list();

	cout << " delete element value = 0 : " << LIST.delete_element(0) << "\n";
	LIST.Write_list();

	cout << " delete element value = 3 : " << LIST.delete_element(3) << "\n";
	LIST.Write_list();

	LIST.~Double_Linked_List();
	return 0;
}
