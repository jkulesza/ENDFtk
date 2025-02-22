/**
 *  @class
 *  @brief The energy dependence of the photon production cross section
 *         is given as multiplicities
 *
 *  The Multiplicities class is used to represent the case in which
 *  the energy dependence of the photon production cross sections is given
 *  as multiplicities. The data consists of a range of partial multiplicities
 *  and an optional total multiplicity (if there is more than 1 partial).
 *
 *  See ENDF102, section 12.2.1 for more information.
 */
class Multiplicities {

  /* fields */
  std::optional< TotalMultiplicity > total_;
  std::vector< PartialMultiplicity > partials_;

  /* auxiliary functions */
  #include "ENDFtk/section/12/Multiplicities/src/verifyNK.hpp"
  #include "ENDFtk/section/12/Multiplicities/src/readTotalMultiplicity.hpp"

public:

  /* constructor */
  #include "ENDFtk/section/12/Multiplicities/src/ctor.hpp"

  /* get methods */

  /**
   *  @brief Return the photon production representation type
   */
  static constexpr int LO() { return 1; }

  /**
   *  @brief Return the photon production representation type
   */
  static constexpr int representation() { return Multiplicities::LO(); }

  /**
   *  @brief Return the number of partial multiplicities (discrete photons
   *         and continuum)
   */
  int NK() const { return this->partials_.size(); }

  /**
  *  @brief Return the number of partial multiplicities (discrete photons
  *         and continuum)
   */
  int numberPartials() const { return this->NK(); }

  /**
   *  @brief Return the total multiplicity (optional)
   */
  const auto& totalMultiplicity() const { return this->total_; }

  /**
   *  @brief Return the partial multiplicities
   */
  auto partialMultiplicities() const {

    return ranges::view::all( this->partials_ );
  }

  #include "ENDFtk/section/12/Multiplicities/src/NC.hpp"
  #include "ENDFtk/section/12/Multiplicities/src/print.hpp"
};
