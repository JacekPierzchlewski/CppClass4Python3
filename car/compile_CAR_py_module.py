try:
    from distutils.core import setup, Extension
except:
    raise RuntimeError("\n\nPython distutils not found!\n")

# Definition of extension modules
cCar = Extension('cCar',
                 sources = ['car.cpp', 'car2py.cpp'])

# Compile Python module
setup (ext_modules = [cCar],
       name = 'cCar',
       description = 'cCar Python module',
       version = '1.0')
