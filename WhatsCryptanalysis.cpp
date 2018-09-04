/* **************************************************************************

    * File Name : WhatsCryptanalysis.cpp

    * Creation Date : 2018-09-03 10:49:22

    * Last Modified : 2018-09-04 10:30:07

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */

#include <iostream>
#include <string> //getline()
using namespace std;

int main()
{
    int numOfInput; //輸入值的個數
    string inputAry[1000]; //將輸入值儲存於陣列
    int count[26]; //計算英文字母次數
    int Max; //次數中的最大值
    int index; //暫存的引數

    cin >> numOfInput; //輸入個數
    for(int h = 0; h < 26; h++)
        count[h] = 0; //初始化count陣列
    for(int i = 0; i <= numOfInput; i++)
        getline(cin, inputAry[i]); //輸入值
    for(int j = 0; j <= numOfInput; j++)
        for(int k = 0; inputAry[j][k] != '\0'; k++)
            if(inputAry[j][k] >= 'a' && inputAry[j][k] <= 'z')
                count[inputAry[j][k] - 'a']++; //於inputAry陣列中次數加1
            else if(inputAry[j][k] >= 'A' && inputAry[j][k] <= 'Z')
                count[inputAry[j][k] - 'A']++; //於inputAry陣列中次數加1
    for(int l = 0; l < 26; l++)
    {
        Max = 0; //最大值每次歸零
        for(int m = 0; m < 26; m++) //找出次數最大值
            if(count[m] > Max)
            {
                Max = count[m];
                index = m;
            }
        if(Max == 0) //當次數全部為0則結束
            break;
        else //印出最大值並將次數改為0
        {
            char word = 'A' + index;
            cout << word << " " << Max << "\n";
            count[index] = 0;
        }
    }
    return 0;
}
