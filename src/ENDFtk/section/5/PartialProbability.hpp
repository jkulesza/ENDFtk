// forward declaration of the Subsection class
class Subsection;

/**
 *  @class
 *  @brief Partial probability for a given distribution
 *
 *  The PartialProbability class is used to provide the probability
 *  that the associated distribution can be used at a given incident
 *  energy.
 *
 *  See ENDF102, section 5 for more information.
 */
class PartialProbability : protected TabulationRecord {

  friend Subsection;

  /**
   *  @brief Return the constant that defines the upper energy
   *         limit E - U for the secondary particle's energy E'
   */
  double U() const { return TabulationRecord::C1(); }

public:

  /* constructor */
  #include "ENDFtk/section/5/PartialProbability/src/ctor.hpp"

  /* get methods */

  /**
   *  @brief Return the distribution law (the LF flag)
   */
  int LF() const { return TabulationRecord::L2(); }

  /**
   *  @brief Return the distribution law (the LF flag)
   */
  int LAW() const { return this->LF(); }

  /**
   *  @brief Return the energy values
   */
  auto E() const { return TabulationRecord::x(); }

  /**
   *  @brief Return the energy values
   */
  auto energies() const { return this->E(); }

  /**
   *  @brief Return the probability values
   */
  auto p() const { return TabulationRecord::y(); }

  /**
   *  @brief Return the probability values
   */
  auto probabilities() const { return this->p(); }

  using TabulationRecord::NP;
  using TabulationRecord::NR;
  using TabulationRecord::interpolants;
  using TabulationRecord::boundaries;
  using TabulationRecord::NC;
  using TabulationRecord::print;
};
