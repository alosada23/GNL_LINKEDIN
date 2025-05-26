# get\_next\_line

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20%7C%2042-blue?style=flat-square" alt="C Badge" />
  <img src="https://img.shields.io/badge/Memory‑Safe-✔️-brightgreen?style=flat-square" alt="Memory Safe" />
  <!-- License badge intentionally omitted until a license is chosen -->
</div>

> **“Reading *Don Quixote* while remembering only five words at a time.”**
> That’s what it feels like to stream a file line‑by‑line under tight buffer constraints.
> This repo contains a minimal, **robust** implementation of `get_next_line` — the classic 42 School challenge that teaches low‑level I/O, dynamic memory management and error handling in C.

⚠️ **Legal note about `subject.pdf`**
The original 42 network assignment (subject) is included in `docs/subject.pdf` **for educational purposes only**. All rights remain with 42 School. If you are a 42 representative and wish it to be removed, please open an issue and it will be taken down immediately.

---

## 📑 Table of Contents

* [Features](#-features)
* [Project Layout](#-project-layout)
* [Build](#-build)
* [Quick Start](#-quick-start)
* [Design Highlights](#-design-highlights)
* [Testing](#-testing)
* [Contributing](#-contributing)
* [Credits](#-credits)
* [License (TBD)](#-license-tbd)
* [Versión en Español](#versión-en-español)

---

## ✨ Features

| Capability                     | Details                                                                             |
| ------------------------------ | ----------------------------------------------------------------------------------- |
| **Line‑by‑line reading**       | Returns exactly **one full line** per call, including the trailing `\n` if present. |
| **Tiny buffers welcome**       | Works with any `BUFFER_SIZE` ≥ 1 without loading the entire file into memory.       |
| **No memory leaks**            | Every allocation is safely freed, even on error paths.                              |
| **Overflow‑safe `calloc`**     | Guards against `SIZE_MAX` multiplication overflow before allocating.                |
| **Static storage, no globals** | Persistent state is kept in a `static` pointer local to the function.               |
| **Modular utils**              | Helper functions live in `get_next_line_utils.c` for easy unit testing.             |

---

## 📁 Project Layout

```
├── src/                 # implementation (.c)
├── include/             # headers (.h)
├── tests/               # simple unit tests
├── docs/subject.pdf     # official 42 subject (see legal note)
├── Makefile
└── README.md
```

---

## 🛠️ Build

```bash
# Clone
git clone https://github.com/<your-user>/get_next_line.git
cd get_next_line

# Compile (replace BUFFER_SIZE as desired)
gcc -Wall -Wextra -Werror -I include -D BUFFER_SIZE=42 src/*.c -o gnl_demo
```

---

## ⚡ Quick Start

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("big_novel.txt", O_RDONLY);
    if (fd == -1) return 1;

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

```bash
valgrind --leak-check=full ./gnl_demo
```

---

## 🧩 Design Highlights

1. **Overflow Protection** – `ft_calloc` verifies multiplication won’t exceed `SIZE_MAX`.
2. **Fail‑safe Cleanup** – All buffers freed on `read` or `malloc` errors.
3. **Precise Allocation** – Space reserved for trailing `\n` and `\0` only when needed.
4. **Static Storage** – State persists across calls without global symbols.
5. **Unit‑test Friendly** – Utilities separated for isolated tests.

---

## 🧪 Testing

```bash
make test      # runs basic tests under tests/
```

Generate coverage (optional):

```bash
make coverage  # requires lcov / genhtml
```

---

## 🤝 Contributing

Pull requests are welcome!

* Follow the 42 **Norminette** style.
* Run `make test` & `make clean` before committing.
* Open an issue first for major changes.

---

## 🙌 Credits

* **Luis Gandarillas Fernández** – invaluable feedback and code review.
* **Elena García Arroyo** – sharp insights and moral support.

---

## 📜 License (TBD)

A license has **not yet been chosen** for this repository. Until then, the code is provided **for academic review only**; please request permission before reusing it in other projects.

---

## Versión en Español

> **«Leer *El Quijote* recordando solo cinco palabras cada vez.»**
> Así se siente procesar un archivo línea a línea con un búfer diminuto.
> Este repositorio contiene una implementación **robusta** y minimalista de `get_next_line`, el reto clásico de 42 School que enseña I/O a bajo nivel, gestión de memoria dinámica y control de errores en C.

### ✨ Características

| Funcionalidad                     | Detalles                                                                         |
| --------------------------------- | -------------------------------------------------------------------------------- |
| **Lectura línea a línea**         | Devuelve **exactamente una línea completa** por llamada, incluido el `\n` final. |
| **Buffers diminutos**             | Funciona con cualquier `BUFFER_SIZE` ≥ 1 sin cargar todo el archivo en RAM.      |
| **Sin fugas de memoria**          | Cada `malloc` se libera, incluso en rutas de error.                              |
| **`calloc` a prueba de overflow** | Verifica la multiplicación contra `SIZE_MAX` antes de reservar memoria.          |
| **Almacenamiento estático**       | Estado persistente en un puntero `static`, sin globales.                         |
| **Utilidades modulares**          | Funciones auxiliares en `get_next_line_utils.c` listas para tests unitarios.     |

### 🛠️ Compilación

```bash
gcc -Wall -Wextra -Werror -I include -D BUFFER_SIZE=42 src/*.c -o gnl_demo
```

### ⚡ Ejemplo Rápido

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("gran_novela.txt", O_RDONLY);
    if (fd == -1) return 1;

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

Comprueba fugas con Valgrind:

```bash
valgrind --leak-check=full ./gnl_demo
```

---

¡Clona, compila y experimenta!
Si te resulta útil, deja una ⭐️ o envía un *pull request*. 😊
