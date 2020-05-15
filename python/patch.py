#######################################################################
from ENDFtk import Section

def _parse_section(self, mf):
    """ Doc string """

    switcher = {
        1: self.parse1,
        3: self.parse3,
        6: self.parse6
    }

    try:
        return switcher[mf]()
    except KeyError as e:
        print( "%i not in switcher!" )
        raise e

Section.parse = _parse_section


#######################################################################
from ENDFtk import File

def _parse_file(self):
    """ Doc string """

    switcher = {
        3: self.parse3
    }

    return switcher[self.fileNumber]()

File.parse = _parse_file

