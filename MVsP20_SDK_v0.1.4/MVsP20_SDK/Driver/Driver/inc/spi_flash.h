/**
 *****************************************************************************
 * @file     spi_code_flash.h
 * @author   lujiangang	
 * @version  V1.0.0
 * @date     16-Oct-2014
 * @brief    spi code flash driver header file
 *****************************************************************************
 * @attention 
 *
 * <h2><center>&copy; COPYRIGHT 2013 MVSilicon </center></h2>
 */
 
 /**
 * @addtogroup FSHC 
 * @{
 * @defgroup spi_flash spi_flash.h
 * @{
 */
 
#ifndef __SPI_CODE_FLASH_H__
#define __SPI_CODE_FLASH_H__

#include "type.h"

#define     POSEDGE_SEL          (0)       /**<sampling at clk posedge */
#define     NEGEDGE_SEL          (1)       /**<sampling at clk negedge */
#define     DELAY_CHAIN_SEL      (4)       /**<sampling at the n clks */

#define     FLASH_GD             (0xC8)    /**<MID */
#define     FLASH_MX             (0xC2)    /**<MID */
#define     FLASH_WINBOUND       (0xEF)    /**<MID */
#define     FLASH_PCT            (0xBF)    /**<MID */
#define     FLASH_EON            (0x1C)    /**<MID */
#define     FLASH_BG             (0xE0)    /**<MID */
#define     FLASH_ESMT           (0x8C)    /**<MID */
#define		FLASH_FT			 (0x0E)		 /**<MID */
#define		FLASH_FM			 (0xA1)		 /**<MID */
#define		FLASH_PY			 (0x85)		 /**<MID */


#define FLASH_GD_VERSION_A	0
#define FLASH_GD_VERSION_B	1
#define FLASH_GD_VERSION_C	2
/**
 * err code definition
 */
typedef enum _SPI_FLASH_ERR_CODE
{
    TIME_OUT_ERR = -255,             /**<function execute time out*/
    UNKNOWN_MID_ERR,                 /**<MID can't indentify*/
    UNKNOWN_DID_ERR,                 /**<identify MID but can't identify DID*/
    FIFO_ALWAYS_EMPTY_ERR,           /**<during reading, time out but fifo is still empty*/
    FIFO_ALWAYS_FULL_ERR,            /**<during writing, time out but fifo is still full*/
    DATALEN_LESS_THEN_ZERO_ERR,      /**<read data but data len is < 0*/
    CODE_AREA_PROTECT_NOT_SUPPORT,   /**<indicate this area which choosed before not support*/
    UNLOCK_FLASH_ERR,                /**<unlock flash err*/
    WSTATUS_ERR,
    FLASH_NONE_ERR = 0,
}SPI_FLASH_ERR_CODE;

#pragma pack(1)

//both for cahce bus and Mcu bus, modify name later
typedef enum _SPIFLASH_IO_MODE
{
		MODE_1BIT,
		MODE_2BIT,
		MODE_4BIT
}SPIFLASH_IO_MODE;


/**
 * flash structure define 
 * each byte definition like:    A B CMP SEC/BP4 TB/BP3 BP2 BP1 BP0 <A:area protection support flag,B:CMP bit exist flag>
 */
typedef struct _SPI_FLASH_INFO
{
    volatile uint8_t      Mid;             /**<Manufacturer's ID*/
    volatile uint16_t      Did;             /**<Device ID*/
    volatile SPIFLASH_IO_MODE      SpiIOMode;     /** r/w*/
    volatile uint8_t      SqiWriteFlag;    /**<bit1:1 support 4bit page programm, 0 not support. read only*/
    volatile uint32_t     Capacity;        /**<flash capacity*/
		
    volatile uint8_t      NoneAreaProtect;
    volatile uint8_t      HalfAreaProtect;
    volatile uint8_t      ThreeQuarterAreaProtect;
    volatile uint8_t      SevenEighthsAreaProtect;
    volatile uint8_t      AllAreaProtect;
    volatile uint8_t			GD_version;

}SPI_FLASH_INFO;

#pragma pack()

typedef enum {
	CHIP_ERASE,
	SECTOR_ERASE,
	BLOCK_ERASE
}ERASE_TYPE_ENUM;


/**
* SPI Flash lock range
*/
typedef enum _SPI_FLASH_LOCK_RANGE
{
	FLASH_LOCK_RANGE_HALF = 1,
	FLASH_LOCK_RANGE_THREE_QUARTERS,
	FLASH_LOCK_RANGE_SEVENTH_EIGHT,
	FLASH_LOCK_RANGE_ALL
}SPI_FLASH_LOCK_RANGE;

typedef enum {

		IOCTL_FLASH_PROTECT=1,
		IOCTL_FLASH_UNPROTECT,
		IOCTL_FLASH_RDID ,			
		IOCTL_FLASH_RDSTATUS,				
		IOCTL_FLASH_CRMRESET,
		IOCTL_FLASH_IO_MODE,
		IOCTL_FLASH_DEEPPOWERDOWN,
		IOCTL_FLASH_EXIT_DEEEPPOWERDOWN,
		IOCTL_FLASH_SETHPM
} IOCTL_FLASH_T;



/**
 * @brief  init flash
 * @param  flash_clk  the clock output to flash, its' setting range: 1.417323M ~ 90M
 * @param  IOMode see SPIFLASH_IO_MODE
 * @param  HpmEn 1: hpm enable, 0: hpm disable
 * @param  CrmEn continuous read mode. 1: enable, 0:disable
 * @return SPI_FLASH_ERR_CODE
 *         @arg UNKNOWN_MID_ERR  MID can't indentify
 *         @arg UNKNOWN_DID_ERR  identify MID but can't identify DID
 *         @arg NONE_ERR  
 */
SPI_FLASH_ERR_CODE SpiFlashInit(uint32_t flash_clk, SPIFLASH_IO_MODE IOMode, bool HpmEn, bool CrmEn);


/**
 * @brief  read data from flash 
 * @param  StartAddr the data addr need to read for flash
 * @param  Buffer the data addr need to save for MCU's mem
 * @param  Length data length
 * @param  TimeOut read data but fifo always empty
 * @return SPI_FLASH_ERR_CODE
 *         @arg  FIFO_ALWAYS_EMPTY_ERR  function execute time out
 *         @arg  DATALEN_LESS_THEN_ZERO_ERR    read data but data len is < 0
 *         @arg  NONE_ERR
 */
SPI_FLASH_ERR_CODE SpiFlashRead( uint32_t StartAddr, uint8_t* Buffer, uint32_t Length, uint32_t TimeOut);

/**
 * @brief  write data into flash 
 * @param  Addr the data addr need to write for flash
 * @param  Buffer the data addr need to read for MCU's mem
 * @param  Length data length
 * @param  TimeOut read data but fifo always empty
 * @return SPI_FLASH_ERR_CODE
 *         @arg  FIFO_ALWAYS_FULL_ERR  function execute time out
 *         @arg  DATALEN_LESS_THEN_ZERO_ERR    read data but data len is < 0
 *         @arg  NONE_ERR
 */
SPI_FLASH_ERR_CODE SpiFlashWrite( uint32_t	Addr, uint8_t	*Buffer, uint32_t 	Length, uint32_t TimeOut);					



/**
 * @brief  flash erase
 * @param  EraseType:	see ERASE_TYPE_ENUM type 
 *										CHIP_ERASE:		Erase whole chip
 *										SECTOR_ERASE:	Erase One sector
 *										BLOCK_ERASE:	Erase One block				
 *				  					for CHIP_ERASE type, param 2 & param 3 are NOT cared.
 * @param  Index:
 *										for SECTOR_ERASE type: 	means sector number
 *										for BLOCK_ERASE type: 	means block number
 * @param  IsSuspend: during flash write or sector/block erase need suspend set it to 1
 * @return NONE
 */
void SpiFlashErase(ERASE_TYPE_ENUM erase_type, uint32_t index, bool IsSuspend);



/**
 * @brief  get spi flash information
 * @param  none
 * @return return the SPI_FLASH_INFO pointer
 * @note this function should be called after SpiFlashInit
 */
SPI_FLASH_INFO* SpiFlashInfoGet(void);


/**
 * @brief  Spi Flash IO Ctrl
 * @param	�ɱ����,arg1,arg2... ����Cmd������
 *			IOCTL_FLASH_PROTECT:
 *				arg1: SPI_FLASH_LOCK_RANGE ProtectRange
 *					  seee SPI_FLASH_LOCK_RANGE enum for detail
 *
 *			IOCTL_FLASH_UNPROTECT:
 *				arg1: uint8_t* Buf, Bufָ���������Ϊ"\x35\xBA\x69"
 *				arg2: int32_t BufLen �̶�Ϊ 3
 *
 *			IOCTL_FLASH_RDID:
 *				arg1: uint16_t * did
 *				arg2: uint8_t * mid
 *
 *			IOCTL_FLASH_RDSTATUS:
 *				arg1: uint32_t *status
 *
 *			IOCTL_FLASH_CRMRESET:
 *
 *			IOCTL_FLASH_IO_MODE:
 *				arg1: SPIFLASH_IO_MODE io_mode
 *
 *			IOCTL_FLASH_DEEPPOWERDOWN:
 *
 *			IOCTL_FLASH_EXIT_DEEEPPOWERDOWN:
 *
 *			IOCTL_FLASH_SETHPM:
 *				arg1: bool hpmEn
 * @return return SPI_FLASH_ERR_CODE for cmd execetued
 */
SPI_FLASH_ERR_CODE SpiFlashIOCtrl(IOCTL_FLASH_T Cmd, ...);



#endif  //__SPI_CODE_FLASH_H__

/**
 * @}
 * @}
 */
