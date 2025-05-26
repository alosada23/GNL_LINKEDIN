# get_next_line

<div align="center">
  <img src="https://img.shields.io/badge/C-99%20%7C%2042-blue?style=flat-square" alt="C Badge" />
  <img src="https://img.shields.io/badge/Memory‑Safe-✔️-brightgreen?style=flat-square" alt="Memory Safe" />
  <img src="https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square" alt="MIT" />
</div>

> **“Reading *Don Quixote* while remembering only five words at a time.”**  
> That’s what it feels like to stream a file line‑by‑line under tight buffer constraints.  
> This repo contains a minimal, **robust** implementation of `get_next_line` — the classic 42 School challenge that teaches low‑level I/O, dynamic memory management and error handling in C.

---

## 📑 Table of Contents
- [Features](#-features)
- [Build](#-build)
- [Quick Start](#-quick-start)
- [Design Highlights](#-design-highlights)
- [Testing](#-testing)
- [Credits](#-credits)
- [License](#-license)
- [Versión en Español](#versión-en-español)

---

## ✨ Features

| Capability | Details |
| ---------- | ------- |
| **Line‑by‑line reading** | Returns exactly **one full line** per call, including the trailing `\n` if present. |
| **Tiny buffers welcome** | Works with any `BUFFER_SIZE` ≥ 1 without loading the entire file into memory. |
| **No memory leaks** | Every allocation is safely freed, even on error paths. |
| **Overflow‑safe `calloc`** | Guards against `SIZE_MAX` multiplication overflow before allocating. |
| **Static storage, no globals** | Persistent state is kept in a `static` pointer local to the function. |
| **Modular utils** | Helper functions live in `get_next_line_utils.c` for easy unit testing. |

---

## 🛠️ Build

```bash
# Clone
git clone https://github.com/your‑user/get_next_line.git
cd get_next_line

# Compile (replace BUFFER_SIZE as desired)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o gnl_demo
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

Compile, run, and watch the lines stream without leaks:

```bash
valgrind --leak-check=full ./gnl_demo
```

---

## 🧩 Design Highlights

1. **Overflow Protection** – `ft_calloc` verifies `count > SIZE_MAX / size` before multiplication.  
2. **Fail‑safe Cleanup** – If `read` or `malloc` fails, all intermediate buffers are freed.  
3. **Precise Allocation** – Each line is allocated with space for the trailing `\n` and `\0`.  
4. **Static Storage** – Keeps leftover bytes between calls without polluting global namespace.  
5. **Unit‑test Friendly** – Utilities are detached for independent testing.

---

## 🧪 Testing

```bash
# run the included basic test
make test
# or use your own file
./test_gnl path/to/file
```

---

## 🙌 Credits

- **Luis Gandarillas Fernández** – invaluable feedback and code review.  
- **Elena García Arroyo** – sharp insights and moral support.  

---

## 📜 License

This project is licensed under the MIT License – see [`LICENSE`](LICENSE) for details.

---

## Versión en Español

> **«Leer *El Quijote* recordando solo cinco palabras cada vez.»**  
> Así se siente procesar un archivo línea a línea con un búfer diminuto.  
> Este repositorio contiene una implementación **robusta** y minimalista de `get_next_line`, el reto clásico de 42 School que enseña I/O a bajo nivel, gestión de memoria dinámica y control de errores en C.

### ✨ Características

| Funcionalidad | Detalles |
| ------------- | -------- |
| **Lectura línea a línea** | Devuelve **exactamente una línea completa** por llamada, incluido el `\n` final. |
| **Buffers diminutos** | Funciona con cualquier `BUFFER_SIZE` ≥ 1 sin cargar todo el archivo en RAM. |
| **Sin fugas de memoria** | Cada `malloc` se libera, incluso en rutas de error. |
| **`calloc` a prueba de overflow** | Verifica `SIZE_MAX` antes de multiplicar. |
| **Almacenamiento estático** | Estado persistente en un puntero `static`, sin globales. |
| **Utilidades modulares** | Helpers en `get_next_line_utils.c` listos para tests unitarios. |

### 🛠️ Compilación

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o gnl_demo
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

Ejecuta con Valgrind para comprobar que no haya fugas.

---

¡Clona, compila y experimenta!  
Si te resulta útil, deja una ⭐️ o envía un *pull request*.
