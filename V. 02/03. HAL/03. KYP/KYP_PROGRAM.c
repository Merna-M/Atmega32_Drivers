/*
 * KYP_PROGRAM.c
 *
 * Created: 10/27/2023 10:06:04 AM
 *  Author: MERNA
 */ 

#include "KYP_INTERFACE.h"
#include "KYP_CONFIG.h"

extern Dio_ChannelType KYP_ARR[8];

void KYP_vInit(void)
{
	Dio_Init(KYP_ARR   , 4 , PORT_PIN_OUT);
	Dio_Init(KYP_ARR+4 , 4 , PORT_PIN_PP);
	Port_Init();
//	Dio_WriteMask(KYP_ARR[0]/8 , 0xFF , 0x0F << KYP_ARR[0]%8);
}


u8 KYP_u8GetPressedKey(void)
{
	u8 LOC_KYP_ARR[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	u8 LOC_Ret = KYP_NOT_PRESSED;
	u8 i,j;
	u8 LOC_READ = 1;
	
	for(i=0 ; i<4 ; i++)
	{
		Dio_WriteChannel(KYP_ARR[i],0);
		for(j=0 ; j<4 ; j++)
		{
			LOC_READ = Dio_ReadChannel(KYP_ARR[j+4]);
			if(LOC_READ == 0)
			{
				LOC_Ret = LOC_KYP_ARR[i][j];
				break;
			}
		}
		Dio_WriteChannel(KYP_ARR[i],1);
		if(LOC_READ == 0)
		{
			break;
		}
	}
	return LOC_Ret;
}