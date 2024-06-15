#include "Library.h"
#include "Book.h"
#include <cstring>
#include <iomanip>
#include <queue>

Library::Library(char filename[]) : rfs(sizeof(Book), filename) {}

bool Library::AddNewBook() {
  bool flag = true;
  Book newBook;
  cout << "\t\t\tAdding new book.\n\n";
  cout << "Book number: ";
  cin >> newBook.Number;

  Book book;
  unsigned int location;
  location = 0;
  while (true) {
    if (!rfs.get(&book, location++)) {
      flag = false;
      break;
    }
    while (newBook.Number != book.Number || !book.isActive()) {
      if (!rfs.get(&book, location++)) {
        flag = false;
        break;
      }
    }
    break;
  }
  if (flag) {
    cout << "This number is already exist.\n";
    return false;
  } else {
    flag = true;
    cin.ignore();
    cout << "Book name: ";
    cin.getline(newBook.Title, 100);
    while (true) {
      location = 0;
      if (!rfs.get(&book, location++)) {
        flag = false;
        break;
      }
      while ((strcmp(newBook.Title, book.Title)) || !book.isActive()) {
        if (!rfs.get(&book, location++)) {
          flag = false;
          break;
        }
      }
      break;
    }
    if (flag) {
      cout << "This title is already exist.\n";
      return false;
    } else {
      cout << "Book author: ";
      cin.getline(newBook.Author, 100);
      cout << "Book publisher: ";
      cin.getline(newBook.Publisher, 100);
      cout << "Book quantity: ";
      cin >> newBook.Quantity;
      cout << "Book number of pages: ";
      cin >> newBook.NumberOfPages;
      cout << "Book cost: ";
      cin >> newBook.cost;
    }
  }

  return rfs.put(&newBook);
}
bool Library::SearchForTitleBook() {
  Book book;
  char Title[100];
  unsigned int location;
  cout << "\t\t\tSearch for book by title.\n\n";
  cin.ignore();
  cout << "Enter book title for search: ";
  cin.getline(Title, 100);
  location = 0;
  if (!rfs.get(&book, location++))
    return false;
  while ((strcmp(Title, book.Title)) || !book.isActive()) {
    if (!rfs.get(&book, location++))
      return false;
  }
  cout << "Book number: " << book.Number << endl;
  cout << "Book name: " << book.Title << endl;
  cout << "Book author: " << book.Author << endl;
  cout << "Book publisher: " << book.Publisher << endl;
  cout << "Book quantity: " << book.Quantity << endl;
  cout << "Book number of pages: " << book.NumberOfPages << endl;
  cout << "Book cost: " << book.cost << endl;
  return true;
}
bool Library::SearchForNumberBook() {
  Book book;
  unsigned int number;
  unsigned int location;
  cout << "\t\t\tSearch for book by number.\n\n";
  cout << "Enter book number for search: ";
  cin >> number;
  location = 0;
  if (!rfs.get(&book, location++))
    return false;
  while (number != book.Number || !book.isActive()) {
    if (!rfs.get(&book, location++))
      return false;
  }
  cout << "Book number: " << book.Number << endl;
  cout << "Book name: " << book.Title << endl;
  cout << "Book author: " << book.Author << endl;
  cout << "Book publisher: " << book.Publisher << endl;
  cout << "Book quantity: " << book.Quantity << endl;
  cout << "Book number of pages: " << book.NumberOfPages << endl;
  cout << "Book cost: " << book.cost << endl;
  return true;
}
bool Library::FindBookByAuthor() {
  bool ans = false;
  Book book;
  queue<Book> booklist;
  int count = 0;
  int location = 0;
  char Author[100];
  cout << "\t\t\tFind all books by author.\n\n";
  cin.ignore();
  cout << "Enter name of author for search: ";
  cin.getline(Author, 100);
  for (; rfs.get(&book, location); location++) {
    if ((strcmp(Author, book.Author)) == 0 && book.isActive()) {
      ans = true;
      booklist.push(book);
    }
  }
  cout << "Search completed.\n";
  count = booklist.size();
  for (int i = 0; i < count; i++) {
    book = booklist.front();
    cout << "Book number: " << book.Number << endl;
    cout << "Book name: " << book.Title << endl;
    cout << "Book publisher: " << book.Publisher << endl;
    cout << "Book quantity: " << book.Quantity << endl;
    cout << "Book number of pages: " << book.NumberOfPages << endl;
    cout << "Book cost: " << book.cost << endl;
    cout << "---------------------------\n";
    booklist.pop();
  }
  cout << "Number of book by author " << Author << " " << count << endl;
  return ans;
}
bool Library::FindBookByPublisher() {
  bool ans = false;
  Book book;
  queue<Book> booklist;
  int count = 0;
  int location = 0;
  char Publisher[100];
  cout << "\t\t\tFind all books by publisher.\n\n";
  cin.ignore();
  cout << "Enter name of publisher for search: ";
  cin.getline(Publisher, 100);
  for (; rfs.get(&book, location); location++) {
    if ((strcmp(Publisher, book.Publisher)) == 0 && book.isActive()) {
      ans = true;
      booklist.push(book);
    }
  }
  cout << "Search completed.\n";
  count = booklist.size();
  for (int i = 0; i < count; i++) {
    book = booklist.front();
    cout << "Book number: " << book.Number << endl;
    cout << "Book name: " << book.Title << endl;
    cout << "Book author: " << book.Author << endl;
    cout << "Book quantity: " << book.Quantity << endl;
    cout << "Book number of pages: " << book.NumberOfPages << endl;
    cout << "Book cost: " << book.cost << endl;
    cout << "---------------------------\n";
    booklist.pop();
  }
  cout << "Number of book by publisher " << Publisher << " " << count << endl;
  return ans;
}
bool Library::ModifyBookCost() {
  Book book;
  int location = 0;
  unsigned int num;
  unsigned int cost;
  cout << "\t\t\tModify book cost.\n\n";
  cout << "Enter book number for modify: ";
  cin >> num;
  for (; rfs.get(&book, location); location++) {
    if (num == book.Number && book.isActive()) {
      cout << "Book number: " << book.Number << endl;
      cout << "Book name: " << book.Title << endl;
      cout << "Book author: " << book.Author << endl;
      cout << "Book publisher: " << book.Publisher << endl;
      cout << "Book quantity: " << book.Quantity << endl;
      cout << "Book number of pages: " << book.NumberOfPages << endl;
      cout << "Book cost: " << book.cost << endl;
      cout << "\n\n\n";
      cout << "Old cost: " << book.cost << endl;
      cout << "New cost: ";
      cin >> cost;
      book.cost = cost;
      return rfs.put(&book, location);
    }
  }
  return false;
}
bool Library::ModifyBookQuantity() {
  Book book;
  int location = 0;
  unsigned int num;
  unsigned int quantity;
  cout << "\t\t\tModify book quantity.\n\n";
  cout << "Enter book number for modify: ";
  cin >> num;
  for (; rfs.get(&book, location); location++) {
    if (num == book.Number && book.isActive()) {
      cout << "Book number: " << book.Number << endl;
      cout << "Book name: " << book.Title << endl;
      cout << "Book author: " << book.Author << endl;
      cout << "Book publisher: " << book.Publisher << endl;
      cout << "Book quantity: " << book.Quantity << endl;
      cout << "Book number of pages: " << book.NumberOfPages << endl;
      cout << "Book cost: " << book.cost << endl;
      cout << "\n\n\n";
      cout << "Old quantity: " << book.Quantity << endl;
      cout << "New quantity: ";
      cin >> quantity;
      book.Quantity = quantity;
      return rfs.put(&book, location);
    }
  }
  return false;
}
bool Library::RemoveBook() {
  Book book;
  int location = 0;
  unsigned int num;
  cout << "\t\t\tRemove book.\n\n";
  cout << "Enter Book Nnumber to be removed: ";
  cin >> num;
  for (; rfs.get(&book, location); location++) {
    if (num == book.Number && book.isActive()) {
      return rfs.del(&book);
    }
  }
  return false;
}
bool Library::SortByTitle() {
  bool flage = true;
  Book book1, book2;
  char Title[100];
  unsigned int Loc1, Loc2, count = 0;
  unsigned int NRecords;
  cout << "\t\t\t\nSort books by title.\n\n";
  NRecords = rfs.GetNumberOfRecords();

  for (Loc1 = 0; Loc1 < NRecords - 1; Loc1++) {
    for (Loc2 = Loc1 + 1; Loc2 < NRecords; Loc2++) {
      if (!rfs.get(&book1, Loc1))
        return false;
      if (!rfs.get(&book2, Loc2))
        return false;
      if (!book2.isActive())
        continue;
      if ((!book1.isActive()) || strcmp(book1.Title, book2.Title) > 0) {
        rfs.put(&book2, Loc1);
        rfs.put(&book1, Loc2);
      }
      if (strlen(book1.Title) > 30 || strlen(book2.Title) > 30)
        flage = false;
    }
  }
  Loc1 = 0;
  while ((rfs.get(&book1, Loc1++)) && (book1.isActive())) {
    count++;
    break;
  }

  if (count == 0)
    return false;

  if (flage) {
    cout << "Sorting completed.\n";
    cout << "Book\n";
    cout << setw(8) << left << "number";
    cout << setw(30) << left << "name";
    cout << setw(20) << left << "author";
    cout << setw(20) << left << "publisher";
    cout << setw(9) << left << "quantity";
    cout << setw(7) << left << "pages";
    cout << setw(6) << left << "cost";
    Loc1 = 0;
    while ((rfs.get(&book1, Loc1++)) && (book1.isActive())) {
      cout << endl;
      cout << setw(8) << left << book1.Number;
      cout << setw(30) << left << book1.Title;
      cout << setw(20) << left << book1.Author;
      cout << setw(20) << left << book1.Publisher;
      cout << setw(9) << left << book1.Quantity;
      cout << setw(7) << left << book1.NumberOfPages;
      cout << setw(6) << left << book1.cost;
    }
  } else {
    Loc1 = 0;
    while ((rfs.get(&book1, Loc1++)) && (book1.isActive())) {
      cout << "Book number: " << book1.Number << endl;
      cout << "Book name: " << book1.Title << endl;
      cout << "Book author: " << book1.Author << endl;
      cout << "Book publisher: " << book1.Publisher << endl;
      cout << "Book quantity: " << book1.Quantity << endl;
      cout << "Book number of pages: " << book1.NumberOfPages << endl;
      cout << "Book cost: " << book1.cost << endl;
      cout << "---------------------------\n";
    }
  }
  return true;
}
bool Library::FindBookWithZeroQuan() {
  bool ans = false;
  Book book;
  queue<Book> booklist;
  int count = 0;
  int location = 0;
  cout << "\t\t\tFind all books with zero quantity.\n\n";
  for (; rfs.get(&book, location); location++) {
    if (book.Quantity == 0 && book.isActive()) {
      ans = true;
      booklist.push(book);
    }
  }
  cout << "Search completed.\n";
  count = booklist.size();
  for (int i = 0; i < count; i++) {
    book = booklist.front();
    cout << "Book number: " << book.Number << endl;
    cout << "Book name: " << book.Title << endl;
    cout << "Book publisher: " << book.Publisher << endl;
    cout << "Book quantity: " << book.Quantity << endl;
    cout << "Book number of pages: " << book.NumberOfPages << endl;
    cout << "Book cost: " << book.cost << endl;
    cout << "----------------------------------------------\n";
    booklist.pop();
  }
  cout << "Number of books with zero quantity " << count << endl;
  return ans;
}
bool Library::FindBookWithCost() {
  bool ans = false;
  Book book;
  queue<Book> booklist;
  int count = 0;
  int location = 0;
  int cost;
  cout << "\t\t\tFind all books with cost above a given value.\n\n";
  cout << "Enter reference cost: ";
  cin >> cost;
  for (; rfs.get(&book, location); location++) {
    if (book.cost > cost && book.isActive()) {
      ans = true;
      booklist.push(book);
    }
  }
  cout << "Search completed.\n";
  count = booklist.size();
  for (int i = 0; i < count; i++) {
    book = booklist.front();
    cout << "Book number: " << book.Number << endl;
    cout << "Book name: " << book.Title << endl;
    cout << "Book publisher: " << book.Publisher << endl;
    cout << "Book quantity: " << book.Quantity << endl;
    cout << "Book number of pages: " << book.NumberOfPages << endl;
    cout << "Book cost: " << book.cost << endl;
    cout << "----------------------------------------------\n";
    booklist.pop();
  }
  cout << "Number of books with cost above the " << cost << " value is "
       << count << endl;
  return ans;
}
// this is a function for show and restor the deleted book.
/*
bool Library::Trash() {
  bool flag = true, re = false;
  Book book, oldbook;
  unsigned int Loc, count = 0;
  unsigned int NRecords, location;
  cout << "\t\t\t\nThis a trash.\n\n";
  NRecords = rfs.GetNumberOfRecords();

  for (Loc = 0; Loc < NRecords - 1; Loc++) {
    if (!rfs.get(&book, Loc))
      return false;
    if (!book.isActive()) {
      cout << book.Number << " : " << book.Title << endl;
      count++;
    }
  }

  if (count == 0)
    return false;

  int num;
  cout << "Enter the number of book you want to restore: ";
  cin >> num;
  Loc = 0;
  for (; rfs.get(&book, Loc); Loc++) {
    if (num == book.Number) {
      location = 0;
      while (true) {
        if (!rfs.get(&oldbook, location++)) {
          flag = false;
          break;
        }
        while (num != oldbook.Number || !book.isActive()) {
          if (!rfs.get(&oldbook, location++)) {
            flag = false;
            break;
          }
        }
        break;
      }
      if (flag) {
        cout << "This number is already exist.\n";
        return false;
      } else {
        flag = true;
        while (true) {
          location = 0;
          if (!rfs.get(&oldbook, location++)) {
            flag = false;
            break;
          }
          while ((strcmp(oldbook.Title, book.Title)) || !book.isActive()) {
            if (!rfs.get(&oldbook, location++)) {
              flag = false;
              break;
            }
          }
          break;
        }
        if (flag) {
          cout << "This title is already exist.\n";
          return false;
        } else {
          re = rfs.restor(&book, Loc);
        }
      }
      break;
    }
  }
  return re;
}
*/
