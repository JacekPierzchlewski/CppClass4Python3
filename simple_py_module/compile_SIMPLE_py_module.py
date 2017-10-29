#
# compile_SIMPLE_py_module.py
#
# Compilation script for Simple Python module written in C++.
#
#  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
#  License:  BSD 2-CLAUSE.
#
try:
    from distutils.core import setup, Extension
except:
    raise RuntimeError("\n\nPython distutils not found!\n")

# Definition of extension modules
simple = Extension('simple',
                   sources = ['simple_py_module.cpp'])

# Compile Python module
setup (ext_modules = [simple],
       name = 'simple',
       description = 'Simple Python module',
       version = '1.0')
