/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 28.10.2020
 *
 */

#ifndef CIRCULAR_BUFFER_H
    #define CIRCULAR_BUFFER_H

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include <stdint.h>



/*****************************************************************************/
/* PUBLIC ENUMS */
/*****************************************************************************/

typedef enum circular_buffer_status {
    CIRCULAR_BUFFER_STATUS_OK,
    CIRCULAR_BUFFER_STATUS_ERROR,
    CIRCULAR_BUFFER_STATUS_EMPTY,
    CIRCULAR_BUFFER_STATUS_NOT_EMPTY,
    CIRCULAR_BUFFER_STATUS_FULL,
    CIRCULAR_BUFFER_STATUS_NOT_FULL
}circular_buffer_status_t;



/*****************************************************************************/
/* PUBLIC DEFINES */
/*****************************************************************************/

#define CIRCULAR_BUFFER_SIZE    128U



/*****************************************************************************/
/* PUBLIC STRUCTURES */
/*****************************************************************************/

typedef struct circular_buffer {
    uint8_t buffer[CIRCULAR_BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
    uint32_t items_count;
}circular_buffer_t;



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

circular_buffer_status_t circular_buffer_init(
    circular_buffer_t *circular_buffer
);

circular_buffer_status_t circular_buffer_is_full(
    circular_buffer_t *circular_buffer
);

circular_buffer_status_t circular_buffer_is_empty(
    circular_buffer_t *circular_buffer
);

circular_buffer_status_t circular_buffer_put_item(
    circular_buffer_t *circular_buffer,
    uint8_t item
);

circular_buffer_status_t circular_buffer_get_item(
    circular_buffer_t *circular_buffer,
    uint8_t *place_to_store_item
);



#endif /* CIRCULAR_BUFFER_H */

