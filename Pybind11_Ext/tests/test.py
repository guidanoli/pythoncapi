import cmake_example as m

assert m.__version__ == '0.0.1'
assert m.add(1, 2) == (1 + 2)
assert m.subtract(1, 2) == (1 - 2)
assert m.multiply(7, 5) == (7 * 5)
assert m.divide(1, 2) == (1 / 2)
assert m.factorial(3) == 6
