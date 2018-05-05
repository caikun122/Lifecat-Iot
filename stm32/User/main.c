/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   LCD��ʾJPG�ļ�����ͼ
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./usart/bsp_usart.h" 
#include "./led/bsp_led.h"   
#include "ff.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void jpgDisplay(char *pic_name);
char *join(char *, char *,char *);  

void delay_us(u16 t)
{  
  u16 i,j;
	for(i=0;i<t;i++){
    for(j=0;j<t;j++){
		}
	}
}


FATFS fs;													/* FatFs�ļ�ϵͳ���� */
FRESULT res_sd;                /* �ļ�������� */

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main ( void )
{
	int p = 0;

	ILI9341_Init ();         //LCD ��ʼ��
	
	LCD_SetFont(&Font8x16);
	LCD_SetColors(RED,BLACK);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
  ILI9341_GramScan ( 6 );
	
	USART_Config();		
	LED_GPIO_Config();

	LED_BLUE;
	
	//�����̱���� jpg�������һЩwarning����Ӱ��ʹ�á�
	//��ֲ������ʱ����ע�������ļ��Ķ�ջ��С
	printf("\r\n ********** ��ʾJPG�ļ�*********** \r\n"); 
	printf("\r\n ʵ��ǰ��ȷ��SD����Ŀ¼�¾���ʵ��ʹ�õ�JPGͼƬ�ļ�, \r\n"); 
	
	/*����sd�ļ�ϵͳ*/
	res_sd = f_mount(&fs,"0:",1);
	if(res_sd != FR_OK)
	{
		printf("\r\n�������������Ѹ�ʽ����fat��ʽ��SD����\r\n");
	}
	
	ILI9341_GramScan ( 6 );
	/*��ʾSD���ڵ�JPG�ļ�����ȷ��SD����·�����и��ļ���
	���ڹ���Ŀ¼�µġ���Ҫ������SD�������ļ����и��Ƶ�SD���ĸ�Ŀ¼*/
	
	jpgDisplay("0:/Image/background.jpg");
	delay_us(4000);
	
	while ( 1 )
	{
		switch(p%10){
			case 0:
		    jpgDisplay("0:/img0.jpg");
		    break;
			case 1:
		    jpgDisplay("0:/img1.jpg");
		    break;
			case 2:
		    jpgDisplay("0:/img2.jpg");
		    break;
			case 3:
		    jpgDisplay("0:/img3.jpg");
		    break;
			case 4:
		    jpgDisplay("0:/img4.jpg");
		    break;
			case 5:
		    jpgDisplay("0:/img5.jpg");
		    break;
			case 6:
		    jpgDisplay("0:/img6.jpg");
		    break;
			case 7:
		    jpgDisplay("0:/img7.jpg");
		    break;
			case 8:
		    jpgDisplay("0:/img8.jpg");
		    break;
			case 9:
		    jpgDisplay("0:/img9.jpg");
		    break;
		}
	
		p++;
		delay_us(8000);
	}
}
  
char* join(char *s1, char *s2,char *s3)  
{  
    char *result = malloc(strlen(s1)+strlen(s2)+strlen(s3)+1);//+1 for the zero-terminator  
  
    strcpy(result, s1);  
    strcat(result, s2);  
	  strcat(result, s3); 
  
    return result;  
}  

/* ------------------------------------------end of file---------------------------------------- */

