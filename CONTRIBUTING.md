# Open source contributions
Thank you for considering to contribute to this project. Please read this document
before preceding.

## Testing infrastructure
All the code written here must be properly tested. We use the `catch2` testing framework.
All of our tests are created in the `test/` directory. Each file in the test directory
corresponds to a header file in the `include/` directory. For example `test/linear_elastic.cc`
describes tests related to the header file `include/constitutive/mech/linear_elastic.h`.

In order to run the tests, create a `build/` directory and enter it. Then use make to build
the target `tests`.
```
cd build
cmake ..
make tests
```

## Reporting a bug
Follow these steps to report a bug:
1. Try to better understand the bug by observing it multiple time and finding a way to
reproduce it.
2. Search in the `issues` and check if someone else has reported it already.
3. Search in `pull requests` to see if someone is already proposing a patch regarding this bug.
4. If this bug has not been reported before, please submit it as a issue to Github. Send all of
information needed to reproduce the bug. These sources of information include (but not limited to)
compiler vendor and version, operating system, CmakeCache.txt, configuration and compilation output,
details of the deal.II installation.
