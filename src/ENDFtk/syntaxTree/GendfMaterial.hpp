class GendfMaterial {

public:
  /* convenience typedefs */
  using BufferIterator = ranges::iterator_t< std::string >;

protected:

  /* fields */
  int materialNo;
  std::map< int, GendfSection > sections_;
  std::pair< BufferIterator, BufferIterator > bufferLimits;

  /* methods */
  static int mapID(int mfd, int mt) { return 1000*mfd + mt; }
  #include "ENDFtk/syntaxTree/GendfMaterial/src/createMap.hpp"

public:

  /* ctor */
  #include "ENDFtk/syntaxTree/GendfMaterial/src/ctor.hpp"

  /* methods */

  /**
   * @brief
   */
  bool hasSection(int mfd, int mt) {
    return sections_.count( mapID(mfd, mt) );
  }

  /**
   * @brief
   */
  std::size_t size() const { return sections_.size(); }

  /**
   * @brief Getter for sections
   */
  auto getSections() const { return sections_; }

  /**
   * @brief Getter for materialNo
   */
  int getMaterialNumber() const { return materialNo; }

};
