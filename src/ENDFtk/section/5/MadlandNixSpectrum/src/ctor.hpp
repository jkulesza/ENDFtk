/**
 *  @brief Constructor
 *
 *  @param[in] efl             the light fission fragment kinetic energy
 *  @param[in] efh             the heavy fission fragment kinetic energy
 *  @param[in] boundaries      the interpolation range boundaries
 *  @param[in] interpolants    the interpolation types for each range
 *  @param[in] energies        the energy values
 *  @param[in] values.         the maximum temperature values
 */
MadlandNixSpectrum( double efl, double efh,
                    std::vector< long >&& boundaries,
                    std::vector< long >&& interpolants,
                    std::vector< double >&& energies,
                    std::vector< double >&& values )
  try : TabulationRecord( efl, efh, 0, 0,
                          std::move( boundaries ),
                          std::move( interpolants ),
                          std::move( energies ),
                          std::move( values ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Error encountered while constructing a Madland-Nix spectrum" );
    throw;
  }

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
MadlandNixSpectrum( Iterator& begin, const Iterator& end,
                    long& lineNumber, int MAT, int MF, int MT )
  try : TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) {}
  catch ( std::exception& e ) {

    Log::info( "Error encountered while reading a Madland-Nix spectrum" );
    throw;
  }
