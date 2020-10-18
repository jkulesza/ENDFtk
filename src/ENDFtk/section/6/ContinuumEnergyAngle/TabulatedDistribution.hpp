/**
 *  @class
 *  @brief An angular distribution given as a tabulated function.
 *
 *  The TabulatedDistribution class is used to represent the case in which the
 *  angular distribution for a secondary particle at a given incident energy is
 *  is given as a tabulated function.
 *
 *  This component is similar to the MF4 component of the same name (with the
 *  exception that this gives tabulated values for each outgoing energy value as
 *  well).
 *
 *  See ENDF102, section 6.2.3.1 for more information.
 */
class TabulatedDistribution : protected Base {

  /* fields */
  int lang_;

  /* auxiliary functions */
  #include "ENDFtk/section/6/ContinuumEnergyAngle/TabulatedDistribution/src/checkLANG.hpp"
  #include "ENDFtk/section/6/ContinuumEnergyAngle/TabulatedDistribution/src/generateList.hpp"

public:

  /* constructor */
  #include "ENDFtk/section/6/ContinuumEnergyAngle/TabulatedDistribution/src/ctor.hpp"

  /* methods */

  /**
   *  @brief Return the representation type
   */
  int LANG() const { return this->lang_; }

  using Base::E;
  using Base::incidentEnergy;
  using Base::ND;
  using Base::numberDiscreteEnergies;
  using Base::NA;
  using Base::numberAngularParameters;
  using Base::NW;
  using Base::NEP;
  using Base::numberSecondaryEnergies;
  using Base::energies;
  using Base::totalEmissionProbabilities;

  /**
   *  @brief Return the cosine values
   */
  auto MU() const {

    return Base::list()
             | ranges::view::chunk( 2 + this->NA() )
             | ranges::view::transform( ranges::view::drop( 2 )
                                          | ranges::view::stride( 2 ) ); }

  /**
   *  @brief Return the cosine values
   */
  auto cosines() const { return this->MU(); }

  /**
   *  @brief Return the distribution probabilities
   */
  auto F() const {

    return Base::list()
             | ranges::view::chunk( 2 + this->NA() )
             | ranges::view::transform( ranges::view::drop( 3 )
                                          | ranges::view::stride( 2 ) ); }

  /**
   *  @brief Return the distribution probabilities
   */
  auto probabilities() const { return this->F(); }

  using Base::NC;
  using Base::print;
};
