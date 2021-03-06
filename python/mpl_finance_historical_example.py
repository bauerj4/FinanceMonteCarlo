import numpy as np
import matplotlib.pylab as plt
import matplotlib.finance as mpf
import pandas
from sklearn.linear_model import LinearRegression

start = (2013,1,1)
end   = (2016,1,1)

# ohcl = open, high, low, close
quotes = mpf.quotes_historical_yahoo_ohlc('GOOG',start,end)
tickerClose = [close[3] for close in quotes]

deltaClose = pandas.Series(np.gradient(tickerClose))

#googleDrift = np.polyfit(np.arange(len(tickerClose))/365., np.log10(tickerClose),1)
#print googleDrift

#plt.plot(np.arange(len(tickerClose)),np.log10(tickerClose))

print tickerClose[0], tickerClose[-1], sum(deltaClose)

plt.plot(pandas.rolling_mean(deltaClose,90))
plt.plot(deltaClose)
plt.show()
