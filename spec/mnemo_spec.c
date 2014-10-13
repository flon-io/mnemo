
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
    it "turns mnemo strings to integers"
  }
}

