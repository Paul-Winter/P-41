using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text; 

namespace DictionaryApplication
{
    public static class StorageManager
    {
        private static readonly string FolderPath = "Dictionaries";
        private static readonly string FilePath = Path.Combine(FolderPath, "data.json");

        public static void SaveDictionaries(List<TranslationDictionary> dictionaries)
        {
            if (!Directory.Exists(FolderPath))
            {
                Directory.CreateDirectory(FolderPath);
            }

            string json = JsonSerializer.Serialize(dictionaries, new JsonSerializerOptions { WriteIndented = true });
            File.WriteAllText(FilePath, json, Encoding.UTF8); 
        }

        public static List<TranslationDictionary> LoadDictionaries()
        {
            if (!Directory.Exists(FolderPath) || !File.Exists(FilePath))
            {
                return new List<TranslationDictionary>();
            }

            try
            {
                string json = File.ReadAllText(FilePath, Encoding.UTF8); 
                return JsonSerializer.Deserialize<List<TranslationDictionary>>(json) ?? new List<TranslationDictionary>();
            }
            catch
            {
                return new List<TranslationDictionary>();
            }
        }
    }
}