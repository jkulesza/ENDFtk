GendfType(HeadRecord& head,
          BufferIterator& begin,
          const BufferIterator& end,
          long& lineNumber,
          int MAT )
  : Base( head, MAT, head.MF() )  {

  // head record metadata
  _num_legendre = head.L1();
  _num_sigma0 = head.L2();

  // populate list records
  populateLists(head, begin, end, lineNumber, MAT);

  // populate cross sections
  for( size_t i=0; i<list_records.size(); i++) {
    _xs.push_back(list_records[i].list()[1]);
  }

}

