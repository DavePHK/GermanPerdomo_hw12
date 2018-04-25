import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('advection.txt')

x=np.linspace(-2.0,2.0,len(datos[0,:]))


plt.figure()
plt.title('Advection')
plt.xlabel('X [m]')
plt.ylabel('Y')
for i in range(0,4):
	plt.plot(x,datos[i,:],label= 't ='+ str((i)*700/4), c = (np.random.rand(),np.random.rand(),np.random.rand()))
plt.legend()
plt.savefig('advection.png')
