#include<iostream>
#include<stdexcept>
#include<string>
class Book {
public:
    enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus; 
    bool isReferenceOnly;
    bool isBorrowed; 
    std::string title;
    Genre genre;

public:
     Book(int id, float rate, double pr, char status, bool isRef, bool borrowed, string title, Genre genre): bookID(id), rating(rate), price(pr), availabilityStatus(status),
          isReferenceOnly(isRef), isBorrowed(borrowed), title(title), genre(genre) {}

    Book() : bookID(0), rating(0.0), price(0.0), availabilityStatus('A'),isReferenceOnly(false), isBorrowed(false), title("Untitled"), genre(FICTION) {}
    //getters
    int getId() const { return bookID; }
    std::string getTitle() const { return title; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    bool getIsBorrowed() const { return isBorrowed; }
    Genre getGenre() const { return genre; }
    //setters
    void setReferenceOnly(bool ref) { isReferenceOnly = ref; }
    void setBorrowed(bool b) { 
        isBorrowed = b; 
        updateAvailability(); }
    void updateAvailability() {
        availabilityStatus = (isBorrowed ? 'B' : 'A');
    }
    bool isAffordable(double budget) const {
        return price <= budget;
    }
    void printFormattedPrice() const {
        std::cout << "Price: $" << std::fixed << price << std::endl;
    }
    void displayInfo() const {
        
        std::cout << "Book ID: " << bookID << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Availability Status: " << availabilityStatus << std::endl;
        std::cout << "Is Reference Only: " << (isBorrowed ? "Yes" : "No") << std::endl;
        std::cout << "Genre: ";
        switch (genre) {
            case FICTION: std::cout << "Fiction"; break;
            case NONFICTION: std::cout << "Nonfiction"; break;
            case SCIENCE: std::cout << "Science"; break;
            case HISTORY: std::cout << "History"; break;
            case TECHNOLOGY: std::cout << "Technology"; break;
            default: std::cout << "Unknown"; break;
        }
        std::cout << std::endl;
    }
    int main() {
    Book books[3] = {
        Book(101, 4.5, 299.99, 'A', false, "C++ Primer", Book::TECHNOLOGY),
        Book(102, 3.8, 150.00, 'B', true, "Design Patterns", Book::SCIENCE),
        Book()
    };

    

    return 0;
}

};