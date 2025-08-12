#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // fixed max size array
int arr[MAX_SIZE];
int size = 0;

void create() {
    cout << "Enter number of elements (max " << MAX_SIZE << "): ";
    cin >> size;
    if (size > MAX_SIZE) {
        cout << "Size exceeds max limit. Setting size to " << MAX_SIZE << ".\n";
        size = MAX_SIZE;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void display() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insert() {
    if (size == MAX_SIZE) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }

    int pos, elem;
    cout << "Enter position to insert (1-based): ";
    cin >> pos;

    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter element to insert: ";
    cin >> elem;

    // shift elements to the right
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    size++;

    cout << "Element inserted.\n";
}

void deleteElement() {
    if (size == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete (1-based): ";
    cin >> pos;

    if (pos < 1 || pos > size) {
        cout << "Invalid position.\n";
        return;
    }

    // shift elements to the left
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Element deleted.\n";
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << ".\n";
            return;
        }
    }

    cout << "Element not found.\n";
}

void pause() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

int main() {
    int choice;

    do {
        cout << "\n——MENU——-\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(); // clear newline

        switch (choice) {
            case 1: create(); pause(); break;
            case 2: display(); pause(); break;
            case 3: insert(); pause(); break;
            case 4: deleteElement(); pause(); break;
            case 5: linearSearch(); pause(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n"; pause();
        }
    } while (choice != 6);

    return 0;
}
