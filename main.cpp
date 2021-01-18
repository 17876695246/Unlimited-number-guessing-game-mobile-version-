//一个可以移动的无限猜数字游戏
//代码...

//IQ库
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

//自制IQ库
#include "主文件.h"

//基础设置
using namespace std;

//数组/变量/函数
//数组
string 游戏界面 = { "1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0" };
string 移动[10] = { "*","    *","        *","            *","                *","                    *","                        *","                            *","                                *","                                    *" };

//变量
int _i = 0;
//初始化密码
int _z = 0;
//密码改变确认的变量
int _zz = 0;
//密码确认要改变的变量
int _zzz = 0;
//第几题
int 第几题 = 0;

//函数
void 界面()
{
	cout << "a - 左  d - 右 x - 退出 z - 选择/确定" << endl;
	cout << 游戏界面 << endl;
	cout << 移动[_i] << endl;
}

void 随机数()
{
	srand((unsigned int)time(NULL));
	//随机密码
	_z = rand() % 100 + 1;
	_z = _z % 10;
	cout << _z << endl;
}

//初始函数
int main()
{
	while(true)
	{
		char p ;
		char a = 'a';
		char d = 'd';
		char x = 'x';
		char z = 'z';

		system("cls");
		随机数();
		界面();
		p = _getch();
		
		//条件选择
		if (p == a)
		{
			_i = _i - 1;

			if (_i < 0)
			{
				_i = 9;
			}

			else if (_i > 9)
			{
				_i = 0;
			}
		}

		else if (p == d)
		{
			_i = _i + 1;
			if (_i < 0)
			{
				_i = 9;
			}

			else if (_i > 9)
			{
				_i = 0;
			}
		}

		//选择/确定
		else if (p == z)
		{
			if (_i != _z)
			{
				cout << "选择错误..." << endl;
			}

			else if (_zz == _zzz)
			{
				if (_i == _z)
				{
					第几题 = 第几题 + 1;
					cout << "第" << 第几题 << "道密码已成功! " << endl;
					_zz = _zz + 1;
					_zzz = _zzz + 1;
					_z = rand() % 100 + 1;
					_z = _z % 10;
					cout << _z << endl;


				}
			}

			system("pause");
		}

		//退出游戏
		else if (p == x)
		{
			cout << "正在退出..." << endl;
			system("pause");
			break;
		}

		//选择错误
		else
		{
			cout << "没有该选择,请重新选择..." << endl;
			Sleep(500);
		}

	}

	return 0;
}
