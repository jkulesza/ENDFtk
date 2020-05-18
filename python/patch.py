""" Patch file for ENDFtk """

#######################################################################
from ENDFtk import Section

def _parse_section(self, mf):
    """ Doc string """

    switcher = {
        1: self.parse1,
        3: self.parse3,
        4: self.parse4,
        # 5: self.parse5,
        6: self.parse6
    }

    try:
        return switcher[mf]()
    except KeyError as e:
        print( "%i not in switcher!" )
        raise e

def _section_len(self):
    """ Return number of lines in a Section. """

    buffer_ = self.buffer
    return len(buffer_.split('\n'))

Section.parse = _parse_section
Section.__len__ = _section_len


#######################################################################
from ENDFtk import File

def _parse_file(self):
    """ Doc string """

    switcher = {
        3: self.parse3
    }

    return switcher[self.fileNumber]()

File.parse = _parse_file


#######################################################################
import ENDFtk.LAW1 as LAW1
import ENDFtk.LAW2 as LAW2
import ENDFtk.LAW5 as LAW5
import ENDFtk.LAW7 as LAW7

def _energies_from_subsections(self):
    if not hasattr(self, '_energies'):
        self._energies = [s.energy for s in self.subsections]
    return self._energies

def _law7_energies(self):
    if not hasattr(self, '_energies'):
        self._energies = [s.energy for s in self.angularDistributions]
    return self._energies

# assign properties to classes
for myclass in [LAW1.ContinuumEnergyAngle,
                LAW2.DiscreteTwoBodyScattering,
                LAW5.ChargedParticleElasticScattering]:
    myclass.energies = property(_energies_from_subsections)
LAW7.LaboratoryAngleEnergy.enegies = property(_law7_energies)


#######################################################################
from ENDFtk import Type4

def _energies_from_distributions(self):
    if not hasattr(self, '_energies'):
        if self.LTT == 0:
            self._energies = None
        else:
            self._energies = [s.incidentEnergy for s in self.distributions]

    return self._energies


def _get_distributions(self):

    if self.LTT == 0:
        return self._distributions

    else:
        return self._distributions.angularDistributions

Type4.distributions = property(_get_distributions)
Type4.energies = property(_energies_from_distributions)
