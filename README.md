
# mnemo

A port of [rufus-mnemo](https://github.com/jmettraux/rufus-mnemo) to C.

Unlike rufus-mnemo doesn't limit itself to japanese kana and uses that array:

```c
static char *fmne_syls[] = {
   "ba",  "bi",  "bu",  "be",  "bo",
  "cha", "chi", "chu", "che", "cho",
   "da",  "di",  "du",  "de",  "do",
   "fa",  "fi",  "fu",  "fe",  "fo",
   "ga",  "gi",  "gu",  "ge",  "go",
   "ha",  "hi",  "hu",  "he",  "ho",
   "ja",  "ji",  "ju",  "je",  "jo",
   "ka",  "ki",  "ku",  "ke",  "ko",
   "la",  "li",  "lu",  "le",  "lo",
   "ma",  "mi",  "mu",  "me",  "mo",
   "na",  "ni",  "nu",  "ne",  "no",
   "pa",  "pi",  "pu",  "pe",  "po",
   "ra",  "ri",  "ru",  "re",  "ro",
   "sa",  "si",  "su",  "se",  "so",
  "sha", "shi", "shu", "she", "sho",
   "ta",  "ti",  "tu",  "te",  "to",
  "tsa", "tsi", "tsu", "tse", "tso",
   "wa",  "wi",  "wu",  "we",  "wo",
   "ya",  "yi",  "yu",  "ye",  "yo",
   "za",  "zi",  "zu",  "ze",  "zo",
};
```

## License

MIT (see [LICENSE.txt](LICENSE.txt))

