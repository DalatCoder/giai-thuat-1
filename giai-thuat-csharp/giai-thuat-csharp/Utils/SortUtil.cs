using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public class SortUtil
    {
        public static void NoiBot(List<int> list)
        {
            for (var i = 0; i < list.Count - 1; i++)
            for (var j = list.Count - 1; j > i; j--)
                if (list[j] < list[j - 1])
                {
                    var c = list[j];
                    list[j] = list[j - 1];
                    list[j - 1] = c;
                }
        }

        public static int TimMin(List<int> list, int begin, int end)
        {
            var min = list[begin];
            var index = begin;

            for (var i = begin + 1; i < end; i++)
                if (min > list[i])
                {
                    min = list[i];
                    index = i;
                }
            return index;
        }

        public static void ChonTrucTiep(List<int> list)
        {
            for (var i = 0; i < list.Count - 1; i++)
            {
                var minIndex = TimMin(list, i, list.Count - 1);
                {
                    var t = list[i];
                    list[i] = list[minIndex];
                    list[minIndex] = t;
                }
            }
        }

        public static void ChenTrucTiep(List<int> list)
        {
            for (var i = 1; i < list.Count; i++)
            {
                var key = list[i];
                var j = i-1;

                while (j >= 0 && key < list[j])
                {
                    list[j+1] = list[j];
                    j--;
                }

                list[j + 1] = key;
            }
        }

        public static void DoiChoTrucTiep(List<int> list)
        {
            for (var i = 0; i < list.Count - 1; i++)
            for (var j = i + 1; j < list.Count; j++)
                if (list[j] < list[i])
                {
                    var t = list[j];
                    list[j] = list[i];
                    list[i] = t;
                }
        }
    }
}