/*
 * CSC 210 Programming Assignment #3
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Header file: bookType.h
 *
 * This class specifies the variables and members
 * to implement the data from the library file.
 * The data includes the Book Title, ISBN,
 * Publisher, Year Published, Cost, Number In Stock,
 * and Number of Authors.
 */

#ifndef BOOKTYPE_H   // Header Guard
#define BOOKTYPE_H   // Header Guard

using namespace std; // Use C++ standard library

/***** bookType Class *****/
// Each object of the class BookType will hold the following information about a book
class bookType
{
// Declare private data member variables
private:
    string bookTitle;      // Title of a book
    string ISBN;           // ISBN 13 (with dashes)
    string publisher;      // Publisher of a book
    string yearPublished;  // Year a book was published
    double price;          // Price of a book
    int copiesAvailable;   // Number of copies in stock (may be 0)
    int numberofAuthors;   // Total number of authors
    string authorList[4];  // Array to hold up to four authors

// Declare the constructors and data member functions
public:
    // Default Constructor
    // Description:   Initializes all pointers (pointing to all bookType class objects) to null values.
    // Signature:     bookType default constructor returns no value.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: All pointers have been initialized to null values.
    // Return:        No value is returned.
    bookType();

    // Overloaded Constructor
    // Description:   Initializes all objects of the bookType class to this pointers.
    // Signature:     bookType overloaded constructor returns no value; it takes
    //                all objects of the bookType class as input.
    // Parameters:    The string object contains a title of a book.
    //                The string object contains a book's ISBN.
    //                The string object contains a book's publisher.
    //                The string object contains a year a book was published.
    //                The double object contains a book's price.
    //                The int object contains a book's stock.
    //                The int object contains a book's total number of authors.
    //                The string object/array contains a book's author list.
    // Precondition:  All this pointers have been initialized in the default constructor.
    // Postcondition: All objects are set to their respective this pointers.
    // Return:        No value is returned.
    bookType(string bookTitle, string ISBN, string publisher, string yearPublished,
             double price, int copiesAvailable, int numberofAuthors, string authorList[]);

    // Description:   Member to get a book title. Returns bookTitle pointer.
    // Signature:     getBookTitle returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->bookTitle.
    string getBookTitle();

    // Description:   Member to get a ISBN. Returns ISBN pointer.
    // Signature:     getISBN returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->ISBN.
    string getISBN();

    // Description:   Member to get a book's publisher. Returns publisher pointer.
    // Signature:     getPublisher returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->publisher.
    string getPublisher();

    // Description:   Member to get a year a book was published. Returns yearPublished pointer.
    // Signature:     getYearPublished returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->yearPublished.
    string getYearPublished();

    // Description:   Member to get a book's price. Returns price pointer.
    // Signature:     getPrice returns a pointer to a double object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->price.
    double getPrice();

    // Description:   Member to get a book's stock. Returns copiesAvailable pointer.
    // Signature:     getCopiesAvailable returns a pointer to a integer object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->copiesAvailable.
    int getCopiesAvailable();

    // Description:   Member to get a book's total number of authors. Returns numberofAuthors pointer.
    // Signature:     getNumberOfAuthors returns a pointer to a integer object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->numberofAuthors.
    int getNumberOfAuthors();

    // Description:   Member to get a book's author list. Returns authorList[] pointer.
    // Signature:     getAuthorList returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->authorList[i].
    string *getAuthorList();

    // Description:   Member to set a book title.
    // Signature:     setBookTitle returns no value; it takes a string variable as input.
    // Parameters:    The string variable contains a title of a book.
    // Precondition:  bookTitle contains a valid string.
    // Postcondition: Set pointer to bookTitle string parameter.
    // Return:        No value is returned.
    void setBookTitle(string bookTitle);

    // Description:   Member to set a ISBN.
    // Signature:     setISBN returns no value; it takes a string variable as input.
    // Parameters:    The string variable contains a book's ISBN.
    // Precondition:  ISBN contains a valid string.
    // Postcondition: Set pointer to ISBN string parameter.
    // Return:        No value is returned.
    void setISBN(string ISBN);

    // Description:   Member to set a book's publisher.
    // Signature:     setPublisher returns no value; it takes a string variable as input.
    // Parameters:    The string variable contains a book's publisher.
    // Precondition:  publisher contains a valid string.
    // Postcondition: Set pointer to publisher string parameter.
    // Return:        No value is returned.
    void setPublisher(string publisher);

    // Description:   Member to set a year a book was published.
    // Signature:     setYearPublished returns no value; it takes a string variable as input.
    // Parameters:    The string variable contains a year a book was published.
    // Precondition:  yearPublished contains a valid string.
    // Postcondition: Set pointer to yearPublished string parameter.
    // Return:        No value is returned.
    void setYearPublished(string yearPublished);

    // Description:   Member to set a book's price.
    // Signature:     setPrice returns no value; it takes a double variable as input.
    // Parameters:    The double variable contains a book's price.
    // Precondition:  price contains a valid double.
    // Postcondition: Set pointer to price double parameter.
    // Return:        No value is returned.
    void setPrice(double price);

    // Description:   Member to set a book's stock.
    // Signature:     setCopiesAvailable returns no value; it takes a integer variable as input.
    // Parameters:    The integer variable contains a book's stock.
    // Precondition:  copiesAvailable contains a valid integer.
    // Postcondition: Set pointer to copiesAvailable integer parameter.
    // Return:        No value is returned.
    void setCopiesAvailable(int copiesAvailable);

    // Description:   Member to set a book's total number of authors.
    // Signature:     setNumberOfAuthors returns no value; it takes a integer variable as input.
    // Parameters:    The integer variable contains a book's total number of authors.
    // Precondition:  numberofAuthors contains a valid integer.
    // Postcondition: Set pointer to numberofAuthors integer parameter.
    // Return:        No value is returned.
    void setNumberOfAuthors(int numberofAuthors);

    // Description:   Member to set a book's author list.
    // Signature:     setAuthorList returns no value; it takes a string pointer variable as input.
    // Parameters:    The integer variable contains a book's author list.
    // Precondition:  authorList points to a valid string array.
    // Postcondition: Set pointer to authorList string parameter.
    // Return:        No value is returned.
    void setAuthorList(string *authorList);

    // Old member
    // Description:   Member to add quantity (user's number of books) to copiesAvailable pointer.
    // Signature:     updateCopiesAvailable returns no value; it takes a integer variable as input.
    // Parameters:    The integer variable contains the number of books
    //                the user wants to add to a stock.
    // Precondition:  quantity contains a valid integer.
    // Postcondition: Update copiesAvailable pointer with quantity.
    // Return:        No value is returned.
    void updateCopiesAvailable(int quantity);

    // Description:   Overloaded operator (+) to add quantity (user's number of books)
    //                to copiesAvailable pointer.
    // Signature:     operator+ returns a pointer to the total.
    // Parameters:    The integer variable contains the number of books
    //                the user wants to add to a stock.
    // Precondition:  quantity contains a valid integer.
    // Postcondition: Update object's stock.
    // Return:        Return *this (newStock) - stored in copiesAvailable.
    bookType operator+(int quantity);

    // Description:   Overloaded operator (-) to subtract quantity (user's number of books)
    //                from copiesAvailable pointer.
    // Signature:     operator- returns a pointer to the difference.
    // Parameters:    The integer variable contains the number of books
    //                the user wants to subtract from a stock.
    // Precondition:  quantity contains a valid integer.
    // Postcondition: Update object's stock.
    // Return:        Return *this (newStock) - stored in copiesAvailable.
    bookType operator-(int quantity);

    // Old member
    // Description:   Member to print all fields/pointers of the bookType class.
    // Signature:     printBookDetails returns no value.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: Display all bookType fields of a book.
    // Return:        No value is returned.
    void printBookDetails();
};

#endif // BOOKTYPE_H
