LegendreCoefficients( ListRecord&& list ) :
  ListRecord( std::move( list ) ) {

    verifyLANG( this->L1() );
    verifySize( this->NW(), this->NL() );
};

LegendreCoefficients( double energy, std::vector< double >&& coefficients ) :
  // this can never fail, try-catch would be unreachable
  LegendreCoefficients( ListRecord( 0.0, energy, 0, 0,
                                    coefficients.size(),
                                    std::move( coefficients ) ) ) {}

template< typename Iterator >
LegendreCoefficients( Iterator& it, const Iterator& end, long& lineNumber,
                      int MAT, int MF, int MT )
  try : LegendreCoefficients(
          ListRecord( it, end, lineNumber, MAT, MF, MT ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while reading Legendre coefficients "
               "(LAW=2 LANG=0)" );
    throw;
  }
