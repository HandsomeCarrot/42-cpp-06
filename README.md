*This project has been created as part of the 42 curriculum by vpoka.*

# CPP06 — C++ casts

A C++98 project from the 42 curriculum focused on choosing the right C++ cast: scalar conversions, pointer serialization, and runtime type identification.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Testing](#testing)
- [Status](#status)

## Description

CPP06 is the 42 C++ module dedicated to C++ casts: how to convert between scalar types, pointers, and classes in a hierarchy, and which cast is appropriate for each job. The module is split into three small exercises, each centered on one cast family, and each ships the test program the subject asks for.

* **ex00 — Conversion of scalar types**
  A non-instantiable `ScalarConverter` class with a single static `convert` method that detects the type of a C++ literal passed as a string and prints its value as `char`, `int`, `float`, and `double`.
* **ex01 — Serialization**
  A `Serializer` class with static `serialize(Data*)` / `deserialize(uintptr_t)` methods that turn a pointer into a `uintptr_t` and back, proving the round-trip preserves the original address.
* **ex02 — Identify real type**
  A `Base` class with empty `A`, `B`, `C` subclasses, a `generate()` function, and two `identify` overloads that report the real type of an object without using `std::typeinfo`.

| Exercise | Executable | Cast used |
| --- | --- | --- |
| [ex00](ex00/) — Conversion of scalar types | `convert` | `static_cast` |
| [ex01](ex01/) — Serialization | `serialize` | `reinterpret_cast` |
| [ex02](ex02/) — Identify real type | `identify` | `dynamic_cast` |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98`; no external libraries are required.
- The repository and the subject specify no minimum compiler or Make versions.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
```

This produces `ex00/convert`, `ex01/serialize`, and `ex02/identify`. Each Makefile provides `all` (default), `clean` (remove the `build/` directory), `fclean` (also remove the executable), `re` (rebuild), `debug` (rebuild with `-g -DDEBUG`), and `run` (rebuild and execute the exercise's test program). For example:

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
```

### ex00 — Conversion of scalar types

From the repository root:

```bash
./ex00/convert 0 42.0f nan
```

The program takes one or more literals as arguments and converts each in turn. Called without arguments it prints an error and exits with status `1`.

Accepted literal forms:

- **char:** a single non-digit character, e.g. `a`, `c`
- **int:** decimal, e.g. `0`, `-42`, `+42`
- **float:** decimal with an `f` suffix, e.g. `0.0f`, `4.2f`, plus the pseudo-literals `nanf`, `+inff`, `-inff`
- **double:** decimal, e.g. `0.0`, `-4.2`, plus the pseudo-literals `nan`, `+inf`, `-inf`

A single digit (`4`) is detected as an int, not a char. A trailing decimal point without fraction digits is accepted (`123.`, `123.f`).

For each literal the program prints four lines — `char`, `int`, `float`, `double` — with the value converted to every scalar type, and marks the line matching the detected input type with `(detected)`. Values follow the subject's examples (`42.0f` gives char `'*'`, int `42`, float `42.0f`, double `42.0`); floats carry a trailing `f` and one decimal place. A non-printable char conversion prints `non displayable`, and conversions that cannot be represented (char or int of `nan`/`±inf`) print `impossible`. Malformed literals are reported on standard error as `invalid character '<c>' (char <n>)`.

```bash
make -C ex00 run
```

rebuilds and feeds the converter a fixed battery of valid and invalid literals taken from the Makefile.

### ex01 — Serialization

From the repository root:

```bash
make -C ex01 run
```

or run the test program directly (it takes no arguments):

```bash
./ex01/serialize
```

Test 1 serializes and deserializes a `Data` object and prints a side-by-side comparison of the original and deserialized values (name, cooked flag, age) and their addresses. Test 2 then mutates the object through the deserialized pointer to show both pointers alias the same instance. The `Data` structure is non-empty (`name_`, `cooked_`, `age_`) as the subject requires.

### ex02 — Identify real type

From the repository root:

```bash
make -C ex02 run
```

or run the test program directly (it takes no arguments):

```bash
./ex02/identify
```

The program seeds `rand()` with the current time, then generates random `A`/`B`/`C` instances and identifies each one by pointer and by reference (tests 1–2). Tests 3–4 pass plain `Base` instances to exercise the error path: both `identify` overloads throw `std::runtime_error`, which the test program catches and prints. `std::typeinfo` is not used anywhere (it is forbidden by the subject); identification relies on `dynamic_cast` — null checks on pointers, and exception handling on references.

## Resources

- **cppreference C++ language reference:** entries for `static_cast`, `dynamic_cast`, `reinterpret_cast`, and implicit/explicit conversions — the cast operators at the center of this module. Consult the C++98 behavior when reading modern documentation.
- **cppreference C++ standard-library reference:** entries for `std::numeric_limits`, `std::strtod`, `std::strtol`, `std::rand`, and `uintptr_t` (`<stdint.h>`).
- **GNU Make manual:** targets, recipes, and dependency files (`-MP -MD`) used by the module Makefiles.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* Choosing the appropriate C++ cast for each problem: `static_cast` (ex00), `reinterpret_cast` (ex01), `dynamic_cast` (ex02)
* Non-instantiable utility classes (private Orthodox Canonical Form members plus a single static method)
* Type detection from string literals, including pseudo-literals and conversions that cannot be represented
* Pointer-to-integer round-tripping with `uintptr_t`
* Runtime type identification without `std::typeinfo`, on both pointers and references

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98**
* Compiler flags: **`-Wall -Wextra -Werror`**; the code must still compile with **`-std=c++98`**
* External libraries, Boost, and C++11 or later features are forbidden; `*printf()`, `*alloc()`, and `free()` are forbidden too
* `using namespace` and `friend` are forbidden unless explicitly stated
* The STL (containers and algorithms) is forbidden in this module
* Classes follow the Orthodox Canonical Form except where the subject says otherwise (ex02's `Base`, `A`, `B`, `C` are explicitly exempt)
* No function implementations in headers (except function templates); headers must be self-contained and guarded
* Module-wide additional rule: each exercise must handle its conversions with one specific cast, and the choice is reviewed during the defense
* ex02: `std::typeinfo` is forbidden, and `identify(Base&)` must not use a pointer inside

## Repository structure

```text
cpp06/
├── README.md
├── .gitignore
├── ex00/   # Conversion of scalar types: ScalarConverter + convert test program
│   ├── include/   # ScalarConverter.hpp, helpers/colors.h, helpers/debug.hpp
│   └── src/       # ScalarConverter.cpp, main.cpp
├── ex01/   # Serialization: Serializer + Data + serialize test program
│   ├── include/   # Serializer.hpp, Data.hpp, helpers/colors.h, helpers/debug.hpp
│   └── src/       # Serializer.cpp, Data.cpp, main.cpp
└── ex02/   # Identify real type: Base/A/B/C + identify test program
    ├── include/   # Base.hpp, A.hpp, B.hpp, C.hpp, helpers/colors.h, helpers/debug.hpp
    └── src/       # main.cpp (generate and identify live here)
```

## Focus areas by exercise

### ex00 — Conversion of scalar types

* detecting the literal's type from its string form (char, int, float, double)
* parsing numeric literals with optional sign, decimal part, and `f` suffix
* pseudo-literals (`nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`)
* explicit scalar conversions with `static_cast`
* reporting non-displayable and impossible conversions

### ex01 — Serialization

* pointer → `uintptr_t` → pointer round-trip with `reinterpret_cast`
* a non-empty `Data` structure designed in Orthodox Canonical Form
* verifying aliasing: mutations through the deserialized pointer affect the original

### ex02 — Identify real type

* random instantiation of `A`, `B`, or `C` returned as a `Base*`
* `dynamic_cast` on a pointer (null check) for `identify(Base*)`
* `dynamic_cast` on a reference (exception handling) for `identify(Base&)`, without using a pointer
* a clear error path for plain `Base` instances

## Testing

Each exercise ships the test program required by the subject (`main.cpp`), and each Makefile has a `run` target that rebuilds and executes it:

```bash
make -C ex00 run   # valid and invalid literal battery for ScalarConverter
make -C ex01 run   # serialize/deserialize round-trip and aliasing tests
make -C ex02 run   # random generate/identify tests plus error cases
```

ex00 also accepts ad-hoc literals directly, e.g. `./ex00/convert 42 4.2f nan`. Building with `make -C exNN debug` adds `-g -DDEBUG`, which enables `[DEBUG]` trace messages from the `DEBUG_MSG` macro in each exercise's `include/helpers/debug.hpp`; error, warning, and info messages use the same helpers.

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
