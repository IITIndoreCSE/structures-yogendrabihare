#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    int year;
    int pages;
    char isbn[20];
};

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
    if (num_books > 10) num_books = 10;
    input.ignore(); // skip newline after num_books

    Book books[10];

    for (int i = 0; i < num_books; i++) {
        input.getline(books[i].title, 100);   // read title
        input.getline(books[i].author, 100);  // read author
        input >> books[i].year;               // read year
        input >> books[i].pages;              // read pages
        input.ignore();                       // skip newline after pages
        input.getline(books[i].isbn, 20);     // read isbn
    }

    for (int i = 0; i < num_books; i++) {
        print_book(i, books[i].title, books[i].author,
                      books[i].year, books[i].pages, books[i].isbn);
    }

    return 0;
}
