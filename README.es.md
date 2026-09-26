# libft - Proyecto de 42 School

Una biblioteca en C que implementa funciones comunes de la biblioteca estándar y utilidades adicionales.

## Descripción General

Este proyecto recrea varias funciones de la biblioteca estándar de C, proporcionando una comprensión más profunda de su implementación. La biblioteca incluye funciones para manipulación de cadenas, operaciones de memoria, clasificación de caracteres y una implementación de lista enlazada.

## Estructura del Proyecto

```
libft/
├── src/           # Archivos fuente (.c)
├── inc/           # Archivos de cabecera (libft.h)
├── test/          # Suite de pruebas
├── .obj/          # Archivos objeto compilados (generados)
├── Makefile       # Configuración de compilación
└── libft.a        # Biblioteca compilada (generada)
```

## Compilación

### Compilación básica
```bash
make
```
Compila todas las funciones en `libft.a`.

### Compilación limpia
```bash
make re
```
Elimina todos los archivos compilados y recompila todo.

### Limpieza
```bash
make clean    # Elimina el directorio .obj/
make fclean   # Elimina .obj/ y libft.a
```

## Pruebas

Ejecuta la suite de pruebas completa:
```bash
make test
```

Esto compila y ejecuta pruebas para todas las funciones, comparando resultados con el comportamiento de la biblioteca estándar cuando aplica.

### Estructura de Pruebas
Las pruebas están organizadas en archivos separados por categoría:
- `test_is.c` - Funciones de clasificación de caracteres
- `test_mem.c` - Operaciones de memoria
- `test_str.c` - Operaciones de cadenas
- `test_conv.c` - Funciones de conversión
- `test_put.c` - Funciones de salida
- `test_lst*.c` - Funciones de lista enlazada

## Funciones

### Funciones Estándar (Obligatorias)

#### Verificación de Caracteres
- `ft_isalpha` - Verifica si el carácter es alfabético
- `ft_isdigit` - Verifica si el carácter es un dígito
- `ft_isalnum` - Verifica si el carácter es alfanumérico
- `ft_isascii` - Verifica si el carácter es ASCII
- `ft_isprint` - Verifica si el carácter es imprimible
- `ft_toupper` - Convierte a mayúsculas
- `ft_tolower` - Convierte a minúsculas

#### Operaciones con Cadenas
- `ft_strlen` - Calcula la longitud de una cadena
- `ft_strchr` - Localiza la primera ocurrencia de un carácter
- `ft_strrchr` - Localiza la última ocurrencia de un carácter
- `ft_strncmp` - Compara cadenas hasta n caracteres
- `ft_strnstr` - Localiza subcadena en una cadena
- `ft_strlcpy` - Copia cadena con límite de tamaño
- `ft_strlcat` - Concatena cadenas con límite de tamaño
- `ft_strdup` - Duplica una cadena
- `ft_substr` - Extrae subcadena
- `ft_strjoin` - Concatena dos cadenas
- `ft_strtrim` - Recorta caracteres de una cadena
- `ft_split` - Divide cadena por delimitador
- `ft_strmapi` - Aplica función a cada carácter
- `ft_striteri` - Aplica función a cada carácter (en su lugar)

#### Operaciones de Memoria
- `ft_memset` - Rellena memoria con valor de byte
- `ft_bzero` - Pone a cero un área de memoria
- `ft_memcpy` - Copia área de memoria
- `ft_memmove` - Copia área de memoria (maneja superposición)
- `ft_memchr` - Localiza byte en memoria
- `ft_memcmp` - Compara áreas de memoria

#### Conversión
- `ft_atoi` - Convierte cadena a entero
- `ft_itoa` - Convierte entero a cadena

#### Salida
- `ft_putchar_fd` - Envía carácter a descriptor de archivo
- `ft_putstr_fd` - Envía cadena a descriptor de archivo
- `ft_putendl_fd` - Envía cadena con salto de línea a descriptor de archivo
- `ft_putnbr_fd` - Envía entero a descriptor de archivo

#### Asignación de Memoria
- `ft_calloc` - Asigna e inicializa a cero memoria

### Funciones Bonus (Lista Enlazada)

- `ft_lstnew` - Crea nuevo nodo de lista
- `ft_lstadd_front` - Añade nodo al principio
- `ft_lstadd_back` - Añade nodo al final
- `ft_lstsize` - Cuenta nodos en la lista
- `ft_lstlast` - Obtiene el último nodo
- `ft_lstdelone` - Elimina y libera un nodo
- `ft_lstclear` - Elimina y libera todos los nodos
- `ft_lstiter` - Aplica función a cada nodo
- `ft_lstmap` - Aplica función y crea nueva lista

## Ejemplo de Uso

```c
#include "libft.h"

int main(void)
{
    // Operaciones con cadenas
    char *str = ft_strdup("Hola, Mundo!");
    int len = ft_strlen(str);
    
    // Operaciones de memoria
    char *buf = ft_calloc(100, sizeof(char));
    ft_memset(buf, 'A', 50);
    
    // Operaciones con listas
    t_list *lista = ft_lstnew(ft_strdup("primero"));
    ft_lstadd_back(&lista, ft_lstnew(ft_strdup("segundo")));
    
    // Limpieza
    ft_lstclear(&lista, free);
    free(str);
    free(buf);
    
    return 0;
}
```

## Compilación con Tu Proyecto

```bash
# Compilar libft
make

# Compilar tu proyecto con libft
gcc -I./inc tu_programa.c -L. -lft -o tu_programa
```

## Calidad del Código

- Cumple con los estándares de norminette de la escuela 42
- Sin fugas de memoria (verificado con valgrind)
- Maneja casos extremos y condiciones de error
- Cobertura de pruebas exhaustiva

## Mejoras Realizadas

- Reestructuración del proyecto con organización de directorios adecuada
- Todas las funciones usan la cabecera `libft.h` consistentemente
- Eliminación de includes no autorizados
- Implementaciones optimizadas usando funciones existentes
- Suite de pruebas exhaustiva añadida
- Código limpio y mantenible siguiendo los estándares de 42

## Requisitos

- Compilador GCC
- Make
- Entorno tipo Unix (Linux, macOS o WSL)

## Licencia

Este proyecto forma parte del plan de estudios de la escuela 42 y sigue sus directrices académicas.
