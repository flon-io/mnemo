
//
// Copyright (c) 2013-2014, John Mettraux, jmettraux+flon@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// Made in Japan.
//

// https://github.com/flon-io/mnemo

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>

#include "mnemo.h"


static char *fmne_syls[] = {
  "a", "ba", "be", "bi", "bo", "bu", "bya", "byo", "byu", "cha", "chi", "cho",
  "chu", "da", "de", "do", "e", "fu", "ga", "ge", "gi", "go", "gu", "gya",
  "gyo", "gyu", "ha", "he", "hi", "ho", "hya", "hyo", "hyu", "i", "ja", "ji",
  "jo", "ju", "ka", "ke", "ki", "ko", "ku", "kya", "kyo", "kyu", "ma", "me",
  "mi", "mo", "mu", "mya", "myo", "myu", "n", "na", "ne", "ni", "no", "nu",
  "nya", "nyo", "nyu", "o", "pa", "pe", "pi", "po", "pu", "pya", "pyo", "pyu",
  "ra", "re", "ri", "ro", "ru", "rya", "ryo", "ryu", "sa", "se", "sha", "shi",
  "sho", "shu", "so", "su", "ta", "te", "to", "tsu", "u", "wa", "ya", "yo",
  "yu", "za", "ze", "zo", "zu"
};
static char *fmne_syls_n[] = {
  "a", "ba", "be", "bi", "bo", "bu", "bya", "byo", "byu", "cha", "chi", "cho",
  "chu", "da", "de", "do", "e", "fu", "ga", "ge", "gi", "go", "gu", "gya",
  "gyo", "gyu", "ha", "he", "hi", "ho", "hya", "hyo", "hyu", "i", "ja", "ji",
  "jo", "ju", "ka", "ke", "ki", "ko", "ku", "kya", "kyo", "kyu", "ma", "me",
  "mi", "mo", "mu", "mya", "myo", "myu", "*", "na", "ne", "ni", "no", "nu",
  "nya", "nyo", "nyu", "o", "pa", "pe", "pi", "po", "pu", "pya", "pyo", "pyu",
  "ra", "re", "ri", "ro", "ru", "rya", "ryo", "ryu", "sa", "se", "sha", "shi",
  "sho", "shu", "so", "su", "ta", "te", "to", "tsu", "u", "wa", "ya", "yo",
  "yu", "za", "ze", "zo", "zu", "n"
};
static size_t fmne_syl_count = 101;
static size_t fmne_n = 54;

static char *fmne_neg = "wi";


static void fmne_tos(long long i, FILE *f)
{
  long long mod = i % fmne_syl_count;
  long long rst = i / fmne_syl_count;
  if (rst > 0) fmne_tos(rst, f);
  fputs(fmne_syls[mod], f);
}

char *fmne_to_s(long long i)
{
  char *s = NULL;
  size_t l = 0;
  FILE *f = open_memstream(&s, &l);

  if (i < 0) { fputs(fmne_neg, f); i = i * -1; }

  fmne_tos(i, f);

  fclose(f);

  return s;
}

fmne_toi_result fmne_to_i(char *s)
{
  fmne_toi_result r = { 0, 0 };

  int sign = 1; if (strncmp(s, "wi", 2) == 0) { sign = -1; s = s + 2; }

  while (1)
  {
    if (r.err || *s == '\0') break;

    for (size_t i = 0; i < fmne_syl_count + 1; ++i)
    {
      char *syl = fmne_syls_n[i];
      size_t l = strlen(syl);

      if (strncmp(s, syl, l) == 0)
      {
        s = s + l;
        r.result =
          fmne_syl_count * r.result + (i == fmne_syl_count) ? fmne_n : i;
        break;
      }

      if (i == fmne_syl_count) { r.err = 1; r.result = 0; }
    }
  }

  r.result = sign * r.result;

  //printf("r.err: %i, r.result: %lli\n", r.err, r.result);

  return r;
}

