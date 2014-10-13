
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
    it "orders the syllables"
    {
      char *s = calloc(512, sizeof(char));
      char *ss = s;
      for (size_t i = 0; i < 75; ++i)
      {
        char *m = fmne_to_s(i);
        strcpy(ss, m);
        ss = ss + strlen(m);
        strcpy(ss++, " ");
      }

      expect(s ===f ""
        "a ba be bi bo bu da de di do du e fu ga ge gi go gu ha he hi ho "
        "i ja je ji jo ju ka ke ki ko ku ma me mi mo mu n na ne ni no nu "
        "o pa pe pi po pu ra re ri ro ru sa se si so su ta te ti to tu "
        "u wa we ya yo yu za ze zo zu ");
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
      expect(fmne_to_s(25437225) ===f "taifun");
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

      expect(fmne_to_i("taifun").err == 0);
      expect(fmne_to_i("taifun").result == 25437225);
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

