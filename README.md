# ft_ssl

A from-scratch implementation of the MD5 and SHA-256 cryptographic hash
algorithms, mirroring the behaviour of the classic `openssl dgst` command-line
tool. It is a 42-style subject project built in pure C with no external
libraries.

## Purpose

The goal of this project is to understand and replicate how a real hashing
utility works under the hood:

- Implement the full MD5 and SHA-256 algorithms from first principles.
- Handle command-line parsing, flags, input sources and output formatting.
- Match the interface and output of `openssl md5` / `openssl sha256`.

## Usage

```
usage: ft_ssl command [flags] [file/string]
```

Supported commands: `md5`, `sha256`.

Options:

| Flag | Meaning                                          |
|------|--------------------------------------------------|
| `-p` | Echo input from stdin and print the digest       |
| `-q` | Quiet mode: print only the digest                |
| `-r` | Reverse mode: print the hash before the filename |
| `-s` | Hash the supplied string rather than a file      |

Example:

```sh
./ft_ssl md5 file.txt
./ft_ssl sha256 -q -s "hello world"
```

## Stack

- **Language:** C (C99)
- **Build:** `make` / `Makefile` (only `cc`, `ar`, standard tools)
- **No external dependencies** — every hash algorithm is implemented from
  scratch in the `srcs/hash/` directory.
- **Style:** 42 Norm-compliant C (functions named, headers, 42 conventions).

## Project layout

```
includes/ft_ssl.h      shared types, structs and prototypes
srcs/main.c            entry point
srcs/dispatcher.c      command dispatch table
srcs/commands/         per-command implementations (md5.c, sha256.c)
srcs/hash/             the algorithms (md5_algo.c, sha256_algo.c)
srcs/io/               input/output handling
srcs/parsing/          argument and flag parsing
srcs/utils/            string and error helpers
```

## Build & run

```sh
make        # build the ft_ssl binary
make re     # rebuild from scratch
```