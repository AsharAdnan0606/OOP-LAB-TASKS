#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
};

class Catalog {
private:
    vector<Book*> index;
public:
    void addBook(Book* book) {
        index.push_back(book);
    }

    void removeBook(string isbn) {
        for (auto it = index.begin(); it != index.end(); ++it) {
            if ((*it)->isbn == isbn) {
                index.erase(it);
                break;
            }
        }
    }

    void findBook(string isbn) {
        for (auto book : index) {
            if (book->isbn == isbn) {
                cout << book->title << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }
};

class Library {
private:
    Catalog catalog;
    vector<Book*> books;
    string name;
    string address;

public:
    Library(string n, string addr) : name(n), address(addr) {}

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }

    void removeBook(string isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->isbn == isbn) {
                books.erase(it);
                catalog.removeBook(isbn);
                break;
            }
        }
    }

    void findBookInCatalog(string isbn) {
        catalog.findBook(isbn);
    }
};

int main() {
    Library myLibrary("City Library", "123 Main St");

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "12345");
    Book book2("1984", "George Orwell", "67890");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.findBookInCatalog("12345");
    myLibrary.findBookInCatalog("67890");
    myLibrary.findBookInCatalog("11111");
    
    return 0;
}

