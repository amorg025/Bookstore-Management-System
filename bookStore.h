/*
 * CSC 210 Programming Assignment #3
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Header file: bookStore.h
 *
 * This file contains the constants and function prototypes
 * used to implement the menu system in main.cpp.
 */

#ifndef BOOKSTORE_H     // Header Guard
#define BOOKSTORE_H     // Header Guard

using namespace std;    // Use C++ standard library

/***** Global Constant *****/
// Maximum size of books (50)
// Used for exbookType bookArray[]
const int MAXSIZE = 50;

/***** OpenFile Prototype *****/
// Description:   OpenFile function opens the library file (bookData.txt).
//
// Signature:     OpenFile returns no value; it takes a ifstream variable as output.
//
// Parameters:    The ifstream parameter contains the link to the library file.
//
// Precondition:  inData is declared as a ifstream variable.
//
// Postcondition: The library file has been opened.
//                But, if the user does not enter a valid library file name, the program will end.
//
// Return:        No value is returned.
void OpenFile(ifstream &inData);

/***** ReadBooks Prototype *****/
// Description:   ReadBooks function reads the data from the library file
//                and uses the set member functions to store the data into bookArray.
//
// Signature:     ReadBooks returns no value; it takes a ifstream variable as output,
//                a exbookType array as output, and a int variable as output.
//
// Parameters:    The ifstream parameter contains the link to the library file.
//                The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//
// Precondition:  The library file has been opened.
//                bookArray is declared as a exbookType variable.
//                bookCount is declared as a integer variable.
//
// Postcondition: The fields of each book are stored inside bookArray
//                and bookCount is recorded with the total amount of books.
//
// Return:        No value is returned.
void ReadBooks(ifstream &inData, exbookType bookArray[], int &bookCount);

/***** GetMenuChoice Prototype *****/
// Description:   GetMenuChoice function displays the first/main input menu selection
//                and validates the user's input.
//
// Signature:     GetMenuChoice returns a integer value; it takes a integer variable as input.
//
// Parameters:    The integer parameter contains the user's selection (0-5).
//
// Precondition:  menuChoice is declared as a integer variable.
//
// Postcondition: menuChoice is stored with a valid integer and is returned to the main function.
//
// Return:        A integer value is returned to the main function.
int GetMenuChoice(int menuChoice);

/***** GetSearchChoice Prototype *****/
// Description:   GetSearchChoice function displays the second input menu selection
//                and validates the user's input.
//
// Signature:     GetSearchChoice returns a integer value; it takes a integer variable as input.
//
// Parameters:    The integer parameter contains the user's selection (6-8).
//
// Precondition:  searchChoice is declared as an integer variable.
//
// Postcondition: searchChoice is stored with a valid integer is returned to the main function.
//
// Return:        A integer value is returned to the main function.
int GetSearchChoice(int searchChoice);

/***** GetSearchInput Prototype *****/
// Description:   GetSearchInput function reads the value in searchChoice
//                and prompts the user to enter a book title, ISBN, or author name,
//                based on the value for searchChoice.
//
// Signature:     GetSearchInput returns a string value; it takes a integer variable as input
//                and a string variable as input.
//
// Parameters:    The integer parameter contains the user's selection (6-8).
//                The string parameter contains the user's input (book title, ISBN, or author name).
//
// Precondition:  searchChoice contains a valid integer value.
//                searchInput is declared as a string variable.
//
// Postcondition: searchInput is stored with the user's input and is returned to the main function.
//
// Return:        A string value is returned to the main function.
string GetSearchInput(int searchChoice, string searchInput);

/***** SearchMessage Prototype *****/
// Description:   SearchMessage function determines if the store sells the user's book
//                based on the value for searchIndex.
//
// Signature:     SearchMessage returns no value; it takes a exbookType array as output
//                and a integer variable as input.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains an index determined by the search functions.
//                (SearchByBookTitle, SearchByISBN, SearchByAuthor)
//
// Precondition:  bookArray contains the fields for each book.
//                searchIndex contains a valid integer value.
//
// Postcondition: The fields of the book are displayed on the console with an appropriate message
//                if the store sells the book (if searchIndex is not equal to -1).
//                But, if the store does not sell the book, an appropriate message is displayed
//                on the console (if searchIndex is equal to -1).
//
// Return:        No value is returned.
void SearchMessage(exbookType bookArray[], int searchIndex);

/***** SearchByBooKTitle Prototype *****/
// Description:   SearchByBookTitle function searches for the user's bookTitle
//                and checks to see if it's inside bookArray by calling the
//                getBookTitle member function.
//
// Signature:     SearchByBookTitle returns a integer value; it takes a exbookType array as output,
//                a integer variable as output, and a string variable as input.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//                The string parameter contains the user's bookTitle determined
//                by the GetSearchInput function.
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//                bookTitle/searchInput contains a valid string.
//
// Postcondition: A positive or negative index is returned to the main function
//                and the UpdateCopiesAvailable function.
//                (positive if the book was found, negative if the book was not found)
//
// Return:        A integer value is returned to the main function
//                and the UpdateCopiesAvailable function.
int SearchByBooKTitle(exbookType bookArray[], int &bookCount, string bookTitle);

/***** SearchByISBN Prototype *****/
// Description:   SearchByISBN function searches for the user's ISBN
//                and checks to see it's inside bookArray by calling the
//                getISBN member function.
//
// Signature:     SearchByISBN returns a integer value; it takes a exbookType array as output,
//                a integer variable as output, and a string variable as input.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//                The string parameter contains the user's ISBN determined
//                by the GetSearchInput function.
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//                ISBN/searchInput contains a valid string.
//
// Postcondition: A positive or negative index is returned to the main function
//                and the UpdateCopiesAvailable function.
//                (positive if the book was found, negative if the book was not found)
//
// Return:        A integer value is returned to the main function
//                and the UpdateCopiesAvailable function.
int SearchByISBN(exbookType bookArray[], int &bookCount, string ISBN);

/***** SearchByAuthor Prototype *****/
// Description:   SearchByAuthor function searches for the user's authorName
//                and checks to see if it's inside bookArray by calling the
//                getAuthorList member function.
//
// Signature:     SearchByAuthor returns a integer value; it takes a exbookType array as output,
//                a integer variable as output, and a string variable as input.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//                The string parameter contains the user's author name determined
//                by the GetSearchInput function.
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//                authorName/searchInput contains a valid string.
//
// Postcondition: A positive or negative index is returned to the main function
//                and the UpdateCopiesAvailable function.
//                (positive if the book was found, negative if the book was not found)
//
// Return:        A integer value is returned to the main function
//                and the UpdateCopiesAvailable function.
int SearchByAuthor(exbookType bookArray[], int &bookCount, string authorName);

/***** UpdateCopiesAvailable Prototype *****/
// Description:   UpdateCopiesAvailable function prompts the user for the number
//                of books they would like to add to a stock and adds the value
//                to the user's book by using a overloaded operator (+).
//
// Signature:     UpdateCopiesAvailable returns a boolean value; it takes a exbookType array as output,
//                a integer variable as output, a integer variable as input, and a string variable
//                as output.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//                The integer parameter contains the user's selection (6-8).
//                The string parameter contains the user's input (book title, ISBN, or author name).
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//                searchChoice contains a valid integer
//                searchInput contains contains a valid string.
//
// Postcondition: True or false is returned to the main function.
//                (True if the book was found, false if the book was not found)
//
// Return:        A boolean value is returned to the main function.
bool UpdateCopiesAvailable(exbookType bookArray[], int &bookCount, int searchChoice, string searchInput);

/***** SellCopies Prototype *****/
// Description:   SellCopies function prompts the user for the number of books
//                they would like to sell and the subtracts the value from the
//                user's book by using a overloaded operator (-).
//
// Signature:     SellCopies returns a boolean value; it takes a exbookType array as output,
//                a integer variable as output, a integer variable as input, and a string variable
//                as output.
//
// Parameters:    The exbookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//                The integer parameter contains the user's selection (6-8).
//                The string parameter contains the user's input (book title, ISBN, or author name).
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//                searchChoice contains a valid integer
//                searchInput contains contains a valid string.
//
// Postcondition: True or false is returned to the main function.
//                (True if the book was found, false if the book was not found)
//
// Return:        A boolean value is returned to the main function.
bool SellCopies(exbookType bookArray[], int &bookCount, int searchChoice, string searchInput);

/***** PrintAllBooksInStock Prototype *****/
// Description:   PrintBooksInStock function searches and displays
//                the books that are in stock and checks to see if
//                it's inside bookArray by using a overloaded operator (<<)
//                and calling the getCopiesAvailable member function
//
// Signature:     PrintBooksInStock returns no value; it takes a bookType array as output
//                and a integer variable as output.
//
// Parameters:    The bookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//
// Postcondition: The fields of the books that are in stock are displayed on the console.
//
// Return:        No value is returned.
void PrintBooksInStock(exbookType bookArray[], int &bookCount);

/***** PrintAllBooks Prototype *****/
// Description:   PrintAllBooks function displays all books inside the array
//                by using a overloaded operator (<<).
//
// Signature:     PrintAllBooks returns no value; it takes a bookType array as output
//                and a integer variable as output.
//
// Parameters:    The bookType parameter contains the data read from the library file.
//                The integer parameter contains the total amount of books.
//
// Precondition:  bookArray contains the fields for each book.
//                bookCount contains a valid integer.
//
// Postcondition: The fields of all books are displayed on the console.
//
// Return:        No value is returned.
void PrintAllBooks(exbookType bookArray[], int &bookCount);

#endif // BOOKSTORE_H
