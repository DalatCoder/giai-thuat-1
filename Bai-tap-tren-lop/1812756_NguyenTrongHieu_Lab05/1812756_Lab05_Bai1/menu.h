void XuatMenu()
{
  cout << "\n0. Thoat chuong trinh";
  cout << "\n1. Tao cay nhi phan tim kiem";
  cout << "\n2. Xem cay nhi phan theo thu tu L - N - R";
  cout << "\n3. Tinh so nut cua cay";
  cout << "\n4. Dem so nut co gia tri < x va xuat ra man hinh";
  cout << "\n5. Tim nut co khoa x cho truoc";
  cout << "\n6. Kiem tra x co phai la nut la";
  cout << "\n7. Dem so nut la cua cay";
  cout << "\n8. Xac dinh chieu cao cua cay";
  cout << "\n9. Xac dinh muc cua nut co khoa x";
  cout << "\n10. So sanh muc cua 2 nut";
  cout << "\n11. Them mot khoa x vao cay nhi phan tim kiem";
  cout << "\n12. Huy nut co khoa x cho truoc";
}

int ChonMenu(int somenu)
{
  int chon;

  while (true)
  {
    XuatMenu();
    cout << "\nChon chuc nang trong khoang [1.." << somenu << "] >> ";
    cin >> chon;

    if (0 <= chon && chon <= somenu)
      break;
  }

  return chon;
}

void XuLyMenu(int menu, BSTree &root)
{
  char filename[50];
  int kq;

  cout << "\n";
  switch (menu)
  {
  case 0:
    cout << "\n0. Thoat chuong trinh";
    break;
  case 1:
    cout << "\n1. Tao cay nhi phan tim kiem";
    cout << "\nNhap ten file de mo: ";
    cin >> filename;

    kq = GetDataFromFile(filename, root);

    if (kq)
      cout << "\nDa chuyen du lieu tu file " << filename << " vao cay BNS Tree.\n";
    else
      cout << "\nMo file " << filename << " khong thanh cong.\n";
    break;
  case 2:
    cout << "\n2. Xem cay nhi phan theo thu tu L - N - R";
    cout << "\nXuat cay theo thu tu giua:\n";
    InOrder(root);
    break;
  case 3:
    cout << "\n3. Tinh so nut cua cay";
    break;
  case 4:
    cout << "\n4. Dem so nut co gia tri < x va xuat ra man hinh";
    break;
  case 5:
    cout << "\n5. Tim nut co khoa x cho truoc";
    break;
  case 6:
    cout << "\n6. Kiem tra x co phai la nut la";
    break;
  case 7:
    cout << "\n7. Dem so nut la cua cay";
    break;
  case 8:
    cout << "\n8. Xac dinh chieu cao cua cay";
    break;
  case 9:
    cout << "\n9. Xac dinh muc cua nut co khoa x";
    break;
  case 10:
    cout << "\n10. So sanh muc cua 2 nut";
    break;
  case 11:
    cout << "\n11. Them mot khoa x vao cay nhi phan tim kiem";
    break;
  case 12:
    cout << "\n12. Huy nut co khoa x cho truoc";
    break;
  }

  cin.get();
}
