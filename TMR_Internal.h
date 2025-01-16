// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef TMR_INTERNAL_H_
    #define TMR_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "TMR_Port.h"
    #include "driver/STM32L496VGT6P/TMR_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef TMR_TIM
        #define TMR_TIM TIM_1
    #endif

    #ifndef TMR_LOG
        #define TMR_LOG LOG_1
    #endif

    #define TMR_NAME       "TMR"
    #define TMR_LOG_PREFIX UTIL_StringConcatenateConstant( TMR_NAME, "> " )

    #ifdef DEBUG
        #define TMR_Raw( Level, Format, ... ) TMR_LOG_Raw( Level, Format, ##__VA_ARGS__ )
        #define TMR_Trace( Format, ... )      TMR_LOG_Trace( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TMR_Debug( Format, ... )      TMR_LOG_Debug( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TMR_Info( Format, ... )       TMR_LOG_Info( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TMR_Warning( Format, ... )    TMR_LOG_Warning( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TMR_Error( Format, ... )      TMR_LOG_Error( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TMR_Fatal( Format, ... )      TMR_LOG_Fatal( UTIL_StringConcatenateConstant( TMR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define TMR_Raw( Level, Format, ... )
        #define TMR_Trace( Format, ... )
        #define TMR_Debug( Format, ... )
        #define TMR_Info( Format, ... )
        #define TMR_Warning( Format, ... )
        #define TMR_Error( Format, ... )
        #define TMR_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct TMR_Instance_Context_t TMR_Instance_Context_t;

    typedef struct TMR_Instance
    {
        TMR_t TMR;

        union
        {
            TMR_Instance_Context_t * Context;
            TMR_STM32L496VGT6P_Instance_t * STM32L496VGT6P;
        };
    } TMR_Instance_t;

    typedef struct TMR_Context
    {
        TMR_Instance_t Instance[ TMR_NUMBER_OF_INSTANCES ];
    } TMR_Context_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    LOG_Status_t TMR_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Trace( LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Debug( LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Info( LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Warning( LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Error( LOG_Format_t LOG_Format, ... );
    LOG_Status_t TMR_LOG_Fatal( LOG_Format_t LOG_Format, ... );

    TMR_Status_t TMR_Instance_IsValid( TMR_Instance_t * TMR_Instance );

    // The following APIs MUST be provided by the port
    TMR_Status_t TMR_IsValid( TMR_t TMR );

    TMR_Status_t TMR_Instance_Initialize( TMR_Instance_t * TMR_Instance );
    TMR_Status_t TMR_Instance_Cycle( TMR_Instance_t * TMR_Instance );
    TMR_Status_t TMR_Instance_DeInitialize( TMR_Instance_t * TMR_Instance );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    extern TMR_Context_t TMR_Context;

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TMR_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
