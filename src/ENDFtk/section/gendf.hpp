template< typename BufferIterator >
class GendfType : protected Base {

private:
  std::vector<ListRecord> list_records;
  std::vector<double> xs_;
  int num_legendre;
  int num_sigma0;
  double temperature_;

protected:
  #include "ENDFtk/section/gendf/src/populateLists.hpp"

public:
  #include "ENDFtk/section/gendf/src/ctor.hpp"

  /* methods */
  const auto& lists() const { return this->list_records; }
  const auto& xs() const { return xs_; }
  double temperature() const { return temperature_; }
  int numLegendre() const { return num_legendre; }
  int numSigma0() const { return num_sigma0; }

};
