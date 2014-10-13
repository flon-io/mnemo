
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *syls[] = {
  "a",  "e",  "i",  "o",  "u",
  "ka", "ke", "ki", "ko", "ku",
  "sa", "se", "si", "so", "su",
  "ta", "te", "ti", "to", "tu",
  "na", "ne", "ni", "no", "nu",
  "ha", "he", "hi", "ho", "fu",
  "ma", "me", "mi", "mo", "mu",
  "ya",             "yo", "yu",
  "ra", "re", "ri", "ro", "ru",
  "wa", "we",
  "ga", "ge", "gi", "go", "gu",
  "za", "ze",       "zo", "zu",
  "da", "de", "di", "do", "du",
  "ba", "be", "bi", "bo", "bu",
  "pa", "pe", "pi", "po", "pu",
  "ja", "je", "ji", "jo", "ju",
  "n"
};
//static char *fmne_neg = "wi";
//static size_t fmne_syl_count = 75;

static int _strcmp(const void *a, const void *b)
{
  return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
  size_t count = 0;
  while (1) { if (strcmp(syls[count++], "n") == 0) break; };

  qsort(syls, count, sizeof(char *), _strcmp);

  printf("\n");
  printf("static char *fmne_syls[] = {");
  for (size_t i = 0; i < count; ++i)
  {
    if (i % 13 == 0) printf("\n  ");
    printf("\"%s\"", syls[i]);
    if (i < count - 1) printf(", ");
  }
  printf("\n};\n");
  printf("static size_t fmne_syl_count = %zu;\n", count);
  printf("\n");
}

