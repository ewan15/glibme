# glibme

A small project for learning how glibc works by implementing libc-style
functions from scratch.

## Building

Configure and build the project with CMake:

```sh
cmake -S . -B build
cmake --build build
```

By default this builds:

- `build/libglibme.a`
- `build/libglibme.dylib` on macOS, or `build/libglibme.so` on Linux
- `build/glibme_tests`

Run the test suite:

```sh
ctest --test-dir build --output-on-failure
```

Install the library and headers:

```sh
cmake --install build --prefix ./dist
```

Build only the static library:

```sh
cmake -S . -B build -DGLIBME_BUILD_SHARED=OFF
cmake --build build
```

## Function Implementation Roadmap

Ordered from easiest to hardest.

### Easiest

1. `srand`
2. `rand`
3. `getchar`
4. `fputc`
5. `fputs`
6. `putchar`
7. `puts`
8. `perror`
9. `strerror`
10. `memchr`

### Easy

11. `isxdigit`, `isprint`, `isspace`
12. `isalnum`, `isdigit`, `isalpha`
13. `tolower`, `toupper`
14. `lldiv`, `ldiv`, `div`
15. `llabs`, `labs`, `abs`
16. `atoll`
17. `atol`
18. `atoi`
19. `strnlen`
20. `strlen`

### Medium

21. `strncasecmp`, `strcasecmp`
22. `strncmp`, `strcmp`
23. `strncpy`, `strcpy`
24. `strncat`, `strcat`
25. `strndup`, `strdup`
26. `strcspn`, `strspn`
27. `strpbrk`
28. `strrchr`, `strchr`
29. `strcasestr`
30. `strstr`

### Medium-Hard

31. `getopt`, `getopt_long`
32. `realpath`
33. `fnmatch`
34. `glob`
35. `regcomp`, `regexec`, `regfree`
36. `strtok`, `strtok_r`
37. `memset`
38. `memcmp`
39. `memcpy`
40. `memmove`

### Hardest

41. `setjmp`, `longjmp`
42. `getline`, `getdelim`
43. `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, `ftell`
44. `bsearch`
45. `qsort`
46. `strtol`, `strtoul`, `strtoll`, `strtoull`
47. `strtod`, `strtof`, `strtold`
48. `scanf`, `sscanf`, `fscanf`
49. `printf`, `fprintf`, `snprintf`, `vprintf`
50. `malloc`, `free`, `calloc`, `realloc`
