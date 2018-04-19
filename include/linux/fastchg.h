/*
 * Author: Chad Froebel <chadfroebel@gmail.com>
 *
 * Ported to Note 3 (n9005) and extended : Jean-Pierre Rasquin <yank555.lu@gmail.com>
 *
 * Updated: sunilpaulmathew <sunil.kde@gmail.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */


#ifndef _LINUX_FASTCHG_H
#define _LINUX_FASTCHG_H

#define FAST_CHARGE_VERSION "v2.0"
#define AC_LEVELS  "1000 1100 1200 1300 1400 1500 1600 1700 1800 1900 2000 2100"
#define USB_LEVELS "400 500 600 700 800 900 1000 1100 1200 1300 1400 1500 1600"
#define WIRELESS_LEVELS "600 700 800 900 1000 1100 1200 1300 1400 1500 1600"
#define ANY_LEVELS "0 to 2100"

extern int force_fast_charge;

#define FAST_CHARGE_DISABLED 0
#define FAST_CHARGE_FORCE_AC 1
#define FAST_CHARGE_FORCE_CUSTOM_MA 2	/* default */

extern int use_mtp_during_fast_charge;

#define USE_MTP_DURING_FAST_CHARGE_DISABLED 0
#define USE_MTP_DURING_FAST_CHARGE_ENABLED 1	/* default */

extern int screen_on_current_limit;

#define SCREEN_ON_CURRENT_LIMIT_DISABLED 0
#define SCREEN_ON_CURRENT_LIMIT_ENABLED 1	/* default */

extern int ac_charge_level;

#define AC_CHARGE_1000 1000
#define AC_CHARGE_1100 1100
#define AC_CHARGE_1200 1200
#define AC_CHARGE_1300 1300
#define AC_CHARGE_1400 1400
#define AC_CHARGE_1500 1500
#define AC_CHARGE_1600 1600
#define AC_CHARGE_1700 1700
#define AC_CHARGE_1800 1800	/* default */
#define AC_CHARGE_1900 1900
#define AC_CHARGE_2000 2000
#define AC_CHARGE_2100 2100

extern int usb_charge_level;

#define USB_CHARGE_400 400
#define USB_CHARGE_500 500
#define USB_CHARGE_600 600
#define USB_CHARGE_700 700	/* default */
#define USB_CHARGE_800 800
#define USB_CHARGE_900 900
#define USB_CHARGE_1000 1000
#define USB_CHARGE_1100 1100
#define USB_CHARGE_1200 1200
#define USB_CHARGE_1300 1300
#define USB_CHARGE_1400 1400
#define USB_CHARGE_1500 1500
#define USB_CHARGE_1600 1600

extern int wireless_charge_level;

#define WIRELESS_CHARGE_600 600
#define WIRELESS_CHARGE_700 700
#define WIRELESS_CHARGE_800 800
#define WIRELESS_CHARGE_900 900	/* default */
#define WIRELESS_CHARGE_1000 1000
#define WIRELESS_CHARGE_1100 1100
#define WIRELESS_CHARGE_1200 1200
#define WIRELESS_CHARGE_1300 1300
#define WIRELESS_CHARGE_1400 1400
#define WIRELESS_CHARGE_1500 1500
#define WIRELESS_CHARGE_1600 1600

#define MAX_CHARGE_LEVEL 2100	/* Whatever happens, this is the limit */

extern int failsafe;
#define FAIL_SAFE_ENABLED 1	/* default */
#define FAIL_SAFE_DISABLED 0

#endif
