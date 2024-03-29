# Alchemist64

An opensource remake of freealchemist for Commodore64 and CommanderX16.

![Gameplay](https://github.com/dakk/alchemist64/raw/master/media/gameplay.gif)


## Commodore64

### Build

To build alchemist64 you need the cc65 C compiler; a prebuilt binary is also
included in this repo.

```bash
make
```

### Run

```bash
x64 alchemist64.c64
```

## CommanderX16
### Build

To build alchemist64 you need the cc65 C compiler; a prebuilt binary is also
included in this repo.

```bash
make -f Makefile.cx16
```

### Run

```bash
x16emu -prg alchemist64.cx16 -run
```



## License

```
Copyright (c) 2021 Davide Gessa

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
```