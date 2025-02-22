#ifndef NJOY_ENDFTK_CONTROLRECORD
#define NJOY_ENDFTK_CONTROLRECORD

// system includes

// other includes
#include "ENDFtk/record.hpp"

namespace njoy {
namespace ENDFtk {

  class ControlRecord : protected record::Base< record::Real,
                                                record::Real,
                                                record::Integer< 11 >,
                                                record::Integer< 11 >,
                                                record::Integer< 11 >,
                                                record::Integer< 11 > > {
    using base = record::Base< record::Real, record::Real,
                               record::Integer< 11 >, record::Integer< 11 >,
                               record::Integer< 11 >, record::Integer< 11 > >;

    using tail = record::TailVerifying< record::MAT, record::MF, record::MT >;

  public:
    ControlRecord( double C1, double C2,
                   long L1, long L2, long N1, long N2 ) :
      base( C1, C2, L1, L2, N1, N2 ){}

    template< typename Iterator >
    ControlRecord( Iterator& it, const Iterator& end, long& lineNumber,
                   int MAT, int MF, int MT )
      try: base( it, end ){
        tail( MAT, MF, MT, it, end, lineNumber );
      } catch ( std::exception& e ) {
        /* TODO error information here */
        throw e;
      } catch ( int fieldNo ){
        --lineNumber;
        /* TODO error information here */
        throw std::exception();
      }

  #define DEFINE_GETTER( name, index )                            \
    MutableReturnType< index >                                    \
    name (){ return std::get< index >( this->fields ); }          \
                                                                  \
    ImmutableReturnType< index >                                  \
    name () const { return std::get< index >( this->fields ); }

    DEFINE_GETTER( C1, 0 )
    DEFINE_GETTER( C2, 1 )
    DEFINE_GETTER( L1, 2 )
    DEFINE_GETTER( L2, 3 )
    DEFINE_GETTER( N1, 4 )
    DEFINE_GETTER( N2, 5 )

  #undef DEFINE_GETTER

    bool
    operator==( const ControlRecord& rhs ) const {
      return static_cast< const base& >( *this ) == rhs;
    }

    bool
    operator!=( const ControlRecord& rhs ) const {
      return not( *this == rhs );
    }

    long NC() const { return 1; }

    #include "ENDFtk/ControlRecord/src/print.hpp"
  };

  using CONT = ControlRecord;

} // ENDFtk namespace
} // njoy namespace

#endif
