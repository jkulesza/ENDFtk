
static auto
createMap( BufferIterator position, const BufferIterator& end ){

  std::multimap< int, GendfMaterial > materials;
  long ln{ 0 };

  auto begin = position;
  auto division = StructureDivision( position, end, ln );

  while ( not division.isTend() ) {
    materials.emplace( division.tail.MAT(),
                       GendfMaterial( asHead( division ),
                                      begin, position, end, ln ) );

    begin = position;
    division = StructureDivision( position, end, ln );
  }

  return materials;
}
