
from setuptools import setup, Extension

# the c extension module
extension_mod = Extension(
    "pywrapper",
    ["src/pywrapper/pywrapper.c"],
    include_dirs=[
    		"src/extlib"
        ],
    extra_objects=['extlib.lib'],
    extra_link_args=['-LIBPATH:src/extlib/build'],
    )

setup(
    name = "pywrapper",
    ext_modules=[extension_mod],
    )
