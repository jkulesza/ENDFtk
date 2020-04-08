/**
 * @brief Find end of section record
 */
static BufferIterator findEnd( BufferIterator& position,
                               const BufferIterator& end,
                               long& lineNumber ){

  while( record::skip( position, end, lineNumber ).MT() != 0 ){
    if( position >= end ){
      Log::error( "Section encountered end of stream before reading SEND" );
      throw std::exception();
    }
  }
  return position;

}
