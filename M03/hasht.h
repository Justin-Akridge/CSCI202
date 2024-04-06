#ifndef HASH_T
#define HASH_T

#include <iostream>
#include <cstring>

using namespace std;

class hashT {
public:
    // default to 5 capacity for space reasons
	hashT(int capacity_ = 5) {
		capacity = capacity_;
		count = 0;
		arr = new node*[capacity]();
	}

	~hashT() {
		for (int i = 0; i < capacity; ++i) {
		node* curr = arr[i];
		while (curr) {
			node* temp = curr;
			curr = curr->next;
			delete temp->key;
			delete temp->value;
			delete temp;
		}
		}
		delete [] arr;
	}

	int hashFunction(const char* key) {
		int index;
		int sum = 0;
		int factor = 31;
		for (int i = 0; i < strlen(key); i++) {
			sum = ((sum % capacity) + (((int)key[i]) * factor) % capacity) % capacity;
			factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
		}
		index = sum;
		return index;
	}

	void insert(const char* key, const char* value) {
		int index = hashFunction(key);
		node* newNode = new node;
		newNode->key = strdup(key);
		newNode->value = strdup(value);
		newNode->next = nullptr;

		if (arr[index] == nullptr) {
			arr[index] = newNode;
		} else {
			newNode->next = arr[index];
			arr[index] = newNode;
		}
		count++;
	}

	const char* search(const char* key) {
		int index = hashFunction(key);
		node* first = arr[index];

		while (first != nullptr) {
			if (strcmp(first->key, key) == 0) {
				return first->value;
			}
			first = first->next;
		}
		return "No data found!";
	}

    bool isItemAtEqual(const char* key1, const char* key2) {
        const char* val1 = search(key1);
        const char* val2 = search(key2);

        if (val1 && val2 && strcmp(val1, val2) == 0) {
            return true;
        }
        return false;
    }

    const char* retrieve(const char* key) {
        int index = hashFunction(key);
        node* first = arr[index];

        while (first != nullptr) {
            if (strcmp(first->key, key) == 0) {
                return first->value;
            }
            first = first->next;
        }
        return nullptr;
    }

    void remove(const char* key) {
        int index = hashFunction(key);
        node* prev = nullptr;
        node* curr = arr[index];

        while (curr != nullptr && strcmp(curr->key, key) != 0) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr) {
            if (prev == nullptr) {
                arr[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr->key;
            delete curr->value;
            delete curr;
            count--;
        }
    }

	void print() {
		for (int i = 0; i < capacity; i++) {
			node* curr = arr[i];
			cout << i << ": ";
			while (curr) {
				cout << "(" << curr->key << ", " << curr->value << ") ";
				curr = curr->next;
			}
			cout << endl;
		}
	}
private:
	struct node {
		char* key;
		char* value;
		node* next;
	};

	int count;
	int capacity;
	node** arr;
};

#endif // HASH_T
