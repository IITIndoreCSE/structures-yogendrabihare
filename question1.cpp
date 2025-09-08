#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// TODO: Write the Book struct here
// struct Book { ... };

void print_book(int index, const char* title, const char* author, int year, int pages, const char* isbn) {
    cout << "Book[" << index << "]: "
         << "title=" << title << ", "
         << "author=" << author << ", "
         << "year=" << year << ", "
         << "pages=" << pages << ", "
         << "isbn=" << isbn << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_books;
    input >> num_books;
    input.ignore(); // skip newline

    // TODO: Create array of Book
    // Book books[10];

    // TODO: Read books from input
    // for (int i = 0; i < num_books; i++) { ... }

    // TODO: Print books using print_book
    // for (int i = 0; i < num_books; i++) { ... }

    return 0;
}
