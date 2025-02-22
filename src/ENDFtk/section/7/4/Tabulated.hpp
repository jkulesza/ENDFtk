/**
 *  @class
 *  @brief Tabulated incoherent inelastic scattering law
 *
 *  The Tabulated class is used to represent the case in which the incoherent
 *  inelastic thermal scattering law of the principal scatterer in
 *  ENDF section MF4/MT4 is represented entirely as a tabulated function.
 *
 *  The tabulated S(alpha,beta,T) functions are given as tabulated S(alpha,T)
 *  functions for fixed beta values.
 *
 *  See ENDF102, section 7.4 for more information.
 */
class Tabulated {

public:

  #include "ENDFtk/section/7/4/Tabulated/ScatteringFunction.hpp"

private:

  /* members */
  InterpolationSequenceRecord< ScatteringFunction > data_;

  /* auxiliary functions */

public:

  /* constructor */
  #include "ENDFtk/section/7/4/Tabulated/src/ctor.hpp"

  /* get methods */

  /** 
   *  @brief Return the number of interpolation ranges on the beta grid
   */
  long NR() const { return this->data_.tab2().NR(); }

  /** 
   *  @brief Return the number of beta values
   */
  long NB() const { return this->data_.tab2().NZ(); }

  /** 
   *  @brief Return the number of beta values
   */
  long numberBetas() const { return this->NB(); }

  /** 
   *  @brief Return the beta values and associated S(alpha,T) functions
   */
  auto betas() const { return this->data_.records(); }

  /** 
   *  @brief Return interpolation type for each range on the beta grid
   */
  auto interpolants() const { return this->data_.tab2().interpolants(); }

  /** 
   *  @brief Return interpolation boundaries for the beta grid
   */
  auto boundaries() const { return this->data_.tab2().boundaries(); }

  /** 
   *  @brief Return the number of lines in this MF7/MT4 component
   */
  long NC() const { return this->data_.NC(); }

  #include "ENDFtk/section/7/4/Tabulated/src/print.hpp"
};

