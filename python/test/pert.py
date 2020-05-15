import time
import sys

import matplotlib.pyplot as plt
import numpy as np

import ENDFtk
import patch


def main():

    # import and parse ENDF section
    with open('tape22', 'r') as f:
        tape = ENDFtk.Tape(f.read())
    initial = tape.materials[0].MF(3).MT(18).parse(3)

    # pertub cross section
    energies = np.array(initial.energies)
    cross_sections = np.array(initial.crossSections)
    energies, cross_sections = perturb(energies, cross_sections, 0.0, 1.0, 2)
    energies, cross_sections = perturb(energies, cross_sections, 1.0e4, 1.0e5, 2)
    energies, cross_sections = perturb(energies, cross_sections, 1.0e6, 1.0e10, 0.5)
    
    # create new section
    new = ENDFtk.Type(initial.MT, initial.ZA, initial.AWR,
                      initial.QM, initial.QI, initial.LR,
                      initial.boundaries,
                      initial.interpolants,
                      energies,
                      cross_sections)

    # write output ENDF sections
    with open('initial.txt', 'w') as f:
        f.write(initial.to_string(7777, 3))
    with open('new.txt', 'w') as f:
        f.write(new.to_string(7777, 3))

    # plot cross sections
    plt.figure()
    plt.plot(initial.energies, initial.crossSections)
    plt.plot(new.energies, new.crossSections)
    plt.xscale('log')
    plt.yscale('log')
    plt.show()


def perturb(x_in, y_in, start, stop, mult):

    # initialize output
    x_out = x_in
    y_out = y_in

    # add point if needed to start, stop
    target = (start, stop)
    idx = [0, 0]
    for i in range(2):
        idx[i] = np.searchsorted(x_out, target[i])
        if idx[i] < len(x_out) and \
                x_out[idx[i]] != target[i] and \
                target[i] > x_out[0] and \
                target[i] < x_out[-1]:

            interp = y_out[idx[i]-1] + ( (start-x_out[idx[i]-1]) * 
                                       (y_out[idx[i]]-y_out[idx[i]-1]) / 
                                       (x_out[idx[i]]-x_out[idx[i]-1]) )

            x_out = np.insert(x_out, idx[i], start)
            y_out = np.insert(y_out, idx[i], interp)

    # modify values
    y_out[idx[0]:idx[1]] *= mult

    # return
    return x_out, y_out


if __name__ == "__main__":
    main()
