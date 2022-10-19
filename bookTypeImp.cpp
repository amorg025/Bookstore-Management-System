/*
 * CSC 210 Programming Assignment #3
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Implementation file: bookTypeImp.cpp
 *
 * This file contains the definitions and functions
 * to implement the operations of the class
 * bookType.h.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <iomanip>        // Allow C++ to access to input and output manipulators
#include <string>         // Allow C++ to store sequences of characters
#include "bookType.h"     // Allow C++ to access "bookType.h"

using namespace std;      // Use C++ standard library

/***** bookType Default Constructor *****/
// Description:   Initializes all pointers (pointing to all bookType class objects) to null values.
// Signature:     bookType default constructor returns no value.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: All pointers have been initialized to null values.
// Return:        No value is returned.
bookType::bookType()
{
    // The this-> pointer represents an object that invokes or calls a member function
    // It will point to the object for which member function is called
    // It is automatically passed to a member function when it is called
    // It is also called as a implicit argument to all member functions

    // Initialize pointer to null string
    this->bookTitle = "";

    // Initialize pointer to null string
    this->ISBN = "";

    // Initialize pointer to null string
    this->publisher = "";

    // Initialize pointer to null string
    this->yearPublished = "";

    // Initialize pointer to null double
    this->price = 0.0;

    // Initialize pointer to null integer
    this->copiesAvailable = 0;

    // Initialize pointer to null integer
    this->numberofAuthors = 0;

    // Loop to total amount of authors
    for (int i = 0; i < 4; i++)
    {
        // Initialize pointer to null string
        this->authorList[i] = "";
    }
}

/***** bookType Overloaded Constructor *****/
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
bookType::bookType(string bookTitle, string ISBN, string publisher, string yearPublished,
                   double price, int copiesAvailable, int numberofAuthors, string authorList[])
{
    // Set pointer to bookTitle string parameter
    this->bookTitle = bookTitle;

    // Set pointer to ISBN string parameter
    this->ISBN = ISBN;

    // Set pointer to publisher string parameter
    this->publisher = publisher;

    // Set pointer to yearPublished string parameter
    this->yearPublished = yearPublished;

    // Set pointer to price double parameter
    this->price = price;

    // Set pointer to copiesAvailable integer parameter
    this->copiesAvailable = copiesAvailable;

    // Set pointer to numberofAuthors integer parameter
    this->numberofAuthors = numberofAuthors;

    // Loop to total amount of authors
    for (int i = 0; i < this->numberofAuthors; i++)
    {
        // Set pointer to authorList string parameter
        this->authorList[i] = authorList[i];
    }
}

/***** getBookTitle Member Function *****/
// Description:   Member to get a book title. Returns bookTitle pointer.
// Signature:     getBookTitle returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->bookTitle.
string bookType::getBookTitle()
{
    // Return bookTitle pointer
    return this->bookTitle;
}

/***** getISBN Member Function *****/
// Description:   Member to get a ISBN. Returns ISBN pointer.
// Signature:     getISBN returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->ISBN.
string bookType::getISBN()
{
    // Return ISBN pointer
    return this->ISBN;
}

/***** getPublisher Member Function *****/
// Description:   Member to get a book's publisher. Returns publisher pointer.
// Signature:     getPublisher returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->publisher.
string bookType::getPublisher()
{
    // Return publisher pointer
    return this->publisher;
}

/***** getYearPublished Member Function *****/
// Description:   Member to get a year a book was published. Returns yearPublished pointer.
// Signature:     getYearPublished returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->yearPublished.
string bookType::getYearPublished()
{
    // Return yearPublished pointer
    return this->yearPublished;
}

/***** getPrice Member Function *****/
// Description:   Member to get a book's price. Returns price pointer.
// Signature:     getPrice returns a pointer to a double object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->price.
double bookType::getPrice()
{
    // Return price pointer
    return this->price;
}

/***** getCopiesAvailable Member Function *****/
// Description:   Member to get a book's stock. Returns copiesAvailable pointer.
// Signature:     getCopiesAvailable returns a pointer to a integer object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->copiesAvailable.
int bookType::getCopiesAvailable()
{
    // Return copiesAvailable pointer
    return this->copiesAvailable;
}

/***** getNumberOfAuthors Member Function *****/
// Description:   Member to get a book's total number of authors. Returns numberofAuthors pointer.
// Signature:     getNumberOfAuthors returns a pointer to a integer object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->numberofAuthors.
int bookType::getNumberOfAuthors()
{
    // Return numberofAuthors pointer
    return this->numberofAuthors;
}

/***** getAuthorList Member Function *****/
// Description:   Member to get a book's author list. Returns authorList[] pointer.
// Signature:     getAuthorList returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->authorList[i].
string *bookType::getAuthorList()
{
    // Return authorList pointer
    return this->authorList;
}

/***** setBookTitle Member Function *****/
// Description:   Member to set a book title.
// Signature:     setBookTitle returns no value; it takes a string variable as input.
// Parameters:    The string variable contains a title of a book.
// Precondition:  bookTitle contains a valid string.
// Postcondition: Set pointer to bookTitle string parameter.
// Return:        No value is returned.
void bookType::setBookTitle(string bookTitle)
{
    // Set pointer to bookTitle string parameter
    this->bookTitle = bookTitle;
}

/***** setISBN Member Function *****/
// Description:   Member to set a ISBN.
// Signature:     setISBN returns no value; it takes a string variable as input.
// Parameters:    The string variable contains a book's ISBN.
// Precondition:  ISBN contains a valid string.
// Postcondition: Set pointer to ISBN string parameter.
// Return:        No value is returned.
void bookType::setISBN(string ISBN)
{
    // Set pointer to bookTitle ISBN parameter
    this->ISBN = ISBN;
}

/***** setPublisher Member Function *****/
// Description:   Member to set a book's publisher.
// Signature:     setPublisher returns no value; it takes a string variable as input.
// Parameters:    The string variable contains a book's publisher.
// Precondition:  publisher contains a valid string.
// Postcondition: Set pointer to publisher string parameter.
// Return:        No value is returned.
void bookType::setPublisher(string publisher)
{
    // Set pointer to publisher string parameter
    this->publisher = publisher;
}

/***** setYearPublished Member Function *****/
// Description:   Member to set a year a book was published.
// Signature:     setYearPublished returns no value; it takes a string variable as input.
// Parameters:    The string variable contains a year a book was published.
// Precondition:  yearPublished contains a valid string.
// Postcondition: Set pointer to yearPublished string parameter.
// Return:        No value is returned
void bookType::setYearPublished(string yearPublished)
{
    // Set pointer to yearPublished string parameter
    this->yearPublished = yearPublished;
}

/***** setPrice Member Function *****/
// Description:   Member to set a book's price.
// Signature:     setPrice returns no value; it takes a double variable as input.
// Parameters:    The double variable contains a book's price.
// Precondition:  price contains a valid double.
// Postcondition: Set pointer to price double parameter.
// Return:        No value is returned.
void bookType::setPrice(double price)
{
    // Set pointer to price double parameter
    this->price = price;
}

/***** setCopiesAvailable Member Function *****/
// Description:   Member to set a book's stock.
// Signature:     setCopiesAvailable returns no value; it takes a integer variable as input.
// Parameters:    The integer variable contains a book's stock.
// Precondition:  copiesAvailable contains a valid integer.
// Postcondition: Set pointer to copiesAvailable integer parameter.
// Return:        No value is returned.
void bookType::setCopiesAvailable(int copiesAvailable)
{
    // Set pointer to copiesAvailable integer parameter
    this->copiesAvailable = copiesAvailable;
}

/***** setNumberOfAuthors Member Function *****/
// Description:   Member to set a book's total number of authors.
// Signature:     setNumberOfAuthors returns no value; it takes a integer variable as input.
// Parameters:    The integer variable contains a book's total number of authors.
// Precondition:  numberofAuthors contains a valid integer.
// Postcondition: Set pointer to numberofAuthors integer parameter.
// Return:        No value is returned.
void bookType::setNumberOfAuthors(int numberofAuthors)
{
    // Set pointer to numberofAuthors integer parameter
    this->numberofAuthors = numberofAuthors;
}

/***** setAuthorList Member Function *****/
// Description:   Member to set a book's author list.
// Signature:     setAuthorList returns no value; it takes a string pointer variable as input.
// Parameters:    The integer variable contains a book's author list.
// Precondition:  authorList points to a valid string array.
// Postcondition: Set pointer to authorList string parameter.
// Return:        No value is returned.
void bookType::setAuthorList(string *authorList)
{
    // Loop to total amount of authors
    for (int i = 0; i < this->numberofAuthors; i++)
    {
        // Set pointer to authorList (another pointer) string parameter
        this->authorList[i] = authorList[i];
    }
}

/***** updateCopiesAvailable Member Function *****/
// Old member
// Description:   Member to add quantity (user's number of books) to copiesAvailable pointer.
// Signature:     updateCopiesAvailable returns no value; it takes a integer variable as input.
// Parameters:    The integer variable contains the number of books
//                the user wants to add to a stock.
// Precondition:  quantity contains a valid integer.
// Postcondition: Update copiesAvailable pointer with quantity.
// Return:        No value is returned.
void bookType::updateCopiesAvailable(int quantity)
{
    // Add quantity to set the sum total in pointer
    this->copiesAvailable += quantity;
}

/***** Overloading operator (+) *****/
// Description:   Overloaded operator (+) to add quantity (user's number of books)
//                to copiesAvailable pointer.
// Signature:     operator+ returns a pointer to the total.
// Parameters:    The integer variable contains the number of books
//                the user wants to add to a stock.
// Precondition:  quantity contains a valid integer.
// Postcondition: Update object's stock.
// Return:        Return *this (newStock) - stored in copiesAvailable.
bookType bookType::operator+(int quantity)
{
    // Add quantity to set the sum total in pointer
    this->copiesAvailable += quantity;

    // Return pointer
    return *this;
}

/***** Overloading operator (-) *****/
// Description:   Overloaded operator (-) to subtract quantity (user's number of books)
//                from copiesAvailable pointer.
// Signature:     operator- returns a pointer to the difference.
// Parameters:    The integer variable contains the number of books
//                the user wants to subtract from a stock.
// Precondition:  quantity contains a valid integer.
// Postcondition: Update object's stock.
// Return:        Return *this (newStock) - stored in copiesAvailable.
bookType bookType::operator-(int quantity)
{
    // If subtracting the quantity does not cause the number of books to drop below zero
    if ((this->copiesAvailable - quantity) >= 0)
    {
        // Subtract quantity to set the difference in pointer
        this->copiesAvailable -= quantity;
    }

    // Return pointer
    return *this;
}

/***** printBookDetails Member Function *****/
// Old member
// Description:   Member to print all fields/pointers of the bookType class.
// Signature:     printBookDetails returns no value.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: Display all bookType fields of a book.
// Return:        No value is returned.
void bookType::printBookDetails()
{
    // Display Barrier
    cout << "--------------------------------------------------" << endl;

    // Display the bookTitle pointer
    cout << "Title: "                  << this->bookTitle       << endl;

    // Display the ISBN pointer
    cout << "ISBN: "                   << this->ISBN            << endl;

    // Display the publisher pointer
    cout << "Publisher: "              << this->publisher       << endl;

    // Display the yearPublished pointer
    cout << "Year of Publication: "    << this->yearPublished   << endl;

    // Display the price pointer
    cout << "Price: $"                 << fixed << setprecision(2) << this->price << endl;

    // Display the copiesAvailable pointer
    cout << "Quantities in Stock: "    << this->copiesAvailable << endl;

    // Display the numberofAuthors pointer
    cout << "Number of Authors: "      << this->numberofAuthors << endl;

    // Display "Authors: "
    cout << "Authors: ";

    // If the pointer is equal to 1 (if there is only one author)
    if (this->numberofAuthors == 1)
    {
        // Loop to total amount of authors
        for (int i = 0; i < this->numberofAuthors; i++)
        {
            // Display the authorList pointer
            cout << this->authorList[i] << " ";
        }
    }
    // Else if the pointer is greater than 1 (if there is more than one author)
    // (Different formatting since there are more names)
    else if (this->numberofAuthors > 1)
    {
        // Loop to total amount of authors
        for (int i = 0; i < this->numberofAuthors; i++)
        {
            // Display the authorList pointer
            cout << this->authorList[i];

            // Add a semicolon after each element excluding the last element
            if (i < this->numberofAuthors - 1)
            {
                // Display the semicolon
                cout << "; ";
            }
        }
    }

    // Line of space
    cout << endl;
}
