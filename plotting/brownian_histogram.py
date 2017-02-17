import matplotlib.pylab as plt
import numpy as np
import sys


bins = np.linspace(-100,100,101)
std   = np.sqrt(1000)
mu    = 0.

def gauss(x,mu,sigma):
    val = np.exp(- (x - mu)**2 / (2. * sigma**2))
    val /= sigma * np.sqrt(2 * np.pi) 
    return val

vgauss = np.vectorize(gauss, excluded=['mu','sigma'])
for fl in sys.argv[1:]:
    f = open(fl)
    values = []

    for line in f:
        values.append(float(line))

    plt.hist(values, bins=bins, histtype='step', normed=True)


plt.plot(bins, vgauss(bins,mu,std), color='black', lw=2)
plt.xlabel(r'Terminal Walk Position',fontsize=16)
plt.ylabel("Normalized Counts",fontsize=16)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.show()
