#
#  use_simple_module.py:
#
#  Python script which use `simple` module
#
#  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
#  License:  BSD 2-CLAUSE.
#
try:
    import simple
except:
    raise RuntimeError("\n\n`simple` module not found, run `$ make` ! \n")

def main():

    # Variables for `simple.print_variables`
    iInt = -10
    iLongInt = 10000000001
    iUInt = 5
    strABC = "ABCDEFGHIJ"
    dPi = 3.1415

    # Call `simple.print_variables`
    i2Int = simple.print_variables(iInt,
                                   iLongInt,
                                   iUInt,
                                   strABC,
                                   dPi)
    print("\nInteger multiplied by 2: %d" % i2Int)

if __name__ == "__main__":
    main()