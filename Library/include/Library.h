#if !defined SchoolInclude
#define SchoolInclude
#include "RFS.h"

class Library {
private:
  RFS rfs;
public:
  Library(char filename[]);
  bool AddNewBook();
  bool SearchForTitleBook();
  bool SearchForNumberBook();
  bool FindBookByAuthor();
  bool FindBookByPublisher();
  bool ModifyBookCost();
  bool ModifyBookQuantity();
  bool RemoveBook();
  bool SortByTitle();
  bool FindBookWithZeroQuan();
  bool FindBookWithCost();
  bool Trash();
};
#endif
