import ENDFtk
import patch


def main():

    with open('resources/n-li6.endf') as f:
        tape = ENDFtk.Tape(f.read())

    mt2 = tape.materials[0].MF(4).MT(2).parse(4)
    energies = mt2.energies
    for i, dist in enumerate(mt2.distributions):
        print( energies[i], type(dist) )

    print()

    mt24 = tape.materials[0].MF(4).MT(24).parse(4)
    energies = mt24.energies
    for i, dist in enumerate(mt24.distributions):
        print( energies[i], type(dist) )


if __name__ == '__main__':
    main()
