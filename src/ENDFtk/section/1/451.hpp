#ifndef NJOY_ENDFTK_SECTION_1_451
#define NJOY_ENDFTK_SECTION_1_451

// system includes

// other includes
#include "range/v3/distance.hpp"
#include "range/v3/view/all.hpp"
#include "range/v3/view/concat.hpp"
#include "range/v3/view/join.hpp"
#include "range/v3/view/single.hpp"
#include "range/v3/view/split.hpp"
#include "range/v3/view/transform.hpp"
#include "ENDFtk/types.hpp"
#include "ENDFtk/TextRecord.hpp"
#include "ENDFtk/HeadRecord.hpp"
#include "ENDFtk/ControlRecord.hpp"
#include "ENDFtk/DirectoryRecord.hpp"
#include "ENDFtk/section.hpp"
#include "ENDFtk/readSequence.hpp"

namespace njoy {
namespace ENDFtk {
namespace section{

  template<>
  class Type< 1, 451 > : protected BaseWithoutMT< Type< 1, 451 > > {

    friend BaseWithoutMT< Type< 1, 451 > >;

    /* fields */
    int lrp_;
    int lfi_;
    int nlib_;
    int nmod_;
    std::array< ControlRecord, 3 > parameters_;
    std::vector< TextRecord > description_;
    std::vector< DirectoryRecord > index_;

    /* auxiliary functions */
    #include "ENDFtk/section/1/451/src/makeParameters.hpp"
    #include "ENDFtk/section/1/451/src/makeDescription.hpp"
    #include "ENDFtk/section/1/451/src/readParameters.hpp"

  public:

    /* constructor */
    #include "ENDFtk/section/1/451/src/ctor.hpp"

    /* get methods */
    static constexpr int sectionNumber(){ return 451; }

    int LRP() const { return this->lrp_; }
    int resonanceParameterFlag() const { return this->LRP(); }
    int LFI() const { return this->lfi_; }
    bool isFissile() const { return this->LFI(); }
    int NLIB() const { return this->nlib_; }
    int libraryType() const { return this->NLIB(); }
    int NMOD() const { return this->nmod_; }
    int modificationNumber() const { return this->NMOD(); }

    double ELIS() const { return std::get< 0 >( this->parameters_ ).C1(); }
    double excitationEnergy() const { return this->ELIS(); }
    double STA() const { return std::get< 0 >( this->parameters_ ).C2(); }
    bool isStable() const { return this->STA(); }
    int LIS() const { return std::get< 0 >( this->parameters_ ).L1(); }
    int excitedLevel() const { return this->LIS(); }
    int LISO() const { return std::get< 0 >( this->parameters_ ).L2(); }
    int isomericLevel() const { return this->LISO(); }
    int NFOR() const { return std::get< 0 >( this->parameters_ ).N2(); }
    int libraryFormat() const { return this->NFOR(); }

    double AWI() const { return std::get< 1 >( this->parameters_ ).C1(); }
    double projectileAtomicMassRatio() const { return this->AWI(); }
    double EMAX() const { return std::get< 1 >( this->parameters_ ).C2(); }
    double maximumEnergy() const { return this->EMAX(); }
    int LREL() const { return std::get< 1 >( this->parameters_ ).L1(); }
    int releaseNumber() const { return this->LREL(); }
    int NSUB() const { return std::get< 1 >( this->parameters_ ).N1(); }
    int subLibrary() const { return this->NSUB(); }
    int NVER() const { return std::get< 1 >( this->parameters_ ).N2(); }
    int versionNumber() const { return this->NVER(); }

    double TEMP() const { return std::get< 2 >( this->parameters_ ).C1(); }
    double temperature() const { return this->TEMP(); }
    int LDRV() const { return std::get< 2 >( this->parameters_ ).L1(); }
    int derivedMaterial() const { return this->LDRV(); }
    int NWD() const { return static_cast< int >( this->description_.size() ); }
    int NXC() const { return static_cast< int >( this->index_.size() ); }

    AllRange< DirectoryRecord > index() const {

      return ranges::view::all( this->index_ );
    }

    long NC() const { return 4 + this->NWD() + this->NXC(); }

    #include "ENDFtk/section/1/451/src/description.hpp"
    #include "ENDFtk/section/1/451/src/print.hpp"

    using BaseWithoutMT::MT;
    using BaseWithoutMT::ZA;
    using BaseWithoutMT::AWR;
    using BaseWithoutMT::atomicWeightRatio;

    /* implement set methods on ContRecord to enable this
    int& LRP() const { return this->lrp_; }
    int& LFI() const { return this->lfi_; }
    int& NLIB() const { return this->nlib_; }
    int& NMOD() const { return this->nmod_; }


    double& ELIS() { return std::get<0>( this->parameters_ ).C1(); }
    double& STA() { return std::get<0>( this->parameters_ ).C2(); }
    int& LIS() { return std::get<0>( this->parameters_ ).L1(); }
    int& LISO() { return std::get<0>( this->parameters_ ).L2(); }
    int& NFOR() { return std::get<0>( this->parameters_ ).N2(); }

    double& AWI() { return std::get<1>( this->parameters_ ).C1(); }
    double& EMAX() { return std::get<1>( this->parameters_ ).C2(); }
    int& LREL() { return std::get<1>( this->parameters_ ).L1(); }
    int& NSUB() { return std::get<1>( this->parameters_ ).N1(); }
    int& NVER() { return std::get<1>( this->parameters_ ).N2(); }

    double& TEMP() { return std::get<2>( this->parameters_ ).C1(); }
    int& LDRV() { return std::get<2>( this->parameters_ ).L1(); }
    */

    // @todo add function to erase and replace/add descriptive text

    // @todo add function to erase and replace/add index


  //
  //  // MT452 total nubar data
  //  template < bool B > class Type< 452, B > : protected Base {
  //
  //  /* fields */
  //  int lnu_;
  //  ListRecord polynomial_;
  //  TabulationRecord tabulated_;
  //
  //  public:
  //
  //  /* constructor */
  //#include "ENDFtk/section/1/451/src/ctor-452.hpp"
  //
  //  /* set methods */
  //
  //  /* get methods */
  //  int LNU() const { return this->lnu_; }
  //
  //  // @todo extract values
  //  const ListRecord& polynomial() const { return this->polynomial_; }
  //  const TabulationRecord& tabulated() const { return this->tabulated_; }
  //
  //  using Base::MT;
  //  using Base::ZA;
  //  using Base::atomicWeightRatio;
  //  };
  //
  //  // MT455 delayed nubar data
  //  template < bool B > class Type< 455, B > : protected Type< 452, B > {
  //
  //  /* fields */
  //  ListRecord independent_; // LDG=0
  //  // @todo need TAB2
  //  // std::vector< ListRecord > // LDG=1
  //
  //  public:
  //
  //  /* constructor */
  //#include "ENDFtk/section/1/451/src/ctor-456.hpp"
  //
  //  /* set methods */
  //
  //  /* get methods */
  //  using Type< 452 >::LNU;
  //
  //  // @todo extract values
  //  const ListRecord& independent() const { return this->independent_; }
  //  using Type< 452 >::polynomial;
  //  using Type< 452 >::tabulated;
  //
  //  using Type< 452 >::MT;
  //  using Type< 452 >::ZA;
  //  using Type< 452 >::atomicWeightRatio;
  //  };
  //
  //  // MT456 prompt nubar data
  //  template < bool B > class Type< 456, B > : protected Type< 452, B > {
  //
  //  public:
  //
  //  /* constructor */
  //#include "ENDFtk/section/1/451/src/ctor-456.hpp"
  //
  //  /* set methods */
  //
  //  /* get methods */
  //  using Type< 452 >::LNU;
  //
  //  // @todo extract values
  //  using Type< 452 >::polynomial;
  //  using Type< 452 >::tabulated;
  //
  //  using Type< 452 >::MT;
  //  using Type< 452 >::ZA;
  //  using Type< 452 >::atomicWeightRatio;
  //  };
  //
  //  // MT458 fission Q value data
  //  template < bool B > class Type< 458, B > : protected Base {
  //
  //  /* fields */
  //  ListRecord data_;
  //
  //  public:
  //
  //  /* constructor */
  //#include "ENDFtk/section/1/451/src/ctor-458.hpp"
  //
  //  /* set methods */
  //  /* implement set methods on ListRecord to enable this
  //  int& NPLY() { return data_.L2() }
  //  */
  //
  //  /* get methods */
  //    int NPLY() const { return data_.L2(); }
  //
  //  // @todo extract values
  //  const ListRecord& data() const { return this->data_; }
  //
  //  using Base::MT;
  //  using Base::ZA;
  //  using Base::atomicWeightRatio;
  //  };
  //
  //  // MT460 delayed photon data
  //  template < bool B > class Type< 460, B > : protected Base {
  //
  //  /* fields */
  //  std::vector< TabulationRecord > discrete_;     // LO=1
  //  ListRecord continuous_;                        // LO=2
  //
  //  // @todo store this as a variant because it is either of these two?
  //
  //  /* auxiliary functions */
  //#include "ENDFtk/section/1/451/src/readRecords.hpp"
  //
  //  public:
  //
  //  /* constructor */
  //#include "ENDFtk/section/1/451/src/ctor-460.hpp"
  //
  //  /* set methods */
  //
  //  /* get methods */
  //  int LO() const { return ( this->NG() != 0 ? 1 : 2 ); }
  //  int NG() const { return static_cast<int>( this->discrete_.size() ); }
  //
  //  using Base::MT;
  //  using Base::ZA;
  //  using Base::atomicWeightRatio;
  //  };
  };

} // section namespace
} // ENDFtk namespace
} // njoy namespace

#endif
