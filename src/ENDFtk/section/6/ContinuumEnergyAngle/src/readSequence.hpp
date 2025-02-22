template< typename Iterator >
static std::vector< Variant >
readSequence( long lang,
              long nep,
              Iterator& begin,
              const Iterator& end,
              long& lineNumber,
              int MAT,
              int MF,
              int MT ) {

  std::vector< Variant > sequence;
  sequence.reserve( nep );

  while( nep-- ) {
    switch ( lang ) {
      case 1 : sequence.emplace_back(
                  LegendreCoefficients( begin, end, lineNumber, MAT, MF, MT ) );
                  break;
      case 2 : sequence.emplace_back(
                  KalbachMann( begin, end, lineNumber, MAT, MF, MT ) );
                  break;
      case 3 : sequence.emplace_back(
                  ThermalScatteringData( begin, end, lineNumber, MAT, MF, MT ) );
                  break;
      case 11 :
      case 12 :
      case 13 :
      case 14 :
      case 15 : sequence.emplace_back(
                  Tabulated( lang, begin, end, lineNumber, MAT, MF, MT ) );
                  break;
      default : {

        Log::error( "Encountered illegal LANG value" );
        Log::info( "LANG must be equal to 1, 2, 3, 11, 12, 13, 14 or 15" );
        Log::info( "LANG value: {}", lang );
        throw std::exception();
      }
    }
  }

  return sequence;
}
