/* tag structs */
struct endf_tag {};
struct gendf_tag {};

/* generic Tape class */
template< typename Buffer, typename tag=endf_tag >
class Tape;

/* partial specialization of Tape for ENDF */
template< typename Buffer >
class Tape< Buffer, endf_tag > {
  using BufferIterator = ranges::iterator_t< const Buffer >;
public:
  /* convenience typedefs */
  using Material_t = Material< BufferIterator >;
  
protected:
  /* fields */
  Buffer buffer_;
  std::optional< TapeIdentification > tpid;
  std::multimap< int, Material_t > materials_;

  /* ctor */
  #include "ENDFtk/syntaxTree/Tape/src/createMap.hpp"
public:
  #include "ENDFtk/syntaxTree/Tape/src/ctor.hpp"

  /* methods */
  #include "ENDFtk/syntaxTree/Tape/src/materialNumber.hpp"

  auto MAT( int materialNo ){ return this->materialNumber( materialNo ); }
  auto MAT( int materialNo ) const { 
    return this->materialNumber( materialNo ); }

  bool hasMAT( int materialNo ) const {
    return this->materials_.count( materialNo );
  }

  bool hasMaterialNumber( int materialNo ) const {
    return this->hasMAT( materialNo );
  }
  
  auto begin(){ return ( this->materials_ | ranges::view::values ).begin(); }
  auto end(){ return ( this->materials_ | ranges::view::values ).end(); }

  auto begin() const { 
    return ( this->materials_ | ranges::view::values ).begin(); 
  }
  auto end() const { return ( this->materials_ | ranges::view::values ).end(); }
  
  std::size_t size() const { return this->materials_.size(); }

  auto buffer() const { return this->buffer_ | ranges::view::all; }

  const TapeIdentification& TPID() const { return *( this->tpid ); }
};


template< typename Range >
auto makeTape( Range&& range ){
  return Tape< Range >{ std::forward< Range >( range ) };
}
