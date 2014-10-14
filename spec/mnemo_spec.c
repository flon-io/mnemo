
//
// specifying mnemo
//
// Mon Oct 13 16:42:13 JST 2014
//

#include "mnemo.h"


context "mnemo"
{
  describe "fmne_to_s()"
  {
    it "turns positive integers to mnemo strings"
    {
      expect(fmne_to_s(0) ===f "a");
      expect(fmne_to_s(1) ===f "i");
      expect(fmne_to_s(99) ===f "n");
      expect(fmne_to_s(100) ===f "ia");
      expect(fmne_to_s(101) ===f "ii");
      expect(fmne_to_s(392406) ===f "futeki");
      expect(fmne_to_s(25437225) ===f "tomijito");
    }

    it "turns negative integers to mnemo strings"
    {
      expect(fmne_to_s(-1) ===f "wii");
      expect(fmne_to_s(-99) ===f "win");
      expect(fmne_to_s(-100) ===f "wiia");
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
      expect(fmne_to_i("yoshida").err == 0);
      expect(fmne_to_i("yoshida").result == 531476);

      expect(fmne_to_i("bajo").err == 0);
      expect(fmne_to_i("bajo").result == 8382);
      expect(fmne_to_i("wibaji").err == 0);
      expect(fmne_to_i("wibaji").result == -8372);

      expect(fmne_to_i("tonkatsu").err == 0);
      expect(fmne_to_i("tonkatsu").result == 25990523);
    }
  }

  describe "mnemo"
  {
    //it "goes its way"
    //{
    //  for (long i = -2; i < 280; ++i)
    //  {
    //    printf("%5li: %7s\n", i, fmne_to_s(i));
    //  }
    //}

    it "goes from string to long and back"
    {
      char *s = NULL;
      long long l = 0;

      s = "tsunami";
      l = fmne_to_i(s).result;
      expect(fmne_to_s(l) ===f s);

      s = "katsudon";
      l = fmne_to_i(s).result;
      expect(fmne_to_s(l) ===f s);

      s = "win";
      l = fmne_to_i(s).result;
      expect(fmne_to_s(l) ===f s);
    }

    it "goes from long to string and back"
    {
      char *s = NULL;
      int err = 0;

      for (long l = -1001; l < 1001; ++l)
      {
        s = fmne_to_s(l);
        if (fmne_to_i(s).result != l) err = 1;
        free(s);
      }

      expect(err == 0);
    }
  }

  describe "fmne_is_mnemo()"
  {
    it "returns 1 if the string is a mnemo string"
    {
      expect(fmne_is_mnemo("tonkatsu") == 1);
    }

    it "returns 0 else"
    {
      expect(fmne_is_mnemo("blah blah blah") == 0);
    }
  }
}

