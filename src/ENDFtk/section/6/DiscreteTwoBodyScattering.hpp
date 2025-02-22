/**
 *  @class
 *  @brief Discrete two-body scattering data for secondary particles (LAW=2)
 *
 *  The DiscreteTwoBodyScattering class is used to represent the discrete
 *  two-body scattering law=2 data of MF6.
 *
 *  See ENDF102, section 6.2.4 for more information.
 */
class DiscreteTwoBodyScattering {

public:

  #include "ENDFtk/section/6/DiscreteTwoBodyScattering/LegendreCoefficients.hpp"
  #include "ENDFtk/section/6/DiscreteTwoBodyScattering/Tabulated.hpp"

  using Variant = std::variant< LegendreCoefficients, // LANG=1
                                Tabulated >;          // LANG=12,14

private:

  /* fields */
  InterpolationSequenceRecord< Variant > data_;

  /* auxiliary functions */
  #include "ENDFtk/section/6/DiscreteTwoBodyScattering/src/readSequence.hpp"

public:

  /* constructor */
  #include "ENDFtk/section/6/DiscreteTwoBodyScattering/src/ctor.hpp"

  /* get methods */

  /**
   *  @brief Return the LAW flag
   */
  static constexpr int LAW() { return 2; }

  /**
   *  @brief Return the number of interpolation ranges on the incident
   *         energy axis
   */
  long NR() const { return this->data_.tab2().NR(); }

  /**
   *  @brief Return the number of secondary energy values
   */
  long NE() const { return this->data_.tab2().NZ(); }

  /**
   *  @brief Return the subsections, one for each incident energy
   */
  auto subsections() const { return this->data_.records(); }

  /**
   *  @brief Return interpolation type for each range on the incident
   *         energy grid
   */
  auto interpolants() const { return this->data_.tab2().interpolants(); }

  /**
   *  @brief Return interpolation boundaries for the incident energy grid
   */
  auto boundaries() const { return this->data_.tab2().boundaries(); }

  /**
   *  @brief Return the number of lines in this MF6 component
   */
  long NC() const { return this->data_.NC(); }

  #include "ENDFtk/section/6/DiscreteTwoBodyScattering/src/print.hpp"
};
