# Mini-projekt: Testowanie kodu w C (GCC/Linux)

Struktura katalogów:

```
.
├── include/          # Nagłówki biblioteki
│   ├── math_utils.h
│   ├── str_utils.h
│   └── test_framework.h
├── src/              # Implementacje biblioteki
│   ├── math_utils.c
│   └── str_utils.c
├── test/             # Testy jednostkowe (osobny program)
│   ├── test_main.c
│   ├── test_math_utils.c
│   └── test_str_utils.c
├── Makefile
└── reports/          # Raporty (coverage)
```

## Uruchomienie

1) Testy jednostkowe:
```bash
make test
```

2) Testy z AddressSanitizer:
```bash
make asan
```

3) Testy pod Valgrind:
```bash
make valgrind
```

4) Pokrycie kodu (HTML w `reports/coverage/index.html`):
```bash
make coverage
```

## Uwagi dydaktyczne

- Testy w tym projekcie korzystają z mini-frameworka w `include/test_framework.h` (PASS/FAIL + summary).
- Funkcje mają „produkcyjny” styl API (zwracanie kodów błędów zamiast `assert` w środku).
- W testach sprawdzane są przypadki brzegowe (NULL, pusty string, błędne dzielenie).
