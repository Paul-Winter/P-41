using System;
using System.Collections.Generic;
using System.IO;

namespace DictionaryApplication
{
    public static class ExportManager
    {
        public static void ExportWord(string word, List<string> translations, string dictionaryType)
        {
            string fileName = $"Экспорт_{word}.txt";
            List<string> lines = new List<string>
            {
                $"Тип словаря: {dictionaryType}",
                $"Исходное слово: {word}",
                "Варианты перевода:"
            };

            foreach (var translation in translations)
            {
                lines.Add($"- {translation}");
            }

            File.WriteAllLines(fileName, lines);
        }
    }
}