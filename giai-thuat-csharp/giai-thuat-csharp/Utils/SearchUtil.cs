using System;
using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public class SearchUtil
    {
        public static int LinearSearch(List<int> list, int x)
        {
            for (int i = 0; i < list.Count; i++)
                if (list[i] == x)
                    return i;
            return -1;
        }

        public static int TK_LinhCanh(List<int> list, int x)
        {
            var buffer = new List<int>(list);
            buffer.Add(x);

            var index = 0;
            while (buffer[index] != x)
                index++;

            if (index == buffer.Count - 1)
                return -1;
            return index;
        }

        public static int BinarySearch(List<int> list, int x)
        {
            int l = 0;
            int r = list.Count - 1;
            int mid;

            while (l <= r)
            {
                mid = (l + r) / 2;
                if (list[mid] == x)
                    return mid;
                if (x < list[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            return -1;
        }
    }
}