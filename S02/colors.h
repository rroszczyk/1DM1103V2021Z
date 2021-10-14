//
// Created by roszczyr on 13.10.2021.
//

#ifndef S_COLORS_H
#define S_COLORS_H

// za kolory odpowiadają ANSI escape code https://en.wikipedia.org/wiki/ANSI_escape_code
// liczby z zakresu 31 - 37 (dla ciemnych kolorów) lub 91 - 97 (dla kolorów jasnych)
// kolor tła zapewnią kody od 40 - 47

/* NAPISY */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif //S_COLORS_H
