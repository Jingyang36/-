/*
NIHAO:

A B C D E F G H I G K L M N O P Q R S T U WV W X Y Z
N I H A O B C D E F G J K L M O 

首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，
其余几个丢弃。现在，修改过的那个单词属于字母表的下面，如下所示：

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

T R A I L B Z E S C D F G H J K M N O P Q U V W X Y

上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，
并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。
因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。

  剔除多余字符，并标记已有的字符（先全存为大写，密文保持通用性，转换密文时处理小写）
  补充剩余密码表
  得到密文
 
  注意：
  地址为空的判断
  接收输入字符串使用gets(可能含有空格，不能用scanf)
 
  注意空格的处理
 
  输入字符串为空时，应该是不影响程序结果的，所以没有处理
  当输入的任一字符串为空时，可以直接将data拷贝到encrypt，即完成，输出即可
  （key为空，则data不变；kay不为空,data为空，则拷贝空串；若均为0，仍输出空串）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>



int main()
{
	/* 初始化对照表 */
	char sAlphabet[26] = { 0 };
	char cBegin = 'A';
	for (int i = 0; i < 26; i++)
	{
		sAlphabet[i] = cBegin;
		cBegin++;
	}


	char sInWord[100] = { 0 };
	char sText[100] = { 0 };
	while (scanf("%s%s", sInWord, sText) != EOF)
	{
			char sKeyUp[26] = { 0 };
			char sKeyDown[26] = { 0 };
			char sUpInWorf[100] = { 0 };
			/* 输入单词转大写 */
			for (int i = 0; i < strlen(sInWord); i++)
			{
				if (sInWord[i] >= 'a' && sInWord[i] <= 'z')
				{
					sUpInWorf[i] = sInWord[i] - 32;
				}
			}
			/* 单词去重 */
			char sOutWord[26] = { 0 };
			int iCount = 0;
			for (int j = 0; j < strlen(sUpInWorf); j++)
			{
				if (strchr(sOutWord, sUpInWorf[j]) == NULL) //找不到重复就拼接上
				{
					sOutWord[iCount] = sUpInWorf[j];
					iCount++;
				}
			}

			/* 生成单词表 */
			sprintf(sKeyUp, "%s", sOutWord);
			for (int i = 0; i < 26; i++)
			{
				if (strchr(sKeyUp, sAlphabet[i]) == NULL)
				{
					sKeyUp[iCount] = sAlphabet[i]; //找不到重复就拼接上
					iCount++;
				}
			}

			/* 对照生成小写密码表 */
			for (int i = 0; i < 26; i++)
			{
				sKeyDown[i] = sKeyUp[i] + 32;
			}

			/* 转换 */
			for (int k = 0; k < strlen(sText); k++)
			{
				if (sText[k] >= 'a' && sText[k] <= 'z')
				{
					printf("%c", sKeyDown[sText[k] - 'a']);
				}
				else if (sText[k] >= 'A' && sText[k] <= 'Z')
				{
					printf("%c", sKeyUp[sText[k] - 'A']);
				}
			}
			printf("\n");
	}

	return 0;
}
