using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public class SortUtil
    {
        public static List<int> SortInc(List<int> list)
        {
            var sorted = new List<int>(list);

            for (int i = 0; i < sorted.Count - 1; i++)
            for (int j = sorted.Count - 1; j > i; j--)
                if (sorted[j] < sorted[j - 1])
                {
                    var c = sorted[j];
                    sorted[j] = sorted[j-1];
                    sorted[j - 1] = c;
                }

            return sorted;
        }
    }
}