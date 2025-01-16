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

static TMR_Status_t TMR_Context_Initialize( void );
static TMR_Status_t TMR_Context_Cycle( void );
static TMR_Status_t TMR_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static TMR_Status_t TMR_Context_Initialize( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        for ( TMR_t TMR = TMR_Null; TMR < TMR_NUMBER_OF_INSTANCES; ++TMR )
        {
            TMR_Context.Instance[ TMR ].TMR = TMR;
            if ( ( TMR_Status = TMR_Instance_Initialize( &TMR_Context.Instance[ TMR ] ) ) != TMR_Status_Success )
            {
                TMR_Warning( "TMR_%d Initialize Failed: Status %d", TMR, TMR_Status );
            }
        }
        TMR_Status = TMR_Status_Success;
    }
    while ( 0 );
    return TMR_Status;
}

static TMR_Status_t TMR_Context_Cycle( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        for ( TMR_t TMR = TMR_Null; TMR < TMR_NUMBER_OF_INSTANCES; ++TMR )
        {
            TMR_Context.Instance[ TMR ].TMR = TMR; // FIXME
            if ( ( TMR_Status = TMR_Instance_Cycle( &TMR_Context.Instance[ TMR ] ) ) != TMR_Status_Success )
            {
                TMR_Warning( "TMR_%d Cycle Failed: Status %d", TMR, TMR_Status );
            }
        }
        TMR_Status = TMR_Status_Success;
    }
    while ( 0 );
    return TMR_Status;
}

static TMR_Status_t TMR_Context_DeInitialize( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        for ( TMR_t TMR = TMR_Null; TMR < TMR_NUMBER_OF_INSTANCES; ++TMR )
        {
            TMR_Context.Instance[ TMR ].TMR = TMR; // FIXME
            if ( ( TMR_Status = TMR_Instance_DeInitialize( &TMR_Context.Instance[ TMR ] ) ) != TMR_Status_Success )
            {
                TMR_Warning( "TMR_%d DeInitialize Failed: Status %d", TMR, TMR_Status );
            }
        }
        TMR_Status = TMR_Status_Success;
    }
    while ( 0 );
    return TMR_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TMR_Status_t TMR_Initialize( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        TMR_Status = TMR_Context_Initialize( );
    }
    while ( 0 );
    return TMR_Status;
}

TMR_Status_t TMR_Cycle( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        TMR_Status = TMR_Context_Cycle( );
    }
    while ( 0 );
    return TMR_Status;
}

TMR_Status_t TMR_DeInitialize( void )
{
    TMR_Status_t TMR_Status = TMR_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        TMR_Status = TMR_Context_DeInitialize( );
    }
    while ( 0 );
    return TMR_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char TMR_VERSION[] = "0.0.0.v20260117-1036";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
