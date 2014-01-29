#ifndef __STATIC_ROUTNG_MAP_H__
#define __STATIC_ROUTNG_MAP_H__

/*                                  0 0 0 0 0 0 0 0 0 1 1 1 1 1 1             */
/*                                  1 2 3 4 5 6 7 8 9 0 1 2 3 4 5             */
static uint8_t nbr_map[15][15] = { {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},  /* 1 */  \
                                   {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},  /* 2 */  \
                                   {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0},  /* 3 */  \
                                   {0,1,0,0,0,0,0,1,1,0,0,0,0,0,0},  /* 4 */  \
                                   {0,1,0,0,0,0,0,0,0,1,1,0,0,0,0},  /* 5 */  \
                                   {0,0,1,0,0,0,0,0,0,0,0,1,1,0,0},  /* 6 */  \
                                   {0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},  /* 7 */  \
                                   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},  /* 8 */  \
                                   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},  /* 9 */  \
                                   {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},  /* 10 */ \
                                   {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},  /* 11 */ \
                                   {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},  /* 12 */ \
                                   {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},  /* 13 */ \
                                   {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},  /* 14 */ \
                                   {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}}; /* 15 */

/*                                        0 0 0 0 0 0 0 0 0 1 1 1 1           */
/*                                      E 1 2 3 4 5 6 7 8 9 0 1 2 3           */
static uint8_t routing_map[13][14] = { {},  /* 1 */  \
                                       {},  /* 2 */  \
                                       {},  /* 3 */  \
                                       {},  /* 4 */  \
                                       {},  /* 5 */  \
                                       {},  /* 6 */  \
                                       {},  /* 7 */  \
                                       {},  /* 8 */  \
                                       {},  /* 9 */  \
                                       {},  /* 10 */ \
                                       {},  /* 11 */ \
                                       {},  /* 12 */ \
                                       {}}; /* 13 */


#endif /* __STATIC_ROUTNG_MAP_H__ */
