import matplotlib.pyplot as plt
import csv

from numpy import double
  
x = []
y = []
  
with open('data.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')
      
    for row in plots:
        x.append(row[0])
        y.append(double(row[2]))

  
plt.plot(x, y, color = 'g', linestyle = 'solid',
         marker = '')
  
plt.xticks()
plt.xlabel('S value')
plt.ylabel('time')
plt.title('n = 2^14', fontsize = 20)
plt.grid()
plt.legend()
plt.show()