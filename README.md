gencrpyt
===

C++ crpyto library by Szabó Gergely

## Disclaimer

> Note that this project is a homework project.

## How to build?

```bash
	$ make install
```

## Other make commands

|Command|Description|
|-------|-----------|
| `$ make all` | Execute: install |
| `$ make install` | Compiles the sources |
| `$ make run` | Executes the compiled binary |
| `$ make test` | Runs the unit tests |
| `$ make integration-test` | Runs the integraion tests |
| `$ make touch` | Touch the source files |
| `$ make clean` | Remove the binary |

## Supported encryptions

|Name|Type|Description|
|----|----|-----------|
|rot13|Symmetric, Keyless|Rotates the alphabet with 13 chars|
|xor  |Symmetric|Applies xor key[i] for every character (i modulo key length)|

## IDE

I use Eclipse CDT but the project can be compiled using only command line tools.