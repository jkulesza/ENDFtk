/** 
 *  @brief Constructor
 *
 *  The number of entries in the temperatures array is checked against the
 *  temperature dependence flag LT (the L1 value on the TabulationRecord).
 *
 *  @param[in] alphas         the TabulationRecord to be moved into the object
 *  @param[in] temperatures   an array of ListRecord, one for each additional
 *                            temperature to be moved into the object
 */
BetaValue( TabulationRecord&& alphas,
           std::vector< ListRecord >&& temperatures ) :
  alphas_( std::move( alphas ) ), temperatures_( std::move( temperatures ) ) {

  verifyLT( this->LT(), this->NT() );
}

/** 
 *  @brief Constructor
 *
 *  The size of the various arrays is checked for consistency where appropriate.
 *
 *  @param[in] beta           the beta value for which data will be given
 *  @param[in] boundaries     the interpolation range boundaries for S(a,beta)
 *  @param[in] interpolants   the interpolation types for each range
 *  @param[in] alphas         the alpha values (NA values)
 *  @param[in] li             the temperature interpolation flags (NT-1 values)
 *  @param[in] temperatures   the temperatures (NT values)
 *  @param[in] sab            the thermal scattering values (NT arrays of NA
 *                            values)
 */
BetaValue( double beta,
           std::vector< long >&& boundaries,
           std::vector< long >&& interpolants,
           std::vector< double >&& alphas,
           std::vector< long >&& li,
           std::vector< double >&& temperatures,
           std::vector< std::vector< double > >&& sab ) :
  BetaValue( TabulationRecord( temperatures[0], beta,
                               temperatures.size() - 1, 0,
                               std::move( boundaries ),
                               std::move( interpolants ),
                               std::move( alphas ),
                               std::move( sab[0] ) ),
             generateTemperatures( beta,
                                   std::move( temperatures ),
                                   std::move( li ),
                                   std::move( sab ) ) ) {}

private:
/** 
 *  @brief Private intermediate constructor
 */
template< typename Iterator >
BetaValue( TabulationRecord&& alphas,
           Iterator& begin,
           const Iterator& end,
           long& lineNumber,
           int MAT,
           int MF,
           int MT ) :
  BetaValue( std::move( alphas ),
             readTemperatures( begin, end, lineNumber,
                               MAT, MF, MT, alphas.L1() ) ) {}

public:
/** 
 *  @brief Constructor (from a buffer)
 *
 *  @tparam Iterator        a buffer iterator
 *
 *  @param[in] it           the current position in the buffer
 *  @param[in] end          the end of the buffer
 *  @param[in] lineNumber   the current line number
 *  @param[in] MAT          the expected MAT number
 *  @param[in] MF           the expected MF number
 *  @param[in] MT           the expected MT number
 */
template< typename Iterator >
BetaValue( Iterator& begin,
           const Iterator& end,
           long& lineNumber,
           int MAT,
           int MF,
           int MT ) :
  BetaValue( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ),
             begin, end, lineNumber, MAT, MF, MT ) {}

