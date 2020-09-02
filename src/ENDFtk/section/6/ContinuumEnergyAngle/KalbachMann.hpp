class KalbachMann : protected Base {

  /* auxiliary functions */
  #include "ENDFtk/section/6/ContinuumEnergyAngle/KalbachMann/src/verifyNA.hpp"
  #include "ENDFtk/section/6/ContinuumEnergyAngle/KalbachMann/src/generateList.hpp"
    
public:
  /* constructor */
  #include "ENDFtk/section/6/ContinuumEnergyAngle/KalbachMann/src/ctor.hpp"

  /* get methods */
  static constexpr int LANG() { return 2; }

  using Base::energy;
  using Base::ND;
  using Base::numberDiscreteEnergies;
  using Base::NA;
  using Base::numberAngularParameters;
  using Base::NW;
  using Base::NEP;
  using Base::numberSecondaryEnergies;

  using Base::energies;
  using Base::totalEmissionProbabilities;
  auto parameters() const { return Base::data(); }
  auto listData() const { return Base::list(); }

  using Base::NC;
  using Base::print;
};
