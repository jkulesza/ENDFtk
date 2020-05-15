import time
import sys

import matplotlib.pyplot as plt
import numpy as np

import ENDFtk
import patch


def main():

    # import and parse ENDF section
    with open('resources/tape20', 'r') as f:
        tape = ENDFtk.Tape(f.read())
    section = tape.materials[0].MF(6).MT(16).parse(6)

    print( type(section) )
    print( type(section.products[0]) )
    print( type(section.products[0].distribution) )

    print( section.products[0].distribution.subsections[0].data.coefficients )


if __name__ == "__main__":
    main()
