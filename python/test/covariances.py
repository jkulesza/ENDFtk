import os
import sys

import ENDFtk
import patch


def main():

    base_path = '/Users/ngibson/work/scratch/ENDF8'
    i = 0

    for fname in sorted(os.listdir(base_path)):
        if not fname.endswith('.endf'):
            continue

        with open(os.path.join(base_path, fname), 'r') as f:
            tape = ENDFtk.Tape(f.read())
      
        result = fname + ':'
 
        matl = tape.materials[0]
        for mf in range(30, 40):
            if matl.hasFileNumber(mf):
                result += ' %i' % mf

        if not result.endswith(':'):
            i += 1
            print( i, result )


if __name__ == '__main__':
    main()
