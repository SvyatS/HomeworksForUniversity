def MNK(x, y):
    n = len(x)
    sx = sum(x)
    sy = sum(y)
    s0 = sum(x[i]*y[i] for i in range(n))
    s1 = sum(x[i]**2 for i in range(n))
    a = (n*s0 - sx*sy)/(n*s1 - sx**2)
    b = (sy - a*sx)/n
    y_func = []
    for i in range(n):
        y_func.append(a*x[i] + b)

    return y_func, a, b
