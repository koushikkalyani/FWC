import numpy as np
import matplotlib.pyplot as plt
#line 1
def line1(x):
  return (3-4*x)/7
#line 1
def line2(x):
  return (1+2*x)/3
l1 = np.loadtxt('l1.dat',dtype='float')
l2 = np.loadtxt('l2.dat',dtype='float')
R = np.loadtxt('result.dat',dtype='float')

def line3(x):
  return (-1*x +(R[0]+R[1]))
# Define the x values for the lines
x_values = np.linspace(-0.7, 0.7, 1000)

# Calculate the y values for each line
y_values1 = line1(x_values)
y_values2 = line2(x_values)
y_values3 = line3(x_values)

# Plot line 1
plt.plot(x_values, y_values1, label='4x + 7y - 3 = 0')

# Plot line 2
plt.plot(x_values, y_values2, label='2x - 3y + 1 = 0')

#plot solution line i.e line3
plt.plot(x_values, y_values3, label='x + y = 6/13')

# Plot the intersection point
plt.plot(R[0], R[1], 'ro', label='Intersection Point')

# Plot x and y axes
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

# Set the limits of the plot
def display_coordinates(x, y):
    plt.scatter(x, y, color='green')  # Plot the point
    plt.text(x, y, f'({x}, {y})', verticalalignment='bottom')
display_coordinates((R[0]+R[1]), 0)
display_coordinates(0,(R[0]+R[1]))
display_coordinates(R[0],R[1])

plt.xlim(-0.7, 0.7)
plt.legend()
plt.savefig('/home/koushike-kun/FWC/Vectors/code/Data_structures/figs/fig')
