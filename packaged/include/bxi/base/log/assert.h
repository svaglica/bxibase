/* -*- coding: utf-8 -*-  */

#ifndef BXILOG_ASSERT_H_
#define BXILOG_ASSERT_H_

#ifndef BXICFFI
#endif


// *********************************************************************************
// ********************************** Defines **************************************
// *********************************************************************************

/**
 * Equivalent to assert() but ensure logs are flushed before exiting.
 *
 * @param[in] logger the logger to use for logging before exiting
 * @param[in] expr the boolean expression to check
 * @see BXIEXIT()
 */
#define BXIASSERT(logger, expr) do {                                                \
            bxilog_assert(logger, expr,                                             \
                          (char *)__FILE__, ARRAYLEN(__FILE__),                     \
                          __func__, ARRAYLEN(__func__),                             \
                          __LINE__, #expr);                                         \
    } while(false)


// *********************************************************************************
// ********************************** Types   **************************************
// *********************************************************************************

// *********************************************************************************
// ********************************** Global Variables *****************************
// *********************************************************************************



// *********************************************************************************
// ********************************** Interface ************************************
// *********************************************************************************



/**
 * Exit the program if the given `result` (normally coming from the given `expr`)
 * is false.
 *
 * This function sole purpose is to make the macro BXIASSERT() cleaner.
 * Use BXIASSERT() instead.
 *
 * @param[in] logger a logger instance
 * @param[in] result a boolean value (usually a check)
 * @param[in] file the file name
 * @param[in] filelen the file name length (including the terminal NULL byte)
 * @param[in] func the function name
 * @param[in] funclen the function name length (including the terminal NULL byte)
 * @param[in] line the line number
 * @param[in] expr a string representing the expression that returned the given result
 *
 * @see BXIASSERT
 */
void bxilog_assert(bxilog_p logger, bool result,
                   char * file, size_t filelen,
                   const char * func, size_t funclen,
                   int line, char * expr);


#endif