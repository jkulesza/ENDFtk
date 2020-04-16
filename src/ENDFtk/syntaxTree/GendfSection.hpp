template< typename BufferIterator >
class GendfSection {

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
  auto buffer() const {
    return ranges::make_iterator_range( this->bufferLimits.first,
                                        this->bufferLimits.second );
  }
  #include "ENDFtk/syntaxTree/GendfSection/src/parse.hpp"

};
