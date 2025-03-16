#include<iostream>
#include<string>
using namespace std;

class Book {
protected:
    string genre;
public:
    Book(string g) : genre(g) {}
    void showGenre() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Book {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Book("Novel"), title(t), author(a) {}
    void showDetails() {
        showGenre();
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Book {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Book("Mystery"), title(t), author(a) {}
    void showDetails() {
        showGenre();
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel novel("The Great Gatsby", "F. Scott Fitzgerald");
    Mystery mystery("The Hound of the Baskervilles", "Arthur Conan Doyle");

    novel.showDetails();
    cout << endl;
    mystery.showDetails();

    return 0;
}

