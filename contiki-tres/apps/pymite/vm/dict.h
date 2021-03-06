/*
# This file is Copyright 2002 Dean Hall.
# This file is part of the PyMite VM.
# This file is licensed under the MIT License.
# See the LICENSE file for details.
*/


#ifndef __DICT_H__
#define __DICT_H__


/**
 * \file
 * \brief Dict Object Type
 *
 * Dict object type header.
 */


/**
 * Dict
 *
 * Contains ptr to two seglists,
 * one for keys, the other for values;
 * and a length, the number of key/value pairs.
 */
typedef struct PmDict_s
{
    /** object descriptor */
    PmObjDesc_t od;
    /** number of key,value pairs in the dict */
    uint16_t length;
    /** ptr to seglist containing keys */
    pSeglist_t d_keys;
    /** ptr to seglist containing values */
    pSeglist_t d_vals;
} PmDict_t,
 *pPmDict_t;


/**
 * Clears the contents of a dict.
 * after this operation, the dict should in the same state
 * as if it were just created using dict_new().
 *
 * @param   pdict ptr to dict to clear.
 * @return  nothing
 */
PmReturn_t dict_clear(pPmObj_t pdict);

/**
 * Gets the value in the dict using the given key.
 *
 * @param   pdict ptr to dict to search
 * @param   pkey ptr to key obj
 * @param   r_pobj Return; addr of ptr to obj
 * @return  Return status
 */
PmReturn_t dict_getItem(pPmObj_t pdict, pPmObj_t pkey, pPmObj_t *r_pobj);

#ifdef HAVE_DEL
/**
 * Removes a key and value from the dict.
 * Throws TypeError if pdict is not a dict.
 * Throws KeyError if pkey does not exist in pdict.
 *
 * @param   pdict Ptr to dict to search
 * @param   pkey Ptr to key obj
 * @return  Return status
 */
PmReturn_t dict_delItem(pPmObj_t pdict, pPmObj_t pkey);
#endif /* HAVE_DEL */

/**
 * Allocates space for a new Dict.
 * Return a pointer to the dict by reference.
 *
 * @param   r_pdict Return; Addr of ptr to dict
 * @return  Return status
 */
PmReturn_t dict_new(pPmObj_t *r_pdict);

/**
 * Sets a value in the dict using the given key.
 *
 * If the dict already contains a matching key, the value is
 * replaced; otherwise the new key,val pair is inserted
 * at the front of the dict (for fast lookup).
 * In the later case, the length of the dict is incremented.
 *
 * @param   pdict ptr to dict in which (key,val) will go
 * @param   pkey ptr to key obj
 * @param   pval ptr to val obj
 * @return  Return status
 */
PmReturn_t dict_setItem(pPmObj_t pdict, pPmObj_t pkey, pPmObj_t pval);

#ifdef HAVE_PRINT
/**
 * Prints out a dict. Uses obj_print() to print elements.
 *
 * @param pobj Object to print.
 * @return Return status
 */
PmReturn_t dict_print(pPmObj_t pdict);
#endif /* HAVE_PRINT */

/**
 * Updates the destination dict with the key,value pairs from the source dict
 *
 * @param   pdestdict ptr to destination dict in which key,val pairs will go
 * @param   psourcedict ptr to source dict which has all key,val pairs to copy
 * @param   omit_underscored Boolean set to true to omit key,val pairs where
 *          the key starts with an underscore '_'.
 * @return  Return status
 */
PmReturn_t dict_update(pPmObj_t pdestdict, pPmObj_t psourcedict,
                       uint8_t omit_underscored);

/**
 * Returns C_SAME if the two given dictionaries have the same contents
 *
 * @param d1 ptr to a dictionary object
 * @param d2 ptr to another dictionary object
 * @return C_DIFFER or C_SAME
 */
int8_t dict_compare(pPmObj_t d1, pPmObj_t d2);

#endif /* __DICT_H__ */
