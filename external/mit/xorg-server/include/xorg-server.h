/* include/xorg-server.h.  Generated from xorg-server.h.in by configure.  */
/* xorg-server.h.in						-*- c -*-
 *
 * This file is the template file for the xorg-server.h file which gets
 * installed as part of the SDK.  The #defines in this file overlap
 * with those from config.h, but only for those options that we want
 * to export to external modules.  Boilerplate autotool #defines such
 * as HAVE_STUFF and PACKAGE_NAME is kept in config.h
 *
 * It is still possible to update config.h.in using autoheader, since
 * autoheader only creates a .h.in file for the first
 * AM_CONFIG_HEADER() line, and thus does not overwrite this file.
 *
 * However, it should be kept in sync with this file.
 */

#ifndef _XORG_SERVER_H_
#define _XORG_SERVER_H_

#ifdef HAVE_XORG_CONFIG_H
#error Include xorg-config.h when building the X server
#endif

/* Support BigRequests extension */
#define BIGREQS 1

/* Default font path */
/* #define COMPILEDDEFAULTFONTPATH "/usr/pkg/share/fonts/X11/misc/,/usr/pkg/share/fonts/X11/TTF/,/usr/pkg/share/fonts/X11/OTF/,/usr/pkg/share/fonts/X11/Type1/,/usr/pkg/share/fonts/X11/100dpi/,/usr/pkg/share/fonts/X11/75dpi/" */

/* Support Composite Extension */
#define COMPOSITE 1

/* Build DPMS extension */
#define DPMSExtension 1

/* Build DRI3 extension */
#define DRI3 1

/* Build GLX extension */
#define GLXEXT 1

/* Support XDM-AUTH*-1 */
#define HASXDMAUTH 1

/* Support SHM */
#define HAS_SHM 1

/* Define to 1 if you have the `reallocarray' function. */
#define HAVE_REALLOCARRAY 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strcasestr' function. */
#define HAVE_STRCASESTR 1

/* Define to 1 if you have the `strlcat' function. */
#define HAVE_STRLCAT 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP 1

/* Support IPv6 for TCP connections */
#define IPv6 1

/* Support MIT-SHM Extension */
#define MITSHM 1

/* Internal define for Xinerama */
#define PANORAMIX 1

/* Support Present extension */
#if 0
#define PRESENT 1
#endif

/* Support RANDR extension */
#define RANDR 1

/* Support RENDER extension */
#define RENDER 1

/* Support X resource extension */
#define RES 1

/* Support MIT-SCREEN-SAVER extension */
#define SCREENSAVER 1

/* Support SHAPE extension */
#define SHAPE 1

/* Define to 1 on systems derived from System V Release 4 */
/* #undef SVR4 */

/* Support TCP socket connections */
#define TCPCONN 1

/* Support UNIX socket connections */
#define UNIXCONN 1

/* Support XCMisc extension */
#define XCMISC 1

/* Support Xdmcp */
#define XDMCP 1

/* Build XFree86 BigFont extension */
/* #undef XF86BIGFONT */

#if 0
/* Support XFree86 Video Mode extension */
#define XF86VIDMODE 1

/* Build XDGA support */
#define XFreeXDGA 1

/* Support Xinerama extension */
#define XINERAMA 1

/* Support X Input extension */
#define XINPUT 1
#endif

/* XKB default rules */
#define XKB_DFLT_RULES "base"

/* Build DRI extension */
#define XF86DRI 1

/* Build DRI2 extension */
#define DRI2 1

/* Build Xorg server */
#define XORGSERVER 1

/* Current Xorg version */
#define XORG_VERSION_CURRENT ((10000000) + ((21) * 100000) + ((1) * 1000) + 9)

/* Build Xv Extension */
#define XvExtension 1

/* Build XvMC Extension */
#define XvMCExtension 1

/* Support XSync extension */
#define XSYNC 1

/* Support XTest extension */
#define XTEST 1

/* Support Xv Extension */
#define XV 1

/* Vendor name */
#define XVENDORNAME "The X.Org Foundation"

/* BSD-compliant source */
/* #undef _BSD_SOURCE */

/* POSIX-compliant source */
/* #undef _POSIX_SOURCE */

/* X/Open-compliant source */
/* #undef _XOPEN_SOURCE */

/* Vendor web address for support */
#define __VENDORDWEBSUPPORT__ "http://wiki.x.org"

/* Location of configuration file */
#define XCONFIGFILE "xorg.conf"

/* Name of X server */
#define __XSERVERNAME__ "Xorg"

/* Building vgahw module */
#define WITH_VGAHW 1

/* System is BSD-like */
#define CSRG_BASED 1

/* System has PC console */
#define PCCONS_SUPPORT 1

/* System has PCVT console */
#define PCVT_SUPPORT 1

/* System has syscons console */
/* #undef SYSCONS_SUPPORT */

/* System has wscons console */
#define WSCONS_SUPPORT 1

/* Loadable XFree86 server awesomeness */
#if 0
#define XFree86LOADER 1

/* Use libpciaccess */
#define XSERVER_LIBPCIACCESS 1
#endif

/* X Access Control Extension */
#define XACE 1

/* Have X server platform bus support */
/* #undef XSERVER_PLATFORM_BUS */

#ifdef _LP64
#define _XSERVER64 1
#endif

/* Have support for X shared memory fence library (xshmfence) */
#define HAVE_XSHMFENCE 1

/* Use XTrans FD passing support */
#define XTRANS_SEND_FDS 1

/* Ask fontsproto to make font path element names const */
#define FONT_PATH_ELEMENT_NAME_CONST    1

/* byte order */
#if 0
#define X_BYTE_ORDER X_LITTLE_ENDIAN
#endif

#endif /* _XORG_SERVER_H_ */
