#if !defined RFSInclude
#define RFSInclude

#include "Record.h"
#include <fstream>
#include <iostream>


using namespace std;

typedef unsigned int uint;

class RFS {
protected:
  uint numberOfRecords;
  uint sizeOfRecord;
  fstream F;
  uint recordLocation(uint i) { return (i * sizeOfRecord); }

public:
  RFS(int sor, char filename[]);
  bool get(Record *r, uint i);
  bool put(Record *r, uint i = -1);
  bool restor(Record *r, uint i);
  bool update(Record *r);
  bool del(Record *r);
  bool good();
  uint GetNumberOfRecords() { return numberOfRecords; }
  virtual ~RFS();
};
#endif
