#ifndef UART_H_
#define UART_H_
#include "Errors.h"
#include "std_types.h"
#include "Mask.h"

/**************************Uart define************************************/
#define UART_INT            0
#define UART_TASK           1
#define UART_BY          UART_INT 
#define UART_1          (void *)0x40011000
#define UART_2          (void *)0x40004400
#define UART_6          (void *)0x40011400

/**************************Uart Registers************************************/
typedef struct
{
    uint8_t* data;
    uint32_t pos;
    uint32_t size;
} buffer_t;

typedef enum
{
    Ready,
    Busy
} ReqState;

typedef struct
{
    buffer_t buffer;
    uint8_t state;
    void* UART_X;
} TxReq;

typedef struct
{
    buffer_t buffer;
    uint8_t state;
    void* UART_X;
} RxReq;

/**************************Uart APIs PROTOTYPES************************************/

ErrorStatus_t Uart_TxBufferAsync(uint8_t* buffer ,uint32_t len,void * UART_x);
ErrorStatus_t Uart_RxBufferAsync(uint8_t* buffer ,uint32_t len,void * UART_x);
ErrorStatus_t UartTx_done(void);

#endif