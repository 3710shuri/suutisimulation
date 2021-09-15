import math
# f()
def f(x):
  return x - 2 * math.sin(x)

# df()
def df(x):
  return 1 - 2 * math.cos(x) #1 - 2 * math.cos(x)を追加

x = 2.0
for i in range(10):
  x = x - f(x)/df(x)
  print("{:.10f} {:.10e}".format(x, f(x)))
#