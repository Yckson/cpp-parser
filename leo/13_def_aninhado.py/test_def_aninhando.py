def outer(x):
    def inner(y):
        if y > 0:
            return y
        return -y
    return inner(x)