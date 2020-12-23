SCENARIO( "TabulationRecord ctor",
          "[ENDFtk], [TabulationRecord]" ){

    std::vector< long > regions{ 4, 5, 6 };
    std::vector< long > interpolation{ 1, 2, 3 };
    std::vector< double > x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
    std::vector< double > y{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

  GIVEN( "a TAB1 object" ){
    TabulationRecord tab1( 1.0, 2.0, 3ul, 4ul,
                               std::move( regions ),
                               std::move( interpolation ),
                               std::move( x ), std::move( y ) );

    THEN( "TAB1 objects can be copied" ) {
      auto copy = tab1;
      REQUIRE( copy == tab1 );
    }
  }

  GIVEN( "mismatched x and y lengths" ){
    std::vector< double > x{ 1.0, 2.0, 3.0, 4.0, 5.0 };

    REQUIRE_THROWS( TabulationRecord
                    ( 1.0, 2.0, 3ul, 4ul,
                      std::make_tuple( regions, interpolation ),
                      std::make_tuple( x, y ) ) );
  }

  GIVEN( "out of order x values" ){
    std::vector< double > x{ 1.0, 3.0, 2.0, 4.0, 5.0 };

    REQUIRE_THROWS( TabulationRecord
                    ( 1.0, 2.0, 3ul, 4ul,
                      std::make_tuple( regions, interpolation ),
                      std::make_tuple( x, y ) ) );
  }

  GIVEN( "mismatched region and interpolation arrays" ){
    std::vector< long > interpolation{ 1, 2, 3, 4 };

    REQUIRE_THROWS( TabulationRecord
                    ( 1.0, 2.0, 3ul, 4ul,
                      std::make_tuple( regions, interpolation ),
                      std::make_tuple( x, y ) ) );
  }

  GIVEN( "out of order region" ){
    std::vector< long > regions{ 5, 4, 6 };

    REQUIRE_THROWS( TabulationRecord
                    ( 1.0, 2.0, 3ul, 4ul,
                      std::make_tuple( regions, interpolation ),
                      std::make_tuple( x, y ) ) );
  }

  GIVEN( "interpolation table index and data table size mismatch" ){
    std::vector< long > regions{ 3, 4, 5 };

    REQUIRE_THROWS( TabulationRecord
                    ( 1.0, 2.0, 3ul, 4ul,
                      std::make_tuple( regions, interpolation ),
                      std::make_tuple( x, y ) ) );
  }

  GIVEN( "single region TAB1 with incorrect tail values" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          1          49328 1460     \n"
      "          4          4                                            9228 1460     \n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460     \n"
      " 2.700000+1 1.605000+1                                            9228 1460     \n";

    WHEN( "constructed with incorrect 'tail' values" ){
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;

      REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
    }
  }

  GIVEN( "single region TAB1" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          1          49228 1460     \n"
      "          4          4                                            9228 1460     \n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460     \n"
      " 2.700000+1 1.605000+1                                            9228 1460     \n";

    WHEN( "constructed with correct 'tail' values" ){
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;

      TabulationRecord tab1_1( begin, end, lineNumber, MAT, MF, MT );
      REQUIRE( tab1_1.NR() == 1 );
      REQUIRE( tab1_1.NP() == 4 );

    }

    SECTION( "NC" ){
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;

      TabulationRecord table( begin, end, lineNumber, MAT, MF, MT );
      REQUIRE( table.NC() == 4 );
    }

    WHEN( "constructed with incorrect 'tail' values" ){
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;

      REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, 9328, MF, MT ) );
      REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, 17, MT ) );
      REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, 15 ) );
    }
  }

  GIVEN( "Equivalent x-values" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          1          49228 1460  438\n"
      "          4          4                                            9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.500001+1 1.850000+1 1.500001+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_NOTHROW( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  } // GIVEN

  GIVEN( "Out of order x-values" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          1          49228 1460  438\n"
      "          4          4                                            9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.400000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Out of order region boundaries" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          2          49228 1460  438\n"
      "          4          4          2          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Negative NR" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0         -1          49228 1460  438\n"
      "          2          4          4          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Negative NP value" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          1         -19228 1460  438\n"
      "          4          4                                            9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Zero NR" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          0          49228 1460  438\n"
      "          2          4          4          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Zero NP" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          2          09228 1460  438\n"
      "          2          4          4          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Mismatched NP and range index" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          2          49228 1460  438\n"
      "          2          4          3          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }

  GIVEN( "Inconsistent interpolation table and data table" ){
    std::string tab1 =
      " 0.000000+0 0.000000+0         33          0          2          49228 1460  438\n"
      "          2          4          4          1                      9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.400000+1 1.850000+1 1.500000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1 2.800000+1 1.700000+1                      9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;

    REQUIRE_THROWS( TabulationRecord( begin, end, lineNumber, MAT, MF, MT ) );
  }
}
