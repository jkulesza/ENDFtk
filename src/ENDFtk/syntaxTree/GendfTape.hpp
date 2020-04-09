class GendfTape {

public:
  using BufferIterator = ranges::iterator_t< std::string >;

protected:
  /* fields */
  std::string buffer_;
  std::multimap< int, GendfMaterial > materials_;

  /* protected methods */
  #include "ENDFtk/syntaxTree/GendfTape/src/createMap.hpp"

public:
  /* ctor */
  #include "ENDFtk/syntaxTree/GendfTape/src/ctor.hpp"

  /* methods */

  /**
   * @brief Checks if given material number is in tree
   *
   * @param materialNo : the given material number
   */
  bool hasMaterialNumber( int materialNo ) const {
    return materials_.count( materialNo );
  }

  /**
   * @brief Returns number of materials in tree
   */
  std::size_t size() const { return materials_.size(); }

  /**
   * @brief Getter for materials
   */
  auto getMaterials() const { return materials_; }

};
