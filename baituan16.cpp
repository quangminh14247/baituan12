#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, vector<string>> ds;

void tim_duong(string bd, string dich)
{
    map<string, bool> tham;
    map<string, string> truoc;
    queue<string> q;

    q.push(bd);
    tham[bd] = true;

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (string v : ds[u])
        {
            if (!tham[v])
            {
                tham[v] = true;
                truoc[v] = u;
                q.push(v);
            }
        }
    }

    if (!tham[dich])
    {
        cout << "Khong co duong di";
        return;
    }

    vector<string> kq;
    string x = dich;

    while (x != "")
    {
        kq.push_back(x);

        if (x == bd)
            break;

        x = truoc[x];
    }

    cout << "\nDuong di ngan nhat:\n";

    for (int i = kq.size() - 1; i >= 0; i--)
    {
        cout << kq[i];

        if (i > 0)
            cout << " -> ";
    }
}

int main()
{
    ds["HaNoi"] = {"SonTay", "HoaBinh", "PhuLy", "HaiDuong", "ThaiNguyen", "BacNinh"};
    ds["SonTay"] = {"HaNoi"};
    ds["HoaBinh"] = {"HaNoi"};
    ds["PhuLy"] = {"HaNoi", "HungYen"};
    ds["HungYen"] = {"PhuLy", "HaiDuong"};
    ds["HaiDuong"] = {"HaNoi", "HungYen", "HaiPhong"};
    ds["HaiPhong"] = {"HaiDuong", "UongBi"};
    ds["ThaiNguyen"] = {"HaNoi"};
    ds["BacNinh"] = {"HaNoi", "BacGiang", "UongBi"};
    ds["BacGiang"] = {"BacNinh", "UongBi"};
    ds["UongBi"] = {"BacGiang", "BacNinh", "HaiPhong"};

    string bd, dich;

    cout << "Nhap tinh bat dau: ";
    cin >> bd;

    cout << "Nhap tinh dich: ";
    cin >> dich;

    tim_duong(bd, dich);

    return 0;
}
