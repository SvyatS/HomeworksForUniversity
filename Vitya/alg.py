
def LeftRect(f, a, d, e, c, b, n = 100000):
    h = (b-c)/float(n)
    total = sum([f((c + (k*h)), a, d, e) for k in range(0, n)])
    result = h * total
    return result

def simpson(f, a, d, e, c, b, n = 100000):
    h=(b-c)/n
    k=0.0
    x=a + h
    for i in range(1,int(n/2 + 1)):
        k += 4*f(x, a, d, e)
        x += 2*h

    x = a + 2*h
    for i in range(1,int(n/2)):
        k += 2*f(x, a, d, e)
        x += 2*h
    return (h/3)*(f(c, a, d, e)+f(b, a, d, e)+k)

def f(x, a, d, e):
    return a*x*x+d*x+e
