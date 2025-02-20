#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title, author, publisher;
    double price;
    int stock;

public:
    Book(string t, string a, string p, double pr, int s) : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool matches(string t, string a) {
        return title == t && author == a;
    }

    void display() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher 
             << "\nPrice: $" << price << "\nStock: " << stock << "\n";
    }

    bool isAvailable(int copies) {
        return stock >= copies;
    }

    double totalCost(int copies) {
        return price * copies;
    }

    void updateStock(int copies) {
        stock -= copies;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <title> <author> <copies>" << endl;
        return 1;
    }

    string searchTitle = argv[1];
    string searchAuthor = argv[2];
    int copiesRequested = stoi(argv[3]);

    vector<Book> inventory = {
        {"C++ Primer", "Stanley Lippman", "Pearson", 50.0, 10},
        {"Effective C++", "Scott Meyers", "O'Reilly", 45.0, 5},
        {"Clean Code", "Robert C. Martin", "Prentice Hall", 40.0, 7}
    };

    for (auto &book : inventory) {
        if (book.matches(searchTitle, searchAuthor)) {
            book.display();
            if (book.isAvailable(copiesRequested)) {
                cout << "Total Cost: $" << book.totalCost(copiesRequested) << endl;
                book.updateStock(copiesRequested);
            } else {
                cout << "Required copies not in stock." << endl;
            }
            return 0;
        }
    }
    
    cout << "Book not available." << endl;
    return 0;
}

