gencrpyt
===

[ ![Trello Board](https://img.shields.io/badge/-Trello%20Board-blue.svg?colorB=0079BF&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA3XAAAN1wFCKJt4AAAAB3RJTUUH4gMfFRg2j85BawAAAJBJREFUSMftk8sNwjAQRGdRukBUwSlOBaEQOqBNqtg+HhciRVYczEZRcvC7rfcz67EsNU4H8ACc/3FgzOfZgoBLugb3czO7/brBRJ+dp5pcjUXFwkjusvebNoF9BABbi+d0wcVewHsW30uFSx8NSTKzYm6NvO+4NwBSFg8RgZANWy3yDfO9xqJnUMS/vY2T8QHlfqEd/I6h/wAAAABJRU5ErkJggg==) ](https://trello.com/b/jgU4LbyG/gencrypt)

![Coverage](https://img.shields.io/badge/Coverage-95%25%2B-brightgreen.svg)

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

|Name  |Type|Description|
|------|----|-----------|
|rot13 |Keyless   |Rotates the alphabet with 13 chars|
|xor   |Symmetric |Applies xor key[i] for every character (i modulo key length)|
|base64|Symmetric |Splits the bits into 6 bit chunks and map the values to `A-Za-z0-9+/` values|
|rsa   |Asymmetric|RSA encode and decode by private and public keys|
|md5   |Hash      |MD5 hasher|

## IDE

I use Eclipse CDT but the project can be compiled using only command line tools.

## Third party code

##### RSA

I used and modified [this](https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/) RSA implementation.

##### MD5

I used [this](http://archive.is/Grv2E) MD5 implementation in my MD5Hasher class.

##### GTEST_LITE and MEMTRACE

GTEST_LITE ( [.h](http://svn.iit.bme.hu/proga2/cporta_peldak/NHF/test/gtest_lite.h) ) and MEMTRACE ( [.cpp](http://svn.iit.bme.hu/proga2/cporta_peldak/NHF/Kesz/memtrace.cpp), [.h](http://svn.iit.bme.hu/proga2/cporta_peldak/NHF/Kesz/memtrace.h) ) is created by Szeberenyi Imre and Peregi Tamas.

