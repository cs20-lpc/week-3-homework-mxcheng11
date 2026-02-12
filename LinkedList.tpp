#include <iostream>
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);
    if (head == nullptr) head = newNode;
    else {
        Node* curr = head;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    this->length = 0;
}

template <typename T>
T& LinkedList<T>::getElement(int position) {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position");
    Node* curr = head;
    for (int i = 0; i < position; ++i) curr = curr->next;
    return curr->value;
}

template <typename T>
const T& LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position");
    Node* curr = head;
    for (int i = 0; i < position; ++i) curr = curr->next;
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) throw std::out_of_range("Invalid position");
    if (position == 0) head = new Node(elem, head);
    else {
        Node* curr = head;
        for (int i = 0; i < position - 1; ++i) curr = curr->next;
        curr->next = new Node(elem, curr->next);
    }
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position");

    Node* temp = nullptr;
    if (position == 0) {
        temp = head;
        head = head->next;
    } else {
        Node* curr = head;
        for (int i = 0; i < position - 1; ++i) curr = curr->next;
        temp = curr->next;
        curr->next = temp->next;
    }
    delete temp;
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position");
    Node* curr = head;
    for (int i = 0; i < position; ++i) curr = curr->next;
    curr->value = elem;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
    if (list.isEmpty()) {
        out << "List is empty\n";
        return out;
    }
    typename LinkedList<T>::Node* curr = list.head;
    while (curr != nullptr) {
        out << curr->value;
        if (curr->next != nullptr) out << "\n";
        curr = curr->next;
    }
    return out;
}
