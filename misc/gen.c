
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *syls[] = {
  "a",  "i",   "u",   "e",   "o",
  "ka", "ki",  "ku",  "ke",  "ko",  "kya", "kyu", "kyo",
  "sa", "shi", "su",  "se",  "so",  "sha", "shu", "sho",
  "ta", "chi", "tsu", "te",  "to",  "cha", "chu", "cho",
  "na", "ni",  "nu",  "ne",  "no",  "nya", "nyu", "nyo",
  "ha", "hi",  "fu",  "he",  "ho",  "hya", "hyu", "hyo",
  "ma", "mi",  "mu",  "me",  "mo",  "mya", "myu", "myo",
  "ya",        "yu",         "yo",
  "ra", "ri",  "ru",  "re",  "ro",  "rya", "ryu", "ryo",
  "wa",
  "ga", "gi",  "gu",  "ge",  "go",  "gya", "gyu", "gyo",
  "za", "ji",  "zu",  "ze",  "zo",
  "da",               "de",  "do",  "ja",  "ju",  "jo",
  "ba", "bi",  "bu",  "be",  "bo",  "bya", "byu", "byo",
  "pa", "pi",  "pu",  "pe",  "po",  "pya", "pyu", "pyo",
  "n",
};
//static char *fmne_neg = "wi";

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
  size_t n = 0;
  for (size_t i = 0; i < count; ++i)
  {
    if (i % 12 == 0) printf("\n  ");
    printf("\"%s\"", syls[i]);
    if (i < count - 1) printf(", ");

    if (strcmp(syls[i], "n") == 0) n = i;
  }
  printf("\n};\n");
  printf("static char *fmne_syls_n[] = {");
  for (size_t i = 0; i < count; ++i)
  {
    if (i % 12 == 0) printf("\n  ");
    if (strcmp(syls[i], "n") == 0) printf("\"*\", ");
    else printf("\"%s\", ", syls[i]);
  }
  printf("\"n\"\n};\n");

  printf("static size_t fmne_syl_count = %zu;\n", count);
  printf("static size_t fmne_n = %zu;\n", n);
  printf("\n");
}

