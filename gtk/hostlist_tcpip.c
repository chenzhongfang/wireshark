/* hostlist_tcpip.c   2004 Ian Schorr
 * modified from endpoint_talkers_tcpip.c   2003 Ronnie Sahlberg
 *
 * $Id: hostlist_tcpip.c,v 1.2 2004/02/22 18:44:02 ulfl Exp $
 *
 * Ethereal - Network traffic analyzer
 * By Gerald Combs <gerald@ethereal.com>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "epan/packet.h"
#include "tap_menu.h"
#include "../tap.h"
#include "../register.h"
#include "hostlist_table.h"
#include "packet-tcp.h"


static int
tcpip_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, void *vip)
{
	hostlist_table *hosts=(hostlist_table *)pit;
	struct tcpheader *tcphdr=vip;

	/* Take two "add" passes per packet, adding for each direction, ensures that all
	packets are counted properly (even if address is sending to itself) 
	XXX - this could probably be done more efficiently inside hostlist_table */
	add_hostlist_table_data(hosts, &tcphdr->ip_src, tcphdr->th_sport, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_TCP);
	add_hostlist_table_data(hosts, &tcphdr->ip_dst, tcphdr->th_dport, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_TCP);

	return 1;
}



static void
gtk_tcpip_hostlist_init(char *optarg)
{
	char *filter=NULL;

	if(!strncmp(optarg,"conv,tcp,",9)){
		filter=optarg+9;
	} else {
		filter=NULL;
	}

	init_hostlist_table(FALSE, "TCP", "tcp", filter, (void *)tcpip_hostlist_packet);

}


static void
gtk_tcpip_hostlist_cb(GtkWidget *w _U_, gpointer d _U_)
{
	gtk_tcpip_hostlist_init("conv,tcp");
}


void
register_tap_listener_tcpip_hostlist(void)
{
	register_ethereal_tap("conv,tcp", gtk_tcpip_hostlist_init);

	register_tap_menu_item("TCP/Host List (IPv4 & IPv6)", REGISTER_TAP_LAYER_TRANSPORT,
	    gtk_tcpip_hostlist_cb, NULL, NULL, NULL);
}

