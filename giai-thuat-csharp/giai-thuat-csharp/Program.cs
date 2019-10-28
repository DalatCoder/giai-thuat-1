﻿using System;
using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public class Program
    {
        static void Main(string[] args)
        {
            try
            {
                ChayChuongTrinh();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static void ChayChuongTrinh()
        {
            const int soMenu = 9;
            int menu;
            var numbers = new List<int>();

            do
            {
                menu = Menu.ChonMenu(soMenu);
                Menu.XuLyMenu(menu, numbers);
            } while (menu > 0);
        }
    }

}
