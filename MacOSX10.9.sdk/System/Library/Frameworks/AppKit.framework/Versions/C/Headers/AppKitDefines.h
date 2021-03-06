/*
	AppKitDefines.h
	Application Kit
	Copyright (c) 1995-2013, Apple Inc.
	All rights reserved.
*/
#ifndef _APPKITDEFINES_H
#define _APPKITDEFINES_H

#import <AvailabilityMacros.h>
#import <Foundation/NSObjCRuntime.h>

#ifndef AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_0
#define AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_0 DEPRECATED_IN_MAC_OS_X_VERSION_10_0_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_1 DEPRECATED_IN_MAC_OS_X_VERSION_10_1_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_2 DEPRECATED_IN_MAC_OS_X_VERSION_10_2_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_3 DEPRECATED_IN_MAC_OS_X_VERSION_10_3_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4 DEPRECATED_IN_MAC_OS_X_VERSION_10_4_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_5 DEPRECATED_IN_MAC_OS_X_VERSION_10_5_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_6 DEPRECATED_IN_MAC_OS_X_VERSION_10_6_AND_LATER
#define AVAILABLE_MAC_OS_X_VERSION_10_7_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_7 DEPRECATED_IN_MAC_OS_X_VERSION_10_7_AND_LATER
#endif

//
//  Platform specific defs for externs
//

//
// For MACH
//

#if defined(__MACH__)

#ifdef __cplusplus
#define APPKIT_EXTERN		extern "C"
#define APPKIT_PRIVATE_EXTERN	__attribute__((visibility("hidden"))) extern "C"
#define APPKIT_PRIVATE          __attribute__((visibility("hidden")))
#else
#define APPKIT_EXTERN		extern
#define APPKIT_PRIVATE_EXTERN	__attribute__((visibility("hidden"))) extern
#define APPKIT_PRIVATE          __attribute__((visibility("hidden")))
#endif

//
// For Windows
//

#elif defined(WIN32)

#ifndef _NSBUILDING_APPKIT_DLL
#define _NSWINDOWS_DLL_GOOP	__declspec(dllimport)
#else
#define _NSWINDOWS_DLL_GOOP	__declspec(dllexport)
#endif

#ifdef __cplusplus
#define APPKIT_EXTERN		extern "C" _NSWINDOWS_DLL_GOOP
#define APPKIT_PRIVATE_EXTERN	extern
#else
#define APPKIT_EXTERN		_NSWINDOWS_DLL_GOOP extern
#define APPKIT_PRIVATE_EXTERN	extern
#endif

//
//  For Solaris
//

#elif defined(SOLARIS)

#ifdef __cplusplus
#define APPKIT_EXTERN		extern "C"
#define APPKIT_PRIVATE_EXTERN	extern "C"
#else
#define APPKIT_EXTERN		extern
#define APPKIT_PRIVATE_EXTERN	extern
#endif

#endif

#endif // _APPKITDEFINES_H

