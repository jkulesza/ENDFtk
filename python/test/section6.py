import time
import sys

import matplotlib.pyplot as plt
import numpy as np

import ENDFtk
import patch


def main():

    # import and parse ENDF section
    with open('li6.endf', 'r') as f:
        tape = ENDFtk.Tape(f.read())
    section = tape.materials[0].MF(6).MT(105).parse6()

    print( type(section) )
    print( type(section.products[0]) )
    print( type(section.products[0].distribution) )

    print( section.products[0].distribution.subsections[0].data.coefficients )


if __name__ == "__main__":
    main()
