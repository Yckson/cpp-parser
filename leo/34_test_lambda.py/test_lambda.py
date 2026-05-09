def apply_op(x):
    inc = lambda y: y + 1
    dec = lambda y: y - 1
    if x > 0:
        return inc(x)
    return dec(x)

nums = [1, 2, 3]
squares = list(map(lambda n: n * n, nums))
