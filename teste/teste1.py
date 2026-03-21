def factorial(n):
    result = 1
    for i in range(n):
        result = result * i
    return result


def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


class Calculator:
    def add(self, a, b):
        return a + b

    def multiply(self, a, b):
        return a * b


def process_data(items):
    for item in items:
        if item < 0:
            continue
        print(item)
