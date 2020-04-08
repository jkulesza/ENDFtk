class GendfSection {

public:
  /* convenience typedefs */
  using BufferIterator = ranges::iterator_t< std::string >;

protected:
  /* fields */
  int fileNo_;
  int sectionNo_;
  std::pair< BufferIterator, BufferIterator > bufferLimits;

  /* methods */
  #include "ENDFtk/syntaxTree/GendfSection/src/findEnd.hpp"
  

public:
  /* ctor */
  #include "ENDFtk/syntaxTree/GendfSection/src/ctor.hpp"

  /* methods */
  int fileNo() const { return fileNo_; }
  int sectionNo() const { return sectionNo_; }

};
