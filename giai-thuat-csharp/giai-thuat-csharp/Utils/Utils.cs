using System;
using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public static class Utils
    {
        public static void DisplayList(List<int> list)
        {
            if (list.Count == 0)
                Console.WriteLine("Danh sach rong.");
            else
            {
                foreach (var element in list)
                    Console.Write(element + " ");
                Console.WriteLine();
            }
        }
    }
}