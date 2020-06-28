import numpy
import math

def f(x):
    mu = 10
    sigma2 = 4
    x = 8
    return (1/math.sqrt(2*math.pi*sigma2) * math.exp((-0.5)*(x-mu)**2/sigma2))

def update(mean1, var1, mean2, var2):
    new_mean = float(var2 * mean1 + var1 * mean2) / (var1 + var2)
    new_var = 1./(1./var1 + 1./var2)
    return new_mean, new_var

def predict(mean1, var1, mean2, var2):
    new_mean = mean1 + mean2
    new_var = var1 + var2
    return new_mean, new_var

'''
1D Kalman Filter
'''
measurements = [5., 6., 7., 9., 10.]
motion = [1., 1., 2., 1., 1.]
measurement_sig = 4.
motion_sig = 2.
mu = 0.
sig = 10000.
#sig = 0.0000000001

init_mu = mu
init_var = sig
for t in range(0, len(measurements)):
    new_mu, new_var = update(init_mu, init_var, measurements[t], measurement_sig)
    print('update ({}): '.format(t), new_mu, new_var)
    new_mu, new_var = predict(new_mu, new_var, motion[t], motion_sig)
    print('predict ({}): '.format(t), new_mu, new_var)

    init_mu = new_mu
    init_var = new_var

print('final: ', new_mu, new_var)
