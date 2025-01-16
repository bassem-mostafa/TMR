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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "TMR.h"
#include "TMR_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LOG_Status_t TMR_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_RawWithArgs( TMR_LOG, LOG_Level, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Trace( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_TraceWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Debug( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_DebugWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Info( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_InfoWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Warning( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_WarningWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Error( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_ErrorWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t TMR_LOG_Fatal( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_FatalWithArgs( TMR_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

TMR_Status_t TMR_Instance_IsValid( TMR_Instance_t * TMR_Instance )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_Instance );
        if ( TMR_Instance == NULL )
        {
            TMR_Error( "Invalid Argument" );
            TMR_Status = TMR_Status_ArgumentInvalid;
            break;
        }
        TMR_Status = TMR_Status_Error;
        for ( TMR_t TMR = TMR_Null; TMR < TMR_NUMBER_OF_INSTANCES; ++TMR )
        {
            if ( TMR_Instance == &TMR_Context.Instance[ TMR ] )
            {
                TMR_Status = TMR_Status_Success;
                break;
            }
        }
        if ( TMR_Status != TMR_Status_Success )
        {
            TMR_Error( "Invalid Reference" );
            TMR_Status = TMR_Status_Error;
            break;
        }
        TMR_Status = TMR_Status_Success;
    }
    while ( 0 );
    return TMR_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

TMR_Context_t TMR_Context;

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
