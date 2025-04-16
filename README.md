This repository is to test CellML models with resets.

**Prerequisites:**
- [CMake](https://cmake.org/); and
- [SUNDIALS](https://computing.llnl.gov/projects/sundials).

**Configuration:**
```bash
# Create a build directory:

mkdir build
cd build

# Configure using the default generator:

cmake ..

# Configure using the Ninja generator:

cmake -G Ninja ..
```

**Build:**
```bash
cmake --build .
```

**Tests:**
```bash
./<test>
```

The tests generate a [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) file of the form `<test>.csv`.
