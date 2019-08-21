// Copyleft ! 2019, 向昕哲
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.If not, see < https://www.gnu.org/licenses/>.
#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <sys/timeb.h>
#include <vector>
#include <Windows.h>
std::vector<int> num;
void monkeySort(int);
int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    bool again;
    char confirm;
    int len;
    again = true;
    confirm = 'Y';
    num.resize(1);
    std::cout << "Copyleft ! 2019, 向昕哲" << std::endl;
    std::cout << "欢迎使用昕哥牌“猴子排序”排序器，本“猴子排序”排序器由昕哥制作。该软件遵守 GPL v3.0 协议" << std::endl;
    std::cout << "由于排序算法特殊，所以速度看RP" << std::endl;
    while (again)
    {
        std::string str;
        std::stringstream ss;
        num.clear();
        std::cout << "请输入您要排序的数的个数：";
        std::cin >> len;
        std::cin.ignore();
        std::cout << "请输入您要排序的数（空格隔开，回车结束）：";
        std::getline(std::cin, str);
        ss << str;
        num.resize(static_cast<long long>(len) + 10LL);
        for (int i = 0; i < len; i++)
        {
            ss >> num.at(i);
        }
        monkeySort(len);
        std::cout << "排序完成：";
        for (int i = 0; i < len - 1; i++)
        {
            std::cout << num.at(i) << ", ";
        }
        std::cout << num.at(static_cast<long long>(len) - 1LL) << std::endl;
        std::cout << "是否重新开始（是/Y重新开始，其他字符结束）？";
        std::cin >> confirm;
        std::cin.ignore();
        switch (confirm)
        {
        case '是': case 'Y': case 'y':
            again = true;
            break;
        default:
            again = false;
            break;
        }
    }
    std::cout << "按Enter键退出" << std::endl;
    std::cin.get();
    return 0;
}
void monkeySort(int n)
{
    struct timeb timeSeed;
    while (!std::is_sorted(num.begin(), num.begin() + n))
    {
        ftime(&timeSeed);
        std::shuffle(num.begin(), num.begin() + n, std::default_random_engine(timeSeed.time * 1000 + timeSeed.millitm));
    }
    return;
}