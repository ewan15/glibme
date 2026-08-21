# glibme

A small project for learning how glibc works by implementing libc-style
functions from scratch.

## Function Implementation Roadmap

Ordered from hardest to easiest.

### Hardest

1. `malloc`, `free`, `calloc`, `realloc`
2. `printf`, `fprintf`, `snprintf`, `vprintf`
3. `scanf`, `sscanf`, `fscanf`
4. `strtod`, `strtof`, `strtold`
5. `strtol`, `strtoul`, `strtoll`, `strtoull`
6. `qsort`
7. `bsearch`
8. `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, `ftell`
9. `getline`, `getdelim`
10. `setjmp`, `longjmp`

### Very Hard

11. `memmove`
12. `memcpy`
13. `memcmp`
14. `memset`
15. `strtok`, `strtok_r`
16. `regcomp`, `regexec`, `regfree`
17. `glob`
18. `fnmatch`
19. `realpath`
20. `getopt`, `getopt_long`

### Medium-Hard

21. `strstr`
22. `strcasestr`
23. `strchr`, `strrchr`
24. `strpbrk`
25. `strspn`, `strcspn`
26. `strdup`, `strndup`
27. `strcat`, `strncat`
28. `strcpy`, `strncpy`
29. `strcmp`, `strncmp`
30. `strcasecmp`, `strncasecmp`

### Medium

31. `strlen`
32. `strnlen`
33. `atoi`
34. `atol`
35. `atoll`
36. `abs`, `labs`, `llabs`
37. `div`, `ldiv`, `lldiv`
38. `toupper`, `tolower`
39. `isalpha`, `isdigit`, `isalnum`
40. `isspace`, `isprint`, `isxdigit`

### Easier

41. `memchr`
42. `strerror`
43. `perror`
44. `puts`
45. `putchar`
46. `fputs`
47. `fputc`
48. `getchar`
49. `rand`
50. `srand`
