def factorial(num):
    if(num == 0):
        return 1
    elif(num < 0):
        return None
    else:
        S = 1
        i = 1
        while(i <= num):
            S *= i
            i += 1
        return S
