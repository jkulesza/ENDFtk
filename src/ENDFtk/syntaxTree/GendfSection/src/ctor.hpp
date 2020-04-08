/**
 * @brief Main constructor
 *
 * @param begin : start of string buffer (value)
 * @param position : current cursor position (changes)
 * @param end : end of string buffer (const)
 * @param lineNo : current line number
 */
GendfSection( const HeadRecord& head,
              BufferIterator begin,
              BufferIterator& position,
              const BufferIterator& end,
              long& lineNo )
try: fileNo_( head.MF() ),   
     sectionNo_( head.MT() ),
     bufferLimits( { begin, findEnd(position, end, lineNo) } ) {
  Log::info( "Successfully made it into GendfSection!" );
}
catch( std::exception& e ){
  Log::info( "Trouble when creating a syntaxTree::GendfSection" );
  throw e;
}
