import numpy as np
import matplotlib.pyplot as plt
from sympy import symbols, Eq, solve
#line 1
def line1(x):
  return (3-4*x)/7
#line 1
def line2(x):
  return (1+2*x)/3

x, y = symbols('x y')

# Define the equations
eq1 = Eq(4*x + 7*y - 3, 0)
eq2 = Eq(2*x - 3*y + 1, 0)

# Solve the system of equations
solution = solve((eq1, eq2), (x, y))

# Extract the solutions for x and y
x_solution = solution[x]
y_solution = solution[y]
print("Solution:")
print(f"x = {x_solution}")
print(f"y = {y_solution}")

def line3(x):
  return (-1*x +(x_solution + y_solution))
# Define the x values for the lines
x_values = np.linspace(-10, 10, 100)

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

# Plot x and y axes
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

# Set the limits of the plot
plt.xlim(-10, 10)
plt.ylim(-10, 10)

# Add labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Line Passing Through Intersection with Equal Intercepts')

# Plot the intersection point
plt.plot(x_intersect, y_intersect, 'ro', label='Intersection Point')

# Add legend
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

