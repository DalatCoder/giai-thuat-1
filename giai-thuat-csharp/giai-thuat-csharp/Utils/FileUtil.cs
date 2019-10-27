using System;
using System.Collections.Generic;
using System.IO;

namespace giai_thuat_csharp
{
    public class FileUtil
    {
        public static List<int> GetDataFromFile(string filename)
        {
            string workingDirectory = Environment.CurrentDirectory;
            string projectDirectory = Directory.GetParent(workingDirectory).Parent.Parent.FullName;
            var filePath = Path.Combine(projectDirectory, "data", filename);

            if (!File.Exists(filePath))
                throw new ArgumentException($"Tap tin '{filename}' khong ton tai.");

            var buffer = File.ReadAllLines(filePath);
            buffer = buffer[0].Split(' ');

            var numbers = new List<int>();
            for (int i = 0; i < buffer.Length; i++)
                numbers.Add(Convert.ToInt32(buffer[i]));

            return numbers;
        }
    }
}