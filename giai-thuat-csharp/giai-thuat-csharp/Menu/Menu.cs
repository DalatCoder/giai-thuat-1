using System;
using System.Collections.Generic;

namespace giai_thuat_csharp
{
    public class Menu
    {
        private static readonly string[] features = new string[]
        {
            "Thoat chuong trinh",
            "Doc mang tu tap tin",
            "Xuat mang hien tai",
            "Tim kiem tuyen tinh tra ve chi so",
            "Tim kiem tuyen tinh linh canh",
            "Tim kiem nhi phan tra ve chi so",
            "Sap xep chon truc tiep",
            "Sap xep chen truc tiep",
            "Sap xep doi cho truc tiep",
            "Sap xep noi bot"
        };

        public static void XuatMenu()
        {
            var duongKe = new string('=', 10);
            Console.WriteLine(duongKe + " HE THONG CHUC NANG " + duongKe);

            for (int i = 0; i < features.Length; i++)
                Console.WriteLine("{0}: {1}", i, features[i]);
        }

        public static int ChonMenu(int soMenu)
        {
            int chon;

            while (true)
            {
                Console.Clear();
                XuatMenu();
                Console.Write("Chon 1 chuc nang trong khoang {0} toi {1} >> ", 0, soMenu);
                chon = Convert.ToInt32(Console.ReadLine());

                if (0 <= chon && chon <= soMenu)
                    break;
            }

            return chon;
        }

        public static void XuLyMenu(int menu, List<int> numbers)
        {
            int x, kq;
            var buffer = new List<int>(numbers);
            
            Console.Clear();
            Console.WriteLine("Chuc nang da chon: {0}: {1}.", menu, features[menu]);

            switch (menu)
            {
                case 0:
                    Console.WriteLine("Thoat chuong trinh ...");
                    break;
                case 1:
                    Console.Write("Nhap ten tap tin de mo: ");
                    var filename = Console.ReadLine();

                    FileUtil.GetDataFromFile(filename, numbers);
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);
                    break;
                case 2:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);
                    break;
                case 3:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.Write("Nhap vao 1 phan tu de tim kiem: ");
                    x = Convert.ToInt32(Console.ReadLine());

                    kq = SearchUtil.LinearSearch(numbers, x);
                    if (kq == -1)
                        Console.WriteLine("Khong tim thay phan tu {0} trong danh sach hien tai.", x);
                    else
                        Console.WriteLine("Tim thay phan tu {0} trong danh sach tai vi tri {1}.", x, kq+1);

                    break;
                case 4:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.Write("Nhap vao 1 phan tu de tim kiem: ");
                    x = Convert.ToInt32(Console.ReadLine());

                    kq = SearchUtil.TK_LinhCanh(numbers, x);
                    if (kq == -1)
                        Console.WriteLine("Khong tim thay phan tu {0} trong danh sach hien tai.", x);
                    else
                        Console.WriteLine("Tim thay phan tu {0} trong danh sach tai vi tri {1}.", x, kq+1);

                    break;
                case 5: 
                    SortUtil.NoiBot(buffer);
                    Console.WriteLine("Danh sach sau khi sap xep tang dan: ");
                    Utils.DisplayList(buffer);

                    Console.Write("Nhap vao 1 phan tu de tim kiem: ");
                    x = Convert.ToInt32(Console.ReadLine());

                    kq = SearchUtil.BinarySearch(buffer, x);
                    if (kq == -1)
                        Console.WriteLine("Khong tim thay phan tu {0} trong danh sach hien tai.", x);
                    else
                        Console.WriteLine("Tim thay phan tu {0} trong danh sach tai vi tri {1}.", x, kq+1);

                    break;
                case 6:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.WriteLine("Danh sach sau khi sap xep tang dan bang phuong phap chon truc tiep");
                    SortUtil.ChonTrucTiep(buffer);
                    Utils.DisplayList(buffer);

                    break;
                case 7:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.WriteLine("Danh sach sau khi sap xep tang dan bang phuong phap chen truc tiep");
                    SortUtil.ChenTrucTiep(buffer);
                    Utils.DisplayList(buffer);

                    break;
                case 8:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.WriteLine("Danh sach sau khi sap xep tang dan bang phuong phap doi cho truc tiep");
                    SortUtil.DoiChoTrucTiep(buffer);
                    Utils.DisplayList(buffer);

                    break;
                case 9:
                    Console.WriteLine("Danh sach hien tai: ");
                    Utils.DisplayList(numbers);

                    Console.WriteLine("Danh sach sau khi sap xep tang dan bang phuong phap noi bot");
                    SortUtil.NoiBot(buffer);
                    Utils.DisplayList(buffer);

                    break;

            }

            Console.ReadLine();
        }
    }
}