def ackermann_peter_10(m, n):
    assert isinstance(m, int) and m >= 0, 'm is unacceptable'
    assert isinstance(n, int) and n >= 0, 'n is unacceptable'
    stack = []
    while True:
        if not m:
            if not stack:
                return n + 1
            m, n = stack.pop(), n + 1
        elif not n:
            m, n = m - 1, 1
        else:
            stack.append(m - 1)
            n -= 1
