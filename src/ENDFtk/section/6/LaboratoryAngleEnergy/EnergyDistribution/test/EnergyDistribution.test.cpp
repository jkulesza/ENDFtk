#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk/section/6.hpp"

// other includes

// convenience typedefs
using namespace njoy::ENDFtk;
using EnergyDistribution = 
section::Type< 6 >::LaboratoryAngleEnergy::EnergyDistribution;

std::string chunk();
void verifyChunk( const EnergyDistribution& );
std::string invalidChunk();

SCENARIO( "EnergyDistribution" ) {

  GIVEN( "valid data for a EnergyDistribution" ) {

    WHEN( "the data is given explicitly" ) {

      double cosine = 1.0;
      std::vector< long > boundaries = { 4 };
      std::vector< long > interpolants = { 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };

      THEN( "a EnergyDistribution can be constructed and members can be "
            "tested" ) {

        EnergyDistribution
          chunk( cosine, std::move( boundaries ), std::move( interpolants ),
                 std::move( energies ), std::move( probabilities ) );
        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      std::string string = chunk();
      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      THEN( "a EnergyDistribution can be constructed and members can be "
            "tested" ) {

        EnergyDistribution chunk(begin, end, lineNumber, 9228, 6, 5 );
        verifyChunk( chunk );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a valid instance of EnergyDistribution" ) {

    std::string string = chunk();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;
    EnergyDistribution chunk(begin, end, lineNumber, 9228, 6, 5 );

    THEN( "it can be printed" ) {

      std::string buffer;
      auto output = std::back_inserter( buffer );
      chunk.print( output, 9228, 6, 5 );
      REQUIRE( buffer == string );
    }
  } // GIVEN

  GIVEN( "invalid data for a AngularDistribution" ) {

    WHEN( "data with an invalid boundary size is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                            6.622950e-8, 2.149790e-1 };
      std::vector< long > wrongsize = { 4 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine,
                              std::move( wrongsize ),
                              std::move( interpolants ),
                              std::move( energies ),
                              std::move( probabilities ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid interpolant size is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                            6.622950e-8, 2.149790e-1 };
      std::vector< long > wrongsize = { 4 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine,
                              std::move( boundaries ),
                              std::move( wrongsize ),
                              std::move( energies ),
                              std::move( probabilities ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid secondary energy size is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };
      std::vector< double > wrongsize = { 1., 2., 3. };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine,
                              std::move( boundaries ),
                              std::move( interpolants ),
                              std::move( wrongsize ),
                              std::move( probabilities ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid probability size is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };
      std::vector< double > wrongsize = { 1., 2., 3. };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine,
                              std::move( boundaries ),
                              std::move( interpolants ),
                              std::move( energies ),
                              std::move( wrongsize ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid order for the boundaries is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };
      std::vector< long > wrongorder = { 4, 2 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine,
                              std::move( wrongorder ),
                              std::move( interpolants ),
                              std::move( energies ),
                              std::move( probabilities ) ) );
      } // THEN
    } // WHEN

    WHEN( "data with an invalid order for the energies is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };
      std::vector< double > wrongorder = { 1.1e+7, 1e-5, 1.147e+7, 3e+7 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine, std::move( boundaries ),
                              std::move( interpolants ),
                              std::move( wrongorder ),
                              std::move( probabilities ) ) );
      } // WHEN
    } // THEN

    WHEN( "data with an incorrect final boundary is used" ){

      double cosine = 1.0;
      std::vector< long > boundaries = { 2, 4 };
      std::vector< long > interpolants = { 2, 2 };
      std::vector< double > energies = { 1e-5, 1.1e+7, 1.147e+7, 3e+7 };
      std::vector< double > probabilities = { 0., 8.45368e-11,
                                              6.622950e-8, 2.149790e-1 };
      std::vector< long > wrongboundaries = { 2, 3 };

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS(
          EnergyDistribution( cosine, std::move( wrongboundaries ),
                              std::move( interpolants ),
                              std::move( energies ),
                              std::move( probabilities ) ) );
      } // THEN
    } // WHEN

    WHEN( "a string representation with an error" ) {

      std::string string = invalidChunk();
      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      THEN( "an exception is thrown" ) {

        REQUIRE_THROWS( EnergyDistribution( begin, end, lineNumber,
                                            9228, 6, 5 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {
  return
    " 0.000000+0 1.000000+0          0          0          1          49228 6  5     \n"
    "          4          2                                            9228 6  5     \n"
    " 1.000000-5 0.000000+0 1.100000+7 8.45368-11 1.147000+7 6.622950-89228 6  5     \n"
    " 3.000000+7 2.149790-1                                            9228 6  5     \n";
}

void verifyChunk( const EnergyDistribution& chunk ) {

      REQUIRE( 1. == Approx( chunk.cosine() ) );

      REQUIRE( 1 == chunk.NRP() );
      REQUIRE( 4 == chunk.NEP() );
      REQUIRE( 1 == chunk.interpolants().size() );
      REQUIRE( 1 == chunk.boundaries().size() );
      REQUIRE( 2 == chunk.interpolants()[0] );
      REQUIRE( 4 == chunk.boundaries()[0] );
      REQUIRE( 4 == chunk.energies().size() );
      REQUIRE( 4 == chunk.probabilities().size() );
      REQUIRE( 1e-5 == Approx( chunk.energies()[0] ) );
      REQUIRE( 1.1e+7 == Approx( chunk.energies()[1] ) );
      REQUIRE( 1.147e+7 == Approx( chunk.energies()[2] ) );
      REQUIRE( 3e+7 == Approx( chunk.energies()[3] ) );
      REQUIRE( 0. == Approx( chunk.probabilities()[0] ) );
      REQUIRE( 8.45368e-11 == Approx( chunk.probabilities()[1] ) );
      REQUIRE( 6.622950e-8 == Approx( chunk.probabilities()[2] ) );
      REQUIRE( 2.149790e-1 == Approx( chunk.probabilities()[3] ) );

      REQUIRE( 4 == chunk.NC() );
}

std::string invalidChunk() {
  return
    " 0.000000+0 1.000000+0          0          0          1          59228 6  5     \n"
    "          4          2                                            9228 6  5     \n"
    " 1.000000-5 0.000000+0 1.100000+7 8.45368-11 1.147000+7 6.622950-89228 6  5     \n"
    " 3.000000+7 2.149790-1                                            9228 6  5     \n";
}
