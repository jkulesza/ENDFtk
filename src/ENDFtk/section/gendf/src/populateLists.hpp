template< typename Iterator >
void populateLists(HeadRecord& head,
                    Iterator& begin,
                    const Iterator& end,
                    long& lineNumber,
                    int MAT ) {

  // first list record
  list_records.emplace_back(
    ListRecord(begin, end, lineNumber, MAT, head.MF(), head.MT()) );

  // loop until SEND is found
  while( list_records.back().N2() < head.N2() ) {

    // emplace next record
    list_records.emplace_back(
      ListRecord(begin, end, lineNumber, MAT, head.MF(), head.MT()) );

  }

  // read SEND card
  readSEND(begin, end, lineNumber, MAT, head.MF());

}
