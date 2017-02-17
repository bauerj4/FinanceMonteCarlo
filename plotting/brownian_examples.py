import matplotlib.pylab as plt
import numpy as np
import sys


for fl in sys.argv[1:]:
    f = open(fl)
    values = []
    steps  = []

    for line in f:
        values.append(float(line.split()[1]))
        steps.append(float(line.split()[0]))

    plt.plot(steps,values, lw=2)


plt.xlabel(r'$t_i$',fontsize=18)
plt.ylabel("$x(t_i)$",fontsize=18)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.show()
