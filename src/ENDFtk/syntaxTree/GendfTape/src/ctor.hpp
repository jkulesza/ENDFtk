/**
 * @brief
 */
GendfTape( std::string buffer, long ln = 0 )
  : buffer_(buffer) {

  Log::info( "Successfully got into GendfTape class." );

  auto begin = buffer.begin();
  auto end = buffer.end();

  auto tpid = TapeIdentification(begin, end, ln);
  materials_ = createMap( begin, end );

}
