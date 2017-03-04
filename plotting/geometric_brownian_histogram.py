import matplotlib.pylab as plt
import numpy as np
import sys


bins = np.linspace(40,180,141)
b     = np.sqrt(60. * 0.002 * 0.4**2)
a     = np.log(100.) - 0.5 * 0.4**2 * 60. * 0.002

def logNorm(x,alpha,beta):
    val = np.exp(- (np.log(x) - alpha)**2 / (2. * beta**2))
    val /= x * beta * np.sqrt(2 * np.pi) 
    return val

vLN = np.vectorize(logNorm, excluded=['alpha','beta'])
for fl in sys.argv[1:]:
    f = open(fl)
    values = []

    for line in f:
        values.append(float(line))

    plt.hist(values, bins=bins, histtype='step', normed=True)


plt.plot(bins, vLN(bins,a,b), color='black', lw=2)
plt.xlabel(r'Terminal Walk Position',fontsize=16)
plt.ylabel("Normalized Counts",fontsize=16)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.show()
