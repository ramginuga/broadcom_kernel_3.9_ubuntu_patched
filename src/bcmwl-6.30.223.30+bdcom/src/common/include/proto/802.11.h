/*
 * Copyright (C) 2013, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Fundamental types and constants relating to 802.11
 *
 * $Id: 802.11.h 384190 2013-02-09 04:34:23Z $
 */

#ifndef _802_11_H_
#define _802_11_H_

#ifndef _TYPEDEFS_H_
#include <typedefs.h>
#endif

#ifndef _NET_ETHERNET_H_
#include <proto/ethernet.h>
#endif

#include <proto/wpa.h>

#include <packed_section_start.h>

#define DOT11_TU_TO_US			1024	

#define DOT11_A3_HDR_LEN		24	
#define DOT11_A4_HDR_LEN		30	
#define DOT11_MAC_HDR_LEN		DOT11_A3_HDR_LEN	
#define DOT11_FCS_LEN			4	
#define DOT11_ICV_LEN			4	
#define DOT11_ICV_AES_LEN		8	
#define DOT11_QOS_LEN			2	
#define DOT11_HTC_LEN			4	

#define DOT11_KEY_INDEX_SHIFT		6	
#define DOT11_IV_LEN			4	
#define DOT11_IV_TKIP_LEN		8	
#define DOT11_IV_AES_OCB_LEN		4	
#define DOT11_IV_AES_CCM_LEN		8	
#define DOT11_IV_MAX_LEN		8	

#define DOT11_MAX_MPDU_BODY_LEN		2304	

#define DOT11_MAX_MPDU_LEN		(DOT11_A4_HDR_LEN + \
					 DOT11_QOS_LEN + \
					 DOT11_IV_AES_CCM_LEN + \
					 DOT11_MAX_MPDU_BODY_LEN + \
					 DOT11_ICV_LEN + \
					 DOT11_FCS_LEN)	

#define DOT11_MAX_SSID_LEN		32	

#define DOT11_DEFAULT_RTS_LEN		2347	
#define DOT11_MAX_RTS_LEN		2347	

#define DOT11_MIN_FRAG_LEN		256	
#define DOT11_MAX_FRAG_LEN		2346	
#define DOT11_DEFAULT_FRAG_LEN		2346	

#define DOT11_MIN_BEACON_PERIOD		1	
#define DOT11_MAX_BEACON_PERIOD		0xFFFF	

#define DOT11_MIN_DTIM_PERIOD		1	
#define DOT11_MAX_DTIM_PERIOD		0xFF	

#define DOT11_LLC_SNAP_HDR_LEN		8	
#define DOT11_OUI_LEN			3	
BWL_PRE_PACKED_STRUCT struct dot11_llc_snap_header {
	uint8	dsap;				
	uint8	ssap;				
	uint8	ctl;				
	uint8	oui[DOT11_OUI_LEN];		
	uint16	type;				
} BWL_POST_PACKED_STRUCT;

#define RFC1042_HDR_LEN	(ETHER_HDR_LEN + DOT11_LLC_SNAP_HDR_LEN)	

BWL_PRE_PACKED_STRUCT struct dot11_header {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	a1;		
	struct ether_addr	a2;		
	struct ether_addr	a3;		
	uint16			seq;		
	struct ether_addr	a4;		
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_rts_frame {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	ra;		
	struct ether_addr	ta;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_RTS_LEN		16		

BWL_PRE_PACKED_STRUCT struct dot11_cts_frame {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	ra;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_CTS_LEN		10		

BWL_PRE_PACKED_STRUCT struct dot11_ack_frame {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	ra;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_ACK_LEN		10		

BWL_PRE_PACKED_STRUCT struct dot11_ps_poll_frame {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	bssid;		
	struct ether_addr	ta;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_PS_POLL_LEN	16		

BWL_PRE_PACKED_STRUCT struct dot11_cf_end_frame {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	ra;		
	struct ether_addr	bssid;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_CS_END_LEN	16		

BWL_PRE_PACKED_STRUCT struct dot11_action_wifi_vendor_specific {
	uint8	category;
	uint8	OUI[3];
	uint8	type;
	uint8	subtype;
	uint8	data[1040];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_action_wifi_vendor_specific dot11_action_wifi_vendor_specific_t;

BWL_PRE_PACKED_STRUCT struct dot11_action_vs_frmhdr {
	uint8	category;
	uint8	OUI[3];
	uint8	type;
	uint8	subtype;
	uint8	data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_action_vs_frmhdr dot11_action_vs_frmhdr_t;
#define DOT11_ACTION_VS_HDR_LEN	6

#define BCM_ACTION_OUI_BYTE0	0x00
#define BCM_ACTION_OUI_BYTE1	0x90
#define BCM_ACTION_OUI_BYTE2	0x4c

#define DOT11_BA_CTL_POLICY_NORMAL	0x0000	
#define DOT11_BA_CTL_POLICY_NOACK	0x0001	
#define DOT11_BA_CTL_POLICY_MASK	0x0001	

#define DOT11_BA_CTL_MTID		0x0002	
#define DOT11_BA_CTL_COMPRESSED		0x0004	

#define DOT11_BA_CTL_NUMMSDU_MASK	0x0FC0	
#define DOT11_BA_CTL_NUMMSDU_SHIFT	6	

#define DOT11_BA_CTL_TID_MASK		0xF000	
#define DOT11_BA_CTL_TID_SHIFT		12	

BWL_PRE_PACKED_STRUCT struct dot11_ctl_header {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	ra;		
	struct ether_addr	ta;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_CTL_HDR_LEN	16		

BWL_PRE_PACKED_STRUCT struct dot11_bar {
	uint16			bar_control;	
	uint16			seqnum;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_BAR_LEN		4		

#define DOT11_BA_BITMAP_LEN	128		
#define DOT11_BA_CMP_BITMAP_LEN	8		

BWL_PRE_PACKED_STRUCT struct dot11_ba {
	uint16			ba_control;	
	uint16			seqnum;		
	uint8			bitmap[DOT11_BA_BITMAP_LEN];	
} BWL_POST_PACKED_STRUCT;
#define DOT11_BA_LEN		4		

BWL_PRE_PACKED_STRUCT struct dot11_management_header {
	uint16			fc;		
	uint16			durid;		
	struct ether_addr	da;		
	struct ether_addr	sa;		
	struct ether_addr	bssid;		
	uint16			seq;		
} BWL_POST_PACKED_STRUCT;
#define	DOT11_MGMT_HDR_LEN	24		

BWL_PRE_PACKED_STRUCT struct dot11_bcn_prb {
	uint32			timestamp[2];
	uint16			beacon_interval;
	uint16			capability;
} BWL_POST_PACKED_STRUCT;
#define	DOT11_BCN_PRB_LEN	12		
#define	DOT11_BCN_PRB_FIXED_LEN	12		

BWL_PRE_PACKED_STRUCT struct dot11_auth {
	uint16			alg;		
	uint16			seq;		
	uint16			status;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_AUTH_FIXED_LEN	6		

BWL_PRE_PACKED_STRUCT struct dot11_assoc_req {
	uint16			capability;	
	uint16			listen;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_ASSOC_REQ_FIXED_LEN	4	

BWL_PRE_PACKED_STRUCT struct dot11_reassoc_req {
	uint16			capability;	
	uint16			listen;		
	struct ether_addr	ap;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_REASSOC_REQ_FIXED_LEN	10	

BWL_PRE_PACKED_STRUCT struct dot11_assoc_resp {
	uint16			capability;	
	uint16			status;		
	uint16			aid;		
} BWL_POST_PACKED_STRUCT;
#define DOT11_ASSOC_RESP_FIXED_LEN	6	

BWL_PRE_PACKED_STRUCT struct dot11_action_measure {
	uint8	category;
	uint8	action;
	uint8	token;
	uint8	data[1];
} BWL_POST_PACKED_STRUCT;
#define DOT11_ACTION_MEASURE_LEN	3	

BWL_PRE_PACKED_STRUCT struct dot11_action_ht_ch_width {
	uint8	category;
	uint8	action;
	uint8	ch_width;
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_action_ht_mimops {
	uint8	category;
	uint8	action;
	uint8	control;
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_action_sa_query {
	uint8	category;
	uint8	action;
	uint16	id;
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_action_vht_oper_mode {
	uint8	category;
	uint8	action;
	uint8	mode;
} BWL_POST_PACKED_STRUCT;

#define SM_PWRSAVE_ENABLE	1
#define SM_PWRSAVE_MODE		2

BWL_PRE_PACKED_STRUCT struct dot11_power_cnst {
	uint8 id;
	uint8 len;
	uint8 power;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_power_cnst dot11_power_cnst_t;

BWL_PRE_PACKED_STRUCT struct dot11_power_cap {
	uint8 min;
	uint8 max;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_power_cap dot11_power_cap_t;

BWL_PRE_PACKED_STRUCT struct dot11_tpc_rep {
	uint8 id;
	uint8 len;
	uint8 tx_pwr;
	uint8 margin;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tpc_rep dot11_tpc_rep_t;
#define DOT11_MNG_IE_TPC_REPORT_LEN	2 	

BWL_PRE_PACKED_STRUCT struct dot11_supp_channels {
	uint8 id;
	uint8 len;
	uint8 first_channel;
	uint8 num_channels;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_supp_channels dot11_supp_channels_t;

BWL_PRE_PACKED_STRUCT struct dot11_extch {
	uint8	id;		
	uint8	len;		
	uint8	extch;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_extch dot11_extch_ie_t;

BWL_PRE_PACKED_STRUCT struct dot11_brcm_extch {
	uint8	id;		
	uint8	len;		
	uint8	oui[3];		
	uint8	type;           
	uint8	extch;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_brcm_extch dot11_brcm_extch_ie_t;

#define BRCM_EXTCH_IE_LEN	5
#define BRCM_EXTCH_IE_TYPE	53	
#define DOT11_EXTCH_IE_LEN	1
#define DOT11_EXT_CH_MASK	0x03	
#define DOT11_EXT_CH_UPPER	0x01	
#define DOT11_EXT_CH_LOWER	0x03	
#define DOT11_EXT_CH_NONE	0x00	

BWL_PRE_PACKED_STRUCT struct dot11_action_frmhdr {
	uint8	category;
	uint8	action;
	uint8	data[1];
} BWL_POST_PACKED_STRUCT;
#define DOT11_ACTION_FRMHDR_LEN	2

BWL_PRE_PACKED_STRUCT struct dot11_channel_switch {
	uint8 id;	
	uint8 len;	
	uint8 mode;	
	uint8 channel;	
	uint8 count;	
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_channel_switch dot11_chan_switch_ie_t;

#define DOT11_SWITCH_IE_LEN	3	

#define DOT11_CSA_MODE_ADVISORY		0	
#define DOT11_CSA_MODE_NO_TX		1	

BWL_PRE_PACKED_STRUCT struct dot11_action_switch_channel {
	uint8	category;
	uint8	action;
	dot11_chan_switch_ie_t chan_switch_ie;	
	dot11_brcm_extch_ie_t extch_ie;		
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_csa_body {
	uint8 mode;	
	uint8 reg;	
	uint8 channel;	
	uint8 count;	
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_ext_csa {
	uint8 id;	
	uint8 len;	
	struct dot11_csa_body b;	
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ext_csa dot11_ext_csa_ie_t;
#define DOT11_EXT_CSA_IE_LEN	4	

BWL_PRE_PACKED_STRUCT struct dot11_action_ext_csa {
	uint8	category;
	uint8	action;
	dot11_ext_csa_ie_t chan_switch_ie;	
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11y_action_ext_csa {
	uint8	category;
	uint8	action;
	struct dot11_csa_body b;	
} BWL_POST_PACKED_STRUCT;

BWL_PRE_PACKED_STRUCT struct dot11_wide_bw_channel_switch {
	uint8 id;				
	uint8 len;				
	uint8 channel_width;			
	uint8 center_frequency_segment_0;	
	uint8 center_frequency_segment_1;	
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wide_bw_channel_switch dot11_wide_bw_chan_switch_ie_t;

#define DOT11_WIDE_BW_SWITCH_IE_LEN     3       

BWL_PRE_PACKED_STRUCT struct dot11_channel_switch_wrapper {
	uint8 id;				
	uint8 len;				
	dot11_wide_bw_chan_switch_ie_t wb_chan_switch_ie;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_channel_switch_wrapper dot11_chan_switch_wrapper_ie_t;

BWL_PRE_PACKED_STRUCT struct dot11_vht_transmit_power_envelope {
	uint8 id;				
	uint8 len;				
	uint8 transmit_power_info;
	uint8 local_max_transmit_power_20;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_vht_transmit_power_envelope dot11_vht_transmit_power_envelope_ie_t;

BWL_PRE_PACKED_STRUCT struct dot11_obss_coex {
	uint8	id;
	uint8	len;
	uint8	info;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_obss_coex dot11_obss_coex_t;
#define DOT11_OBSS_COEXINFO_LEN	1	

#define	DOT11_OBSS_COEX_INFO_REQ		0x01
#define	DOT11_OBSS_COEX_40MHZ_INTOLERANT	0x02
#define	DOT11_OBSS_COEX_20MHZ_WIDTH_REQ	0x04

BWL_PRE_PACKED_STRUCT struct dot11_obss_chanlist {
	uint8	id;
	uint8	len;
	uint8	regclass;
	uint8	chanlist[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_obss_chanlist dot11_obss_chanlist_t;
#define DOT11_OBSS_CHANLIST_FIXED_LEN	1	

BWL_PRE_PACKED_STRUCT struct dot11_extcap_ie {
	uint8 id;
	uint8 len;
	uint8 cap[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_extcap_ie dot11_extcap_ie_t;

#define DOT11_EXTCAP_LEN_MAX	8
#define DOT11_EXTCAP_LEN_COEX	1
#define DOT11_EXTCAP_LEN_BT	3
#define DOT11_EXTCAP_LEN_IW	4
#define DOT11_EXTCAP_LEN_SI	6

#define DOT11_EXTCAP_LEN_TDLS	5
#define DOT11_11AC_EXTCAP_LEN_TDLS	8

#define DOT11_EXTCAP_LEN_FMS			2
#define DOT11_EXTCAP_LEN_PROXY_ARP		2
#define DOT11_EXTCAP_LEN_TFS			3
#define DOT11_EXTCAP_LEN_WNM_SLEEP		3
#define DOT11_EXTCAP_LEN_TIMBC			3
#define DOT11_EXTCAP_LEN_BSS_TRANSITION		3
#define DOT11_EXTCAP_LEN_DMS			4
#define DOT11_EXTCAP_LEN_WNM_NOTIFICATION	6
#define DOT11_EXTCAP_LEN_TDLS_WBW		8
#define DOT11_EXTCAP_LEN_OPMODE_NOTIFICATION	8

BWL_PRE_PACKED_STRUCT struct dot11_extcap {
	uint8 extcap[DOT11_EXTCAP_LEN_MAX];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_extcap dot11_extcap_t;

#define DOT11_TDLS_CAP_TDLS			37		
#define DOT11_TDLS_CAP_PU_BUFFER_STA	28		
#define DOT11_TDLS_CAP_PEER_PSM		20		
#define DOT11_TDLS_CAP_CH_SW			30		
#define DOT11_TDLS_CAP_PROH			38		
#define DOT11_TDLS_CAP_CH_SW_PROH		39		
#define DOT11_TDLS_CAP_TDLS_WIDER_BW	61	

#define DOT11_MEASURE_TYPE_BASIC 	0	
#define DOT11_MEASURE_TYPE_CCA 		1	
#define DOT11_MEASURE_TYPE_RPI		2	
#define DOT11_MEASURE_TYPE_CHLOAD		3	
#define DOT11_MEASURE_TYPE_NOISE		4	
#define DOT11_MEASURE_TYPE_BEACON		5	
#define DOT11_MEASURE_TYPE_FRAME	6	
#define DOT11_MEASURE_TYPE_STAT		7	
#define DOT11_MEASURE_TYPE_LCI		8	
#define DOT11_MEASURE_TYPE_TXSTREAM		9	
#define DOT11_MEASURE_TYPE_PAUSE		255	

#define DOT11_MEASURE_MODE_PARALLEL 	(1<<0)	
#define DOT11_MEASURE_MODE_ENABLE 	(1<<1)	
#define DOT11_MEASURE_MODE_REQUEST	(1<<2)	
#define DOT11_MEASURE_MODE_REPORT 	(1<<3)	
#define DOT11_MEASURE_MODE_DUR 	(1<<4)	

#define DOT11_MEASURE_MODE_LATE 	(1<<0)	
#define DOT11_MEASURE_MODE_INCAPABLE	(1<<1)	
#define DOT11_MEASURE_MODE_REFUSED	(1<<2)	

#define DOT11_MEASURE_BASIC_MAP_BSS	((uint8)(1<<0))	
#define DOT11_MEASURE_BASIC_MAP_OFDM	((uint8)(1<<1))	
#define DOT11_MEASURE_BASIC_MAP_UKNOWN	((uint8)(1<<2))	
#define DOT11_MEASURE_BASIC_MAP_RADAR	((uint8)(1<<3))	
#define DOT11_MEASURE_BASIC_MAP_UNMEAS	((uint8)(1<<4))	

BWL_PRE_PACKED_STRUCT struct dot11_meas_req {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint8 channel;
	uint8 start_time[8];
	uint16 duration;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_meas_req dot11_meas_req_t;
#define DOT11_MNG_IE_MREQ_LEN 14	

#define DOT11_MNG_IE_MREQ_FIXED_LEN 3	

BWL_PRE_PACKED_STRUCT struct dot11_meas_rep {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	BWL_PRE_PACKED_STRUCT union
	{
		BWL_PRE_PACKED_STRUCT struct {
			uint8 channel;
			uint8 start_time[8];
			uint16 duration;
			uint8 map;
		} BWL_POST_PACKED_STRUCT basic;
		uint8 data[1];
	} BWL_POST_PACKED_STRUCT rep;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_meas_rep dot11_meas_rep_t;

#define DOT11_MNG_IE_MREP_FIXED_LEN	3	

BWL_PRE_PACKED_STRUCT struct dot11_meas_rep_basic {
	uint8 channel;
	uint8 start_time[8];
	uint16 duration;
	uint8 map;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_meas_rep_basic dot11_meas_rep_basic_t;
#define DOT11_MEASURE_BASIC_REP_LEN	12	

BWL_PRE_PACKED_STRUCT struct dot11_quiet {
	uint8 id;
	uint8 len;
	uint8 count;	
	uint8 period;	
	uint16 duration;	
	uint16 offset;	
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_quiet dot11_quiet_t;

BWL_PRE_PACKED_STRUCT struct chan_map_tuple {
	uint8 channel;
	uint8 map;
} BWL_POST_PACKED_STRUCT;
typedef struct chan_map_tuple chan_map_tuple_t;

BWL_PRE_PACKED_STRUCT struct dot11_ibss_dfs {
	uint8 id;
	uint8 len;
	uint8 eaddr[ETHER_ADDR_LEN];
	uint8 interval;
	chan_map_tuple_t map[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ibss_dfs dot11_ibss_dfs_t;

#define WME_OUI			"\x00\x50\xf2"	
#define WME_OUI_LEN		3
#define WME_OUI_TYPE		2	
#define WME_TYPE		2	
#define WME_SUBTYPE_IE		0	
#define WME_SUBTYPE_PARAM_IE	1	
#define WME_SUBTYPE_TSPEC	2	
#define WME_VER			1	

#define AC_BE			0	
#define AC_BK			1	
#define AC_VI			2	
#define AC_VO			3	
#define AC_COUNT		4	

typedef uint8 ac_bitmap_t;	

#define AC_BITMAP_NONE		0x0	
#define AC_BITMAP_ALL		0xf	
#define AC_BITMAP_TST(ab, ac)	(((ab) & (1 << (ac))) != 0)
#define AC_BITMAP_SET(ab, ac)	(((ab) |= (1 << (ac))))
#define AC_BITMAP_RESET(ab, ac) (((ab) &= ~(1 << (ac))))

BWL_PRE_PACKED_STRUCT struct wme_ie {
	uint8 oui[3];
	uint8 type;
	uint8 subtype;
	uint8 version;
	uint8 qosinfo;
} BWL_POST_PACKED_STRUCT;
typedef struct wme_ie wme_ie_t;
#define WME_IE_LEN 7	

BWL_PRE_PACKED_STRUCT struct edcf_acparam {
	uint8	ACI;
	uint8	ECW;
	uint16  TXOP;		
} BWL_POST_PACKED_STRUCT;
typedef struct edcf_acparam edcf_acparam_t;

BWL_PRE_PACKED_STRUCT struct wme_param_ie {
	uint8 oui[3];
	uint8 type;
	uint8 subtype;
	uint8 version;
	uint8 qosinfo;
	uint8 rsvd;
	edcf_acparam_t acparam[AC_COUNT];
} BWL_POST_PACKED_STRUCT;
typedef struct wme_param_ie wme_param_ie_t;
#define WME_PARAM_IE_LEN            24          

#define WME_QI_AP_APSD_MASK         0x80        
#define WME_QI_AP_APSD_SHIFT        7           
#define WME_QI_AP_COUNT_MASK        0x0f        
#define WME_QI_AP_COUNT_SHIFT       0           

#define WME_QI_STA_MAXSPLEN_MASK    0x60        
#define WME_QI_STA_MAXSPLEN_SHIFT   5           
#define WME_QI_STA_APSD_ALL_MASK    0xf         
#define WME_QI_STA_APSD_ALL_SHIFT   0           
#define WME_QI_STA_APSD_BE_MASK     0x8         
#define WME_QI_STA_APSD_BE_SHIFT    3           
#define WME_QI_STA_APSD_BK_MASK     0x4         
#define WME_QI_STA_APSD_BK_SHIFT    2           
#define WME_QI_STA_APSD_VI_MASK     0x2         
#define WME_QI_STA_APSD_VI_SHIFT    1           
#define WME_QI_STA_APSD_VO_MASK     0x1         
#define WME_QI_STA_APSD_VO_SHIFT    0           

#define EDCF_AIFSN_MIN               1           
#define EDCF_AIFSN_MAX               15          
#define EDCF_AIFSN_MASK              0x0f        
#define EDCF_ACM_MASK                0x10        
#define EDCF_ACI_MASK                0x60        
#define EDCF_ACI_SHIFT               5           
#define EDCF_AIFSN_SHIFT             12          

#define EDCF_ECW_MIN                 0           
#define EDCF_ECW_MAX                 15          
#define EDCF_ECW2CW(exp)             ((1 << (exp)) - 1)
#define EDCF_ECWMIN_MASK             0x0f        
#define EDCF_ECWMAX_MASK             0xf0        
#define EDCF_ECWMAX_SHIFT            4           

#define EDCF_TXOP_MIN                0           
#define EDCF_TXOP_MAX                65535       
#define EDCF_TXOP2USEC(txop)         ((txop) << 5)

#define NON_EDCF_AC_BE_ACI_STA          0x02

#define EDCF_AC_BE_ACI_STA           0x03	
#define EDCF_AC_BE_ECW_STA           0xA4	
#define EDCF_AC_BE_TXOP_STA          0x0000	
#define EDCF_AC_BK_ACI_STA           0x27	
#define EDCF_AC_BK_ECW_STA           0xA4	
#define EDCF_AC_BK_TXOP_STA          0x0000	
#define EDCF_AC_VI_ACI_STA           0x42	
#define EDCF_AC_VI_ECW_STA           0x43	
#define EDCF_AC_VI_TXOP_STA          0x005e	
#define EDCF_AC_VO_ACI_STA           0x62	
#define EDCF_AC_VO_ECW_STA           0x32	
#define EDCF_AC_VO_TXOP_STA          0x002f	

#define EDCF_AC_BE_ACI_AP            0x03	
#define EDCF_AC_BE_ECW_AP            0x64	
#define EDCF_AC_BE_TXOP_AP           0x0000	
#define EDCF_AC_BK_ACI_AP            0x27	
#define EDCF_AC_BK_ECW_AP            0xA4	
#define EDCF_AC_BK_TXOP_AP           0x0000	
#define EDCF_AC_VI_ACI_AP            0x41	
#define EDCF_AC_VI_ECW_AP            0x43	
#define EDCF_AC_VI_TXOP_AP           0x005e	
#define EDCF_AC_VO_ACI_AP            0x61	
#define EDCF_AC_VO_ECW_AP            0x32	
#define EDCF_AC_VO_TXOP_AP           0x002f	

BWL_PRE_PACKED_STRUCT struct edca_param_ie {
	uint8 qosinfo;
	uint8 rsvd;
	edcf_acparam_t acparam[AC_COUNT];
} BWL_POST_PACKED_STRUCT;
typedef struct edca_param_ie edca_param_ie_t;
#define EDCA_PARAM_IE_LEN            18          

BWL_PRE_PACKED_STRUCT struct qos_cap_ie {
	uint8 qosinfo;
} BWL_POST_PACKED_STRUCT;
typedef struct qos_cap_ie qos_cap_ie_t;

BWL_PRE_PACKED_STRUCT struct dot11_qbss_load_ie {
	uint8 id; 			
	uint8 length;
	uint16 station_count; 		
	uint8 channel_utilization;	
	uint16 aac; 			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_qbss_load_ie dot11_qbss_load_ie_t;
#define BSS_LOAD_IE_SIZE 	7	

#define FIXED_MSDU_SIZE 0x8000		
#define MSDU_SIZE_MASK	0x7fff		

#define	INTEGER_SHIFT	13	
#define FRACTION_MASK	0x1FFF	

BWL_PRE_PACKED_STRUCT struct dot11_management_notification {
	uint8 category;			
	uint8 action;
	uint8 token;
	uint8 status;
	uint8 data[1];			
} BWL_POST_PACKED_STRUCT;
#define DOT11_MGMT_NOTIFICATION_LEN 4	

BWL_PRE_PACKED_STRUCT struct ti_ie {
	uint8 ti_type;
	uint32 ti_val;
} BWL_POST_PACKED_STRUCT;
typedef struct ti_ie ti_ie_t;
#define TI_TYPE_REASSOC_DEADLINE	1
#define TI_TYPE_KEY_LIFETIME		2

#define WME_ADDTS_REQUEST	0	
#define WME_ADDTS_RESPONSE	1	
#define WME_DELTS_REQUEST	2	

#define WME_ADMISSION_ACCEPTED		0	
#define WME_INVALID_PARAMETERS		1	
#define WME_ADMISSION_REFUSED		3	

#define BCN_PRB_SSID(body) ((char*)(body) + DOT11_BCN_PRB_LEN)

#define DOT11_OPEN_SYSTEM	0	
#define DOT11_SHARED_KEY	1	
#define DOT11_FAST_BSS		2	
#define DOT11_CHALLENGE_LEN	128	

#define FC_PVER_MASK		0x3	
#define FC_PVER_SHIFT		0	
#define FC_TYPE_MASK		0xC	
#define FC_TYPE_SHIFT		2	
#define FC_SUBTYPE_MASK		0xF0	
#define FC_SUBTYPE_SHIFT	4	
#define FC_TODS			0x100	
#define FC_TODS_SHIFT		8	
#define FC_FROMDS		0x200	
#define FC_FROMDS_SHIFT		9	
#define FC_MOREFRAG		0x400	
#define FC_MOREFRAG_SHIFT	10	
#define FC_RETRY		0x800	
#define FC_RETRY_SHIFT		11	
#define FC_PM			0x1000	
#define FC_PM_SHIFT		12	
#define FC_MOREDATA		0x2000	
#define FC_MOREDATA_SHIFT	13	
#define FC_WEP			0x4000	
#define FC_WEP_SHIFT		14	
#define FC_ORDER		0x8000	
#define FC_ORDER_SHIFT		15	

#define SEQNUM_SHIFT		4	
#define SEQNUM_MAX		0x1000	
#define FRAGNUM_MASK		0xF	

#define FC_TYPE_MNG		0	
#define FC_TYPE_CTL		1	
#define FC_TYPE_DATA		2	

#define FC_SUBTYPE_ASSOC_REQ		0	
#define FC_SUBTYPE_ASSOC_RESP		1	
#define FC_SUBTYPE_REASSOC_REQ		2	
#define FC_SUBTYPE_REASSOC_RESP		3	
#define FC_SUBTYPE_PROBE_REQ		4	
#define FC_SUBTYPE_PROBE_RESP		5	
#define FC_SUBTYPE_BEACON		8	
#define FC_SUBTYPE_ATIM			9	
#define FC_SUBTYPE_DISASSOC		10	
#define FC_SUBTYPE_AUTH			11	
#define FC_SUBTYPE_DEAUTH		12	
#define FC_SUBTYPE_ACTION		13	
#define FC_SUBTYPE_ACTION_NOACK		14	

#define FC_SUBTYPE_CTL_WRAPPER		7	
#define FC_SUBTYPE_BLOCKACK_REQ		8	
#define FC_SUBTYPE_BLOCKACK		9	
#define FC_SUBTYPE_PS_POLL		10	
#define FC_SUBTYPE_RTS			11	
#define FC_SUBTYPE_CTS			12	
#define FC_SUBTYPE_ACK			13	
#define FC_SUBTYPE_CF_END		14	
#define FC_SUBTYPE_CF_END_ACK		15	

#define FC_SUBTYPE_DATA			0	
#define FC_SUBTYPE_DATA_CF_ACK		1	
#define FC_SUBTYPE_DATA_CF_POLL		2	
#define FC_SUBTYPE_DATA_CF_ACK_POLL	3	
#define FC_SUBTYPE_NULL			4	
#define FC_SUBTYPE_CF_ACK		5	
#define FC_SUBTYPE_CF_POLL		6	
#define FC_SUBTYPE_CF_ACK_POLL		7	
#define FC_SUBTYPE_QOS_DATA		8	
#define FC_SUBTYPE_QOS_DATA_CF_ACK	9	
#define FC_SUBTYPE_QOS_DATA_CF_POLL	10	
#define FC_SUBTYPE_QOS_DATA_CF_ACK_POLL	11	
#define FC_SUBTYPE_QOS_NULL		12	
#define FC_SUBTYPE_QOS_CF_POLL		14	
#define FC_SUBTYPE_QOS_CF_ACK_POLL	15	

#define FC_SUBTYPE_ANY_QOS(s)		(((s) & 8) != 0)
#define FC_SUBTYPE_ANY_NULL(s)		(((s) & 4) != 0)
#define FC_SUBTYPE_ANY_CF_POLL(s)	(((s) & 2) != 0)
#define FC_SUBTYPE_ANY_CF_ACK(s)	(((s) & 1) != 0)

#define FC_KIND_MASK		(FC_TYPE_MASK | FC_SUBTYPE_MASK)	

#define FC_KIND(t, s)	(((t) << FC_TYPE_SHIFT) | ((s) << FC_SUBTYPE_SHIFT))	

#define FC_SUBTYPE(fc)	(((fc) & FC_SUBTYPE_MASK) >> FC_SUBTYPE_SHIFT)	
#define FC_TYPE(fc)	(((fc) & FC_TYPE_MASK) >> FC_TYPE_SHIFT)	

#define FC_ASSOC_REQ	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_ASSOC_REQ)	
#define FC_ASSOC_RESP	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_ASSOC_RESP)	
#define FC_REASSOC_REQ	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_REASSOC_REQ)	
#define FC_REASSOC_RESP	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_REASSOC_RESP)	
#define FC_PROBE_REQ	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_PROBE_REQ)	
#define FC_PROBE_RESP	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_PROBE_RESP)	
#define FC_BEACON	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_BEACON)		
#define FC_DISASSOC	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_DISASSOC)	
#define FC_AUTH		FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_AUTH)		
#define FC_DEAUTH	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_DEAUTH)		
#define FC_ACTION	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_ACTION)		
#define FC_ACTION_NOACK	FC_KIND(FC_TYPE_MNG, FC_SUBTYPE_ACTION_NOACK)	

#define FC_CTL_WRAPPER	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_CTL_WRAPPER)	
#define FC_BLOCKACK_REQ	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_BLOCKACK_REQ)	
#define FC_BLOCKACK	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_BLOCKACK)	
#define FC_PS_POLL	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_PS_POLL)	
#define FC_RTS		FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_RTS)		
#define FC_CTS		FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_CTS)		
#define FC_ACK		FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_ACK)		
#define FC_CF_END	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_CF_END)		
#define FC_CF_END_ACK	FC_KIND(FC_TYPE_CTL, FC_SUBTYPE_CF_END_ACK)	

#define FC_DATA		FC_KIND(FC_TYPE_DATA, FC_SUBTYPE_DATA)		
#define FC_NULL_DATA	FC_KIND(FC_TYPE_DATA, FC_SUBTYPE_NULL)		
#define FC_DATA_CF_ACK	FC_KIND(FC_TYPE_DATA, FC_SUBTYPE_DATA_CF_ACK)	
#define FC_QOS_DATA	FC_KIND(FC_TYPE_DATA, FC_SUBTYPE_QOS_DATA)	
#define FC_QOS_NULL	FC_KIND(FC_TYPE_DATA, FC_SUBTYPE_QOS_NULL)	

#define QOS_PRIO_SHIFT		0	
#define QOS_PRIO_MASK		0x0007	
#define QOS_PRIO(qos)		(((qos) & QOS_PRIO_MASK) >> QOS_PRIO_SHIFT)	

#define QOS_TID_SHIFT		0	
#define QOS_TID_MASK		0x000f	
#define QOS_TID(qos)		(((qos) & QOS_TID_MASK) >> QOS_TID_SHIFT)	

#define QOS_EOSP_SHIFT		4	
#define QOS_EOSP_MASK		0x0010	
#define QOS_EOSP(qos)		(((qos) & QOS_EOSP_MASK) >> QOS_EOSP_SHIFT)	

#define QOS_ACK_NORMAL_ACK	0	
#define QOS_ACK_NO_ACK		1	
#define QOS_ACK_NO_EXP_ACK	2	
#define QOS_ACK_BLOCK_ACK	3	
#define QOS_ACK_SHIFT		5	
#define QOS_ACK_MASK		0x0060	
#define QOS_ACK(qos)		(((qos) & QOS_ACK_MASK) >> QOS_ACK_SHIFT)	

#define QOS_AMSDU_SHIFT		7	
#define QOS_AMSDU_MASK		0x0080	

#define DOT11_MNG_AUTH_ALGO_LEN		2	
#define DOT11_MNG_AUTH_SEQ_LEN		2	
#define DOT11_MNG_BEACON_INT_LEN	2	
#define DOT11_MNG_CAP_LEN		2	
#define DOT11_MNG_AP_ADDR_LEN		6	
#define DOT11_MNG_LISTEN_INT_LEN	2	
#define DOT11_MNG_REASON_LEN		2	
#define DOT11_MNG_AID_LEN		2	
#define DOT11_MNG_STATUS_LEN		2	
#define DOT11_MNG_TIMESTAMP_LEN		8	

#define DOT11_AID_MASK			0x3fff	

#define DOT11_RC_RESERVED		0	
#define DOT11_RC_UNSPECIFIED		1	
#define DOT11_RC_AUTH_INVAL		2	
#define DOT11_RC_DEAUTH_LEAVING		3	
#define DOT11_RC_INACTIVITY		4	
#define DOT11_RC_BUSY			5	
#define DOT11_RC_INVAL_CLASS_2		6	
#define DOT11_RC_INVAL_CLASS_3		7	
#define DOT11_RC_DISASSOC_LEAVING	8	
#define DOT11_RC_NOT_AUTH		9	
#define DOT11_RC_BAD_PC			10	
#define DOT11_RC_BAD_CHANNELS		11	

#define DOT11_RC_UNSPECIFIED_QOS	32	
#define DOT11_RC_INSUFFCIENT_BW		33	
#define DOT11_RC_EXCESSIVE_FRAMES	34	
#define DOT11_RC_TX_OUTSIDE_TXOP	35	
#define DOT11_RC_LEAVING_QBSS		36	
#define DOT11_RC_BAD_MECHANISM		37	
#define DOT11_RC_SETUP_NEEDED		38	
#define DOT11_RC_TIMEOUT		39	

#define DOT11_RC_MAX			23	

#define DOT11_RC_TDLS_PEER_UNREACH	25
#define DOT11_RC_TDLS_DOWN_UNSPECIFIED	26

#define DOT11_SC_SUCCESS		0	
#define DOT11_SC_FAILURE		1	
#define DOT11_SC_TDLS_WAKEUP_SCH_ALT 2	

#define DOT11_SC_TDLS_WAKEUP_SCH_REJ 3	
#define DOT11_SC_TDLS_SEC_DISABLED	5	
#define DOT11_SC_LIFETIME_REJ		6	
#define DOT11_SC_NOT_SAME_BSS		7	
#define DOT11_SC_CAP_MISMATCH		10	
#define DOT11_SC_REASSOC_FAIL		11	
#define DOT11_SC_ASSOC_FAIL		12	
#define DOT11_SC_AUTH_MISMATCH		13	
#define DOT11_SC_AUTH_SEQ		14	
#define DOT11_SC_AUTH_CHALLENGE_FAIL	15	
#define DOT11_SC_AUTH_TIMEOUT		16	
#define DOT11_SC_ASSOC_BUSY_FAIL	17	
#define DOT11_SC_ASSOC_RATE_MISMATCH	18	
#define DOT11_SC_ASSOC_SHORT_REQUIRED	19	
#define DOT11_SC_ASSOC_PBCC_REQUIRED	20	
#define DOT11_SC_ASSOC_AGILITY_REQUIRED	21	
#define DOT11_SC_ASSOC_SPECTRUM_REQUIRED	22	
#define DOT11_SC_ASSOC_BAD_POWER_CAP	23	
#define DOT11_SC_ASSOC_BAD_SUP_CHANNELS	24	
#define DOT11_SC_ASSOC_SHORTSLOT_REQUIRED	25	
#define DOT11_SC_ASSOC_ERPBCC_REQUIRED	26	
#define DOT11_SC_ASSOC_DSSOFDM_REQUIRED	27	
#define DOT11_SC_ASSOC_R0KH_UNREACHABLE	28	
#define DOT11_SC_ASSOC_TRY_LATER	30	
#define DOT11_SC_ASSOC_MFP_VIOLATION	31	

#define	DOT11_SC_DECLINED		37	
#define	DOT11_SC_INVALID_PARAMS		38	
#define DOT11_SC_INVALID_PAIRWISE_CIPHER	42 
#define	DOT11_SC_INVALID_AKMP		43	
#define DOT11_SC_INVALID_RSNIE_CAP	45	
#define DOT11_SC_DLS_NOT_ALLOWED	48	
#define	DOT11_SC_INVALID_PMKID		53	
#define	DOT11_SC_INVALID_MDID		54	
#define	DOT11_SC_INVALID_FTIE		55	

#define DOT11_SC_ADV_PROTO_NOT_SUPPORTED	59	
#define DOT11_SC_NO_OUTSTAND_REQ			60	
#define DOT11_SC_RSP_NOT_RX_FROM_SERVER		61	
#define DOT11_SC_TIMEOUT					62	
#define DOT11_SC_QUERY_RSP_TOO_LARGE		63	
#define DOT11_SC_SERVER_UNREACHABLE			65	

#define DOT11_SC_UNEXP_MSG			70	
#define DOT11_SC_INVALID_SNONCE		71	
#define DOT11_SC_INVALID_RSNIE		72	

#define DOT11_SC_TRANSMIT_FAILURE	79	

#define DOT11_MNG_DS_PARAM_LEN			1	
#define DOT11_MNG_IBSS_PARAM_LEN		2	

#define DOT11_MNG_TIM_FIXED_LEN			3	
#define DOT11_MNG_TIM_DTIM_COUNT		0	
#define DOT11_MNG_TIM_DTIM_PERIOD		1	
#define DOT11_MNG_TIM_BITMAP_CTL		2	
#define DOT11_MNG_TIM_PVB			3	

#define TLV_TAG_OFF		0	
#define TLV_LEN_OFF		1	
#define TLV_HDR_LEN		2	
#define TLV_BODY_OFF		2	

#define DOT11_MNG_SSID_ID			0	
#define DOT11_MNG_RATES_ID			1	
#define DOT11_MNG_FH_PARMS_ID			2	
#define DOT11_MNG_DS_PARMS_ID			3	
#define DOT11_MNG_CF_PARMS_ID			4	
#define DOT11_MNG_TIM_ID			5	
#define DOT11_MNG_IBSS_PARMS_ID			6	
#define DOT11_MNG_COUNTRY_ID			7	
#define DOT11_MNG_HOPPING_PARMS_ID		8	
#define DOT11_MNG_HOPPING_TABLE_ID		9	
#define DOT11_MNG_REQUEST_ID			10	
#define DOT11_MNG_QBSS_LOAD_ID 			11	
#define DOT11_MNG_EDCA_PARAM_ID			12	
#define DOT11_MNG_TSPEC_ID			13	
#define DOT11_MNG_TCLAS_ID			14	
#define DOT11_MNG_CHALLENGE_ID			16	
#define DOT11_MNG_PWR_CONSTRAINT_ID		32	
#define DOT11_MNG_PWR_CAP_ID			33	
#define DOT11_MNG_TPC_REQUEST_ID 		34	
#define DOT11_MNG_TPC_REPORT_ID			35	
#define DOT11_MNG_SUPP_CHANNELS_ID		36	
#define DOT11_MNG_CHANNEL_SWITCH_ID		37	
#define DOT11_MNG_MEASURE_REQUEST_ID		38	
#define DOT11_MNG_MEASURE_REPORT_ID		39	
#define DOT11_MNG_QUIET_ID			40	
#define DOT11_MNG_IBSS_DFS_ID			41	
#define DOT11_MNG_ERP_ID			42	
#define DOT11_MNG_TS_DELAY_ID			43	
#define DOT11_MNG_TCLAS_PROC_ID			44	
#define	DOT11_MNG_HT_CAP			45	
#define DOT11_MNG_QOS_CAP_ID			46	
#define DOT11_MNG_NONERP_ID			47	
#define DOT11_MNG_RSN_ID			48	
#define DOT11_MNG_EXT_RATES_ID			50	
#define DOT11_MNG_AP_CHREP_ID		51	
#define DOT11_MNG_NBR_REP_ID		52	
#define DOT11_MNG_RCPI_ID		53	
#define DOT11_MNG_MDIE_ID		54	
#define DOT11_MNG_FTIE_ID		55	
#define DOT11_MNG_FT_TI_ID		56	
#define DOT11_MNG_RDE_ID			57	
#define	DOT11_MNG_REGCLASS_ID			59	
#define DOT11_MNG_EXT_CSA_ID			60	
#define	DOT11_MNG_HT_ADD			61	
#define	DOT11_MNG_EXT_CHANNEL_OFFSET		62	
#define DOT11_MNG_BSS_AVR_ACCESS_DELAY_ID	63	
#define DOT11_MNG_ANTENNA_ID			64	
#define DOT11_MNG_RSNI_ID			65	
#define DOT11_MNG_MEASUREMENT_PILOT_TX_ID	66	
#define DOT11_MNG_BSS_AVAL_ADMISSION_CAP_ID	67	
#define DOT11_MNG_BSS_AC_ACCESS_DELAY_ID	68	
#define DOT11_MNG_WAPI_ID			68	
#define DOT11_MNG_TIME_ADVERTISE_ID		69	
#define DOT11_MNG_RRM_CAP_ID			70	
#define DOT11_MNG_MULTIPLE_BSSID_ID		71	
#define	DOT11_MNG_HT_BSS_COEXINFO_ID		72	
#define	DOT11_MNG_HT_BSS_CHANNEL_REPORT_ID	73	
#define	DOT11_MNG_HT_OBSS_ID			74	
#define DOT11_MNG_MMIE_ID			76	
#define DOT11_MNG_BSS_MAX_IDLE_PERIOD_ID	90	
#define DOT11_MNG_TFS_REQUEST_ID		91	
#define DOT11_MNG_TFS_RESPONSE_ID		92	
#define DOT11_MNG_WNM_SLEEP_MODE_ID		93	
#define DOT11_MNG_TIMBC_REQ_ID			94	
#define DOT11_MNG_TIMBC_RESP_ID			95	
#define DOT11_MNG_CHANNEL_USAGE			97	
#define DOT11_MNG_TIME_ZONE_ID			98	
#define DOT11_MNG_DMS_REQUEST_ID		99	
#define DOT11_MNG_DMS_RESPONSE_ID		100	
#define DOT11_MNG_LINK_IDENTIFIER_ID		101	
#define DOT11_MNG_WAKEUP_SCHEDULE_ID		102	
#define DOT11_MNG_CHANNEL_SWITCH_TIMING_ID	104	
#define DOT11_MNG_PTI_CONTROL_ID		105	
#define DOT11_MNG_PU_BUFFER_STATUS_ID		106	
#define DOT11_MNG_INTERWORKING_ID		107	
#define DOT11_MNG_ADVERTISEMENT_ID		108	
#define DOT11_MNG_EXP_BW_REQ_ID			109	
#define DOT11_MNG_QOS_MAP_ID			110	
#define DOT11_MNG_ROAM_CONSORT_ID		111	
#define DOT11_MNG_EMERGCY_ALERT_ID		112	
#define	DOT11_MNG_EXT_CAP_ID			127	
#define	DOT11_MNG_VHT_CAP_ID			191	
#define	DOT11_MNG_VHT_OPERATION_ID		192	
#define DOT11_MNG_WIDE_BW_CHANNEL_SWITCH_ID		194	
#define DOT11_MNG_VHT_TRANSMIT_POWER_ENVELOPE_ID	195	
#define DOT11_MNG_CHANNEL_SWITCH_WRAPPER_ID		196	
#define DOT11_MNG_AID_ID					197	
#define	DOT11_MNG_OPER_MODE_NOTIF_ID	199	

#define DOT11_MNG_WPA_ID			221	
#define DOT11_MNG_PROPR_ID			221	

#define DOT11_MNG_VS_ID				221	

#define DOT11_RATE_1M   2       
#define DOT11_RATE_2M   4       
#define DOT11_RATE_5M5  11      
#define DOT11_RATE_11M  22      
#define DOT11_RATE_6M   12      
#define DOT11_RATE_9M   18      
#define DOT11_RATE_12M  24      
#define DOT11_RATE_18M  36      
#define DOT11_RATE_24M  48      
#define DOT11_RATE_36M  72      
#define DOT11_RATE_48M  96      
#define DOT11_RATE_54M  108     
#define DOT11_RATE_MAX  108     

#define DOT11_RATE_BASIC                0x80 
#define DOT11_RATE_MASK                 0x7F 

#define DOT11_MNG_ERP_LEN			1	
#define DOT11_MNG_NONERP_PRESENT		0x01	
#define DOT11_MNG_USE_PROTECTION		0x02	
#define DOT11_MNG_BARKER_PREAMBLE		0x04	

#define DOT11_MGN_TS_DELAY_LEN		4	
#define TS_DELAY_FIELD_SIZE			4	

#define DOT11_CAP_ESS				0x0001	
#define DOT11_CAP_IBSS				0x0002	
#define DOT11_CAP_POLLABLE			0x0004	
#define DOT11_CAP_POLL_RQ			0x0008	
#define DOT11_CAP_PRIVACY			0x0010	
#define DOT11_CAP_SHORT				0x0020	
#define DOT11_CAP_PBCC				0x0040	
#define DOT11_CAP_AGILITY			0x0080	
#define DOT11_CAP_SPECTRUM			0x0100	
#define DOT11_CAP_QOS				0x0200	
#define DOT11_CAP_SHORTSLOT			0x0400	
#define DOT11_CAP_APSD				0x0800	
#define DOT11_CAP_RRM				0x1000	
#define DOT11_CAP_CCK_OFDM			0x2000	
#define DOT11_CAP_DELAY_BA			0x4000	
#define DOT11_CAP_IMMEDIATE_BA			0x8000	

#define DOT11_EXT_CAP_OBSS_COEX_MGMT		0

#define DOT11_EXT_CAP_SPSMP			6

#define DOT11_EXT_CAP_FMS			11

#define DOT11_EXT_CAP_PROXY_ARP			12

#define DOT11_EXT_CAP_TFS			16

#define DOT11_EXT_CAP_WNM_SLEEP			17

#define DOT11_EXT_CAP_TIMBC			18

#define DOT11_EXT_CAP_BSS_TRANSITION_MGMT	19

#define DOT11_EXT_CAP_DMS			26

#define DOT11_EXT_CAP_IW			31

#define DOT11_EXT_CAP_SI			41
#define DOT11_EXT_CAP_SI_MASK			0x0E

#define DOT11_EXT_CAP_WNM_NOTIF			46

#define DOT11_EXT_CAP_OPER_MODE_NOTIF		62

#define DOT11_OPER_MODE_CHANNEL_WIDTH_SHIFT 0
#define DOT11_OPER_MODE_CHANNEL_WIDTH_MASK 0x3
#define DOT11_OPER_MODE_RXNSS_SHIFT 4
#define DOT11_OPER_MODE_RXNSS_MASK 0x70
#define DOT11_OPER_MODE_RXNSS_TYPE_SHIFT 7
#define DOT11_OPER_MODE_RXNSS_TYPE_MASK 0x80

#define DOT11_OPER_MODE(type, nss, chanw) (\
	((type) << DOT11_OPER_MODE_RXNSS_TYPE_SHIFT &\
		 DOT11_OPER_MODE_RXNSS_TYPE_MASK) |\
	(((nss) - 1) << DOT11_OPER_MODE_RXNSS_SHIFT & DOT11_OPER_MODE_RXNSS_MASK) |\
	((chanw) << DOT11_OPER_MODE_CHANNEL_WIDTH_SHIFT &\
		 DOT11_OPER_MODE_CHANNEL_WIDTH_MASK))

#define DOT11_OPER_MODE_CHANNEL_WIDTH(mode) \
	(((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK)\
		>> DOT11_OPER_MODE_CHANNEL_WIDTH_SHIFT)
#define DOT11_OPER_MODE_RXNSS(mode) \
	((((mode) & DOT11_OPER_MODE_RXNSS_MASK)		\
		>> DOT11_OPER_MODE_RXNSS_SHIFT) + 1)
#define DOT11_OPER_MODE_RXNSS_TYPE(mode) \
	(((mode) & DOT11_OPER_MODE_RXNSS_TYPE_MASK)\
		>> DOT11_OPER_MODE_RXNSS_TYPE_SHIFT)

#define DOT11_OPER_MODE_20MHZ 0
#define DOT11_OPER_MODE_40MHZ 1
#define DOT11_OPER_MODE_80MHZ 2
#define DOT11_OPER_MODE_160MHZ 3
#define DOT11_OPER_MODE_8080MHZ 3

#define DOT11_OPER_MODE_CHANNEL_WIDTH_20MHZ(mode) (\
	((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK) == DOT11_OPER_MODE_20MHZ)
#define DOT11_OPER_MODE_CHANNEL_WIDTH_40MHZ(mode) (\
	((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK) == DOT11_OPER_MODE_40MHZ)
#define DOT11_OPER_MODE_CHANNEL_WIDTH_80MHZ(mode) (\
	((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK) == DOT11_OPER_MODE_80MHZ)
#define DOT11_OPER_MODE_CHANNEL_WIDTH_160MHZ(mode) (\
	((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK) == DOT11_OPER_MODE_160MHZ)
#define DOT11_OPER_MODE_CHANNEL_WIDTH_8080MHZ(mode) (\
	((mode) & DOT11_OPER_MODE_CHANNEL_WIDTH_MASK) == DOT11_OPER_MODE_8080MHZ)

BWL_PRE_PACKED_STRUCT struct dot11_oper_mode_notif_ie {
	uint8 mode;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_oper_mode_notif_ie dot11_oper_mode_notif_ie_t;

#define DOT11_OPER_MODE_NOTIF_IE_LEN 1

#define DOT11_ACTION_HDR_LEN		2	
#define DOT11_ACTION_CAT_OFF		0	
#define DOT11_ACTION_ACT_OFF		1	

#define DOT11_ACTION_CAT_ERR_MASK	0x80	
#define DOT11_ACTION_CAT_MASK		0x7F	
#define DOT11_ACTION_CAT_SPECT_MNG	0	
#define DOT11_ACTION_CAT_QOS		1	
#define DOT11_ACTION_CAT_DLS		2	
#define DOT11_ACTION_CAT_BLOCKACK	3	
#define DOT11_ACTION_CAT_PUBLIC		4	
#define DOT11_ACTION_CAT_RRM		5	
#define DOT11_ACTION_CAT_FBT	6	
#define DOT11_ACTION_CAT_HT		7	
#define	DOT11_ACTION_CAT_SA_QUERY	8	
#define	DOT11_ACTION_CAT_PDPA		9	
#define DOT11_ACTION_CAT_WNM		10	
#define DOT11_ACTION_CAT_UWNM		11	
#define DOT11_ACTION_NOTIFICATION	17
#define DOT11_ACTION_CAT_VHT		21	
#define DOT11_ACTION_CAT_VSP		126	
#define DOT11_ACTION_CAT_VS		127	

#define DOT11_SM_ACTION_M_REQ		0	
#define DOT11_SM_ACTION_M_REP		1	
#define DOT11_SM_ACTION_TPC_REQ		2	
#define DOT11_SM_ACTION_TPC_REP		3	
#define DOT11_SM_ACTION_CHANNEL_SWITCH	4	
#define DOT11_SM_ACTION_EXT_CSA		5	

#define DOT11_ACTION_ID_HT_CH_WIDTH	0	
#define DOT11_ACTION_ID_HT_MIMO_PS	1	

#define DOT11_PUB_ACTION_BSS_COEX_MNG	0	
#define DOT11_PUB_ACTION_CHANNEL_SWITCH	4	

#define DOT11_BA_ACTION_ADDBA_REQ	0	
#define DOT11_BA_ACTION_ADDBA_RESP	1	
#define DOT11_BA_ACTION_DELBA		2	

#define DOT11_ADDBA_PARAM_AMSDU_SUP	0x0001	
#define DOT11_ADDBA_PARAM_POLICY_MASK	0x0002	
#define DOT11_ADDBA_PARAM_POLICY_SHIFT	1	
#define DOT11_ADDBA_PARAM_TID_MASK	0x003c	
#define DOT11_ADDBA_PARAM_TID_SHIFT	2	
#define DOT11_ADDBA_PARAM_BSIZE_MASK	0xffc0	
#define DOT11_ADDBA_PARAM_BSIZE_SHIFT	6	

#define DOT11_ADDBA_POLICY_DELAYED	0	
#define DOT11_ADDBA_POLICY_IMMEDIATE	1	

#define DOT11_FT_ACTION_FT_RESERVED		0
#define DOT11_FT_ACTION_FT_REQ			1	
#define DOT11_FT_ACTION_FT_RES			2	
#define DOT11_FT_ACTION_FT_CON			3	
#define DOT11_FT_ACTION_FT_ACK			4	

#define DOT11_DLS_ACTION_REQ			0	
#define DOT11_DLS_ACTION_RESP			1	
#define DOT11_DLS_ACTION_TD			2	

#define DOT11_WNM_ACTION_EVENT_REQ		0
#define DOT11_WNM_ACTION_EVENT_REP		1
#define DOT11_WNM_ACTION_DIAG_REQ		2
#define DOT11_WNM_ACTION_DIAG_REP		3
#define DOT11_WNM_ACTION_LOC_CFG_REQ		4
#define DOT11_WNM_ACTION_LOC_RFG_RESP		5
#define DOT11_WNM_ACTION_BSS_TRANS_QURY		6
#define DOT11_WNM_ACTION_BSS_TRANS_REQ		7
#define DOT11_WNM_ACTION_BSS_TRANS_RESP		8
#define DOT11_WNM_ACTION_FMS_REQ		9
#define DOT11_WNM_ACTION_FMS_RESP		10
#define DOT11_WNM_ACTION_COL_INTRFRNCE_REQ	11
#define DOT11_WNM_ACTION_COL_INTRFRNCE_REP	12
#define DOT11_WNM_ACTION_TFS_REQ		13
#define DOT11_WNM_ACTION_TFS_RESP		14
#define DOT11_WNM_ACTION_TFS_NOTIFY		15
#define DOT11_WNM_ACTION_WNM_SLEEP_REQ		16
#define DOT11_WNM_ACTION_WNM_SLEEP_RESP		17
#define DOT11_WNM_ACTION_TIMBC_REQ		18
#define DOT11_WNM_ACTION_TIMBC_RESP		19
#define DOT11_WNM_ACTION_QOS_TRFC_CAP_UPD	20
#define DOT11_WNM_ACTION_CHAN_USAGE_REQ		21
#define DOT11_WNM_ACTION_CHAN_USAGE_RESP	22
#define DOT11_WNM_ACTION_DMS_REQ		23
#define DOT11_WNM_ACTION_DMS_RESP		24
#define DOT11_WNM_ACTION_TMNG_MEASUR_REQ	25
#define DOT11_WNM_ACTION_NOTFCTN_REQ		26
#define DOT11_WNM_ACTION_NOTFCTN_RES		27

#define DOT11_UWNM_ACTION_TIM			0
#define DOT11_UWNM_ACTION_TIMING_MEASUREMENT	1

#define DOT11_MNG_COUNTRY_ID_LEN 3

#define DOT11_VHT_ACTION_CBF				0	
#define DOT11_VHT_ACTION_GID_MGMT			1	
#define DOT11_VHT_ACTION_OPER_MODE_NOTIF	2	

BWL_PRE_PACKED_STRUCT struct dot11_dls_req {
	uint8 category;			
	uint8 action;				
	struct ether_addr	da;		
	struct ether_addr	sa;		
	uint16 cap;				
	uint16 timeout;			
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dls_req dot11_dls_req_t;
#define DOT11_DLS_REQ_LEN 18	

BWL_PRE_PACKED_STRUCT struct dot11_dls_resp {
	uint8 category;			
	uint8 action;				
	uint16 status;				
	struct ether_addr	da;		
	struct ether_addr	sa;		
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dls_resp dot11_dls_resp_t;
#define DOT11_DLS_RESP_LEN 16	

BWL_PRE_PACKED_STRUCT struct dot11_bss_trans_query {
	uint8 category;			
	uint8 action;			
	uint8 token;			
	uint8 reason;			
	uint8 data[1];			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_bss_trans_query dot11_bss_trans_query_t;
#define DOT11_BSS_TRANS_QUERY_LEN 4	

BWL_PRE_PACKED_STRUCT struct dot11_bss_trans_req {
	uint8 category;			
	uint8 action;			
	uint8 token;			
	uint8 reqmode;			
	uint16 disassoc_tmr;		
	uint8 validity_intrvl;		
	uint8 data[1];			

} BWL_POST_PACKED_STRUCT;
typedef struct dot11_bss_trans_req dot11_bss_trans_req_t;
#define DOT11_BSS_TRANS_REQ_LEN 7	

#define DOT11_BSS_TERM_DUR_LEN 12	

#define DOT11_BSS_TRNS_REQMODE_PREF_LIST_INCL		0x01
#define DOT11_BSS_TRNS_REQMODE_ABRIDGED			0x02
#define DOT11_BSS_TRNS_REQMODE_DISASSOC_IMMINENT	0x04
#define DOT11_BSS_TRNS_REQMODE_BSS_TERM_INCL		0x08
#define DOT11_BSS_TRNS_REQMODE_ESS_DISASSOC_IMNT	0x10

BWL_PRE_PACKED_STRUCT struct dot11_bss_trans_res {
	uint8 category;			
	uint8 action;			
	uint8 token;			
	uint8 status;			
	uint8 term_delay;		
	uint8 data[1];			

} BWL_POST_PACKED_STRUCT;
typedef struct dot11_bss_trans_res dot11_bss_trans_res_t;
#define DOT11_BSS_TRANS_RES_LEN 5	

#define DOT11_BSS_TRNS_RES_STATUS_ACCEPT		0
#define DOT11_BSS_TRNS_RES_STATUS_REJECT		1
#define DOT11_BSS_TRNS_RES_STATUS_REJ_INSUFF_BCN	2
#define DOT11_BSS_TRNS_RES_STATUS_REJ_INSUFF_CAP	3
#define DOT11_BSS_TRNS_RES_STATUS_REJ_TERM_UNDESIRED	4
#define DOT11_BSS_TRNS_RES_STATUS_REJ_TERM_DELAY_REQ	5
#define DOT11_BSS_TRNS_RES_STATUS_REJ_BSS_LIST_PROVIDED	6
#define DOT11_BSS_TRNS_RES_STATUS_REJ_NO_SUITABLE_BSS	7
#define DOT11_BSS_TRNS_RES_STATUS_REJ_LEAVING_ESS	8

#define DOT11_NBR_RPRT_BSSID_INFO_REACHABILTY_UNKNOWN	0x0002
#define DOT11_NBR_RPRT_BSSID_INFO_REACHABILTY		0x0003
#define DOT11_NBR_RPRT_BSSID_INFO_SEC				0x0004
#define DOT11_NBR_RPRT_BSSID_INFO_KEY_SCOPE			0x0008
#define DOT11_NBR_RPRT_BSSID_INFO_CAP				0x03f0

#define DOT11_NBR_RPRT_BSSID_INFO_CAP_SPEC_MGMT		0x0010
#define DOT11_NBR_RPRT_BSSID_INFO_CAP_QOS			0x0020
#define DOT11_NBR_RPRT_BSSID_INFO_CAP_APSD			0x0040
#define DOT11_NBR_RPRT_BSSID_INFO_CAP_RDIO_MSMT		0x0080
#define DOT11_NBR_RPRT_BSSID_INFO_CAP_DEL_BA		0x0100
#define DOT11_NBR_RPRT_BSSID_INFO_CAP_IMM_BA		0x0200

#define DOT11_NBR_RPRT_SUBELEM_BSS_CANDDT_PREF_ID	3
#define DOT11_NBR_RPRT_SUBELEM_BSS_TERM_DUR_ID		4

BWL_PRE_PACKED_STRUCT struct dot11_bss_term_dur_subelem {
	uint8 id;
	uint8 len;
	uint8 bss_term_tsf[8];
	uint16 duration;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_bss_term_dur_subelem dot11_bss_term_dur_subelem_t;
#define DOT11_BSS_TERM_DUR_SUBELEM_LEN			12

BWL_PRE_PACKED_STRUCT struct dot11_bss_max_idle_period_ie {
	uint8 id;				
	uint8 length;
	uint16 max_idle_period;			
	uint8 idle_opt;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_bss_max_idle_period_ie dot11_bss_max_idle_period_ie_t;
#define DOT11_BSS_MAX_IDLE_PERIOD_IE_LEN	3	
#define DOT11_BSS_MAX_IDLE_PERIOD_OPT_PROTECTED	1	

BWL_PRE_PACKED_STRUCT struct dot11_timbc_req_ie {
	uint8 id;				
	uint8 length;
	uint8 interval;				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timbc_req_ie dot11_timbc_req_ie_t;
#define DOT11_TIMBC_REQ_IE_LEN		1	

BWL_PRE_PACKED_STRUCT struct dot11_timbc_req {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timbc_req dot11_timbc_req_t;
#define DOT11_TIMBC_REQ_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_timbc_resp_ie {
	uint8 id;				
	uint8 length;
	uint8 status;				
	uint8 interval;				
	int32 offset;				
	uint16 high_rate;			
	uint16 low_rate;			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timbc_resp_ie dot11_timbc_resp_ie_t;
#define DOT11_TIMBC_DENY_RESP_IE_LEN	1	
#define DOT11_TIMBC_ACCEPT_RESP_IE_LEN	10	

#define DOT11_TIMBC_STATUS_ACCEPT		0
#define DOT11_TIMBC_STATUS_ACCEPT_TSTAMP	1
#define DOT11_TIMBC_STATUS_DENY			2
#define DOT11_TIMBC_STATUS_OVERRIDDEN		3

BWL_PRE_PACKED_STRUCT struct dot11_timbc_resp {
	uint8 category;			
	uint8 action;			
	uint8 token;			
	uint8 data[1];			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timbc_resp dot11_timbc_resp_t;
#define DOT11_TIMBC_RESP_LEN	3	

BWL_PRE_PACKED_STRUCT struct dot11_tim_ie {
	uint8 id;			
	uint8 len;			
	uint8 dtim_count;		
	uint8 dtim_period;		
	uint8 bitmap_control;		
	uint8 pvb[1];			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tim_ie dot11_tim_ie_t;
#define DOT11_TIM_IE_FIXED_LEN	3	

BWL_PRE_PACKED_STRUCT struct dot11_timbc {
	uint8 category;			
	uint8 action;			
	uint8 check_beacon;		
	uint8 tsf[8];			
	dot11_tim_ie_t tim_ie;		
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timbc dot11_timbc_t;
#define DOT11_TIMBC_HDR_LEN	(sizeof(dot11_timbc_t) - sizeof(dot11_tim_ie_t))
#define DOT11_TIMBC_FIXED_LEN	(sizeof(dot11_timbc_t) - 1)	

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_hdr {
	uint8 type;
	uint8 mask;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_hdr dot11_tclas_fc_hdr_t;
#define DOT11_TCLAS_FC_HDR_LEN		2	

#define DOT11_TCLAS_MASK_0		0x1
#define DOT11_TCLAS_MASK_1		0x2
#define DOT11_TCLAS_MASK_2		0x4
#define DOT11_TCLAS_MASK_3		0x8
#define DOT11_TCLAS_MASK_4		0x10
#define DOT11_TCLAS_MASK_5		0x20
#define DOT11_TCLAS_MASK_6		0x40
#define DOT11_TCLAS_MASK_7		0x80

#define DOT11_TCLAS_FC_0_ETH		0
#define DOT11_TCLAS_FC_1_IP		1
#define DOT11_TCLAS_FC_2_8021Q		2
#define DOT11_TCLAS_FC_3_OFFSET		3
#define DOT11_TCLAS_FC_4_IP_HIGHER	4
#define DOT11_TCLAS_FC_5_8021D		5

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_0_eth {
	uint8 type;
	uint8 mask;
	uint8 sa[ETHER_ADDR_LEN];
	uint8 da[ETHER_ADDR_LEN];
	uint16 eth_type;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_0_eth dot11_tclas_fc_0_eth_t;
#define DOT11_TCLAS_FC_0_ETH_LEN	16

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_1_ipv4 {
	uint8 type;
	uint8 mask;
	uint8 version;
	uint32 src_ip;
	uint32 dst_ip;
	uint16 src_port;
	uint16 dst_port;
	uint8 dscp;
	uint8 protocol;
	uint8 reserved;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_1_ipv4 dot11_tclas_fc_1_ipv4_t;
#define DOT11_TCLAS_FC_1_IPV4_LEN	18

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_2_8021q {
	uint8 type;
	uint8 mask;
	uint16 tci;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_2_8021q dot11_tclas_fc_2_8021q_t;
#define DOT11_TCLAS_FC_2_8021Q_LEN	4

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_3_filter {
	uint8 type;
	uint8 mask;
	uint16 offset;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_3_filter dot11_tclas_fc_3_filter_t;
#define DOT11_TCLAS_FC_3_FILTER_LEN	4

typedef struct dot11_tclas_fc_1_ipv4 dot11_tclas_fc_4_ipv4_t;
#define DOT11_TCLAS_FC_4_IPV4_LEN	DOT11_TCLAS_FC_1_IPV4_LEN

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_4_ipv6 {
	uint8 type;
	uint8 mask;
	uint8 version;
	uint8 saddr[16];
	uint8 daddr[16];
	uint16 src_port;
	uint16 dst_port;
	uint8 dscp;
	uint8 nexthdr;
	uint8 flow_lbl[3];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_4_ipv6 dot11_tclas_fc_4_ipv6_t;
#define DOT11_TCLAS_FC_4_IPV6_LEN	44

BWL_PRE_PACKED_STRUCT struct dot11_tclas_fc_5_8021d {
	uint8 type;
	uint8 mask;
	uint8 pcp;
	uint8 cfi;
	uint16 vid;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_fc_5_8021d dot11_tclas_fc_5_8021d_t;
#define DOT11_TCLAS_FC_5_8021D_LEN	6

BWL_PRE_PACKED_STRUCT union dot11_tclas_fc {
	uint8 data[1];
	dot11_tclas_fc_hdr_t hdr;
	dot11_tclas_fc_0_eth_t t0_eth;
	dot11_tclas_fc_1_ipv4_t	t1_ipv4;
	dot11_tclas_fc_2_8021q_t t2_8021q;
	dot11_tclas_fc_3_filter_t t3_filter;
	dot11_tclas_fc_4_ipv4_t	t4_ipv4;
	dot11_tclas_fc_4_ipv6_t	t4_ipv6;
	dot11_tclas_fc_5_8021d_t t5_8021d;
} BWL_POST_PACKED_STRUCT;
typedef union dot11_tclas_fc dot11_tclas_fc_t;
#define DOT11_TCLAS_FC_MIN_LEN		4
#define DOT11_TCLAS_FC_MAX_LEN		254

BWL_PRE_PACKED_STRUCT struct dot11_tclas_ie {
	uint8 id;				
	uint8 length;
	uint8 user_priority;
	dot11_tclas_fc_t fc;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_ie dot11_tclas_ie_t;
#define DOT11_TCLAS_IE_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_tclas_proc_ie {
	uint8 id;				
	uint8 length;
	uint8 process;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tclas_proc_ie dot11_tclas_proc_ie_t;
#define DOT11_TCLAS_PROC_IE_LEN		3	

#define DOT11_TCLAS_PROC_MATCHALL	0	
#define DOT11_TCLAS_PROC_MATCHONE	1	
#define DOT11_TCLAS_PROC_NONMATCH	2	

#define DOT11_TSPEC_IE_LEN		57	

BWL_PRE_PACKED_STRUCT struct dot11_tfs_req_ie {
	uint8 id;				
	uint8 length;
	uint8 tfs_id;
	uint8 tfs_actcode;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_req_ie dot11_tfs_req_ie_t;
#define DOT11_TFS_REQ_IE_LEN		4	

#define DOT11_TFS_ACTCODE_DELETE	1
#define DOT11_TFS_ACTCODE_MODIFY	2

BWL_PRE_PACKED_STRUCT struct dot11_tfs_se {
	uint8 sub_id;
	uint8 length;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_se dot11_tfs_se_t;

#define DOT11_TFS_REQ_SUBELEM_LEN	2	

#define DOT11_TFS_SUBELEM_ID_TFS	1
#define DOT11_TFS_SUBELEM_ID_VENDOR	221

BWL_PRE_PACKED_STRUCT struct dot11_tfs_resp_ie {
	uint8 id;				
	uint8 length;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_resp_ie dot11_tfs_resp_ie_t;
#define DOT11_TFS_RESP_IE_LEN		2	

BWL_PRE_PACKED_STRUCT struct dot11_tfs_status_se {
	uint8 id;				
	uint8 length;
	uint8 resp_st;
	uint8 tfs_id;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_status_se dot11_tfs_status_se_t;

#define DOT11_TFS_STATUS_SE_LEN		4	
#define DOT11_TFS_STATUS_SE_DATA_LEN	2	

#define DOT11_TFS_STATUS_SE_ID_TFS_ST	1
#define DOT11_TFS_STATUS_SE_ID_TFS	2
#define DOT11_TFS_STATUS_SE_ID_VENDOR	221

#define DOT11_TFS_RESP_ST_ACCEPT	0
#define DOT11_TFS_RESP_ST_DENY_FORMAT	1
#define DOT11_TFS_RESP_ST_DENY_RESOURCE	2
#define DOT11_TFS_RESP_ST_DENY_POLICY	4
#define DOT11_TFS_RESP_ST_PREFERRED_AP_INCAP	14

BWL_PRE_PACKED_STRUCT struct dot11_tfs_req {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_req dot11_tfs_req_t;
#define DOT11_TFS_REQ_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_tfs_resp {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_resp dot11_tfs_resp_t;
#define DOT11_TFS_RESP_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_tfs_notify {
	uint8 category;				
	uint8 action;				
	uint8 num_tfs_id;			
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_tfs_notify dot11_tfs_notify_t;
#define DOT11_TFS_NOTIFY_LEN		3	

#define DOT11_TFS_NOTIFY_ACT_DEL	1
#define DOT11_TFS_NOTIFY_ACT_NOTIFY	2

BWL_PRE_PACKED_STRUCT struct dot11_wnm_sleep_req {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wnm_sleep_req dot11_wnm_sleep_req_t;
#define DOT11_WNM_SLEEP_REQ_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_wnm_sleep_resp {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint16 key_len;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wnm_sleep_resp dot11_wnm_sleep_resp_t;
#define DOT11_WNM_SLEEP_RESP_LEN	5	

#define DOT11_WNM_SLEEP_SUBELEM_ID_GTK	0
#define DOT11_WNM_SLEEP_SUBELEM_ID_IGTK	1

BWL_PRE_PACKED_STRUCT struct dot11_wnm_sleep_subelem_gtk {
	uint8 sub_id;
	uint8 length;
	uint16 key_info;
	uint8 key_length;
	uint8 rsc[8];
	uint8 key[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wnm_sleep_subelem_gtk dot11_wnm_sleep_subelem_gtk_t;
#define DOT11_WNM_SLEEP_SUBELEM_GTK_FIXED_LEN	11	
#define DOT11_WNM_SLEEP_SUBELEM_GTK_MAX_LEN	43	

BWL_PRE_PACKED_STRUCT struct dot11_wnm_sleep_subelem_igtk {
	uint8 sub_id;
	uint8 length;
	uint16 key_id;
	uint8 pn[6];
	uint8 key[16];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wnm_sleep_subelem_igtk dot11_wnm_sleep_subelem_igtk_t;
#define DOT11_WNM_SLEEP_SUBELEM_IGTK_LEN 24	

BWL_PRE_PACKED_STRUCT struct dot11_wnm_sleep_ie {
	uint8 id;				
	uint8 length;
	uint8 act_type;
	uint8 resp_status;
	uint16 interval;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_wnm_sleep_ie dot11_wnm_sleep_ie_t;
#define DOT11_WNM_SLEEP_IE_LEN		4	

#define DOT11_WNM_SLEEP_ACT_TYPE_ENTER	0
#define DOT11_WNM_SLEEP_ACT_TYPE_EXIT	1

#define DOT11_WNM_SLEEP_RESP_ACCEPT	0
#define DOT11_WNM_SLEEP_RESP_UPDATE	1
#define DOT11_WNM_SLEEP_RESP_DENY	2
#define DOT11_WNM_SLEEP_RESP_DENY_TEMP	3
#define DOT11_WNM_SLEEP_RESP_DENY_KEY	4
#define DOT11_WNM_SLEEP_RESP_DENY_INUSE	5
#define DOT11_WNM_SLEEP_RESP_LAST	6

BWL_PRE_PACKED_STRUCT struct dot11_dms_req {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_req dot11_dms_req_t;
#define DOT11_DMS_REQ_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_dms_resp {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_resp dot11_dms_resp_t;
#define DOT11_DMS_RESP_LEN		3	

BWL_PRE_PACKED_STRUCT struct dot11_dms_req_ie {
	uint8 id;				
	uint8 length;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_req_ie dot11_dms_req_ie_t;
#define DOT11_DMS_REQ_IE_LEN		2	

BWL_PRE_PACKED_STRUCT struct dot11_dms_resp_ie {
	uint8 id;				
	uint8 length;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_resp_ie dot11_dms_resp_ie_t;
#define DOT11_DMS_RESP_IE_LEN		2	

BWL_PRE_PACKED_STRUCT struct dot11_dms_req_desc {
	uint8 dms_id;
	uint8 length;
	uint8 type;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_req_desc dot11_dms_req_desc_t;
#define DOT11_DMS_REQ_DESC_LEN		3	

#define DOT11_DMS_REQ_TYPE_ADD		0
#define DOT11_DMS_REQ_TYPE_REMOVE	1
#define DOT11_DMS_REQ_TYPE_CHANGE	2

BWL_PRE_PACKED_STRUCT struct dot11_dms_resp_st {
	uint8 dms_id;
	uint8 length;
	uint8 type;
	uint16 lsc;
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_dms_resp_st dot11_dms_resp_st_t;
#define DOT11_DMS_RESP_STATUS_LEN	5	

#define DOT11_DMS_RESP_TYPE_ACCEPT	0
#define DOT11_DMS_RESP_TYPE_DENY	1
#define DOT11_DMS_RESP_TYPE_TERM	2

#define DOT11_DMS_RESP_LSC_UNSUPPORTED	0xFFFF

BWL_PRE_PACKED_STRUCT struct dot11_addba_req {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint16 addba_param_set;			
	uint16 timeout;				
	uint16 start_seqnum;			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_addba_req dot11_addba_req_t;
#define DOT11_ADDBA_REQ_LEN		9	

BWL_PRE_PACKED_STRUCT struct dot11_addba_resp {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint16 status;				
	uint16 addba_param_set;			
	uint16 timeout;				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_addba_resp dot11_addba_resp_t;
#define DOT11_ADDBA_RESP_LEN		9	

#define DOT11_DELBA_PARAM_INIT_MASK	0x0800	
#define DOT11_DELBA_PARAM_INIT_SHIFT	11	
#define DOT11_DELBA_PARAM_TID_MASK	0xf000	
#define DOT11_DELBA_PARAM_TID_SHIFT	12	

BWL_PRE_PACKED_STRUCT struct dot11_delba {
	uint8 category;				
	uint8 action;				
	uint16 delba_param_set;			
	uint16 reason;				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_delba dot11_delba_t;
#define DOT11_DELBA_LEN			6	

#define SA_QUERY_REQUEST		0
#define SA_QUERY_RESPONSE		1

BWL_PRE_PACKED_STRUCT struct dot11_ft_req {
	uint8 category;			
	uint8 action;			
	uint8 sta_addr[ETHER_ADDR_LEN];
	uint8 tgt_ap_addr[ETHER_ADDR_LEN];
	uint8 data[1];			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ft_req dot11_ft_req_t;
#define DOT11_FT_REQ_FIXED_LEN 14

BWL_PRE_PACKED_STRUCT struct dot11_ft_res {
	uint8 category;			
	uint8 action;			
	uint8 sta_addr[ETHER_ADDR_LEN];
	uint8 tgt_ap_addr[ETHER_ADDR_LEN];
	uint16 status;			
	uint8 data[1];			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ft_res dot11_ft_res_t;
#define DOT11_FT_RES_FIXED_LEN 16

BWL_PRE_PACKED_STRUCT struct dot11_rde_ie {
	uint8 id;			
	uint8 length;
	uint8 rde_id;			
	uint8 rd_count;			
	uint16 status;			
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rde_ie dot11_rde_ie_t;

#define DOT11_MNG_RDE_IE_LEN sizeof(dot11_rde_ie_t)

#define DOT11_RRM_CAP_LEN		5	
#define RCPI_IE_LEN 1
#define RSNI_IE_LEN 1
BWL_PRE_PACKED_STRUCT struct dot11_rrm_cap_ie {
	uint8 cap[DOT11_RRM_CAP_LEN];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rrm_cap_ie dot11_rrm_cap_ie_t;

#define DOT11_RRM_CAP_LINK			0
#define DOT11_RRM_CAP_NEIGHBOR_REPORT	1
#define DOT11_RRM_CAP_PARALLEL		2
#define DOT11_RRM_CAP_REPEATED		3
#define DOT11_RRM_CAP_BCN_PASSIVE	4
#define DOT11_RRM_CAP_BCN_ACTIVE	5
#define DOT11_RRM_CAP_BCN_TABLE		6
#define DOT11_RRM_CAP_BCN_REP_COND	7
#define DOT11_RRM_CAP_AP_CHANREP	16

#define DOT11_OP_CLASS_NONE			255

BWL_PRE_PACKED_STRUCT struct do11_ap_chrep {
	uint8 id;
	uint8 len;
	uint8 reg;
	uint8 chanlist[1];
} BWL_POST_PACKED_STRUCT;
typedef struct do11_ap_chrep dot11_ap_chrep_t;

#define DOT11_RM_ACTION_RM_REQ		0	
#define DOT11_RM_ACTION_RM_REP		1	
#define DOT11_RM_ACTION_LM_REQ		2	
#define DOT11_RM_ACTION_LM_REP		3	
#define DOT11_RM_ACTION_NR_REQ		4	
#define DOT11_RM_ACTION_NR_REP		5	

BWL_PRE_PACKED_STRUCT struct dot11_rm_action {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rm_action dot11_rm_action_t;
#define DOT11_RM_ACTION_LEN 3

BWL_PRE_PACKED_STRUCT struct dot11_rmreq {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint16 reps;				
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq dot11_rmreq_t;
#define DOT11_RMREQ_LEN	5

BWL_PRE_PACKED_STRUCT struct dot11_rm_ie {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rm_ie dot11_rm_ie_t;
#define DOT11_RM_IE_LEN	5

#define DOT11_RMREQ_MODE_PARALLEL	1
#define DOT11_RMREQ_MODE_ENABLE		2
#define DOT11_RMREQ_MODE_REQUEST	4
#define DOT11_RMREQ_MODE_REPORT		8
#define DOT11_RMREQ_MODE_DURMAND	0x10	

#define DOT11_RMREP_MODE_LATE		1
#define DOT11_RMREP_MODE_INCAPABLE	2
#define DOT11_RMREP_MODE_REFUSED	4

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_bcn {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint8 reg;
	uint8 channel;
	uint16 interval;
	uint16 duration;
	uint8 bcn_mode;
	struct ether_addr	bssid;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_bcn dot11_rmreq_bcn_t;
#define DOT11_RMREQ_BCN_LEN	18

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_bcn {
	uint8 reg;
	uint8 channel;
	uint32 starttime[2];
	uint16 duration;
	uint8 frame_info;
	uint8 rcpi;
	uint8 rsni;
	struct ether_addr	bssid;
	uint8 antenna_id;
	uint32 parent_tsf;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_bcn dot11_rmrep_bcn_t;
#define DOT11_RMREP_BCN_LEN	26

#define DOT11_RMREQ_BCN_PASSIVE	0
#define DOT11_RMREQ_BCN_ACTIVE	1
#define DOT11_RMREQ_BCN_TABLE	2

#define DOT11_RMREQ_BCN_SSID_ID 0
#define DOT11_RMREQ_BCN_REPINFO_ID  1
#define DOT11_RMREQ_BCN_REPDET_ID   2
#define DOT11_RMREQ_BCN_REQUEST_ID  10
#define DOT11_RMREQ_BCN_APCHREP_ID  DOT11_MNG_AP_CHREP_ID

#define DOT11_RMREQ_BCN_REPDET_FIXED	0	
#define DOT11_RMREQ_BCN_REPDET_REQUEST	1	
#define DOT11_RMREQ_BCN_REPDET_ALL	2	

#define DOT11_RMREP_BCN_FRM_BODY	1

#define DOT11_RMREP_FRAME_COUNT_REPORT 1

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_chanload {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint8 reg;
	uint8 channel;
	uint16 interval;
	uint16 duration;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_chanload dot11_rmreq_chanload_t;
#define DOT11_RMREQ_CHANLOAD_LEN	11

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_chanload {
	uint8 reg;
	uint8 channel;
	uint32 starttime[2];
	uint16 duration;
	uint8 channel_load;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_chanload dot11_rmrep_chanload_t;
#define DOT11_RMREP_CHANLOAD_LEN	13

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_noise {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint8 reg;
	uint8 channel;
	uint16 interval;
	uint16 duration;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_noise dot11_rmreq_noise_t;
#define DOT11_RMREQ_NOISE_LEN 11

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_noise {
	uint8 reg;
	uint8 channel;
	uint32 starttime[2];
	uint16 duration;
	uint8 antid;
	uint8 anpi;
	uint8 ipi0_dens;
	uint8 ipi1_dens;
	uint8 ipi2_dens;
	uint8 ipi3_dens;
	uint8 ipi4_dens;
	uint8 ipi5_dens;
	uint8 ipi6_dens;
	uint8 ipi7_dens;
	uint8 ipi8_dens;
	uint8 ipi9_dens;
	uint8 ipi10_dens;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_noise dot11_rmrep_noise_t;
#define DOT11_RMREP_NOISE_LEN 25

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_frame {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint8 reg;
	uint8 channel;
	uint16 interval;
	uint16 duration;
	uint8 req_type;
	struct ether_addr	ta;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_frame dot11_rmreq_frame_t;
#define DOT11_RMREQ_FRAME_LEN 18

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_frame {
	uint8 reg;
	uint8 channel;
	uint32 starttime[2];
	uint16 duration;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_frame dot11_rmrep_frame_t;
#define DOT11_RMREP_FRAME_LEN 12

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_frmentry {
	struct ether_addr	ta;
	struct ether_addr	bssid;
	uint8 phy_type;
	uint8 avg_rcpi;
	uint8 last_rsni;
	uint8 last_rcpi;
	uint8 ant_id;
	uint16 frame_cnt;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_frmentry dot11_rmrep_frmentry_t;
#define DOT11_RMREP_FRMENTRY_LEN 19

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_stat {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	struct ether_addr	peer;
	uint16 interval;
	uint16 duration;
	uint8 group_id;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_stat dot11_rmreq_stat_t;
#define DOT11_RMREQ_STAT_LEN 16

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_stat {
	uint16 duration;
	uint8 group_id;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_stat dot11_rmrep_stat_t;

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_tx_stream {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint16 interval;
	uint16 duration;
	struct ether_addr	peer;
	uint8 traffic_id;
	uint8 bin0_range;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_tx_stream dot11_rmreq_tx_stream_t;

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_tx_stream {
	uint32 starttime[2];
	uint16 duration;
	struct ether_addr	peer;
	uint8 traffic_id;
	uint8 reason;
	uint32 txmsdu_cnt;
	uint32 msdu_discarded_cnt;
	uint32 msdufailed_cnt;
	uint32 msduretry_cnt;
	uint32 cfpolls_lost_cnt;
	uint32 avrqueue_delay;
	uint32 avrtx_delay;
	uint8 bin0_range;
	uint32 bin0;
	uint32 bin1;
	uint32 bin2;
	uint32 bin3;
	uint32 bin4;
	uint32 bin5;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_tx_stream dot11_rmrep_tx_stream_t;

BWL_PRE_PACKED_STRUCT struct dot11_rmreq_pause_time {
	uint8 id;
	uint8 len;
	uint8 token;
	uint8 mode;
	uint8 type;
	uint16 pause_time;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmreq_pause_time dot11_rmreq_pause_time_t;

BWL_PRE_PACKED_STRUCT struct dot11_rmrep_nbr {
	struct ether_addr bssid;
	uint32 bssid_info;
	uint8 reg;
	uint8 channel;
	uint8 phytype;
	uchar sub_elements[1]; 	
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rmrep_nbr dot11_rmrep_nbr_t;
#define DOT11_RMREP_NBR_LEN	13

BWL_PRE_PACKED_STRUCT struct dot11_rrmrep_nbr {
	uint8 id;
	uint8 len;
	dot11_rmrep_nbr_t nbr_rrmrep;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_rrmrep_nbr dot11_rrmrep_nbr_t;
#define DOT11_RRMREP_NBR_LEN	15

#define DOT11_BSSTYPE_INFRASTRUCTURE		0	
#define DOT11_BSSTYPE_INDEPENDENT		1	
#define DOT11_BSSTYPE_ANY			2	
#define DOT11_SCANTYPE_ACTIVE			0	
#define DOT11_SCANTYPE_PASSIVE			1	

BWL_PRE_PACKED_STRUCT struct dot11_lmreq {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	uint8 txpwr;				
	uint8 maxtxpwr;				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_lmreq dot11_lmreq_t;
#define DOT11_LMREQ_LEN	5

BWL_PRE_PACKED_STRUCT struct dot11_lmrep {
	uint8 category;				
	uint8 action;				
	uint8 token;				
	dot11_tpc_rep_t tpc;			
	uint8 rxant;				
	uint8 txant;				
	uint8 rcpi;				
	uint8 rsni;				
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_lmrep dot11_lmrep_t;
#define DOT11_LMREP_LEN	11

#define PREN_PREAMBLE		24	
#define PREN_MM_EXT		12	
#define PREN_PREAMBLE_EXT	4	

#define RIFS_11N_TIME		2	

#define HT_SIG1_MCS_MASK        0x00007F
#define HT_SIG1_CBW             0x000080
#define HT_SIG1_HT_LENGTH       0xFFFF00

#define HT_SIG2_SMOOTHING       0x000001
#define HT_SIG2_NOT_SOUNDING    0x000002
#define HT_SIG2_RESERVED        0x000004
#define HT_SIG2_AGGREGATION     0x000008
#define HT_SIG2_STBC_MASK       0x000030
#define HT_SIG2_STBC_SHIFT      4
#define HT_SIG2_FEC_CODING      0x000040
#define HT_SIG2_SHORT_GI        0x000080
#define HT_SIG2_ESS_MASK        0x000300
#define HT_SIG2_ESS_SHIFT       8
#define HT_SIG2_CRC             0x03FC00
#define HT_SIG2_TAIL            0x1C0000

#define HT_T_LEG_PREAMBLE      16
#define HT_T_L_SIG              4
#define HT_T_SIG                8
#define HT_T_LTF1               4
#define HT_T_GF_LTF1            8
#define HT_T_LTFs               4
#define HT_T_STF                4
#define HT_T_GF_STF             8
#define HT_T_SYML               4

#define HT_N_SERVICE           16       
#define HT_N_TAIL               6       

#define APHY_SLOT_TIME          9       
#define APHY_SIFS_TIME          16      
#define APHY_DIFS_TIME          (APHY_SIFS_TIME + (2 * APHY_SLOT_TIME))  
#define APHY_PREAMBLE_TIME      16      
#define APHY_SIGNAL_TIME        4       
#define APHY_SYMBOL_TIME        4       
#define APHY_SERVICE_NBITS      16      
#define APHY_TAIL_NBITS         6       
#define APHY_CWMIN              15      

#define BPHY_SLOT_TIME          20      
#define BPHY_SIFS_TIME          10      
#define BPHY_DIFS_TIME          50      
#define BPHY_PLCP_TIME          192     
#define BPHY_PLCP_SHORT_TIME    96      
#define BPHY_CWMIN              31      

#define DOT11_OFDM_SIGNAL_EXTENSION	6	

#define PHY_CWMAX		1023	

#define	DOT11_MAXNUMFRAGS	16	

typedef int vht_group_id_t;

#define VHT_SIGA1_CONST_MASK            0x800004

#define VHT_SIGA1_BW_MASK               0x000003
#define VHT_SIGA1_20MHZ_VAL             0x000000
#define VHT_SIGA1_40MHZ_VAL             0x000001
#define VHT_SIGA1_80MHZ_VAL             0x000002
#define VHT_SIGA1_160MHZ_VAL            0x000003

#define VHT_SIGA1_STBC                  0x000008

#define VHT_SIGA1_GID_MASK              0x0003f0
#define VHT_SIGA1_GID_SHIFT             4
#define VHT_SIGA1_GID_TO_AP             0x00
#define VHT_SIGA1_GID_NOT_TO_AP         0x3f
#define VHT_SIGA1_GID_MAX_GID           0x3f

#define VHT_SIGA1_NSTS_SHIFT_MASK_USER0 0x001C00
#define VHT_SIGA1_NSTS_SHIFT            10

#define VHT_SIGA1_PARTIAL_AID_MASK      0x3fe000
#define VHT_SIGA1_PARTIAL_AID_SHIFT     13

#define VHT_SIGA1_TXOP_PS_NOT_ALLOWED   0x400000

#define VHT_SIGA2_GI_NONE               0x000000
#define VHT_SIGA2_GI_SHORT              0x000001
#define VHT_SIGA2_GI_W_MOD10            0x000002
#define VHT_SIGA2_CODING_LDPC           0x000004
#define VHT_SIGA2_LDPC_EXTRA_OFDM_SYM   0x000008
#define VHT_SIGA2_BEAMFORM_ENABLE       0x000100
#define VHT_SIGA2_MCS_SHIFT             4

#define VHT_SIGA2_B9_RESERVED           0x000200
#define VHT_SIGA2_TAIL_MASK             0xfc0000
#define VHT_SIGA2_TAIL_VALUE            0x000000

#define VHT_T_LEG_PREAMBLE      16
#define VHT_T_L_SIG              4
#define VHT_T_SIG_A              8
#define VHT_T_LTF                4
#define VHT_T_STF                4
#define VHT_T_SIG_B              4
#define VHT_T_SYML               4

#define VHT_N_SERVICE           16	
#define VHT_N_TAIL               6	

typedef struct d11cnt {
	uint32		txfrag;		
	uint32		txmulti;	
	uint32		txfail;		
	uint32		txretry;	
	uint32		txretrie;	
	uint32		rxdup;		
	uint32		txrts;		
	uint32		txnocts;	
	uint32		txnoack;	
	uint32		rxfrag;		
	uint32		rxmulti;	
	uint32		rxcrc;		
	uint32		txfrmsnt;	
	uint32		rxundec;	
} d11cnt_t;

#define BRCM_PROP_OUI		"\x00\x90\x4C"	

#define BRCM_SYSCAP_WET_TUNNEL	0x0100	

#define BRCM_OUI		"\x00\x10\x18"	

BWL_PRE_PACKED_STRUCT struct brcm_ie {
	uint8	id;		
	uint8	len;		
	uint8	oui[3];		
	uint8	ver;		
	uint8	assoc;		
	uint8	flags;		
	uint8	flags1;		
	uint16	amsdu_mtu_pref;	
} BWL_POST_PACKED_STRUCT;
typedef	struct brcm_ie brcm_ie_t;
#define BRCM_IE_LEN		11	
#define BRCM_IE_VER		2	
#define BRCM_IE_LEGACY_AES_VER	1	

#define	BRF_LZWDS		0x4	
#define	BRF_BLOCKACK		0x8	

#define	BRF1_AMSDU		0x1	
#define BRF1_WMEPS		0x4	
#define BRF1_PSOFIX		0x8	
#define	BRF1_RX_LARGE_AGG	0x10	
#define BRF1_RFAWARE_DCS	0x20    
#define BRF1_SOFTAP		0x40    
#define BRF1_DWDS		0x80    

BWL_PRE_PACKED_STRUCT struct vndr_ie {
	uchar id;
	uchar len;
	uchar oui [3];
	uchar data [1]; 	
} BWL_POST_PACKED_STRUCT;
typedef struct vndr_ie vndr_ie_t;

#define VNDR_IE_HDR_LEN		2	
#define VNDR_IE_MIN_LEN		3	
#define VNDR_IE_MAX_LEN		255	

BWL_PRE_PACKED_STRUCT struct member_of_brcm_prop_ie {
	uchar id;
	uchar len;
	uchar oui[3];
	uint8	type;           
	struct ether_addr ea;   
} BWL_POST_PACKED_STRUCT;
typedef struct member_of_brcm_prop_ie member_of_brcm_prop_ie_t;

#define MEMBER_OF_BRCM_PROP_IE_LEN		10	
#define MEMBER_OF_BRCM_PROP_IE_TYPE		54

BWL_PRE_PACKED_STRUCT struct relmcast_brcm_prop_ie {
	uchar id;
	uchar len;
	uchar oui[3];
	uint8 type;           
	struct ether_addr ea;   
	struct ether_addr mcast_ea;  
	uint8 updtmo; 
} BWL_POST_PACKED_STRUCT;
typedef struct relmcast_brcm_prop_ie relmcast_brcm_prop_ie_t;

#define RELMCAST_BRCM_PROP_IE_LEN	(sizeof(relmcast_brcm_prop_ie_t)-2)	
#define RELMCAST_BRCM_PROP_IE_TYPE	55

#define MCSSET_LEN	16	
#define MAX_MCS_NUM	(128)	

BWL_PRE_PACKED_STRUCT struct ht_cap_ie {
	uint16	cap;
	uint8	params;
	uint8	supp_mcs[MCSSET_LEN];
	uint16	ext_htcap;
	uint32	txbf_cap;
	uint8	as_cap;
} BWL_POST_PACKED_STRUCT;
typedef struct ht_cap_ie ht_cap_ie_t;
BWL_PRE_PACKED_STRUCT struct dot11_ht_cap_ie {
	uint8	id;
	uint8	len;
	ht_cap_ie_t ht_cap;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ht_cap_ie dot11_ht_cap_ie_t;

BWL_PRE_PACKED_STRUCT struct ht_prop_cap_ie {
	uint8	id;		
	uint8	len;		
	uint8	oui[3];		
	uint8	type;           
	ht_cap_ie_t cap_ie;
} BWL_POST_PACKED_STRUCT;
typedef struct ht_prop_cap_ie ht_prop_cap_ie_t;

#define HT_PROP_IE_OVERHEAD	4	
#define HT_CAP_IE_LEN		26	
#define HT_CAP_IE_TYPE		51

#define HT_CAP_LDPC_CODING	0x0001	
#define HT_CAP_40MHZ		0x0002  
#define HT_CAP_MIMO_PS_MASK	0x000C  
#define HT_CAP_MIMO_PS_SHIFT	0x0002	
#define HT_CAP_MIMO_PS_OFF	0x0003	
#define HT_CAP_MIMO_PS_RTS	0x0001	
#define HT_CAP_MIMO_PS_ON	0x0000	
#define HT_CAP_GF		0x0010	
#define HT_CAP_SHORT_GI_20	0x0020	
#define HT_CAP_SHORT_GI_40	0x0040	
#define HT_CAP_TX_STBC		0x0080	
#define HT_CAP_RX_STBC_MASK	0x0300	
#define HT_CAP_RX_STBC_SHIFT	8	
#define HT_CAP_DELAYED_BA	0x0400	
#define HT_CAP_MAX_AMSDU	0x0800	

#define HT_CAP_DSSS_CCK	0x1000	
#define HT_CAP_PSMP		0x2000	
#define HT_CAP_40MHZ_INTOLERANT 0x4000	
#define HT_CAP_LSIG_TXOP	0x8000	

#define HT_CAP_RX_STBC_NO		0x0	
#define HT_CAP_RX_STBC_ONE_STREAM	0x1	
#define HT_CAP_RX_STBC_TWO_STREAM	0x2	
#define HT_CAP_RX_STBC_THREE_STREAM	0x3	

#define HT_CAP_TXBF_CAP_IMPLICIT_TXBF_RX	0x1
#define HT_CAP_TXBF_CAP_NDP_TX			0x8
#define HT_CAP_TXBF_CAP_NDP_RX			0x10
#define HT_CAP_TXBF_CAP_EXPLICIT_CSI		0x100
#define HT_CAP_TXBF_CAP_EXPLICIT_NC_STEERING	0x200
#define HT_CAP_TXBF_CAP_EXPLICIT_C_STEERING	0x400
#define HT_CAP_TXBF_CAP_EXPLICIT_CSI_FB_MASK	0x1800
#define HT_CAP_TXBF_CAP_EXPLICIT_CSI_FB_SHIFT	11
#define HT_CAP_TXBF_CAP_EXPLICIT_NC_FB_MASK	0x6000
#define HT_CAP_TXBF_CAP_EXPLICIT_NC_FB_SHIFT	13
#define HT_CAP_TXBF_CAP_EXPLICIT_C_FB_MASK	0x18000
#define HT_CAP_TXBF_CAP_EXPLICIT_C_FB_SHIFT	15
#define HT_CAP_TXBF_CAP_CSI_BFR_ANT_SHIFT	19
#define HT_CAP_TXBF_CAP_NC_BFR_ANT_SHIFT	21
#define HT_CAP_TXBF_CAP_C_BFR_ANT_SHIFT		23
#define HT_CAP_TXBF_CAP_C_BFR_ANT_MASK		0x1800000

#define HT_CAP_TXBF_CAP_CHAN_ESTIM_SHIFT	27
#define HT_CAP_TXBF_CAP_CHAN_ESTIM_MASK		0x18000000

#define HT_CAP_TXBF_FB_TYPE_NONE 	0
#define HT_CAP_TXBF_FB_TYPE_DELAYED 	1
#define HT_CAP_TXBF_FB_TYPE_IMMEDIATE 	2
#define HT_CAP_TXBF_FB_TYPE_BOTH 	3

#define VHT_MAX_MPDU		11454	
#define VHT_MPDU_MSDU_DELTA	56		

#define VHT_MAX_AMSDU		(VHT_MAX_MPDU - VHT_MPDU_MSDU_DELTA)

#define HT_MAX_AMSDU		7935	
#define HT_MIN_AMSDU		3835	

#define HT_PARAMS_RX_FACTOR_MASK	0x03	
#define HT_PARAMS_DENSITY_MASK		0x1C	
#define HT_PARAMS_DENSITY_SHIFT	2	

#define AMPDU_MAX_MPDU_DENSITY  7       
#define AMPDU_DENSITY_NONE      0       
#define AMPDU_DENSITY_1over4_US 1       
#define AMPDU_DENSITY_1over2_US 2       
#define AMPDU_DENSITY_1_US      3       
#define AMPDU_DENSITY_2_US      4       
#define AMPDU_DENSITY_4_US      5       
#define AMPDU_DENSITY_8_US      6       
#define AMPDU_DENSITY_16_US     7       
#define AMPDU_RX_FACTOR_8K      0       
#define AMPDU_RX_FACTOR_16K     1       
#define AMPDU_RX_FACTOR_32K     2       
#define AMPDU_RX_FACTOR_64K     3       
#define AMPDU_RX_FACTOR_BASE    8*1024  

#define AMPDU_DELIMITER_LEN	4	
#define AMPDU_DELIMITER_LEN_MAX	63	

#define HT_CAP_EXT_PCO			0x0001
#define HT_CAP_EXT_PCO_TTIME_MASK	0x0006
#define HT_CAP_EXT_PCO_TTIME_SHIFT	1
#define HT_CAP_EXT_MCS_FEEDBACK_MASK	0x0300
#define HT_CAP_EXT_MCS_FEEDBACK_SHIFT	8
#define HT_CAP_EXT_HTC			0x0400
#define HT_CAP_EXT_RD_RESP		0x0800

BWL_PRE_PACKED_STRUCT struct ht_add_ie {
	uint8	ctl_ch;			
	uint8	byte1;			
	uint16	opmode;			
	uint16	misc_bits;		
	uint8	basic_mcs[MCSSET_LEN];  
} BWL_POST_PACKED_STRUCT;
typedef struct ht_add_ie ht_add_ie_t;

BWL_PRE_PACKED_STRUCT struct ht_prop_add_ie {
	uint8	id;		
	uint8	len;		
	uint8	oui[3];		
	uint8	type;		
	ht_add_ie_t add_ie;
} BWL_POST_PACKED_STRUCT;
typedef struct ht_prop_add_ie ht_prop_add_ie_t;

#define HT_ADD_IE_LEN	22
#define HT_ADD_IE_TYPE	52

#define HT_BW_ANY		0x04	
#define HT_RIFS_PERMITTED     	0x08	

#define HT_OPMODE_MASK	        0x0003	
#define HT_OPMODE_SHIFT		0	
#define HT_OPMODE_PURE		0x0000	
#define HT_OPMODE_OPTIONAL	0x0001	
#define HT_OPMODE_HT20IN40	0x0002	
#define HT_OPMODE_MIXED	0x0003	
#define HT_OPMODE_NONGF	0x0004	
#define DOT11N_TXBURST		0x0008	
#define DOT11N_OBSS_NONHT	0x0010	

#define HT_BASIC_STBC_MCS	0x007f	
#define HT_DUAL_STBC_PROT	0x0080	
#define HT_SECOND_BCN		0x0100	
#define HT_LSIG_TXOP		0x0200	
#define HT_PCO_ACTIVE		0x0400	
#define HT_PCO_PHASE		0x0800	
#define HT_DUALCTS_PROTECTION	0x0080	

#define DOT11N_2G_TXBURST_LIMIT	6160	
#define DOT11N_5G_TXBURST_LIMIT	3080	

#define GET_HT_OPMODE(add_ie)		((ltoh16_ua(&add_ie->opmode) & HT_OPMODE_MASK) \
					>> HT_OPMODE_SHIFT)
#define HT_MIXEDMODE_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & HT_OPMODE_MASK) \
					== HT_OPMODE_MIXED)	
#define HT_HT20_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & HT_OPMODE_MASK) \
					== HT_OPMODE_HT20IN40)	
#define HT_OPTIONAL_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & HT_OPMODE_MASK) \
					== HT_OPMODE_OPTIONAL)	
#define HT_USE_PROTECTION(add_ie)	(HT_HT20_PRESENT((add_ie)) || \
					HT_MIXEDMODE_PRESENT((add_ie))) 
#define HT_NONGF_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & HT_OPMODE_NONGF) \
					== HT_OPMODE_NONGF)	
#define DOT11N_TXBURST_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & DOT11N_TXBURST) \
					== DOT11N_TXBURST)	
#define DOT11N_OBSS_NONHT_PRESENT(add_ie)	((ltoh16_ua(&add_ie->opmode) & DOT11N_OBSS_NONHT) \
					== DOT11N_OBSS_NONHT)	

BWL_PRE_PACKED_STRUCT struct obss_params {
	uint16	passive_dwell;
	uint16	active_dwell;
	uint16	bss_widthscan_interval;
	uint16	passive_total;
	uint16	active_total;
	uint16	chanwidth_transition_dly;
	uint16	activity_threshold;
} BWL_POST_PACKED_STRUCT;
typedef struct obss_params obss_params_t;

BWL_PRE_PACKED_STRUCT struct dot11_obss_ie {
	uint8	id;
	uint8	len;
	obss_params_t obss_params;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_obss_ie dot11_obss_ie_t;
#define DOT11_OBSS_SCAN_IE_LEN	sizeof(obss_params_t)	

#define HT_CTRL_LA_TRQ		0x00000002	
#define HT_CTRL_LA_MAI		0x0000003C	
#define HT_CTRL_LA_MAI_SHIFT	2
#define HT_CTRL_LA_MAI_MRQ	0x00000004	
#define HT_CTRL_LA_MAI_MSI	0x00000038	
#define HT_CTRL_LA_MFSI		0x000001C0	
#define HT_CTRL_LA_MFSI_SHIFT	6
#define HT_CTRL_LA_MFB_ASELC	0x0000FE00	
#define HT_CTRL_LA_MFB_ASELC_SH	9
#define HT_CTRL_LA_ASELC_CMD	0x00000C00	
#define HT_CTRL_LA_ASELC_DATA	0x0000F000	
#define HT_CTRL_CAL_POS		0x00030000	
#define HT_CTRL_CAL_SEQ		0x000C0000	
#define HT_CTRL_CSI_STEERING	0x00C00000	
#define HT_CTRL_CSI_STEER_SHIFT	22
#define HT_CTRL_CSI_STEER_NFB	0		
#define HT_CTRL_CSI_STEER_CSI	1		
#define HT_CTRL_CSI_STEER_NCOM	2		
#define HT_CTRL_CSI_STEER_COM	3		
#define HT_CTRL_NDP_ANNOUNCE	0x01000000	
#define HT_CTRL_AC_CONSTRAINT	0x40000000	
#define HT_CTRL_RDG_MOREPPDU	0x80000000	

#define HT_OPMODE_OPTIONAL	0x0001	
#define HT_OPMODE_HT20IN40	0x0002	
#define HT_OPMODE_MIXED	0x0003	
#define HT_OPMODE_NONGF	0x0004	
#define DOT11N_TXBURST		0x0008	
#define DOT11N_OBSS_NONHT	0x0010	

BWL_PRE_PACKED_STRUCT struct vht_cap_ie {
	uint32  vht_cap_info;

	uint16	rx_mcs_map;
	uint16  rx_max_rate;
	uint16  tx_mcs_map;
	uint16	tx_max_rate;
} BWL_POST_PACKED_STRUCT;
typedef struct vht_cap_ie vht_cap_ie_t;

#define VHT_CAP_IE_LEN 12

#define VHT_CAP_INFO_MAX_MPDU_LEN_MASK          0x00000003
#define VHT_CAP_INFO_SUPP_CHAN_WIDTH_MASK       0x0000000c
#define VHT_CAP_INFO_LDPC                       0x00000010
#define VHT_CAP_INFO_SGI_80MHZ                  0x00000020
#define VHT_CAP_INFO_SGI_160MHZ                 0x00000040
#define VHT_CAP_INFO_TX_STBC                    0x00000080
#define VHT_CAP_INFO_RX_STBC_MASK               0x00000700
#define VHT_CAP_INFO_RX_STBC_SHIFT              8
#define VHT_CAP_INFO_SU_BEAMFMR                 0x00000800
#define VHT_CAP_INFO_SU_BEAMFMEE                0x00001000
#define VHT_CAP_INFO_NUM_BMFMR_ANT_MASK         0x0000e000
#define VHT_CAP_INFO_NUM_BMFMR_ANT_SHIFT        13
#define VHT_CAP_INFO_NUM_SOUNDING_DIM_MASK      0x00070000
#define VHT_CAP_INFO_NUM_SOUNDING_DIM_SHIFT     16
#define VHT_CAP_INFO_MU_BEAMFMR                 0x00080000
#define VHT_CAP_INFO_MU_BEAMFMEE                0x00100000
#define VHT_CAP_INFO_TXOPPS                     0x00200000
#define VHT_CAP_INFO_HTCVHT                     0x00400000
#define VHT_CAP_INFO_AMPDU_MAXLEN_EXP_MASK      0x03800000
#define VHT_CAP_INFO_AMPDU_MAXLEN_EXP_SHIFT     23
#define VHT_CAP_INFO_LINK_ADAPT_CAP_MASK        0x0c000000
#define VHT_CAP_INFO_LINK_ADAPT_CAP_SHIFT       26

#define VHT_CAP_SUPP_MCS_RX_HIGHEST_RATE_MASK   0x1fff
#define VHT_CAP_SUPP_MCS_RX_HIGHEST_RATE_SHIFT  0

#define VHT_CAP_SUPP_MCS_TX_HIGHEST_RATE_MASK   0x1fff
#define VHT_CAP_SUPP_MCS_TX_HIGHEST_RATE_SHIFT  0

#define VHT_CAP_MCS_MAP_0_7                     0
#define VHT_CAP_MCS_MAP_0_8                     1
#define VHT_CAP_MCS_MAP_0_9                     2
#define VHT_CAP_MCS_MAP_NONE                    3
#define VHT_CAP_MCS_MAP_S                       2 
#define VHT_CAP_MCS_MAP_M                       0x3 

#define VHT_CAP_MCS_MAP_NONE_ALL                0xffff

#define VHT_CAP_MCS_MAP_0_9_NSS3 \
	        ((VHT_CAP_MCS_MAP_0_9 << VHT_MCS_MAP_GET_SS_IDX(1)) | \
	         (VHT_CAP_MCS_MAP_0_9 << VHT_MCS_MAP_GET_SS_IDX(2)) | \
	         (VHT_CAP_MCS_MAP_0_9 << VHT_MCS_MAP_GET_SS_IDX(3)))

#define VHT_CAP_MCS_MAP_NSS_MAX                 8

#define VHT_CAP_MCS_MAP_CREATE(mcsmap, nss, mcs) \
	do { \
		int i; \
		for (i = 1; i <= nss; i++) { \
			VHT_MCS_MAP_SET_MCS_PER_SS(i, mcs, mcsmap); \
		} \
	} while (0)

#define VHT_MCS_CODE_TO_MCS_MAP(mcs_code) \
	((mcs_code == VHT_CAP_MCS_MAP_0_7) ? 0xff : \
	 (mcs_code == VHT_CAP_MCS_MAP_0_8) ? 0x1ff : \
	 (mcs_code == VHT_CAP_MCS_MAP_0_9) ? 0x3ff : 0)

#define VHT_MCS_MAP_TO_MCS_CODE(mcs_map) \
	((mcs_map == 0xff)  ? VHT_CAP_MCS_MAP_0_7 : \
	 (mcs_map == 0x1ff) ? VHT_CAP_MCS_MAP_0_8 : \
	 (mcs_map == 0x3ff) ? VHT_CAP_MCS_MAP_0_9 : VHT_CAP_MCS_MAP_NONE)

typedef enum vht_cap_chan_width {
	VHT_CAP_CHAN_WIDTH_SUPPORT_MANDATORY = 0x00,
	VHT_CAP_CHAN_WIDTH_SUPPORT_160       = 0x04,
	VHT_CAP_CHAN_WIDTH_SUPPORT_160_8080  = 0x08
} vht_cap_chan_width_t;

typedef enum vht_cap_max_mpdu_len {
	VHT_CAP_MPDU_MAX_4K     = 0x00,
	VHT_CAP_MPDU_MAX_8K     = 0x01,
	VHT_CAP_MPDU_MAX_11K    = 0x02
} vht_cap_max_mpdu_len_t;

#define VHT_MPDU_LIMIT_4K        3895
#define VHT_MPDU_LIMIT_8K        7991
#define VHT_MPDU_LIMIT_11K      11454

BWL_PRE_PACKED_STRUCT struct vht_op_ie {
	uint8	chan_width;
	uint8	chan1;
	uint8	chan2;
	uint16	supp_mcs;  
} BWL_POST_PACKED_STRUCT;
typedef struct vht_op_ie vht_op_ie_t;

#define VHT_OP_IE_LEN 5

typedef enum vht_op_chan_width {
	VHT_OP_CHAN_WIDTH_20_40	= 0,
	VHT_OP_CHAN_WIDTH_80	= 1,
	VHT_OP_CHAN_WIDTH_160	= 2,
	VHT_OP_CHAN_WIDTH_80_80	= 3
} vht_op_chan_width_t;

#define AID_IE_LEN		2

#define VHT_FEATURES_IE_TYPE	0x4
BWL_PRE_PACKED_STRUCT struct vht_features_ie_hdr {
	uint8 oui[3];		
	uint8 type;		
	uint8 rate_mask;	
} BWL_POST_PACKED_STRUCT;
typedef struct vht_features_ie_hdr vht_features_ie_hdr_t;

#define VHT_MCS_MAP_GET_SS_IDX(nss) (((nss)-1) * VHT_CAP_MCS_MAP_S)
#define VHT_MCS_MAP_GET_MCS_PER_SS(nss, mcsMap) \
	(((mcsMap) >> VHT_MCS_MAP_GET_SS_IDX(nss)) & VHT_CAP_MCS_MAP_M)
#define VHT_MCS_MAP_SET_MCS_PER_SS(nss, numMcs, mcsMap) \
	do { \
	 (mcsMap) &= (~(VHT_CAP_MCS_MAP_M << VHT_MCS_MAP_GET_SS_IDX(nss))); \
	 (mcsMap) |= (((numMcs) & VHT_CAP_MCS_MAP_M) << VHT_MCS_MAP_GET_SS_IDX(nss)); \
	} while (0)
#define VHT_MCS_SS_SUPPORTED(nss, mcsMap) \
		 (VHT_MCS_MAP_GET_MCS_PER_SS((nss), (mcsMap)) != VHT_CAP_MCS_MAP_NONE)

#define WPA_OUI			"\x00\x50\xF2"	
#define WPA_OUI_LEN		3		
#define WPA_OUI_TYPE		1
#define WPA_VERSION		1		
#define WPA2_OUI		"\x00\x0F\xAC"	
#define WPA2_OUI_LEN		3		
#define WPA2_VERSION		1		
#define WPA2_VERSION_LEN	2		

#define WPS_OUI			"\x00\x50\xF2"	
#define WPS_OUI_LEN		3		
#define WPS_OUI_TYPE		4

#define WFA_OUI			"\x50\x6F\x9A"	
#define WFA_OUI_LEN		3		
#define WFA_OUI_TYPE_P2P	9

#define WFA_OUI_TYPE_TPC	8

#define RSN_AKM_NONE		0	
#define RSN_AKM_UNSPECIFIED	1	
#define RSN_AKM_PSK		2	
#define RSN_AKM_FBT_1X		3	
#define RSN_AKM_FBT_PSK		4	
#define RSN_AKM_MFP_1X		5	
#define RSN_AKM_MFP_PSK		6	
#define RSN_AKM_TPK			7	

#define DOT11_MAX_DEFAULT_KEYS	4	
#define DOT11_MAX_KEY_SIZE	32	
#define DOT11_MAX_IV_SIZE	16	
#define DOT11_EXT_IV_FLAG	(1<<5)	
#define DOT11_WPA_KEY_RSC_LEN   8       

#define WEP1_KEY_SIZE		5	
#define WEP1_KEY_HEX_SIZE	10	
#define WEP128_KEY_SIZE		13	
#define WEP128_KEY_HEX_SIZE	26	
#define TKIP_MIC_SIZE		8	
#define TKIP_EOM_SIZE		7	
#define TKIP_EOM_FLAG		0x5a	
#define TKIP_KEY_SIZE		32	
#define TKIP_MIC_AUTH_TX	16	
#define TKIP_MIC_AUTH_RX	24	
#define TKIP_MIC_SUP_RX		TKIP_MIC_AUTH_TX	
#define TKIP_MIC_SUP_TX		TKIP_MIC_AUTH_RX	
#define AES_KEY_SIZE		16	
#define AES_MIC_SIZE		8	
#define BIP_KEY_SIZE		16	
#define BIP_MIC_SIZE		8   

#define WCN_OUI			"\x00\x50\xf2"	
#define WCN_TYPE		4	

BWL_PRE_PACKED_STRUCT struct dot11_mdid_ie {
	uint8 id;
	uint8 len;
	uint16 mdid;		
	uint8 cap;
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_mdid_ie dot11_mdid_ie_t;

#define FBT_MDID_CAP_OVERDS	0x01	
#define FBT_MDID_CAP_RRP	0x02	

BWL_PRE_PACKED_STRUCT struct dot11_ft_ie {
	uint8 id;
	uint8 len;
	uint16 mic_control;		
	uint8 mic[16];
	uint8 anonce[32];
	uint8 snonce[32];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_ft_ie dot11_ft_ie_t;

#define TIE_TYPE_RESERVED		0
#define TIE_TYPE_REASSOC_DEADLINE	1
#define TIE_TYPE_KEY_LIEFTIME		2
#define TIE_TYPE_ASSOC_COMEBACK		3
BWL_PRE_PACKED_STRUCT struct dot11_timeout_ie {
	uint8 id;
	uint8 len;
	uint8 type;		
	uint32 value;		
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_timeout_ie dot11_timeout_ie_t;

BWL_PRE_PACKED_STRUCT struct dot11_gtk_ie {
	uint8 id;
	uint8 len;
	uint16 key_info;
	uint8 key_len;
	uint8 rsc[8];
	uint8 data[1];
} BWL_POST_PACKED_STRUCT;
typedef struct dot11_gtk_ie dot11_gtk_ie_t;

BWL_PRE_PACKED_STRUCT struct mmic_ie {
	uint8   id;					
	uint8   len;				
	uint16  key_id;				
	uint8   ipn[6];				
	uint8   mic[BIP_MIC_SIZE];	
} BWL_POST_PACKED_STRUCT;
typedef struct mmic_ie mmic_ie_t;

#define BSSID_INVALID           "\x00\x00\x00\x00\x00\x00"
#define BSSID_BROADCAST         "\xFF\xFF\xFF\xFF\xFF\xFF"

#define WMM_OUI			"\x00\x50\xF2"	
#define WMM_OUI_LEN		3		
#define WMM_OUI_TYPE	2		
#define WMM_VERSION		1
#define WMM_VERSION_LEN	1

#define WMM_OUI_SUBTYPE_PARAMETER	1
#define WMM_PARAMETER_IE_LEN		24

BWL_PRE_PACKED_STRUCT struct link_id_ie {
	uint8 id;
	uint8 len;
	struct ether_addr	bssid;
	struct ether_addr	tdls_init_mac;
	struct ether_addr	tdls_resp_mac;
} BWL_POST_PACKED_STRUCT;
typedef struct link_id_ie link_id_ie_t;
#define TDLS_LINK_ID_IE_LEN		18

BWL_PRE_PACKED_STRUCT struct wakeup_sch_ie {
	uint8 id;
	uint8 len;
	uint32 offset;			
	uint32 interval;		
	uint32 awake_win_slots;	
	uint32 max_wake_win;	
	uint16 idle_cnt;		
} BWL_POST_PACKED_STRUCT;
typedef struct wakeup_sch_ie wakeup_sch_ie_t;
#define TDLS_WAKEUP_SCH_IE_LEN		18

BWL_PRE_PACKED_STRUCT struct channel_switch_timing_ie {
	uint8 id;
	uint8 len;
	uint16 switch_time;		
	uint16 switch_timeout;	
} BWL_POST_PACKED_STRUCT;
typedef struct channel_switch_timing_ie channel_switch_timing_ie_t;
#define TDLS_CHANNEL_SWITCH_TIMING_IE_LEN		4

BWL_PRE_PACKED_STRUCT struct pti_control_ie {
	uint8 id;
	uint8 len;
	uint8 tid;
	uint16 seq_control;
} BWL_POST_PACKED_STRUCT;
typedef struct pti_control_ie pti_control_ie_t;
#define TDLS_PTI_CONTROL_IE_LEN		3

BWL_PRE_PACKED_STRUCT struct pu_buffer_status_ie {
	uint8 id;
	uint8 len;
	uint8 status;
} BWL_POST_PACKED_STRUCT;
typedef struct pu_buffer_status_ie pu_buffer_status_ie_t;
#define TDLS_PU_BUFFER_STATUS_IE_LEN	1
#define TDLS_PU_BUFFER_STATUS_AC_BK		1
#define TDLS_PU_BUFFER_STATUS_AC_BE		2
#define TDLS_PU_BUFFER_STATUS_AC_VI		4
#define TDLS_PU_BUFFER_STATUS_AC_VO		8

#define GAS_REQUEST_ACTION_FRAME				10
#define GAS_RESPONSE_ACTION_FRAME				11
#define GAS_COMEBACK_REQUEST_ACTION_FRAME		12
#define GAS_COMEBACK_RESPONSE_ACTION_FRAME		13

#define IW_ANT_MASK				0x0f
#define IW_INTERNET_MASK		0x10
#define IW_ASRA_MASK			0x20
#define IW_ESR_MASK				0x40
#define IW_UESA_MASK			0x80

#define IW_ANT_PRIVATE_NETWORK					0
#define IW_ANT_PRIVATE_NETWORK_WITH_GUEST		1
#define IW_ANT_CHARGEABLE_PUBLIC_NETWORK		2
#define IW_ANT_FREE_PUBLIC_NETWORK				3
#define IW_ANT_PERSONAL_DEVICE_NETWORK			4
#define IW_ANT_EMERGENCY_SERVICES_NETWORK		5
#define IW_ANT_TEST_NETWORK						14
#define IW_ANT_WILDCARD_NETWORK					15

#define ADVP_ANQP_PROTOCOL_ID	0

#define ADVP_QRL_MASK					0x7f
#define ADVP_PAME_BI_MASK				0x80

#define ADVP_QRL_REQUEST				0x00
#define ADVP_QRL_RESPONSE				0x7f
#define ADVP_PAME_BI_DEPENDENT			0x00
#define ADVP_PAME_BI_INDEPENDENT		ADVP_PAME_BI_MASK

#define ANQP_ID_QUERY_LIST							256
#define ANQP_ID_CAPABILITY_LIST						257
#define ANQP_ID_VENUE_NAME_INFO						258
#define ANQP_ID_EMERGENCY_CALL_NUMBER_INFO			259
#define ANQP_ID_NETWORK_AUTHENTICATION_TYPE_INFO	260
#define ANQP_ID_ROAMING_CONSORTIUM_LIST				261
#define ANQP_ID_IP_ADDRESS_TYPE_AVAILABILITY_INFO	262
#define ANQP_ID_NAI_REALM_LIST						263
#define ANQP_ID_G3PP_CELLULAR_NETWORK_INFO			264
#define ANQP_ID_AP_GEOSPATIAL_LOCATION				265
#define ANQP_ID_AP_CIVIC_LOCATION					266
#define ANQP_ID_AP_LOCATION_PUBLIC_ID_URI			267
#define ANQP_ID_DOMAIN_NAME_LIST					268
#define ANQP_ID_EMERGENCY_ALERT_ID_URI				269
#define ANQP_ID_EMERGENCY_NAI						271
#define ANQP_ID_VENDOR_SPECIFIC_LIST				56797

#define ANQP_OUI_SUBTYPE	9

#define VENUE_LANGUAGE_CODE_SIZE		3
#define VENUE_NAME_SIZE					255

#define VENUE_UNSPECIFIED				0
#define VENUE_ASSEMBLY					1
#define VENUE_BUSINESS					2
#define VENUE_EDUCATIONAL				3
#define VENUE_FACTORY					4
#define VENUE_INSTITUTIONAL				5
#define VENUE_MERCANTILE				6
#define VENUE_RESIDENTIAL				7
#define VENUE_STORAGE					8
#define VENUE_UTILITY					9
#define VENUE_VEHICULAR					10
#define VENUE_OUTDOOR					11

#define NATI_ACCEPTANCE_OF_TERMS_CONDITIONS			0
#define NATI_ONLINE_ENROLLMENT_SUPPORTED			1
#define NATI_HTTP_HTTPS_REDIRECTION					2
#define NATI_DNS_REDIRECTION						3

#define IPA_IPV6_SHIFT						0
#define IPA_IPV6_MASK						(0x03 << IPA_IPV6_SHIFT)
#define	IPA_IPV6_NOT_AVAILABLE				0x00
#define IPA_IPV6_AVAILABLE					0x01
#define IPA_IPV6_UNKNOWN_AVAILABILITY		0x02

#define IPA_IPV4_SHIFT						2
#define IPA_IPV4_MASK						(0x3f << IPA_IPV4_SHIFT)
#define	IPA_IPV4_NOT_AVAILABLE				0x00
#define IPA_IPV4_PUBLIC						0x01
#define IPA_IPV4_PORT_RESTRICT				0x02
#define IPA_IPV4_SINGLE_NAT					0x03
#define IPA_IPV4_DOUBLE_NAT					0x04
#define IPA_IPV4_PORT_RESTRICT_SINGLE_NAT	0x05
#define IPA_IPV4_PORT_RESTRICT_DOUBLE_NAT	0x06
#define IPA_IPV4_UNKNOWN_AVAILABILITY		0x07

#define REALM_ENCODING_RFC4282	0
#define REALM_ENCODING_UTF8		1

#define REALM_EAP_TLS					13
#define REALM_EAP_SIM					18
#define REALM_EAP_TTLS					21
#define REALM_EAP_AKA					23
#define REALM_EAP_PSK					47
#define REALM_EAP_AKAP					50

#define REALM_EXPANDED_EAP						1
#define REALM_NON_EAP_INNER_AUTHENTICATION		2
#define REALM_INNER_AUTHENTICATION_EAP			3
#define REALM_EXPANDED_INNER_EAP				4
#define REALM_CREDENTIAL						5
#define REALM_TUNNELED_EAP_CREDENTIAL			6
#define REALM_VENDOR_SPECIFIC_EAP				221

#define REALM_PAP					1
#define REALM_CHAP					2
#define REALM_MSCHAP				3
#define REALM_MSCHAPV2				4

#define REALM_SIM					1
#define REALM_USIM					2
#define REALM_NFC					3
#define REALM_HARDWARE_TOKEN		4
#define REALM_SOFTOKEN				5
#define REALM_CERTIFICATE			6
#define REALM_USERNAME_PASSWORD		7
#define REALM_SERVER_SIDE			8

#define G3PP_GUD_VERSION		0
#define G3PP_PLMN_LIST_IE		0

#include <packed_section_end.h>

#endif 
