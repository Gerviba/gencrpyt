gencrpyt
===

[ ![Trello Board](https://img.shields.io/badge/-Trello%20Board-blue.svg?colorB=0079BF&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA3XAAAN1wFCKJt4AAAAB3RJTUUH4gMfFRg2j85BawAAAJBJREFUSMftk8sNwjAQRGdRukBUwSlOBaEQOqBNqtg+HhciRVYczEZRcvC7rfcz67EsNU4H8ACc/3FgzOfZgoBLugb3czO7/brBRJ+dp5pcjUXFwkjusvebNoF9BABbi+d0wcVewHsW30uFSx8NSTKzYm6NvO+4NwBSFg8RgZANWy3yDfO9xqJnUMS/vY2T8QHlfqEd/I6h/wAAAABJRU5ErkJggg==) ](https://trello.com/b/jgU4LbyG/gencrypt)

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
|rot13|Keyless|Rotates the alphabet with 13 chars|
|xor  |Symmetric|Applies xor key[i] for every character (i modulo key length)|

## IDE

I use Eclipse CDT but the project can be compiled using only command line tools.