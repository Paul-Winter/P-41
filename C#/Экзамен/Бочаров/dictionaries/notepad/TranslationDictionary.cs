using System;
using System.Collections.Generic;

namespace DictionaryApplication
{
    public class TranslationDictionary
    {
        public string Type { get; set; }
        public Dictionary<string, List<string>> Words { get; set; } = new Dictionary<string, List<string>>();

        public TranslationDictionary(string type)
        {
            Type = type;
        }
    }
}