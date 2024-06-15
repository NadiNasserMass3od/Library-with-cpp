#include "RFS.h"

#if !defined StudentInclude
#define StudentInclude

class Book : public Record {
public:
  unsigned int Number;
  char Title[100];
  char Author[100];
  char Publisher[100];
  unsigned int Quantity;
  unsigned int NumberOfPages;
  unsigned int cost;

public:
  Book();
  virtual ~Book();
};

#endif
