/*
 * CSC 210 Programming Assignment #3
 * Main file: main.cpp
 * Implementation file(s): bookTypeImp.cpp, exbookTypeImp.cpp
 * Header file(s): bookType.h, exbookType.h, bookStore.h
 * Author: Alysha Morgan
 * Date: 03/28/22
 *
 * Input: Requests the input file name from the user (bookData3.txt provided).
 *
 * Output: Displays output on the console.
 *
 * Description: A program that reads book data from a library file
 * and allows the user to search, print, update, and sell the books
 * through a menu system. The menu system and results are displayed
 * on the console.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <fstream>        // Allow C++ to operate on files
#include <iomanip>        // Allow C++ to access to input and output manipulators
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters
#include "exbookType.h"   // Allow C++ to access "exbookType.h"  (header file)
#include "bookStore.h"    // Allow C++ to access "bookStore.h"   (header file)

using namespace std;      // Use C++ standard library

/***** Main Function *****/
int main()
{
    // Declare and/or initialize local variables
    ifstream inData;               // Link to the input file

    exbookType bookArray[MAXSIZE]; // Contains up to 50 books
    int bookCount = 0;             // Contains total amount of books (limiting factor)

    int menuChoice = 0;            // Choice from the first input menu selection read from user (0-5)
    int searchChoice = 0;          // Choice from the second input menu selection read from user (6-8)
    string searchInput;            // Book title, ISBN, or author name(s) read from user

    // Call OpenFile function
    OpenFile(inData);

    // Call ReadBooks function
    ReadBooks(inData, bookArray, bookCount);

    // While the user does not enter 5 (quit)
    while (menuChoice != 5)
    {
        // Call GetChoice function and
        // Store value returned from function in menuChoice variable
        menuChoice = GetMenuChoice(menuChoice);

        // Determine which case is going to run, based on menuChoice
        switch (menuChoice)
        {
        // If the user enters 0, check to see if a book is sold by the store
        case 0:

            // Call GetChoice function and
            // Store value returned from function in searchChoice variable
            searchChoice = GetSearchChoice(searchChoice);

            // Call GetSearchInput function and
            // Store value returned from function in searchInput variable
            searchInput = GetSearchInput(searchChoice, searchInput);

            // Line of space
            cout << endl;

            // If the user enters 6
            if (searchChoice == 6)
            {
                // Call SearchMessage function and
                // Pass SearchByBookTitle function as a parameter
                SearchMessage(bookArray, SearchByBooKTitle(bookArray, bookCount, searchInput));
            }
            // Else if the user enters 7
            else if (searchChoice == 7)
            {
                // Call SearchMessage function and
                // Pass SearchByISBN function as a parameter
                SearchMessage(bookArray, SearchByISBN(bookArray, bookCount, searchInput));
            }
            // Else if the user enters 8
            else if (searchChoice == 8)
            {
                // Call SearchMessage function and
                // Pass SearchByAuthor function as a parameter
                SearchMessage(bookArray, SearchByAuthor(bookArray, bookCount, searchInput));
            }

            // Terminate
            break;

        // If the user enters 1, update the number of copies of a book
        case 1:

            // Call GetChoice function and
            // Store value returned from function in searchChoice variable
            searchChoice = GetSearchChoice(searchChoice);

            // Call GetSearchInput function and
            // Store value returned from function in searchInput variable
            searchInput = GetSearchInput(searchChoice, searchInput);

            // Line of space
            cout << endl;

            // If the UpdateCopiesAvailable function returns true
            if (UpdateCopiesAvailable(bookArray, bookCount, searchChoice, searchInput))
            {
                // Display "Stock updated successfully."
                cout << "Stock updated successfully." << endl << endl;
            }
            // Otherwise if the UpdateCopiesAvailable function returns false
            else
            {
                // Display "Failed to update stock."
                cout << "Failed to update stock." << endl << endl;
            }

            // Terminate
            break;

        // If the user enters 2, print all books in stock
        case 2:

            // Call PrintBooksInStock function
            PrintBooksInStock(bookArray, bookCount);

            // Terminate
            break;

        // If the user enters 3, print all books
        case 3:

            // Call PrintAllBooks function
            PrintAllBooks(bookArray, bookCount);

            // Terminate
            break;

        // If the user enters 4, sell the number of copies of a book
        case 4:

            // Call GetChoice function and
            // Store value returned from function in searchChoice variable
            searchChoice = GetSearchChoice(searchChoice);

            // Call GetSearchInput function and
            // Store value returned from function in searchInput variable
            searchInput = GetSearchInput(searchChoice, searchInput);

            // If the UpdateCopiesAvailable function returns true
            if (SellCopies(bookArray, bookCount, searchChoice, searchInput))
            {
                // Display "Stock sold successfully."
                cout << "Stock sold successfully." << endl << endl;
            }
            // Otherwise if the UpdateCopiesAvailable function returns false
            else
            {
                // Display "Failed to sell stock."
                cout << "Failed to sell stock." << endl << endl;
            }

            // Terminate
            break;

        // If the user enters 5, end program
        case 5:

            // Display a salutation to the user
            cout << "Ok. Goodbye!" << endl;

            // Close file
            inData.close();

            // Terminate
            break;
        }
    }

    // End program
    return 0;
}

/***** OpenFile Function *****/
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
void OpenFile(ifstream &inData)
{
    // Declare local variables
    string inputName;          // Name of the input file

    // Prompt the user and get a name for the input file
    cout << "Please enter the library book file name (bookData3.txt): " << endl;
    cin >> inputName;

    // Line of space
    cout << endl;

    // Open the input file
    inData.open(inputName);

    // If the input file does not open
    if (inData.fail())
    {
        // Inform the user that the input file has failed to open and end program
        cout << "The library file failed to open. Please start over." << endl;
        exit(1);
    }
    // Else the input file does open
    else
    {
        // Inform the user that the input file has opened successfully
        cout << "The library file opened successfully." << endl << endl;
    }
}

/***** ReadBooks Function *****/
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
void ReadBooks(ifstream &inData, exbookType bookArray[], int &bookCount)
{
    // Declare local variables
    string bookTitle;          // Title of a book
    string ISBN;               // ISBN 13 (with dashes)
    string publisher;          // Publisher of a book
    string yearPublished;      // Year a book was published
    string authorList[4];      // Array to hold up to four authors
    int copiesAvailable;       // Number of copies in stock (may be 0)
    int numberofAuthors;       // Total number of authors
    double price;              // Price of a book
    int numberofFormats;       // Number of formats a book contains
    string formatList[3];      // Array to hold up to three formats
    int numberofPages;         // Total number of pages

    bookCount = 0;             // Initialize bookCount for accurate results

    // Read all data from the input file
    // Omit extra white spaces and newline characters
    while (inData)
    {
        // Read title of a book from the input file
        getline(inData, bookTitle, '\n');

        // Read ISBN from the input file
        getline(inData, ISBN, '\n');

        // Read publisher of a book from the input file
        getline(inData, publisher, '\n');

        // Read the year a book was published from the input file
        inData >> yearPublished;
        inData.ignore(1, '\n');

        // Read the price of a book from the input file
        inData >> price;
        inData.ignore(1, '\n');

        // Read the number of copies in stock from the input file
        inData >> copiesAvailable;
        inData.ignore(1, '\n');

        // Read the number of authors from the input file
        inData >> numberofAuthors;
        inData.ignore(1, '\n');

        // Loop to total amount of authors (for each book)
        for (int i = 0; i < numberofAuthors; i++)
        {
            // Read the author(s) from the input file
            getline(inData, authorList[i]);
        }

        // Read the number of formats from the input file
        inData >> numberofFormats;
        inData.ignore(1, '\n');

        // Loop to total amount of formats (for each book)
        for (int i = 0; i < numberofFormats; i++)
        {
            // Read the format(s) from the input file
            getline(inData, formatList[i]);
        }

        // Read the number of pages from the input file
        inData >> numberofPages;
        inData.ignore(1, '\n');

        // Set all local variables to private member variables using set functions and
        // Store variables inside bookArray
        bookArray[bookCount].setBookTitle(bookTitle);
        bookArray[bookCount].setISBN(ISBN);
        bookArray[bookCount].setPublisher(publisher);
        bookArray[bookCount].setYearPublished(yearPublished);
        bookArray[bookCount].setPrice(price);
        bookArray[bookCount].setNumberOfAuthors(numberofAuthors);
        bookArray[bookCount].setCopiesAvailable(copiesAvailable);
        bookArray[bookCount].setAuthorList(authorList);
        bookArray[bookCount].setNumberOfFormats(numberofFormats);
        bookArray[bookCount].setFormatList(formatList);
        bookArray[bookCount].setNumberOfPages(numberofPages);

        // Increment bookCount
        bookCount ++;
    }

    // Decrement bookCount
    bookCount --;
}

/***** GetMenuChoice Function *****/
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
int GetMenuChoice(int menuChoice)
{
    // Display book store heading
    cout << "--------------------------------------------------" << endl;
    cout << "           Bookstore Management System            " << endl;
    cout << "--------------------------------------------------" << endl;

    // Display options for input selection to the user
    cout << "Input Menu Selection" << endl;
    cout << "0:  Check to see if a book is sold by the store (search)" << endl;
    cout << "1:  Update the number of copies of a book" << endl;
    cout << "2:  Print a list of books in stock" << endl;
    cout << "3:  Print a list of all books sold" << endl;
    cout << "4:  Sell the number of copies of a book" << endl;
    cout << "5:  Exit the program" << endl << endl;

    // Prompt the user for a 0, 1, 2, 3, 4, or 5
    cout << "Please enter a number from the Input Menu Selection: " << endl;
    cin >> menuChoice;

    // Discard all unread characters possibly left in istream
    cin.sync();

    // Line of space
    cout << endl;

    // If the user does not enter a valid number
    // Program will loop until a valid number has been entered
    while ((!cin) || (menuChoice > 5) || (menuChoice < 0))
    {
        // If the user does not enter a number
        if (!cin)
        {
            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');

            // Display a error for not entering a number
            cout << "Error! You need to enter a number." << endl << endl;
        }
        // Otherwise if the user enters a invalid number
        else
        {
            // Display a error for entering a invalid number (greater than 5 or less than 0)
            cout << "Error! You need to enter a valid number (0-5)." << endl << endl;
        }

        // Allow the user to try again
        cout << "Please enter a number from the Input Menu Selection: " << endl;
        cin >> menuChoice;

        // Discard all unread characters possibly left in istream
        cin.sync();

        // Line of space
        cout << endl;
    }

    // Return menuChoice
    return menuChoice;
}

/***** GetSearchChoice Function *****/
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
int GetSearchChoice(int searchChoice)
{
    // Display options for input selection to the user
    cout << "Input Menu Selection" << endl;
    cout << "6:  Search a book by its title" << endl;
    cout << "7:  Search a book by its ISBN" << endl;
    cout << "8:  Search a book by its author" << endl << endl;

    // Prompt the user for a 6, 7, or 8
    cout << "Please enter a number from the Input Menu Selection: " << endl;
    cin >> searchChoice;

    // Discard all unread characters possibly left in istream
    cin.sync();

    // Line of space
    cout << endl;

    // If the user does not enter a valid number
    // Program will loop until a valid number has been entered
    while ((!cin) || (searchChoice > 8) || (searchChoice < 6))
    {
        // If the user does not enter a number
        if (!cin)
        {
            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');

            // Display a error for not entering a number
            cout << "Error! You need to enter a number." << endl << endl;
        }
        // Otherwise if the user enters a invalid number
        else
        {
            // Display a error for entering a invalid number (greater than 8 or less than 6)
            cout << "Error! You need to enter a valid number (6-8)." << endl << endl;
        }

        // Allow the user to try again
        cout << "Please enter a number from the Input Menu Selection: " << endl;
        cin >> searchChoice;

        // Discard all unread characters possibly left in istream
        cin.sync();

        // Line of space
        cout << endl;
    }

    // Return searchChoice
    return searchChoice;
}

/***** GetSearchInput Function *****/
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
string GetSearchInput(int searchChoice, string searchInput)
{
    // If the user entered 6 in the second input menu
    if (searchChoice == 6)
    {
        // Prompt the user for a book title
        cout << "Please enter a book title: " << endl;
    }
    // Else if the user entered 7 in the second input menu
    else if (searchChoice == 7)
    {
        // Prompt the user for a ISBN number
        cout << "Please enter a ISBN number (13 digits with dashes): " << endl;
    }
    // Else if the user entered 8 in the second input menu
    else if (searchChoice == 8)
    {
        // Prompt the user for a author name
        cout << "Please enter a author name (last name, first name MI.): " << endl;
        cout << "ex. Morgan, Alysha" << endl;
        cout << "ex. Morgan, Alysha R." << endl;
    }

    // Allow the user to enter a string
    getline(cin, searchInput);

    // Return searchInput
    return searchInput;
}

/***** SearchMessage Function *****/
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
void SearchMessage(exbookType bookArray[], int searchIndex)
{
    // If the searchIndex is not equal to -1
    if (searchIndex != -1)
    {
        // Inform the user that the store sells their book
        cout << "The store sells this book." << endl;

        // For debugging purposes
        // Call printEXBookDetails data member function to print private member variables
        // (Printing the details of the user's selected book)
        // bookArray[searchIndex].printEXBookDetails();

        // Use overloaded operator (<<) to print private member variables of the search index
        cout << bookArray[searchIndex] << endl;
    }
    // Otherwise if the searchIndex is equal to -1
    else
    {
        // Inform the user that the store does not sell their book
        cout << "The store does not sell this book." << endl << endl;
    }
}

/***** SearchByBookTitle Function *****/
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
int SearchByBooKTitle(exbookType bookArray[], int &bookCount, string bookTitle)
{
    // Loop to total amount of books
    for (int i = 0; i < bookCount; i++)
    {
        // If the store sells the user's book
        // (Call getBookTitle member function to check if the user's book title is inside bookArray)
        if (bookArray[i].getBookTitle() == bookTitle)
        {
            // Return its index
            return i;
        }
    }

    // Otherwise return -1
    return -1;
}

/***** SearchByISBN Function *****/
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
int SearchByISBN(exbookType bookArray[], int &bookCount, string ISBN)
{
    // Loop to total amount of books
    for (int i = 0; i < bookCount; i++)
    {
        // If the store sells the user's book
        // (Call getISBN member function to check if the user's ISBN is inside bookArray)
        if (bookArray[i].getISBN() == ISBN)
        {
            // Return its index
            return i;
        }
    }

    // Otherwise return -1
    return -1;
}

/***** SearchByAuthor Function *****/
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
int SearchByAuthor(exbookType bookArray[], int &bookCount, string authorName)
{
    // Loop to total amount of books
    for (int i = 0; i < bookCount; i++)
    {
        // Declare and initialize authorIndex
        int authorIndex = 4;

        // Call getAuthorList member function and
        // Store value returned from function into pointer
        string *authorList = bookArray[i].getAuthorList();

        // Reading the index in reverse
        while (authorIndex--)
        {
            // If the store sells the user's book
            // (If the pointer contains the user's author name)
            if (authorList[authorIndex - 1] == authorName)
            {
                // Return its index
                return i;
            }
        }
    }

    // Otherwise return -1
    return -1;
}

/***** UpdateCopiesAvailable Function *****/
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
bool UpdateCopiesAvailable(exbookType bookArray[], int &bookCount, int searchChoice, string searchInput)
{
    // Declare and initialize local variables
    int quantity = 0;                    // Number of books to be added to stock
    int updateIndex = -1;                // Index to determine if stock has been successfully added
    int total = 0;                       // Total number of copies a book has
    int newStock = 0;                    // Sum of total and user's quantity
    exbookType stock;                    // exbookType object to hold book's stock

    // If the user entered 6 in the second input menu
    if (searchChoice == 6)
    {
        // Call SearchByBookTitle function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByBooKTitle(bookArray, bookCount, searchInput);
    }
    // If the user entered 7 in the second input menu
    else if (searchChoice == 7)
    {
        // Call SearchByISBN function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByISBN(bookArray, bookCount, searchInput);
    }
    // If the user entered 8 in the second input menu
    else if (searchChoice == 8)
    {
        // Call SearchByAuthor function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByAuthor(bookArray, bookCount, searchInput);
    }

    // Prompt the user for the number of books they would like to add to the stock available
    cout << "Please enter the number of books: " << endl;
    cin >> quantity;

    // Discard all unread characters possibly left in istream
    cin.sync();

    // Line of space
    cout << endl;

    // If the user does not enter a valid number
    // Program will loop until a valid number has been entered
    while ((!cin) || (quantity <= 0))
    {
        // If the user does not enter a number
        if (!cin)
        {
            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');

            // Display a error for not entering a number
            cout << "Error! You need to enter a number." << endl << endl;
        }
        // Otherwise if the user enters a invalid number
        else
        {
            // Display a error for entering a invalid number (greater than 0)
            cout << "Error! You need to enter a valid number (greater than 0)." << endl << endl;
        }

        // Allow the user to try again
        cout << "Please enter the number of books: " << endl;
        cin >> quantity;

        // Discard all unread characters possibly left in istream
        cin.sync();

        // Line of space
        cout << endl;
    }

    // If updateIndex is equal to -1
    // (If the user's book was not found in the functions called above)
    if (updateIndex == -1)
    {
        // Return false
        return false;
    }
    // Otherwise
    else
    {
        // Old method to update copies available
        // Call updateCopiesAvailable member function to add quantity
        // To the user's selected book (by its updateIndex)
        // bookArray[updateIndex].updateCopiesAvailable(quantity);

        // Set total equal to book's total number of copies
        total = bookArray[updateIndex].getCopiesAvailable();

        // Set quantity to the sum of the user's quantity and total number of books
        quantity = quantity + total;

        // Use overloaded operator (+) to add quantity to bookType object
        stock = stock + quantity;

        // Call getCopiesAvailable member function to set stock's copies available to newStock
        newStock = stock.getCopiesAvailable();

        // Call set CopiesAvailable function and pass newStock to the user's selected book
        // (By its updateIndex)
        bookArray[updateIndex].setCopiesAvailable(newStock);

        // Return true
        return true;
    }
}

/***** SellCopies Function *****/
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
bool SellCopies(exbookType bookArray[], int &bookCount, int searchChoice, string searchInput)
{
    // Declare and initialize local variables
    int quantity = 0;                    // Number of books to be added to stock
    int updateIndex = -1;                // Index to determine if stock has been successfully added
    int total = 0;                       // Total number of copies a book has
    int newStock = 0;                    // Difference of total and user's quantity
    exbookType stock;                    // exbookType object to hold book's stock

    // If the user entered 6 in the second input menu
    if (searchChoice == 6)
    {
        // Call SearchByBookTitle function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByBooKTitle(bookArray, bookCount, searchInput);
    }
    // If the user entered 7 in the second input menu
    else if (searchChoice == 7)
    {
        // Call SearchByISBN function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByISBN(bookArray, bookCount, searchInput);
    }
    // If the user entered 8 in the second input menu
    else if (searchChoice == 8)
    {
        // Call SearchByAuthor function and
        // Store value returned from function in updateIndex variable
        updateIndex = SearchByAuthor(bookArray, bookCount, searchInput);
    }

    // Set total equal to book's total number of copies
    total = bookArray[updateIndex].getCopiesAvailable();

    // Call setCopiesAvailable function and pass total to stock's copiesAvailable
    stock.setCopiesAvailable(total);

    // Line of space
    cout << endl;

    // Prompt the user for the number of books they would like to add to the stock available
    cout << "Please enter the number of books: " << endl;
    cin >> quantity;

    // Discard all unread characters possibly left in istream
    cin.sync();

    // Line of space
    cout << endl;

    // If the user does not enter a valid number
    // Program will loop until a valid number has been entered
    while ((!cin) || (stock.getCopiesAvailable() - quantity < 0))
    {
        // If the user does not enter a number
        if (!cin)
        {
            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');

            // Display a error for not entering a number
            cout << "Error! You need to enter a number." << endl << endl;
        }
        // Otherwise if the user enters a invalid number
        else
        {
            // Display a error for entering a invalid number (causing the total to drop to zero)
            cout << "Error! " << "Subtracting " << quantity << " will take the value below 0." << endl;

            // Display a note for the user for a situation where the stock is 0
            cout << "Note! If the quantities of stock is 0 then you must enter 0." << endl << endl;
        }

        // Allow the user to try again
        cout << "Please enter the number of books: " << endl;
        cin >> quantity;

        // Discard all unread characters possibly left in istream
        cin.sync();

        // Line of space
        cout << endl;
    }

    // If updateIndex is equal to -1
    // (If the user's book was not found in the functions called above)
    if (updateIndex == -1)
    {
        // Return false
        return false;
    }
    // Otherwise
    else
    {
        // Set total equal to book's total number of copies
        total = bookArray[updateIndex].getCopiesAvailable();

        // Call setCopiesAvailable function and pass total to stock's copiesAvailable
        stock.setCopiesAvailable(total);

        // Use overloaded operator (-) to subtract quantity from bookType object
        stock = stock - quantity;

        // Call getCopiesAvailable member function to set stock's copies available to newStock
        newStock = stock.getCopiesAvailable();

        // Call set CopiesAvailable function and pass newStock to the user's selected book
        // (By its updateIndex)
        bookArray[updateIndex].setCopiesAvailable(newStock);

        // Return true
        return true;
    }
}

/***** PrintBooksInStock Function *****/
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
void PrintBooksInStock(exbookType bookArray[], int &bookCount)
{
    // Loop to total amount of books
    for (int i = 0; i < bookCount; i++)
    {
        // If the book is in stock
        // (If the copies available inside bookArray are greater than 0)
        if (bookArray[i].getCopiesAvailable() > 0)
        {
            // For debugging purposes
            // Call printEXBookDetails data member function to print private member variables
            // bookArray[i].printEXBookDetails();

            // Use overloaded operator (<<) to print private member variables
            cout << bookArray[i] << endl;
        }
    }
}

/***** PrintAllBooks Function *****/
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
void PrintAllBooks(exbookType bookArray[], int &bookCount)
{
    // Loop to total amount of books
    for (int i = 0; i < bookCount; i++)
    {
        // Old method to print the fields of each book
        // Call printEXBookDetails data member function to print private member variables
        // bookArray[i].printEXBookDetails();

        // Use overloaded operator (<<) to print private member variables
        cout << bookArray[i] << endl;
    }
}
