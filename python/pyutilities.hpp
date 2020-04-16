#ifndef PYUTILITIES
#define PYUTILITIES

#include <vector>

// wrapper for multimap to Python bindable vector
template< typename T1, typename T2 >
auto toVectorFromMap( const T2& map ) {

  std::vector< const T1* > recast;
  for ( auto& i : map )
    recast.push_back( &i.second ); 

  return recast;
}

// wrapper for view to Python bindable vector
template< typename T1, typename T2 >
auto toVector( const T2& view ) {

  std::vector< const T1* > recast;
  for ( auto& i : view )
    recast.push_back( &i ); 

  return recast;
}

#endif
