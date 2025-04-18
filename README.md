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

**Notes:**
- If a `<reset_condition>` is an equality such as `x == 3.0` then the generated code must look like `resets[i] = x - 3.0`.
- If a `<reset_condition>` is an inequality such as `x > 3.0` or `x >= 3.0` then the generated code must look like `resets[i] = 1.0 - (x > 3.0)` or `resets[i] = 1.0 - (x >= 3.0)`, respectively.
