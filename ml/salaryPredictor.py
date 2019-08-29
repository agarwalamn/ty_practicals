
import numpy as np
import matplotlib.pyplot as plt 
def estimate_coef(x,y):
	n=np.size(x)

	m_x,m_y = np.mean(x), np.mean(y)
	S_xy = np.sum(y*x) - n*m_y*m_x
	S_xx = np.sum(x*x) - n*m_x*m_x

	b_1 = S_xy/S_xx
	b_0 = m_y - b_1*m_x

	return (b_0,b_1)
def plot_regression_line(x, y, b): 
    plt.scatter(x, y, color = "m", 
               marker = "o", s = 30) 
    y_pred = b[0] + b[1]*x 
    plt.plot(x, y_pred, color = "g") 
  
    plt.xlabel('x') 
    plt.ylabel('y') 
    plt.show() 

ar=[3, 8, 9, 13,3, 6, 11,21,1, 16]
ar1=[30,37,64,72,36,43,59,90,20,83]
x=np.array(ar)
y=np.array(ar1)
b = estimate_coef(x, y)
print(b[0],b[1]) 
print("enter the x to predict")
t = int(input())
cal = b[0]+b[1]*t
print(cal)
if t in ar:
    print("diff = %f"%abs(cal-ar1[ar.index(t)]))
plot_regression_line(x, y, b)