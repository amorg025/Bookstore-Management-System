/*
 * CSC 210 Programming Assignment #3
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Header file: exbookType.h
 *
 * This extended class specifies the variables
 * and members to implement the data from the
 * library file. The data includes the format(s),
 * the number of formats, and the number of pages.
 */

#ifndef EXBOOKTYPE_H   // Header Guard
#define EXBOOKTYPE_H   // Header Guard

#include "bookType.h"  // Allow C++ to access "bookType.h"  (header file)

using namespace std;   // Use C++ standard library

/***** exbookType Class *****/
// Class exbookType inherited from class bookType
class exbookType : public bookType
{
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
    friend ostream& operator<< (ostream&, exbookType&);

// Declare private data member variables
private:
    int numberofFormats;   // Number of formats of a book
    string formatList[3];  // Array to hold up to 3 types of formats (paperback, hardback, digital)
    int numberofPages;     // Number of pages of a book

// Declare the constructors and data member functions
public:
    // Bring the overloaded operator (+) from class bookType into class exbookType
    using bookType::operator+;

    // Bring the overloaded operator (-) from class bookType into class exbookType
    using bookType::operator-;

    // Bring the overloaded operator (=) from class bookType into class exbookType
    using bookType::operator=;

    // Default Constructor
    // Description:   Initializes all pointers of the exbookType class to null values.
    // Signature:     exbookType default constructor returns no value.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: All pointers have been initialized to null values.
    // Return:        No value is returned.
    exbookType();

    // Overloaded Constructor
    // Description:   Initializes all objects of the exbookType class to this pointers.
    // Signature:     bookType overloaded constructor returns no value; it takes
    //                all objects of the exbookType class as input.
    // Parameters:    The int object contains a book's total number of formats.
    //                The string object/array contains a book's format list.
    //                The int object contains a book's total number of pages.
    // Precondition:  All this pointers have been initialized in the default constructor.
    // Postcondition: All objects are set to their respective this pointers.
    // Return:        No value is returned.
    exbookType(int numberofFormats, string formatList[], int numberofPages);

    // Description:   Member to get a book's total number of formats. Returns numberofFormats pointer.
    // Signature:     getNumberOfFormats returns a pointer to a integer object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->numberofFormats.
    int getNumberOfFormats();

    // Description:   Member to get a book's format list. Returns formatList[] pointer.
    // Signature:     getFormatList returns a pointer to a string object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->formatList[i].
    string *getFormatList();

    // Description:   Member to get a book's total number of pages. Returns numberofPages pointer.
    // Signature:     getNumberOfPages returns a pointer to a integer object.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: A valid pointer is returned.
    // Return:        Return this->numberofPages.
    int getNumberOfPages();

    // Description:   Member to set a book's total number of formats.
    // Signature:     setNumberOfFormats returns no value; it takes a integer variable as input.
    // Parameters:    The integer variable contains a book's total number of formats.
    // Precondition:  numberofFormats contains a valid integer.
    // Postcondition: Set pointer to numberofFormats integer parameter.
    // Return:        No value is returned.
    void setNumberOfFormats(int numberofFormats);

    // Description:   Member to set a book's format list.
    // Signature:     setFormat returns no value; it takes a string pointer variable as input.
    // Parameters:    The integer variable contains a book's format list.
    // Precondition:  formatList points to a valid string array.
    // Postcondition: Set pointer to formatList string parameter.
    // Return:        No value is returned.
    void setFormatList(string *formatList);

    // Description:   Member to set a book's total number of pages.
    // Signature:     setNumberOfPages returns no value; it takes a integer variable as input.
    // Parameters:    The integer variable contains a book's total number of pages.
    // Precondition:  numberofPages contains a valid integer.
    // Postcondition: Set pointer to numberofPages integer parameter.
    // Return:        No value is returned.
    void setNumberOfPages(int numberofPages);

    // For debugging purposes
    // Description:   Member to print all fields/pointers of the extended bookType class.
    // Signature:     printBookDetails returns no value.
    // Parameters:    There are no parameters.
    // Precondition:  There are no preconditions.
    // Postcondition: Display all extended bookType fields of a book.
    // Return:        No value is returned.
    void printEXBookDetails();
};

#endif // EXBOOKTYPE_H
