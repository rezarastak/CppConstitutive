# CppConstitutive
A collection of high-performance material constitutive models used in computational mechanics.

[![Build Status](https://travis-ci.com/rezarastak/CppConstitutive.svg?branch=master)](https://travis-ci.com/rezarastak/CppConstitutive)
![C++ CI](https://github.com/rezarastak/CppConstitutive/workflows/C++%20CI/badge.svg)
[![Release](https://img.shields.io/github/v/release/rezarastak/CppConstitutive)](https://github.com/rezarastak/CppConstitutive/releases)
[![DOI](https://zenodo.org/badge/225561737.svg)](https://zenodo.org/badge/latestdoi/225561737)

## Goals of the project
* A Large number of existing material models are available.
* For each material model, the corresponding article introducing the model is available. Ideally,
a benchmark is provided to reproduce the results and plots of the corresponding article.
* Each material can support multiple formulations such as small-strain, Lagrangian large-strain,
and Updated Lagrangian large-strain formulations.
* Materials can provide consistent tangent operators for their materials. However, this is not
required. The materials without a proper definition of consistent tangents can compute them using
automatic differentiation.
* All functions and classes can use arbitrary types. Therefore, most of the coding uses generic
expressions, because the types of scalar variables can be `double`, `float`, or types needed for
automatic differentiation. Tensor types can represent Deal.II types or any other types that provide
tensorial operations.
* Initially, the materials and examples will use Deal.II capabilities. However, the goal is to
provide a method in which this repository can be compiled without a Deal.II installation.
* Several drivers will be provided such as uniaxial, biaxial, simple shear, etc.
* Using Deal.II, some examples provide simple FE simulations in 2D and 3D.
* Material models are provided for various physics such as thermal materials, electro-static materials,
Thermo-elastic materials, poro-elastic materials, etc.

## Installation Guide:
You can use the code as a header-only library. Just add the `include/` to your include directories,
then you can `#include` the header files in your code and compile them.

If you want to run the examples, go to their directory in the terminal and type:
```
cmake .
make run
```
to run the example.

## Open source code contributions
Thank you for considering to contribute to this project. Please read the file [CONTRIBUTING.md](CONTRIBUTING.md)

