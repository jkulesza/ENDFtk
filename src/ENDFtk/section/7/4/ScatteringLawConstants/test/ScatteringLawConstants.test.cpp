#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk/section/7/4.hpp"

// other includes

// convenience typedefs
using namespace njoy::ENDFtk;
using ScatteringLawConstants =
section::Type< 7, 4 >::ScatteringLawConstants;

std::string chunkWithOnlyPrincipalScatterer();
void verifyChunkWithOnlyPrincipalScatterer( const ScatteringLawConstants& );
std::string chunkWithBothPrincipalAndSecondaryScatterer();
void verifyChunkWithBothPrincipalAndSecondaryScatterer(
       const ScatteringLawConstants& );
std::string chunkWithTwoSecondaryScatterers();
void verifyChunkWithTwoSecondaryScatterers( const ScatteringLawConstants& );
std::string chunkWithThreeSecondaryScatterers();
void verifyChunkWithThreeSecondaryScatterers( const ScatteringLawConstants& );
std::string invalidSize();
std::string invalidLLN();
std::string invalidNS();

SCENARIO( "ScatteringLawConstants" ) {

  GIVEN( "valid data for a ScatteringLawConstants with only a principal "
         "scatterer" ) {

    std::string string = chunkWithOnlyPrincipalScatterer();

    WHEN( "the data is given explicitly" ) {

      int lln = 0;
      int ns = 0;
      std::vector< double > values = { 6.153875e+0, 1.976285e+2, 8.934780e+0,
                                       5.000001e+0, 0.000000e+0, 1.000000e+0 };
      double epsilon = 1.976285e+2;
      double emax = 5.000001e+0;
      std::vector< double > crossSections = { 6.153875e+0 };
      std::vector< double > weightRatios = { 8.934780e+0 };
      std::vector< unsigned int > numberAtoms = { 1 };
      std::vector< unsigned int > functionTypes = {};
      double crossSection = 6.153875e+0;
      double weightRatio = 8.934780e+0;
      unsigned int numberAtom = 1;

      ScatteringLawConstants chunk( lln, ns, std::move( values ) );

      ScatteringLawConstants chunk2( lln, ns, epsilon, emax,
                                     std::move( crossSections ),
                                     std::move( weightRatios ),
                                     std::move( numberAtoms ),
                                     std::move( functionTypes ) );

      ScatteringLawConstants chunk3( lln, epsilon, emax, crossSection,
                                     weightRatio, numberAtom );

      THEN( "a ScatteringLawConstants can be constructed using a list and "
            "members can be tested" ) {

        verifyChunkWithOnlyPrincipalScatterer( chunk );
      } // THEN

      THEN( "a ScatteringLawConstants can be constructed using separate arrays "
            "and members can be tested" ) {

        verifyChunkWithOnlyPrincipalScatterer( chunk2 );
      } // THEN

      THEN( "a ScatteringLawConstants can be constructed using individual "
            "values and members can be tested" ) {

        verifyChunkWithOnlyPrincipalScatterer( chunk3 );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );

        std::string buffer2;
        output = std::back_inserter( buffer2 );
        chunk2.print( output, 27, 7, 4 );

        REQUIRE( buffer2 == string );

        std::string buffer3;
        output = std::back_inserter( buffer3 );
        chunk3.print( output, 27, 7, 4 );

        REQUIRE( buffer3 == string );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      ScatteringLawConstants chunk( begin, end, lineNumber, 27, 7, 4 );

      THEN( "a ScatteringLawConstants can be constructed and members can be "
            "tested" ) {

        verifyChunkWithOnlyPrincipalScatterer( chunk );
      }

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );
      } // THEN
    } // GIVEN
  } // GIVEN

  GIVEN( "valid data for a ScatteringLawConstants with both principal and "
         "secondary scatterers" ) {

    std::string string = chunkWithBothPrincipalAndSecondaryScatterer();

    WHEN( "the data is given explicitly" ) {

      int lln = 0;
      int ns = 1;
      std::vector< double > values = { 2.021000e+0, 9.750000e+1, 2.784423e+1,
                                       2.466750e+0, 0.000000e+0, 1.000000e+0,
                                       0.000000e+0, 3.748750e+0, 1.586200e+1,
                                       0.000000e+0, 0.000000e+0, 2.000000e+0 };
      double epsilon = 9.750000e+1;
      double emax = 2.466750e+0;
      std::vector< double > crossSections = { 2.021000e+0, 3.748750e+0 };
      std::vector< double > weightRatios = { 2.784423e+1, 1.586200e+1 };
      std::vector< unsigned int > numberAtoms = { 1, 2 };
      std::vector< unsigned int > functionTypes = { 0 };

      ScatteringLawConstants chunk( lln, ns, std::move( values ) );

      ScatteringLawConstants chunk2( lln, ns, epsilon, emax,
                                     std::move( crossSections ),
                                     std::move( weightRatios ),
                                     std::move( numberAtoms ),
                                     std::move( functionTypes ) );

      THEN( "a ScatteringLawConstants can be constructed using a list and "
            "members can be tested" ) {

        verifyChunkWithBothPrincipalAndSecondaryScatterer( chunk );
      } // THEN

      THEN( "a ScatteringLawConstants can be constructed using separate arrays "
            "and members can be tested" ) {

        verifyChunkWithBothPrincipalAndSecondaryScatterer( chunk2 );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );

        std::string buffer2;
        output = std::back_inserter( buffer2 );
        chunk2.print( output, 27, 7, 4 );

        REQUIRE( buffer2 == string );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      ScatteringLawConstants chunk( begin, end, lineNumber, 27, 7, 4 );

      THEN( "a ScatteringLawConstants can be constructed and members can be "
            "tested" ) {

        verifyChunkWithBothPrincipalAndSecondaryScatterer( chunk );
      }

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );
      } // THEN
    } // GIVEN
  } // GIVEN

  GIVEN( "valid data for a ScatteringLawConstants two secondary scatterers" ) {

    std::string string = chunkWithTwoSecondaryScatterers();

    WHEN( "the data is given explicitly" ) {

      int lln = 0;
      int ns = 2;
      std::vector< double > values = { 2.021000e+0, 9.750000e+1, 2.784423e+1,
                                       2.466750e+0, 0.000000e+0, 1.000000e+0,
                                       0.000000e+0, 3.748750e+0, 1.586200e+1,
                                       0.000000e+0, 0.000000e+0, 2.000000e+0,
                                       1.000000e+0, 4.000000e+0, 2.000000e+0,
                                       0.000000e+0, 0.000000e+0, 3.000000e+0 };
      double epsilon = 9.750000e+1;
      double emax = 2.466750e+0;
      std::vector< double > crossSections = { 2.021000e+0, 3.748750e+0, 4. };
      std::vector< double > weightRatios = { 2.784423e+1, 1.586200e+1, 2. };
      std::vector< unsigned int > numberAtoms = { 1, 2, 3 };
      std::vector< unsigned int > functionTypes = { 0, 1 };

      ScatteringLawConstants chunk( lln, ns, std::move( values ) );

      ScatteringLawConstants chunk2( lln, ns, epsilon, emax,
                                     std::move( crossSections ),
                                     std::move( weightRatios ),
                                     std::move( numberAtoms ),
                                     std::move( functionTypes ) );

      THEN( "a ScatteringLawConstants can be constructed using a list and "
            "members can be tested" ) {

        verifyChunkWithTwoSecondaryScatterers( chunk );
      } // THEN

      THEN( "a ScatteringLawConstants can be constructed using separate arrays "
            "and members can be tested" ) {

        verifyChunkWithTwoSecondaryScatterers( chunk2 );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );

        std::string buffer2;
        output = std::back_inserter( buffer2 );
        chunk2.print( output, 27, 7, 4 );

        REQUIRE( buffer2 == string );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      ScatteringLawConstants chunk( begin, end, lineNumber, 27, 7, 4 );

      THEN( "a ScatteringLawConstants can be constructed and members can be "
            "tested" ) {

        verifyChunkWithTwoSecondaryScatterers( chunk );
      }

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );
      } // THEN
    } // GIVEN
  } // GIVEN

  GIVEN( "valid data for a ScatteringLawConstants three secondary scatterers" ) {

    std::string string = chunkWithThreeSecondaryScatterers();

    WHEN( "the data is given explicitly" ) {

      int lln = 0;
      int ns = 3;
      std::vector< double > values = { 2.021000e+0, 9.750000e+1, 2.784423e+1,
                                       2.466750e+0, 0.000000e+0, 1.000000e+0,
                                       0.000000e+0, 3.748750e+0, 1.586200e+1,
                                       0.000000e+0, 0.000000e+0, 2.000000e+0,
                                       1.000000e+0, 4.000000e+0, 2.000000e+0,
                                       0.000000e+0, 0.000000e+0, 3.000000e+0,
                                       2.000000e+0, 8.000000e+0, 4.000000e+0,
                                       0.000000e+0, 0.000000e+0, 4.000000e+0 };
      double epsilon = 9.750000e+1;
      double emax = 2.466750e+0;
      std::vector< double > crossSections = { 2.021000e+0, 3.748750e+0, 4., 8. };
      std::vector< double > weightRatios = { 2.784423e+1, 1.586200e+1, 2., 4. };
      std::vector< unsigned int > numberAtoms = { 1, 2, 3, 4 };
      std::vector< unsigned int > functionTypes = { 0, 1, 2 };

      ScatteringLawConstants chunk( lln, ns, std::move( values ) );

      ScatteringLawConstants chunk2( lln, ns, epsilon, emax,
                                     std::move( crossSections ),
                                     std::move( weightRatios ),
                                     std::move( numberAtoms ),
                                     std::move( functionTypes ) );

      THEN( "a ScatteringLawConstants can be constructed using a list and "
            "members can be tested" ) {

        verifyChunkWithThreeSecondaryScatterers( chunk );
      } // THEN

      THEN( "a ScatteringLawConstants can be constructed using separate arrays "
            "and members can be tested" ) {

        verifyChunkWithThreeSecondaryScatterers( chunk2 );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );

        std::string buffer2;
        output = std::back_inserter( buffer2 );
        chunk2.print( output, 27, 7, 4 );

        REQUIRE( buffer2 == string );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      ScatteringLawConstants chunk( begin, end, lineNumber, 27, 7, 4 );

      THEN( "a ScatteringLawConstants can be constructed and members can be "
            "tested" ) {

        verifyChunkWithThreeSecondaryScatterers( chunk );
      }

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 27, 7, 4 );

        REQUIRE( buffer == string );
      } // THEN
    } // GIVEN
  } // GIVEN

  GIVEN( "invalid data" ) {

    WHEN( "data with inconsistent sizes are used" ) {

      int lln = 0;
      int ns = 0;
      double epsilon = 1.976285e+2;
      double emax = 5.000001e+0;
      std::vector< double > crossSections = { 6.153875e+0 };
      std::vector< double > weightRatios = { 8.934780e+0 };
      std::vector< unsigned int > numberAtoms = { 1 };
      std::vector< unsigned int > functionTypes = {};

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( lln, ns, epsilon, emax,
                                                {},
                                                std::move( weightRatios ),
                                                std::move( numberAtoms ),
                                                std::move( functionTypes ) ) );
        REQUIRE_THROWS( ScatteringLawConstants( lln, ns, epsilon, emax,
                                                std::move( crossSections ),
                                                {},
                                                std::move( numberAtoms ),
                                                std::move( functionTypes ) ) );
        REQUIRE_THROWS( ScatteringLawConstants( lln, ns, epsilon, emax,
                                                std::move( crossSections ),
                                                std::move( weightRatios ),
                                                {},
                                                std::move( functionTypes ) ) );
        REQUIRE_THROWS( ScatteringLawConstants( lln, ns, epsilon, emax,
                                                std::move( crossSections ),
                                                std::move( weightRatios ),
                                                std::move( numberAtoms ),
                                                { 1 } ) );
      } // THEN
    } // WHEN

    WHEN( "data with inconsistent NI and NS is used" ) {

      int lln = 0;
      std::vector< double > values = { 6.153875e+0, 1.976285e+2, 8.934780e+0,
                                       5.000001e+0, 0.000000e+0, 1.000000e+0 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( lln, 1, std::move( values ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid NS is used" ) {

      int lln = 0;
      std::vector< double > values = { 6.153875e+0, 1.976285e+2, 8.934780e+0,
                                       5.000001e+0, 0.000000e+0, 1.000000e+0,
                                        7,  8,  9, 10, 11, 12,
                                       13, 14, 15, 16, 17, 18,
                                       19, 20, 21, 22, 23, 24,
                                       25, 26, 27, 28, 29, 30 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( lln, 4, std::move( values ) ) );
      } // THEN
    } // WHEN

    WHEN( "a string with inconsistent NI and NS is used" ) {

      std::string string = invalidSize();
      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( begin, end, lineNumber,
                                                27, 7, 4 ) );
      } // THEN
    } // WHEN

    WHEN( "a string with an invalid NS is used" ) {

      std::string string = invalidNS();
      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( begin, end, lineNumber,
                                                27, 7, 4 ) );
      } // THEN
    } // WHEN

    WHEN( "invalid LLN values are given" ) {

      std::vector< int > invalid = { -1, 2, 5, 10 };

      THEN( "an exception is thrown" ){

        for ( auto lln : invalid ) {

          int ns = 0;
          std::vector< double > values = { 6.153875e+0, 1.976285e+2,
                                           8.934780e+0, 5.000001e+0,
                                           0.000000e+0, 1.000000e+0 };

          REQUIRE_THROWS(
            ScatteringLawConstants( lln, ns, std::move( values ) ) );
        } // THEN
      } // THEN
    } // WHEN

    WHEN( "a string with an invalid LLN is used" ) {

      std::string string = invalidLLN();
      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( ScatteringLawConstants( begin, end, lineNumber,
                                                27, 7, 4 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunkWithOnlyPrincipalScatterer() {
  return
    " 0.000000+0 0.000000+0          0          0          6          0  27 7  4     \n"
    " 6.153875+0 1.976285+2 8.934780+0 5.000001+0 0.000000+0 1.000000+0  27 7  4     \n";
}

void
verifyChunkWithOnlyPrincipalScatterer( const ScatteringLawConstants& chunk ) {

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 0 == chunk.sabStorageType() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 6 == chunk.numberConstants() );
      REQUIRE( 0 == chunk.NS() );
      REQUIRE( 0 == chunk.numberNonPrincipalScatterers() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
}

std::string chunkWithBothPrincipalAndSecondaryScatterer() {
  return
    " 0.000000+0 0.000000+0          0          0         12          1  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n";
}

void verifyChunkWithBothPrincipalAndSecondaryScatterer(
       const ScatteringLawConstants& chunk ) {

  REQUIRE( 0 == chunk.LLN() );
  REQUIRE( 0 == chunk.sabStorageType() );
  REQUIRE( 12 == chunk.NI() );
  REQUIRE( 12 == chunk.numberConstants() );
  REQUIRE( 1 == chunk.NS() );
  REQUIRE( 1 == chunk.numberNonPrincipalScatterers() );

  REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
  REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
  REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
  REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
  REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
  REQUIRE( 2 == chunk.atomicWeightRatios().size() );
  REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
  REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
  REQUIRE( 2 == chunk.numberAtoms().size() );
  REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
  REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
  REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
  REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

  REQUIRE( 3 == chunk.NC() );
}

std::string chunkWithTwoSecondaryScatterers() {
  return
    " 0.000000+0 0.000000+0          0          0         18          2  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n"
    " 1.000000+0 4.000000+0 2.000000+0 0.000000+0 0.000000+0 3.000000+0  27 7  4     \n";
}

void verifyChunkWithTwoSecondaryScatterers(
       const ScatteringLawConstants& chunk ) {

  REQUIRE( 0 == chunk.LLN() );
  REQUIRE( 0 == chunk.sabStorageType() );
  REQUIRE( 18 == chunk.NI() );
  REQUIRE( 18 == chunk.numberConstants() );
  REQUIRE( 2 == chunk.NS() );
  REQUIRE( 2 == chunk.numberNonPrincipalScatterers() );

  REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
  REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
  REQUIRE( 3 == chunk.totalFreeCrossSections().size() );
  REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
  REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
  REQUIRE( 4.000000e+0 == Approx( chunk.totalFreeCrossSections()[2] ) );
  REQUIRE( 3 == chunk.atomicWeightRatios().size() );
  REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
  REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
  REQUIRE( 2.000000e+0 == Approx( chunk.atomicWeightRatios()[2] ) );
  REQUIRE( 3 == chunk.numberAtoms().size() );
  REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
  REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
  REQUIRE( 3. == Approx( chunk.numberAtoms()[2] ) );
  REQUIRE( 2 == chunk.analyticalFunctionTypes().size() );
  REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );
  REQUIRE( 1. == chunk.analyticalFunctionTypes()[1] );

  REQUIRE( 4 == chunk.NC() );
}

std::string chunkWithThreeSecondaryScatterers() {
  return
    " 0.000000+0 0.000000+0          0          0         24          3  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n"
    " 1.000000+0 4.000000+0 2.000000+0 0.000000+0 0.000000+0 3.000000+0  27 7  4     \n"
    " 2.000000+0 8.000000+0 4.000000+0 0.000000+0 0.000000+0 4.000000+0  27 7  4     \n";
}

void verifyChunkWithThreeSecondaryScatterers(
       const ScatteringLawConstants& chunk ) {

  REQUIRE( 0 == chunk.LLN() );
  REQUIRE( 0 == chunk.sabStorageType() );
  REQUIRE( 24 == chunk.NI() );
  REQUIRE( 24 == chunk.numberConstants() );
  REQUIRE( 3 == chunk.NS() );
  REQUIRE( 3 == chunk.numberNonPrincipalScatterers() );

  REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
  REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
  REQUIRE( 4 == chunk.totalFreeCrossSections().size() );
  REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
  REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
  REQUIRE( 4.000000e+0 == Approx( chunk.totalFreeCrossSections()[2] ) );
  REQUIRE( 8.000000e+0 == Approx( chunk.totalFreeCrossSections()[3] ) );
  REQUIRE( 4 == chunk.atomicWeightRatios().size() );
  REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
  REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
  REQUIRE( 2.000000e+0 == Approx( chunk.atomicWeightRatios()[2] ) );
  REQUIRE( 4.000000e+0 == Approx( chunk.atomicWeightRatios()[3] ) );
  REQUIRE( 4 == chunk.numberAtoms().size() );
  REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
  REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
  REQUIRE( 3. == Approx( chunk.numberAtoms()[2] ) );
  REQUIRE( 4. == Approx( chunk.numberAtoms()[3] ) );
  REQUIRE( 3 == chunk.analyticalFunctionTypes().size() );
  REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );
  REQUIRE( 1. == chunk.analyticalFunctionTypes()[1] );
  REQUIRE( 2. == chunk.analyticalFunctionTypes()[2] );

  REQUIRE( 5 == chunk.NC() );
}

std::string invalidSize() {
  return
    " 0.000000+0 0.000000+0          0          0         12          0  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n";
}

std::string invalidLLN() {
  return
    " 0.000000+0 0.000000+0          2          0         12          0  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n";
}

std::string invalidNS() {
  return
    " 0.000000+0 0.000000+0          0          0         30          4  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n"
    " 1.000000+0 4.000000+0 2.000000+0 0.000000+0 0.000000+0 3.000000+0  27 7  4     \n"
    " 2.000000+0 8.000000+0 4.000000+0 0.000000+0 0.000000+0 4.000000+0  27 7  4     \n"
    " 3.000000+0 1.200000+1 8.000000+0 0.000000+0 0.000000+0 5.000000+0  27 7  4     \n";
}
