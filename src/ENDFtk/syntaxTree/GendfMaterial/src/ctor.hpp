/**
 * @brief
 */
GendfMaterial( const HeadRecord& head,
               BufferIterator begin,
               BufferIterator& position,
               const BufferIterator& end,
               long& lineNumber )
try: materialNo( head.MAT() ),
     sections_( createMap(head, begin, position, end, lineNumber) ),
     bufferLimits( {begin, position} ) {

  Log::info("Made it into GendfMaterial.  Hooray!");

}
catch( std::exception& e ){
  Log::info("Trouble while constructing GendfMaterial." );
  throw e;
}
