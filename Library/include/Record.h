
#if !defined RecoreInclude
#define RecoreInclude

typedef unsigned int uint;

class RFS;
class Record {
protected:
  uint RecordNumber;
  bool active;
  friend class RFS;

public:
  Record();
  virtual ~Record();
  bool isActive() { return active; }
};

#endif
