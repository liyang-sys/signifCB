#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "all.h"
#include "encoding.h"
#include "parameter_setting.h"

int ptr;
uchar *bin;
void test_en_sub3d_sub2()
{
	ptr = 0;
	bin = calloc(4096, sizeof(uchar));
	union data
	{
		unsigned short int a;
		uchar b[4];
	} rem;
	int snLen = 58;
	unsigned int *bigZ = (unsigned int *)calloc(snLen, sizeof(unsigned int));
	FILE *fp = fopen("snCCC.txt", "rb");
	fread(bigZ, sizeof( unsigned int), snLen, fp);
	int index = 0;
	int indexZ = 0;
	Uint8_Dat sn;
	sn.len = snLen;
	sn.dat = (unsigned char *)calloc(snLen, sizeof(unsigned char));
	int sumZ = 0;
	for (int i = 0; i < snLen; i++)
	{
		if (bigZ[i] == 1)
		{
			rem.a = 1;
			rem.a = rem.a << (15 - index);
			sn.dat[indexZ >> 3] |= rem.b[1];
			sn.dat[(indexZ >> 3) + 1] |= rem.b[0];
			sumZ++;
		}
		index++;
		indexZ++;
		index &= 7;
		printf("%d ", bigZ[i]);
	}
	printf("\n------------------------------------------------------------------------------------------\n");
	///从matlab读取runs数组
	Int32_Dat cf0;
	cf0.len = 8192;
	cf0.dat = (int*)calloc(cf0.len, sizeof(int));
	fp = fopen("cf0CCC.txt", "rb");
	//fp = fopen("wunsDAYUlenf1C2N.txt","rb");
	fread(cf0.dat, sizeof(int), cf0.len, fp);
	//    printf("c2n = %p",c2n.dat);
	fclose(fp);
	//for (int i = 0; i < cf0.len; i++)
	//{
	//	printf("%d ", cf0.dat[i]);
	//}

	int maxcf0 = 2;
	en_sub3d_sub2(&cf0, &sn, maxcf0);
	printf("\n编码结束后ptr = %d\n", ptr);
	fp = fopen("encodeZThd4Code.txt", "wb");
	fwrite(bin, sizeof(unsigned char), (ptr / 8) + 1, fp);
	fclose(fp);
	//ptr = 0;
	//DEC dec = de_z0_r0(bin, 8192);
	//fp = fopen("CDecodeZElse.txt", "wb");
	//fwrite(dec.z, sizeof(unsigned char), (8192 / 8) + 1, fp);
	//fclose(fp);
}
