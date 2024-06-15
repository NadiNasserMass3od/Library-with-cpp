#include "RFS.h"

RFS::~RFS() { F.close(); }

RFS::RFS(int sor, char filename[]) {
  numberOfRecords = 0;
  sizeOfRecord = sor;
  F.open(filename, ios::app | ios::in | ios::out | ios::binary);
  F.close(); // to create it if not exist
  F.open(filename, ios::in | ios::out | ios::binary);
  if (good()) {
    cout << filename << " is open.\n";
    F.seekg(0, ios::end);
    numberOfRecords = F.tellg() / sizeOfRecord;
  } else
    cout << "could not open" << filename << endl;
}

bool RFS::update(Record *r) { return put(r, r->RecordNumber); }

bool RFS::get(Record *r, uint i) {
  if (!good()) {
    cout << "Error reading from file.\n";
    return false;
  }
  if (i < numberOfRecords) {
    F.seekp(recordLocation(i), ios::beg);
    F.read((char *)r, sizeOfRecord);
    return true;
  } else
    return false;
}

bool RFS::put(Record *r, uint i) {
  if (!good()) {
    cout << "Error writing to file.\n";
    return false;
  }
  if (i == -1) {
    r->active = true;
    r->RecordNumber = numberOfRecords;
    F.seekp(recordLocation(numberOfRecords), ios::beg);
    F.write((char *)r, sizeOfRecord);
    numberOfRecords++;
    return true;
  } else {
    if (i < numberOfRecords) {
      r->RecordNumber = i;
      F.seekp(recordLocation(i), ios::beg);
      F.write((char *)r, sizeOfRecord);
      return true;
    } else
      return false;
  }
}

bool RFS::del(Record *r) {
  r->active = false;
  return put(r, r->RecordNumber);
}

bool RFS::good() { return F.good(); }

bool RFS::restor(Record *r, uint i) {
  r->active = true;
  return put(r, r->RecordNumber);
}
