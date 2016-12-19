
import matplotlib.pyplot as plt
import scipy.stats as stats
import numpy as np

real_min = 0
real_max = 100

def prob_max(x,n,max_value):
	"""
        Calculate the probabilty for X being the max value of N values
	"""
	prob = float(1)
	xf = float(x)
	mv = float(max_value)
	for i in range(1,n):
		prob *= xf / mv

	return prob



def prob_distrib(n,max_value):
	distrib = []
	for i in range(1,max_value+1):
		distrib.append(prob_max(i,n,max_value))

	return distrib


def gaussian(x,mu,sigma):
	return 20/(sigma * np.sqrt(2 * np.pi)) * np.exp( - (x - mu)**2 / (2 * sigma**2))

def merge_cost(n,m,max_value):
	sum1 = 0
	for i in range(0,max_value):
		p = prob_max(i,m,max_value)
		sum1 += p * ( max_value - i ) * float(n) / float(max_value)
	sum1 = sum1 / max_value
	sum2 = 0
	for i in range(0,max_value):
		p = prob_max(i,n,max_value)
		sum2 += p * ( max_value - i ) * float(m) / float(max_value)
	sum2 = sum2 / max_value
	compute_cost = (n + m - sum1 ) * 2 + sum1
	compute_cost += ( n + m - sum2 ) * 2
	compute_cost *= 0.5
	return compute_cost


merge_cost_array = np.empty([200,100])

print(merge_cost(7,4,1000) )
print(merge_cost(4,7,1000) )

distrib = prob_distrib(2,1000)

plt.title("Probability of x bieng the max_value") 
plt.xlabel('x')
plt.ylabel('prob')

plt.plot(distrib)


plt.show()