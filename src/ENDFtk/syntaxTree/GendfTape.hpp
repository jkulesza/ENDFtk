class GendfTape {

public:
  using BufferIterator = ranges::iterator_t< std::string >;

protected:
  /* fields */
  std::string buffer_;
  std::multimap< int, GendfMaterial > materials_;
  std::map< int, std::vector< GendfMaterial* > > materialsAsMap_;

  /* protected methods */
  #include "ENDFtk/syntaxTree/GendfTape/src/createMap.hpp"

  /**
   * @brief helper to "bind" std::multimap to Python
   *
   * @note This is the wrong place for this function to be!!
   */
  template< typename T1, typename T2 >
  static auto asMap( std::multimap<T1,T2> &mmap ) {
    std::map<T1,std::vector<T2*>> new_map;
    for (auto& it : mmap)
      new_map[it.first].push_back(&it.second);
    return new_map;
  }

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
  auto getMaterials() { return materials_; }
  const auto& getMaterials() const { return materials_; }

  // python stuff
  void convertMap() { materialsAsMap_ = asMap(materials_); }
  const auto& getMaterialsAsMap() const { return materialsAsMap_; }

};



