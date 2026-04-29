def f(x):
    try:
        y = 10 / x
    except ZeroDivisionError:
        return 0
    else:
        return y
    finally:
        print("fim")