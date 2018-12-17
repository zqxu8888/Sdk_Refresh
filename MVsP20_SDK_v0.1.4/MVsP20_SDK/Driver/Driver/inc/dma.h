/**
 *******************************************************************************
 * @file    dma.h
 * @author  lilu
 * @version V1.0.0
 * @date    2014/10/21
 * @brief	dma module drever interface
 *
 * Changelog:
 *			2014-10-21	create by lilu
 ******************************************************************************* 
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, MVSILICON SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2014 MVSilicon </center></h2>
*/

/**
 * @addtogroup DMA
 * @{
 * @defgroup dma dma.h
 * @{
 */
 
#ifndef __DMA_H__
#define __DMA_H__

typedef void (*INT_FUNC)(void);

typedef enum
{
	DMA_STREAM_INVALID = -127,
	DMA_DIRECTION_INVALID,
	DMA_AINCR_INVALID,
	DMA_MODE_INVALID,
	DMA_CBT_LEN_INVALID,
	DMA_CHANNEL_UNALLOCATED,
	DMA_NOT_ENOUGH_SPACE,
	DMA_UNALIGNED_ADDRESS,
	DMA_INT_TYPE_INVALID,
	DMA_OK = -1
}DMA_ERROR;

typedef enum
{
	PERIPHERAL_ID_SPIS_RX = 0,	//0
	PERIPHERAL_ID_SPIS_TX,		//1
	PERIPHERAL_ID_SD_RX,		//2
	PERIPHERAL_ID_SD_TX,		//3
	PERIPHERAL_ID_SPIM0_RX,		//4
	PERIPHERAL_ID_SPIM0_TX,		//5
	PERIPHERAL_ID_SPIM1_RX,		//6
	PERIPHERAL_ID_SPIM1_TX,		//7
	PERIPHERAL_ID_UART0_RX,		//8
	PERIPHERAL_ID_UART1_RX,		//9
	PERIPHERAL_ID_UART2_RX,		//10
	PERIPHERAL_ID_TIMER3,		//11
	PERIPHERAL_ID_TIMER4,		//12
	PERIPHERAL_ID_I2S_TX,		//13
	PERIPHERAL_ID_I2S_RX,		//14
	PERIPHERAL_ID_SARADC,		//15
	PERIPHERAL_ID_UART0_TX,		//16
	PERIPHERAL_ID_UART1_TX,		//17
	PERIPHERAL_ID_UART2_TX,		//18
	PERIPHERAL_ID_TIMER5,		//19
	PERIPHERAL_ID_TIMER6,		//20
	PERIPHERAL_ID_TIMER7,		//21
	PERIPHERAL_ID_TIMER8,		//22
	PERIPHERAL_ID_DPA_SRC,		//23
	PERIPHERAL_ID_DPA_DST,		//24
	PERIPHERAL_ID_DPA_DSTRD,   //25
	PERIPHERAL_ID_SOFTWARE,		//26

}DMA_PERIPHERAL_ID;

typedef enum
{
	DMA_BLOCK_MODE = 0,
	DMA_CIRCULAR_MODE
}DMA_MODE;

typedef enum
{
	DMA_CHANNEL_DIR_PERI2MEM = 0,
	DMA_CHANNEL_DIR_MEM2PERI,
	DMA_CHANNEL_DIR_MEM2MEM
}DMA_CHANNEL_DIR;

typedef enum
{
	DMA_PRIORITY_LEVEL_LOW = 0,
	DMA_PRIORITY_LEVEL_HIGH
}DMA_PRIORITY_LEVEL;

typedef enum
{
	DMA_SRC_DWIDTH_BYTE = 0,
	DMA_SRC_DWIDTH_HALF_WORD,
	DMA_SRC_DWIDTH_WORD
}DMA_SRC_DWIDTH;

typedef enum
{
	DMA_DST_DWIDTH_BYTE = 0,
	DMA_DST_DWIDTH_HALF_WORD,
	DMA_DST_DWIDTH_WORD
}DMA_DST_DWIDTH;

typedef enum
{
	DMA_SRC_AINCR_NO = 0,
	DMA_SRC_AINCR_SRC_WIDTH
}DMA_SRC_AINCR;

typedef enum
{
	DMA_DST_AINCR_NO = 0,
	DMA_DST_AINCR_DST_WIDTH
}DMA_DST_AINCR;

typedef struct
{
	DMA_CHANNEL_DIR		Dir;
	DMA_MODE			Mode;
	uint16_t			ThresholdLen;//仅在循环模式下有效
	DMA_SRC_DWIDTH		SrcDataWidth;
	DMA_DST_DWIDTH		DstDataWidth;
	DMA_SRC_AINCR		SrcAddrIncremental;
	DMA_DST_AINCR		DstAddrIncremental;
	uint32_t			SrcAddress;
	uint32_t			DstAddress;	
	uint16_t			BufferLen;
} DMA_CONFIG;

typedef enum
{
	DMA_DONE_INT = 0,
	DMA_THRESHOLD_INT,
	DMA_ERROR_INT
}DMA_INT_TYPE;

//------------------------------------------------------以下为通用配置API---------------------------------------------------------
/**
 * @brief	设置DMA的通道分配表
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	DMAChannelMap		DMA通道分配表
 *
 * @return
 *   		NONE
 * @note 
 */
void DMA_ChannelAllocTableSet(uint8_t* DMAChannelMap);

/**
 * @brief	使能DMA通道，启动传输
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 * @param	En				1:开启    0:关闭
 *
 * @return
 *   		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_ChannelEnable(uint8_t PeripheralID, bool En);

/**
 * @brief	设置指定通道中断的回调函数
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	IntType				中断类型，详见DMA_INT_TYPE
 * @param	CallBack			中断回调函数
 *								 
 * @return
 *   		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_InterruptFunSet(uint8_t PeripheralID, DMA_INT_TYPE IntType, INT_FUNC CallBack);

/**
 * @brief	开启或关闭指定通道的中断
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	IntType				中断类型，详见DMA_INT_TYPE
 * @param	En					1:开启    0:关闭	
 *								 
 * @return
 *   		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_InterruptEnable(uint8_t PeripheralID, DMA_INT_TYPE IntType, bool En);

/**
 * @brief	获取指定通道的中断标志
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	IntType				中断类型，详见DMA_INT_TYPE
 *								 
 * @return
 *   		返回中断标志或DMA_ERROR
 * @note	中断标志在不开启中断的情况下也会置位
 */
int32_t DMA_InterruptFlagGet(uint8_t PeripheralID, DMA_INT_TYPE IntType);

/**
 * @brief	清除指定通道的中断标志
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	IntType				中断类型，详见DMA_INT_TYPE
 *								 
 * @return
 *   		DMA_ERROR
 * @note	中断标志在不开启中断的情况下也会置位
 */
DMA_ERROR DMA_InterruptFlagClear(uint8_t PeripheralID, DMA_INT_TYPE IntType);

//------------------------------------------------------以下为Block模式专用API-------------------------------------------------------
/**
 * @brief	配置外设ID指定的DMA通道为Block模式
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *   		DMA_ERROR
 * @note	
 */
DMA_ERROR DMA_BlockConfig(uint8_t PeripheralID);

/**
 * @brief	设置block模式的传输buffer
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	Ptr					传输buffer首地址
 * @param	Len					传输buffer长度
 *
 * @return	
 *			DMA_ERROR
 * @note
*/
DMA_ERROR DMA_BlockBufSet(uint8_t PeripheralID, void* Ptr, uint16_t Len);

/**
 * @brief	获取block模式的传输buffer中已经传输的数据长度
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return	
 *			已经传输的数据长度或DMA_ERROR
 * @note
*/
int32_t DMA_BlockDoneLenGet(uint8_t PeripheralID);

//-----------------------------------------------------以下为Circular模式专用API----------------------------------------------------
/**
 * @brief	配置外设ID指定的DMA通道为Circular模式
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	CircularThreshold	循环FIFO水位，最大长度65535，单位Byte (本参数仅在循环模式下有效)
 * @param	CircularFifoAddr	循环FIFO首地址 （如地址不对齐，会返回DMA_UNALIGNED_ADDRESS）(本参数仅在循环模式下有效)
 * @param	CircularFifoLen		循环FIFO长度，最大长度65535，单位Byte (本参数仅在循环模式下有效)
 *
 * @return
 *   		DMA_ERROR
 * @note	
 */
DMA_ERROR DMA_CircularConfig(uint8_t PeripheralID, uint16_t CircularThreshold, void* CircularFifoAddr, uint16_t CircularFifoLen);

/**
 * @brief	向循环FIFO中填入数据
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 * @param	Ptr				填入数据的首地址
 * @param	Len				填入数据长度，单位Byte
 *
 * @return
 *   		返回填入的数据实际长度
 * @note	循环模式下，剩余空间长度小于Len数据时，会将buffer填满，返回实际填入的长度
 */
int32_t DMA_CircularDataPut(uint8_t PeripheralID, void* Ptr, uint16_t Len);

/**
 * @brief	从循环FIFO中取出数据
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 * @param	Ptr				取出数据存放的首地址
 * @param	Len				本次取出数据的最大长度，单位Byte
 *
 * @return
 *   		返回取出数据的实际长度
 * @note	循环模式下，剩余数据长度小于Len时，会将buffer取空，返回实际填入的长度
 */
int32_t DMA_CircularDataGet(uint8_t PeripheralID, void* Ptr, uint16_t MaxLen);

/**
 * @brief	设置循环FIFO的水位值，传输数据量到达该水位时置位DMA_THRESHOLD_FLAG
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 * @param	Len				水位值（单位Byte）
 *
 * @return
 *   		DMA_ERROR
 * @note	
 */
DMA_ERROR DMA_CircularThresholdLenSet(uint8_t PeripheralID, uint16_t Len);

/**
 * @brief	获取循环FIFO的水位值，传输数据量到达该水位时置位DMA_THRESHOLD_FLAG
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *   		返回水位值或DMA_ERROR
 * @note	
 */
int32_t DMA_CircularThresholdLenGet(uint8_t PeripheralID);

/**
 * @brief	获取循环FIFO中的数据长度，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *    		返回buffer中的数据长度(单位Byte) 或 DMAC_ERROR
 * @note
 */
int32_t DMA_CircularDataLenGet(uint8_t PeripheralID);

/**
 * @brief	获取循环FIFO中的剩余空间长度，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *   		返回buffer中剩余空间长度或 DMAC_ERROR
 * @note
 */
int32_t DMA_CircularSpaceLenGet(uint8_t PeripheralID);

/**
 * @brief	清空循环FIFO
 * @param	PeripheralID	外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *   		返回DMA_ERROR
 * @note	循环FIFO的清空是将读写指针指向同一地址
 */
DMA_ERROR DMA_CircularFIFOClear(uint8_t PeripheralID);

/**
 * @brief	获取循环FIFO的写指针的位置，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *    		返回循环FIFO中写指针位置或DMA_ERROR
 * @note
 */
int32_t DMA_CircularWritePtrGet(uint8_t PeripheralID);

/**
 * @brief	获取循环FIFO的读指针的位置，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *    		返回循环FIFO中读指针位置或DMA_ERROR
 * @note
 */
int32_t DMA_CircularReadPtrGet(uint8_t PeripheralID);

/**
 * @brief	设置循环FIFO的写指针的位置，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *    		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_CircularWritePtrSet(uint8_t PeripheralID, uint16_t Ptr);

/**
 * @brief	设置循环FIFO的写指针的位置，单位Byte
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 *
 * @return
 *    		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_CircularReadPtrSet(uint8_t PeripheralID, uint16_t Ptr);

//--------------------------------------------------------以下为Timer专用API-------------------------------------------------------
/**
 * @brief	配置外设ID指定的DMA通道（外设一般仅限定为TIMER）
 * @param	PeripheralID		外设ID，详见DMA_PERIPHERAL_ID
 * @param	DMA_CONFIG			DMA配置结构体，详见DMA_CONFIG （如地址不对齐，会返回DMA_UNALIGNED_ADDRESS）
 *
 * @return
 *   		DMA_ERROR
 * @note
 */
DMA_ERROR DMA_TimerConfig(uint8_t PeripheralID, DMA_CONFIG* Config);

#endif

/**
 * @}
 * @}
 */
