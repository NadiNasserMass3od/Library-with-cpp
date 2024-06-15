#include "Book.h"
#include <cstring>

Book::Book() {
  strcpy(Title, "");
  strcpy(Author, "");
  strcpy(Publisher, "");
  Quantity = 0;
  NumberOfPages = 0;
  cost = 0;
}
Book::~Book() {}
