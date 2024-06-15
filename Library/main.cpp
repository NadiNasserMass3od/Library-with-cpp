#include "Library.h"
#include <iostream>

using namespace std;

void cleanScreen();
int showMenu();
char againYON();

int main() {
  Library library("library.db");
  char again;
  int choice;
  bool exit = false;

  while (true) {
    cleanScreen();
    choice = showMenu();
    switch (choice) {
    case 1:
      again = 'Y';
      while (again == 'Y') {
        if (library.AddNewBook()) {
          cout << "Book has been successfully added.\n";
          cout << "Do you want to add another (y/n)? ";
          again = againYON();
        } else {
          again = 'N';
          cout << "Can't add a new book.\n";
          cout << "Press any key to continue ";
          cin.get();
        }
      }
      break;
    case 2:
      again = 'Y';
      while (again == 'Y') {
        if (library.SearchForTitleBook()) {
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        } else {
          cout << "Can't find this book.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 3:
      again = 'Y';
      while (again == 'Y') {
        if (library.SearchForNumberBook()) {
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        } else {
          cout << "Can't find this book.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 4:
      again = 'Y';
      while (again == 'Y') {
        if (library.FindBookByAuthor()) {
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        } else {
          cout << "This author not written any book.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 5:
      again = 'Y';
      while (again == 'Y') {
        if (library.FindBookByPublisher()) {
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        } else {
          cout << "This publisher not written any book.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 6:
      again = 'Y';
      while (again == 'Y') {
        if (library.ModifyBookCost()) {
          cout << "A book has been successfully modified.\n";
          cout << "Do you want to modify another (y/n)? ";
          again = againYON();
        } else {
          cout << "This book doesn't exist.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 7:
      again = 'Y';
      while (again == 'Y') {
        if (library.ModifyBookQuantity()) {
          cout << "A book has been successfully modified.\n";
          cout << "Do you want to modify another (y/n)? ";
          again = againYON();
        } else {
          cout << "This book doesn't exist.\n";
          cout << "Do you want to search for another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 8:
      again = 'Y';
      while (again == 'Y') {
        if (library.RemoveBook()) {
          cout << "A book has been successfully removed.\n";
          cout << "Do you want to remove another (y/n)? ";
          again = againYON();
        } else {
          cout << "This book doesn't exist.\n";
          cout << "Do you want to remove another (y/n)? ";
          again = againYON();
        }
      }
      break;
    case 9:
      if (library.SortByTitle()) {
        cout << "\nPress any key to continue ";
        cin.get();
      } else {
        cout << "This data base is empty.\n";
        cout << "Press any key to continue ";
        cin.get();
      }
      break;
    case 10:
      if (library.FindBookWithZeroQuan()) {
        cout << "Press any key to continue ";
        cin.get();
      } else {
        cout << "Can't find any book with zero quantity.\n";
        cout << "Press any key to continue ";
        cin.get();
      }
      break;
    case 11:
      again = 'Y';
      while (again == 'Y') {
        if (library.FindBookWithCost()) {
          cout << "Do you want to add another (y/n)? ";
          again = againYON();
        } else {
          cout << "Can't find any book with cost above a given value.\n";
          cout << "Do you want to add another (y/n)? ";
          again = againYON();
        }
      }
      break;
      // this for check the Trash function.
      /*
          case 12:
            again = 'Y';
            while (again == 'Y') {
              if (library.Trash()) {
                cout << "This book is restored.\n";
                cout << "Do you want to modify another (y/n)? ";
                again = againYON();
              } else {
                cout << "can't restore this book.\n";
                cout << "Do you want to modify another (y/n)? ";
                again = againYON();
              }
            }
            break;
      */
    case 12:
      exit = true;
      break;
    default:
      cout << "Error in input number you must enter in range(1....12).\n";
      cout << "Press any key to continue ";
    }
    if (exit)
      break;
  }
  cout << endl;
  return 0;
}

void cleanScreen() {
  cin.ignore();
  cout.flush();
  for (int i = 0; i < 25; i++)
    cout << endl;
}

int showMenu() {
  int choice;
  cout << "		                MainMenu\n"
          "		       (1) Add New Book.\n"
          "		       (2) Search for a book (by book title).\n"
          "		       (3) Search for a book (by book number).\n"
          "		       (4) Find all books by author.\n"
          "		       (5) Find all books by publisher.\n"
          "		       (6) Modify book cost (provide book number).\n"
          "		       (7) Modify book quantity (provide book "
          "number).\n"
          "		       (8) Remove book (provide book number).\n"
          "		       (9) Sort books by title.\n"
          "		       (10) Find all books with zero quantity.\n"
          "		       (11) Find all books with cost above a given "
          "value (provide reference cost).\n"
          // "		       (12) The trash.\n"
          "		       (12) Exit.\n"
          "		Enter your choice (1...12) :";
  cin >> choice;
  cin.ignore();
  return choice;
}

char againYON() {
  char again = 0;
  while ((again != 'Y') && (again != 'N')) {
    again = cin.get();
    again = toupper(again);
  }
  return again;
}
