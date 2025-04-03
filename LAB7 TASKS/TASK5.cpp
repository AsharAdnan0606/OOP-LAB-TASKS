#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub) : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\n";
    }
    void checkOut() { cout << title << " checked out.\n"; }
    void returnItem() { cout << title << " returned.\n"; }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media {
    string director, rating;
    int duration;
public:
    DVD(string t, string pDate, string id, string pub, string d, int dur, string r)
        : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << "\n";
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string id, string pub, string a, int tracks, string g)
        : Media(t, pDate, id, pub), artist(a), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

class Magazine : public Media {
    string editor;
public:
    Magazine(string t, string pDate, string id, string pub, string e)
        : Media(t, pDate, id, pub), editor(e) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Editor: " << editor << "\n";
    }
};

int main() {
    Book b("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD d("Inception", "2010", "D001", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine m("National Geographic", "2024", "M001", "National Geographic Society", "Susan Goldberg");
    
    b.displayInfo();
    d.displayInfo();
    c.displayInfo();
    m.displayInfo();
    
    return 0;
}

