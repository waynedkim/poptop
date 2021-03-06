#ifndef _NETINET_DHCP_H
#define _NETINET_DHCP_H

/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_OSREFERENCE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code 
 * as defined in and that are subject to the Apple Public Source License 
 * Version 2.0 (the 'License'). You may not use this file except in 
 * compliance with the License.  The rights granted to you under the 
 * License may not be used to create, or enable the creation or 
 * redistribution of, unlawful or unlicensed copies of an Apple operating 
 * system, or to circumvent, violate, or enable the circumvention or 
 * violation of, any terms of an Apple operating system software license 
 * agreement.
 *
 * Please obtain a copy of the License at 
 * http://www.opensource.apple.com/apsl/ and read it before using this 
 * file.
 *
 * The Original Code and all software distributed under the License are 
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, 
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. 
 * Please see the License for the specific language governing rights and 
 * limitations under the License.
 *
 * @APPLE_LICENSE_OSREFERENCE_HEADER_END@
 */
/*
 * dhcp.h
 * - definitions for DHCP (as specified in RFC2132)
 */
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

struct dhcp {
    char		dp_op;		/* packet opcode type */
    char		dp_htype;	/* hardware addr type */
    char		dp_hlen;	/* hardware addr length */
    char		dp_hops;	/* gateway hops */
    u_int32_t		dp_xid;		/* transaction ID */
    u_int16_t		dp_secs;	/* seconds since boot began */	
    u_int16_t		dp_flags;	/* flags */
    struct in_addr	dp_ciaddr;	/* client IP address */
    struct in_addr	dp_yiaddr;	/* 'your' IP address */
    struct in_addr	dp_siaddr;	/* server IP address */
    struct in_addr	dp_giaddr;	/* gateway IP address */
    char		dp_chaddr[16];	/* client hardware address */
    char		dp_sname[64];	/* server host name */
    char		dp_file[128];	/* boot file name */
    u_int32_t   dp_magic;   /* magic cookie */
    char		dp_options[0];	/* variable-length options field */
};

struct dhcp_packet {
    struct ip 		ip;
    struct udphdr 	udp;
    struct dhcp 	dhcp;
};

/* Values for 'op' field. */
#define DHCP_BOOTREQUEST        1        /* Message sent by DHCP client. */
#define DHCP_BOOTREPLY          2        /* Message sent by DHCP server. */

/* Bits in 'flags' field. */
#define DHCP_FLAGS_BROADCAST    0x8000 /* Server must broadcast all replies. */
#define DHCP_FLAGS_MBZ          0x7fff /* Must be zero. */

/* First four bytes of 'options' field. */
#define DHCP_OPTS_COOKIE 0x63825363

/* dhcp message types */
#define DHCPDISCOVER	1
#define DHCPOFFER	2
#define DHCPREQUEST	3
#define DHCPDECLINE	4
#define DHCPACK		5
#define DHCPNAK		6
#define DHCPRELEASE	7
#define DHCPINFORM	8

#endif /* _NETINET_DHCP_H */

