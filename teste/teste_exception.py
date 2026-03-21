def risky_operation(x):
    try:
        result = 10 / x
        print(result)
    except ZeroDivisionError:
        print("Divided by zero!")
    finally:
        print("Done")
    return result
