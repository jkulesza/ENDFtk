/**
 *  @class
 *  @brief The general evaporation spectrum (LF=5)
 *
 *  See ENDF102, section 5.1.1.2 and 5.2.2 for more information.
 */
class GeneralEvaporationSpectrum {

  EffectiveTemperature temperature_;
  DistributionFunction distribution_;

public:

  /* constructor */
  #include "ENDFtk/section/5/GeneralEvaporationSpectrum/src/ctor.hpp"

  /* get methods */

  /**
   *  @brief Return the distribution type (the LF flag)
   */
  static constexpr int LF() { return 5; }

  /**
   *  @brief Return the distribution type (the LF flag)
   */
  static constexpr int LAW() { return GeneralEvaporationSpectrum::LF(); }

  /**
   *  @brief Return the effective temperature
   */
  const auto& effectiveTemperature() const { return this->temperature_; }

  /**
   *  @brief Return the distribution function g(x)
   */
  const auto& g() const { return this->distribution_; }

  /**
   *  @brief Return the distribution function g(x)
   */
  const auto& distributionFunction() const { return this->g(); }

  #include "ENDFtk/section/5/GeneralEvaporationSpectrum/src/NC.hpp"
  #include "ENDFtk/section/5/GeneralEvaporationSpectrum/src/print.hpp"
};

