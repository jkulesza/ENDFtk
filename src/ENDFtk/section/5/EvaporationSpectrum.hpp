/**
 *  @class
 *  @brief The evaporation spectrum (LF=9)
 *
 *  See ENDF102, section 5.1.1.4 and 5.2.4 for more information.
 */
class EvaporationSpectrum : protected EffectiveTemperature {

public:

  /* constructor */
  #include "ENDFtk/section/5/EvaporationSpectrum/src/ctor.hpp"

  /* get methods */

  /**
   *  @brief Return the distribution type (the LF flag)
   */
  static constexpr int LF() { return 9; }

  /**
   *  @brief Return the distribution type (the LF flag)
   */
  static constexpr int LAW() { return EvaporationSpectrum::LF(); }

  using EffectiveTemperature::E;
  using EffectiveTemperature::energies;
  using EffectiveTemperature::thetas;
  using EffectiveTemperature::values;
  using EffectiveTemperature::NE;
  using EffectiveTemperature::NR;
  using EffectiveTemperature::interpolants;
  using EffectiveTemperature::boundaries;
  using EffectiveTemperature::NC;
  using EffectiveTemperature::print;
};
