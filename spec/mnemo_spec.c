
//
// specifying mnemo
//
// Mon Oct 13 16:42:13 JST 2014
//

#include "mnemo.h"


context "mnemo"
{
  describe "mnemo"
  {
    it "goes in alphabetical order"
    {
      for (long i = -2; i < 280; ++i)
      {
        printf("%5li: %7s\n", i, fmne_to_s(i));
      }
    }

    it "goes in alphabetical order"
    {
      size_t i;
      size_t n = 100000;

      char *s0 = fmne_to_s(0);
      char *s1 = NULL;

      for (i = 1; i < n; ++i)
      {
        s1 = fmne_to_s(i);
        //printf("i: %zu, s0: '%s', s1: '%s' (%i)\n", i, s0, s1, strcmp(s0, s1));
        if (strcmp(s0, s1) >= 0) break;
        free(s0);
        s0 = s1;
        s1 = NULL;
      }
      free(s0);
      free(s1);

      expect(i == n);
    }
  }

  describe "fmne_to_s()"
  {
    it "turns positive integers to mnemo strings"
    {
      expect(fmne_to_s(0) ===f "a");
      expect(fmne_to_s(1) ===f "ba");
      expect(fmne_to_s(101) ===f "bajo");
      expect(fmne_to_s(392406) ===f "yosida");
      expect(fmne_to_s(25437225) ===f "tonkatsu");
    }

    it "turns negative integers to mnemo strings"
    {
      expect(fmne_to_s(-1) ===f "wiba");
      expect(fmne_to_s(-100) ===f "wibaji");
    }
  }

  describe "fmne_to_i()"
  {
    it "rejects strings that are not mnemo strings"
    {
      expect(fmne_to_i("blah blah blah").err == 1);
      expect(fmne_to_i("blah blah blah").result == 0);

      expect(fmne_to_i("wibawiba").err == 1);
      expect(fmne_to_i("wibawiba").result == 0);
    }

    it "turns mnemo strings to integers"
    {
      expect(fmne_to_i("yosida").err == 0);
      expect(fmne_to_i("yosida").result == 392406);

      expect(fmne_to_i("bajo").err == 0);
      expect(fmne_to_i("bajo").result == 101);
      expect(fmne_to_i("wibaji").err == 0);
      expect(fmne_to_i("wibaji").result == -100);

      expect(fmne_to_i("tonkatsu").err == 0);
      expect(fmne_to_i("tonkatsu").result == 25437225);
    }
  }

  describe "fmne_is_mnemo()"
  {
    it "returns 1 if the string is a mnemo string"
    it "returns 0 else"
  }

  describe "fmne_extract_i()"
  {
    it "returns a result, given a starting point"
    it "returns a result with .err == 1 else"
  }
}

