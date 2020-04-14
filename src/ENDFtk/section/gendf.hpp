class GendfType : protected Base {

public:
  using BufferIterator = ranges::iterator_t<std::string>;

private:
  std::vector<ListRecord> list_records;
  std::vector<double> _xs;
  int _num_legendre;
  int _num_sigma0;
  double _temperature;

protected:
  #include "ENDFtk/section/gendf/src/populateLists.hpp"

public:
  #include "ENDFtk/section/gendf/src/ctor.hpp"

  /* methods */
  const auto& lists() const { return this->list_records; }
  const auto& xs() const { return _xs; }
  double temperature() const { return _temperature; }
  int numLegendre() const { return _num_legendre; }
  int numSigma0() const { return _num_sigma0; }

};
