/*
 * CSC 210 Programming Assignment #3
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Implementation file: exbookTypeImp.cpp
 *
 * This file contains the definitions and functions
 * to implement the operations of the class
 * exbookType.h.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <iomanip>        // Allow C++ to access to input and output manipulators
#include <string>         // Allow C++ to store sequences of characters
#include "exbookType.h"   // Allow C++ to access "exbookType.h"

using namespace std;      // Use C++ standard library

/***** exbookType Default Constructor *****/
// Description:   Initializes all pointers of the exbookType class to null values.
// Signature:     exbookType default constructor returns no value.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: All pointers have been initialized to null values.
// Return:        No value is returned.
exbookType::exbookType()
{
    // Initialize pointer to null integer
    this->numberofFormats = 0;

    // Loop to total amount of formats
    for (int i = 0; i < 3; i++)
    {
        // Initialize pointer to null string
        this->formatList[i] = "";
    }

    // Initialize pointer to null integer
    this->numberofPages = 0;
}

/***** exbookType Overloaded Constructor *****/
// Description:   Initializes all objects of the exbookType class to this pointers.
// Signature:     bookType overloaded constructor returns no value; it takes
//                all objects of the exbookType class as input.
// Parameters:    The int object contains a book's total number of formats.
//                The string object/array contains a book's format list.
//                The int object contains a book's total number of pages.
// Precondition:  All this pointers have been initialized in the default constructor.
// Postcondition: All objects are set to their respective this pointers.
// Return:        No value is returned.
exbookType::exbookType(int numberofFormats, string formatList[], int numberofPages)
{
    // Set pointer to numberofFormats integer parameter
    this->numberofFormats = numberofFormats;

    // Loop to total number of formats
    for (int i = 0; i < this->numberofFormats; i++)
    {
        // Set pointer to formatList string parameter
        this->formatList[i] = formatList[i];
    }

    // Set pointer to numberofPages integer parameter
    this->numberofPages = numberofPages;
}

/***** getNumberOfFormats Member Function *****/
// Description:   Member to get a book's total number of formats. Returns numberofFormats pointer.
// Signature:     getNumberOfFormats returns a pointer to a integer object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->numberofFormats.
int exbookType::getNumberOfFormats()
{
    // Return numberofFormats pointer
    return this->numberofFormats;
}

/***** getFormatList Member Function *****/
// Description:   Member to get a book's format list. Returns formatList[] pointer.
// Signature:     getFormatList returns a pointer to a string object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->formatList[i].
string *exbookType::getFormatList()
{
    // Return formatList pointer
    return this->formatList;
}

/***** getNumberOfPages Member Function *****/
// Description:   Member to get a book's total number of pages. Returns numberofPages pointer.
// Signature:     getNumberOfPages returns a pointer to a integer object.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: A valid pointer is returned.
// Return:        Return this->numberofPages.
int exbookType::getNumberOfPages()
{
    // Return numberofPages pointer
    return this->numberofPages;
}

/***** setNumberOfFormats Member Function *****/
// Description:   Member to set a book's total number of formats.
// Signature:     setNumberOfFormats returns no value; it takes a integer variable as input.
// Parameters:    The integer variable contains a book's total number of formats.
// Precondition:  numberofFormats contains a valid integer.
// Postcondition: Set pointer to numberofFormats integer parameter.
// Return:        No value is returned.
void exbookType::setNumberOfFormats(int numberofFormats)
{
    // Set pointer to numberofFormats integer parameter
    this->numberofFormats = numberofFormats;
}

/***** setFormatList Member Function *****/
// Description:   Member to set a book's format list.
// Signature:     setFormat returns no value; it takes a string pointer variable as input.
// Parameters:    The integer variable contains a book's format list.
// Precondition:  formatList points to a valid string array.
// Postcondition: Set pointer to formatList string parameter.
// Return:        No value is returned.
void exbookType::setFormatList(string *formatList)
{
    // Loop to total number of formats
    for (int i = 0; i < this->numberofFormats; i++)
    {
        // Set pointer to formatList (another pointer) string parameter
        this->formatList[i] = formatList[i];
    }
}

/***** setNumberOfPages Member Function *****/
// Description:   Member to set a book's total number of pages.
// Signature:     setNumberOfPages returns no value; it takes a integer variable as input.
// Parameters:    The integer variable contains a book's total number of pages.
// Precondition:  numberofPages contains a valid integer.
// Postcondition: Set pointer to numberofPages integer parameter.
// Return:        No value is returned.
void exbookType::setNumberOfPages(int numberofPages)
{
    // Set pointer to numberofPages integer parameter
    this->numberofPages = numberofPages;
}

/***** Overloading operator (<<) *****/
// Description:   Overloaded operator (<<) to display the private member variables
//                of the base class and the derived class.
// Signature:     operator<< returns a ostream value; it takes a ostream variable as output
//                and a exbookType object as output.
// Parameters:    The ostream variable contains the entirety of a book's ostream data.
//                The exbookType object contains the data from the private variables.
// Precondition:  output is declared as a ostream variable.
//                bookDetails is declared as a exbookType object.
// Postcondition: Display all fields of the base and derived class.
// Return:        Return output to where overloaded << is used with exbookType object.
ostream& operator<<(ostream &output, exbookType &bookDetails)
{
    // Declare local variables
    string *authorList;        // Pointer containing author list of a book
    string *formatList;        // Pointer containing format list of a book

    // Display Barrier
    cout << "--------------------------------------------------" << endl;

    // Display the book title
    cout << "Title: "                  << bookDetails.getBookTitle()       << endl;

    // Display the ISBN
    cout << "ISBN: "                   << bookDetails.getISBN()            << endl;

    // Display the publisher
    cout << "Publisher: "              << bookDetails.getPublisher()       << endl;

    // Display the year of publication
    cout << "Year of Publication: "    << bookDetails.getYearPublished()   << endl;

    // Display the price
    cout << "Price: $"                 << fixed << setprecision(2) << bookDetails.getPrice() << endl;

    // Display the quantities in stock
    cout << "Quantities in Stock: "    << bookDetails.getCopiesAvailable() << endl;

    // Display the number of authors
    cout << "Number of Authors: "      << bookDetails.getNumberOfAuthors() << endl;

    // Display "Authors: "
    cout << "Authors: ";

    // If the book's number of authors is equal to 1 (if there is only one author)
    if (bookDetails.getNumberOfAuthors() == 1)
    {
        // Loop to total amount of authors
        for (int i = 0; i < bookDetails.getNumberOfAuthors(); i++)
        {
            // Store data from called function into string pointer
            authorList = bookDetails.getAuthorList();

            // Display the author list
            cout << authorList[i] << " ";
        }
    }
    // Else if the  book's number of authors is greater than 1 (if there is more than one author)
    // (Different formatting since there are more names)
    else if (bookDetails.getNumberOfAuthors() > 1)
    {
        // Loop to total amount of authors
        for (int i = 0; i < bookDetails.getNumberOfAuthors(); i++)
        {
            // Store data from called function into string pointer
            authorList = bookDetails.getAuthorList();

            // Display the author list
            cout << authorList[i];

            // Add a semicolon after each element excluding the last element
            if (i < bookDetails.getNumberOfAuthors() - 1)
            {
                // Display the semicolon
                cout << "; ";
            }
        }
    }

    // Line of space
    cout << endl;

    // Display the number of formats
    cout << "Number of Formats: "      << bookDetails.getNumberOfFormats() << endl;

    // Display "Formats: "
    cout << "Formats: ";

    // If the book's number of formats is equal to 1 (if there is only one format)
    if (bookDetails.getNumberOfFormats() == 1)
    {
        // Loop to total amount of formats
        for (int i = 0; i < bookDetails.getNumberOfFormats(); i++)
        {
            // Store data from called function into string pointer
            formatList = bookDetails.getFormatList();

            // Display the format list
            cout << formatList[i] << " ";
        }
    }
    // Else if the book's number of formats is greater than 1 (if there is more than one format)
    // (Different formatting since there are more names)
    else if (bookDetails.getNumberOfFormats() > 1)
    {
        // Loop to total amount of formats
        for (int i = 0; i < bookDetails.getNumberOfFormats(); i++)
        {
            // Store data from called function into string pointer
            formatList = bookDetails.getFormatList();

            // Display the format list
            cout << formatList[i];

            // Add a semicolon after each element excluding the last element
            if (i < bookDetails.getNumberOfFormats() - 1)
            {
                // Display the semicolon
                cout << "; ";
            }
        }
    }

    // Line of space
    cout << endl;

    // Display the number of pages
    cout << "Number of Pages: "      << bookDetails.getNumberOfPages() << endl;

    // Return ostream variable
    return output;
}

/***** printEXBookDetails Member Function *****/
// For debugging purposes
// Description:   Member to print all fields/pointers of the extended bookType class.
// Signature:     printBookDetails returns no value.
// Parameters:    There are no parameters.
// Precondition:  There are no preconditions.
// Postcondition: Display all extended bookType fields of a book.
// Return:        No value is returned.
void exbookType::printEXBookDetails()
{
    // Display fields of the bookType class
    bookType::printBookDetails();

    // Display the numberofFormats pointer
    cout << "Number of Formats: "      << this->numberofFormats << endl;

    // Display "Formats: "
    cout << "Formats: ";

    // If the pointer is equal to 1 (if there is only one format)
    if (this->numberofFormats == 1)
    {
        // Loop to total amount of formats
        for (int i = 0; i < this->numberofFormats; i++)
        {
            // Display the formatList pointer
            cout << this->formatList[i] << " ";
        }
    }
    // Else if the pointer is greater than 1 (if there is more than one format)
    // (Different formatting since there are more names)
    else if (this->numberofFormats > 1)
    {
        // Loop to total amount of formats
        for (int i = 0; i < this->numberofFormats; i++)
        {
            // Display the formatList pointer
            cout << this->formatList[i];

            // Add a semicolon after each element excluding the last element
            if (i < this->numberofFormats - 1)
            {
                // Display the semicolon
                cout << "; ";
            }
        }
    }

    // Line of space
    cout << endl;

    // Display the numberofPages pointer
    cout << "Number of Pages: "      << this->numberofPages << endl << endl;
}
