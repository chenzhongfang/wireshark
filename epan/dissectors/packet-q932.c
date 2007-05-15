/* Do not modify this file.                                                   */
/* It is created automatically by the ASN.1 to Wireshark dissector compiler   */
/* .\packet-q932.c                                                            */
/* ../../tools/asn2wrs.py -b -T -e -p q932 -c q932.cnf -s packet-q932-template Addressing-Data-Elements.asn Network-Facility-Extension.asn Network-Protocol-Profile-component.asn Interpretation-component.asn */

/* Input file: packet-q932-template.c */

#line 1 "packet-q932-template.c"
/* packet-q932.c
 * Routines for Q.932 packet dissection
 * 2007  Tomas Kukosa
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
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

#include <epan/packet.h>
#include <epan/prefs.h>
#include <epan/strutil.h>
#include <epan/emem.h>
#include <epan/asn1.h>

#include "packet-ber.h"
#include "packet-q932-ros.h"
#include "packet-q932.h"

#define PNAME  "Q.932"
#define PSNAME "Q932"
#define PFNAME "q932"

/* Initialize the protocol and registered fields */
int proto_q932 = -1;
static int hf_q932_ie_type = -1;
static int hf_q932_ie_len = -1;
static int hf_q932_ie_data = -1;
static int hf_q932_pp = -1;
static int hf_q932_nd = -1;

/*--- Included file: packet-q932-hf.c ---*/
#line 1 "packet-q932-hf.c"
static int hf_q932_NetworkFacilityExtension_PDU = -1;  /* NetworkFacilityExtension */
static int hf_q932_NetworkProtocolProfile_PDU = -1;  /* NetworkProtocolProfile */
static int hf_q932_InterpretationComponent_PDU = -1;  /* InterpretationComponent */
static int hf_q932_presentationAlIowedAddress = -1;  /* AddressScreened */
static int hf_q932_presentationRestricted = -1;   /* NULL */
static int hf_q932_numberNotAvailableDueTolnterworking = -1;  /* NULL */
static int hf_q932_presentationRestrictedAddressScreened = -1;  /* AddressScreened */
static int hf_q932_presentationAllowedAddress = -1;  /* Address */
static int hf_q932_presentationRestrictedAddress = -1;  /* Address */
static int hf_q932_presentationAllowedNumberScreened = -1;  /* NumberScreened */
static int hf_q932_numberNotAvailableDueToInterworking = -1;  /* NULL */
static int hf_q932_presentationRestrictedNumberScreened = -1;  /* NumberScreened */
static int hf_q932_presentationAllowedNumber = -1;  /* PartyNumber */
static int hf_q932_presentationRestrictedNumber = -1;  /* PartyNumber */
static int hf_q932_partyNumber = -1;              /* PartyNumber */
static int hf_q932_screeninglndicator = -1;       /* ScreeningIndicator */
static int hf_q932_partySubaddress = -1;          /* PartySubaddress */
static int hf_q932_screeningIndicator = -1;       /* ScreeningIndicator */
static int hf_q932_unknownPartyNumber = -1;       /* NumberDigits */
static int hf_q932_publicPartyNumber = -1;        /* PublicPartyNumber */
static int hf_q932_nsapEncodedNumber = -1;        /* NsapEncodedNumber */
static int hf_q932_dataPartyNumber = -1;          /* NumberDigits */
static int hf_q932_telexPartyNumber = -1;         /* NumberDigits */
static int hf_q932_privatePartyNumber = -1;       /* PrivatePartyNumber */
static int hf_q932_nationalStandardPartyNumber = -1;  /* NumberDigits */
static int hf_q932_publicTypeOfNumber = -1;       /* PublicTypeOfNumber */
static int hf_q932_publicNumberDigits = -1;       /* NumberDigits */
static int hf_q932_privateTypeOfNumber = -1;      /* PrivateTypeOfNumber */
static int hf_q932_privateNumberDigits = -1;      /* NumberDigits */
static int hf_q932_userSpecifiedSubaddress = -1;  /* UserSpecifiedSubaddress */
static int hf_q932_nSAPSubaddress = -1;           /* NSAPSubaddress */
static int hf_q932_subaddressInformation = -1;    /* SubaddressInformation */
static int hf_q932_oddCountIndicator = -1;        /* BOOLEAN */
static int hf_q932_sourceEntity = -1;             /* EntityType */
static int hf_q932_sourceEntityAddress = -1;      /* AddressInformation */
static int hf_q932_destinationEntity = -1;        /* EntityType */
static int hf_q932_destinationEntityAddress = -1;  /* AddressInformation */

/*--- End of included file: packet-q932-hf.c ---*/
#line 52 "packet-q932-template.c"

/* Initialize the subtree pointers */
static gint ett_q932 = -1;
static gint ett_q932_ie = -1;

/*--- Included file: packet-q932-ett.c ---*/
#line 1 "packet-q932-ett.c"
static gint ett_q932_PresentedAddressScreened = -1;
static gint ett_q932_PresentedAddressUnscreened = -1;
static gint ett_q932_PresentedNumberScreened = -1;
static gint ett_q932_PresentedNumberUnscreened = -1;
static gint ett_q932_AddressScreened = -1;
static gint ett_q932_NumberScreened = -1;
static gint ett_q932_Address = -1;
static gint ett_q932_PartyNumber = -1;
static gint ett_q932_PublicPartyNumber = -1;
static gint ett_q932_PrivatePartyNumber = -1;
static gint ett_q932_PartySubaddress = -1;
static gint ett_q932_UserSpecifiedSubaddress = -1;
static gint ett_q932_NetworkFacilityExtension_U = -1;

/*--- End of included file: packet-q932-ett.c ---*/
#line 57 "packet-q932-template.c"

/* Preferences */

/* ROSE context */
static rose_context q932_rose_ctx;

/* Subdissectors */
static dissector_handle_t data_handle = NULL; 

/* Gloabl variables */


#define	Q932_IE_EXTENDED_FACILITY   0x0D
#define	Q932_IE_FACILITY            0x1C
#define	Q932_IE_NOTIFICATION_INDICATOR  0x27
#define	Q932_IE_INFORMATION_REQUEST 0x32
#define	Q932_IE_FEATURE_ACTIVATION  0x38
#define	Q932_IE_FEATURE_INDICATION  0x39
#define	Q932_IE_SERVICE_PROFILE_ID  0x3A
#define	Q932_IE_ENDPOINT_IDENTIFIER 0x3B
static const value_string q932_str_ie_type[] = {
  { Q932_IE_EXTENDED_FACILITY  , "Extended facility" },
  { Q932_IE_FACILITY           , "Facility" },
  { Q932_IE_NOTIFICATION_INDICATOR, "Notification indicator" },
  { Q932_IE_INFORMATION_REQUEST, "Information request" },
  { Q932_IE_FEATURE_ACTIVATION , "Feature activation" },
  { Q932_IE_FEATURE_INDICATION , "Feature indication" },
  { Q932_IE_SERVICE_PROFILE_ID , "Service profile identification" },
  { Q932_IE_ENDPOINT_IDENTIFIER, "Endpoint identifier" },
  { 0, NULL}
};

static const value_string str_pp[] = {
  { 0x11  , "Remote Operations Protocol" },
  { 0x12  , "CMIP Protocol" },
  { 0x13  , "ACSE Protocol" },
  { 0x1F  , "Networking extensions" },
  { 0, NULL}
};

static const value_string str_nd[] = {
  { 0x00  , "User suspended" },
  { 0x01  , "User resume" },
  { 0x02  , "Bearer service change" },
  { 0x04  , "Call completion delay" },
  { 0x03  , "Discriminator for extension to ASN.1 encoded component" },
  { 0x40  , "Discriminator for extension to ASN.1 encoded component for ISO" },
  { 0x42  , "Conference established" },
  { 0x43  , "Conference disconnected" },
  { 0x44  , "Other party added" },
  { 0x45  , "Isolated" },
  { 0x46  , "Reattached" },
  { 0x47  , "Other party isolated" },
  { 0x48  , "Other party reattached" },
  { 0x49  , "Other party split" },
  { 0x4A  , "Other party disconnected" },
  { 0x4B  , "Conference floating" },
  { 0x4C  , "Conference disconnected, pre-emption" },
  { 0x4F  , "Conference floating, served user pre-empted" },
  { 0x60  , "Call is a waiting call" },
  { 0x68  , "Diversion activated" },
  { 0x69  , "call transferred, alerting" },
  { 0x6A  , "call transferred, answered" },
  { 0x6E  , "reverse charging (whole call)" },
  { 0x6F  , "reverse charging (for the rest of the call)" },
  { 0x74  , "service profile update" },
  { 0x79  , "Remote hold" },
  { 0x7A  , "Remote retrieval" },
  { 0x7B  , "Call is diverting" },
  { 0, NULL}
};


/*--- Included file: packet-q932-fn.c ---*/
#line 1 "packet-q932-fn.c"
/*--- Fields for imported types ---*/




static int
dissect_q932_NumberDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
                                            actx, tree, tvb, offset, hf_index,
                                            NULL);

  return offset;
}
static int dissect_unknownPartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(TRUE, tvb, offset, actx, tree, hf_q932_unknownPartyNumber);
}
static int dissect_dataPartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(TRUE, tvb, offset, actx, tree, hf_q932_dataPartyNumber);
}
static int dissect_telexPartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(TRUE, tvb, offset, actx, tree, hf_q932_telexPartyNumber);
}
static int dissect_nationalStandardPartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(TRUE, tvb, offset, actx, tree, hf_q932_nationalStandardPartyNumber);
}
static int dissect_publicNumberDigits(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(FALSE, tvb, offset, actx, tree, hf_q932_publicNumberDigits);
}
static int dissect_privateNumberDigits(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberDigits(FALSE, tvb, offset, actx, tree, hf_q932_privateNumberDigits);
}


static const value_string q932_PublicTypeOfNumber_vals[] = {
  {   0, "unknown" },
  {   1, "internationalNumber" },
  {   2, "nationalNumber" },
  {   3, "networkSpecificNumber" },
  {   4, "subscriberNumber" },
  {   6, "abbreviatedNumber" },
  { 0, NULL }
};


static int
dissect_q932_PublicTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}
static int dissect_publicTypeOfNumber(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PublicTypeOfNumber(FALSE, tvb, offset, actx, tree, hf_q932_publicTypeOfNumber);
}


static const ber_sequence_t PublicPartyNumber_sequence[] = {
  { BER_CLASS_UNI, BER_UNI_TAG_ENUMERATED, BER_FLAGS_NOOWNTAG, dissect_publicTypeOfNumber },
  { BER_CLASS_UNI, BER_UNI_TAG_NumericString, BER_FLAGS_NOOWNTAG, dissect_publicNumberDigits },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_PublicPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   PublicPartyNumber_sequence, hf_index, ett_q932_PublicPartyNumber);

  return offset;
}
static int dissect_publicPartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PublicPartyNumber(TRUE, tvb, offset, actx, tree, hf_q932_publicPartyNumber);
}



static int
dissect_q932_NsapEncodedNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}
static int dissect_nsapEncodedNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NsapEncodedNumber(TRUE, tvb, offset, actx, tree, hf_q932_nsapEncodedNumber);
}


static const value_string q932_PrivateTypeOfNumber_vals[] = {
  {   0, "unknown" },
  {   1, "level2RegionalNumber" },
  {   2, "level1RegionalNumber" },
  {   3, "pTNSpecificNumber" },
  {   4, "localNumber" },
  {   6, "abbreviatedNumber" },
  { 0, NULL }
};


static int
dissect_q932_PrivateTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}
static int dissect_privateTypeOfNumber(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PrivateTypeOfNumber(FALSE, tvb, offset, actx, tree, hf_q932_privateTypeOfNumber);
}


static const ber_sequence_t PrivatePartyNumber_sequence[] = {
  { BER_CLASS_UNI, BER_UNI_TAG_ENUMERATED, BER_FLAGS_NOOWNTAG, dissect_privateTypeOfNumber },
  { BER_CLASS_UNI, BER_UNI_TAG_NumericString, BER_FLAGS_NOOWNTAG, dissect_privateNumberDigits },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_PrivatePartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   PrivatePartyNumber_sequence, hf_index, ett_q932_PrivatePartyNumber);

  return offset;
}
static int dissect_privatePartyNumber_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PrivatePartyNumber(TRUE, tvb, offset, actx, tree, hf_q932_privatePartyNumber);
}


static const ber_choice_t PartyNumber_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_unknownPartyNumber_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_publicPartyNumber_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_nsapEncodedNumber_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_dataPartyNumber_impl },
  {   4, BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_telexPartyNumber_impl },
  {   5, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_privatePartyNumber_impl },
  {   8, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_nationalStandardPartyNumber_impl },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PartyNumber_choice, hf_index, ett_q932_PartyNumber,
                                 NULL);

  return offset;
}
static int dissect_presentationAllowedNumber(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PartyNumber(FALSE, tvb, offset, actx, tree, hf_q932_presentationAllowedNumber);
}
static int dissect_presentationRestrictedNumber(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PartyNumber(FALSE, tvb, offset, actx, tree, hf_q932_presentationRestrictedNumber);
}
static int dissect_partyNumber(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PartyNumber(FALSE, tvb, offset, actx, tree, hf_q932_partyNumber);
}



int
dissect_q932_ScreeningIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}
static int dissect_screeninglndicator(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ScreeningIndicator(FALSE, tvb, offset, actx, tree, hf_q932_screeninglndicator);
}
static int dissect_screeningIndicator(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ScreeningIndicator(FALSE, tvb, offset, actx, tree, hf_q932_screeningIndicator);
}



static int
dissect_q932_SubaddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}
static int dissect_subaddressInformation(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_SubaddressInformation(FALSE, tvb, offset, actx, tree, hf_q932_subaddressInformation);
}



static int
dissect_q932_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}
static int dissect_oddCountIndicator(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_BOOLEAN(FALSE, tvb, offset, actx, tree, hf_q932_oddCountIndicator);
}


static const ber_sequence_t UserSpecifiedSubaddress_sequence[] = {
  { BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_subaddressInformation },
  { BER_CLASS_UNI, BER_UNI_TAG_BOOLEAN, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_oddCountIndicator },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_UserSpecifiedSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   UserSpecifiedSubaddress_sequence, hf_index, ett_q932_UserSpecifiedSubaddress);

  return offset;
}
static int dissect_userSpecifiedSubaddress(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_UserSpecifiedSubaddress(FALSE, tvb, offset, actx, tree, hf_q932_userSpecifiedSubaddress);
}



static int
dissect_q932_NSAPSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}
static int dissect_nSAPSubaddress(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NSAPSubaddress(FALSE, tvb, offset, actx, tree, hf_q932_nSAPSubaddress);
}


static const ber_choice_t PartySubaddress_choice[] = {
  {   0, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_userSpecifiedSubaddress },
  {   1, BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_nSAPSubaddress },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PartySubaddress_choice, hf_index, ett_q932_PartySubaddress,
                                 NULL);

  return offset;
}
static int dissect_partySubaddress(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_PartySubaddress(FALSE, tvb, offset, actx, tree, hf_q932_partySubaddress);
}


static const ber_sequence_t AddressScreened_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_partyNumber },
  { BER_CLASS_UNI, BER_UNI_TAG_ENUMERATED, BER_FLAGS_NOOWNTAG, dissect_screeninglndicator },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_partySubaddress },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_AddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   AddressScreened_sequence, hf_index, ett_q932_AddressScreened);

  return offset;
}
static int dissect_presentationAlIowedAddress_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_AddressScreened(TRUE, tvb, offset, actx, tree, hf_q932_presentationAlIowedAddress);
}
static int dissect_presentationRestrictedAddressScreened_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_AddressScreened(TRUE, tvb, offset, actx, tree, hf_q932_presentationRestrictedAddressScreened);
}



static int
dissect_q932_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}
static int dissect_presentationRestricted_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NULL(TRUE, tvb, offset, actx, tree, hf_q932_presentationRestricted);
}
static int dissect_numberNotAvailableDueTolnterworking_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NULL(TRUE, tvb, offset, actx, tree, hf_q932_numberNotAvailableDueTolnterworking);
}
static int dissect_numberNotAvailableDueToInterworking_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NULL(TRUE, tvb, offset, actx, tree, hf_q932_numberNotAvailableDueToInterworking);
}


static const ber_choice_t PresentedAddressScreened_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_presentationAlIowedAddress_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_presentationRestricted_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_numberNotAvailableDueTolnterworking_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_presentationRestrictedAddressScreened_impl },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PresentedAddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PresentedAddressScreened_choice, hf_index, ett_q932_PresentedAddressScreened,
                                 NULL);

  return offset;
}


static const ber_sequence_t Address_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_partyNumber },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_partySubaddress },
  { 0, 0, 0, NULL }
};

int
dissect_q932_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   Address_sequence, hf_index, ett_q932_Address);

  return offset;
}
static int dissect_presentationAllowedAddress_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_Address(TRUE, tvb, offset, actx, tree, hf_q932_presentationAllowedAddress);
}
static int dissect_presentationRestrictedAddress_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_Address(TRUE, tvb, offset, actx, tree, hf_q932_presentationRestrictedAddress);
}


static const ber_choice_t PresentedAddressUnscreened_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_presentationAllowedAddress_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_presentationRestricted_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_numberNotAvailableDueTolnterworking_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_presentationRestrictedAddress_impl },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PresentedAddressUnscreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PresentedAddressUnscreened_choice, hf_index, ett_q932_PresentedAddressUnscreened,
                                 NULL);

  return offset;
}


static const ber_sequence_t NumberScreened_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_partyNumber },
  { BER_CLASS_UNI, BER_UNI_TAG_ENUMERATED, BER_FLAGS_NOOWNTAG, dissect_screeningIndicator },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_NumberScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   NumberScreened_sequence, hf_index, ett_q932_NumberScreened);

  return offset;
}
static int dissect_presentationAllowedNumberScreened_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberScreened(TRUE, tvb, offset, actx, tree, hf_q932_presentationAllowedNumberScreened);
}
static int dissect_presentationRestrictedNumberScreened_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_NumberScreened(TRUE, tvb, offset, actx, tree, hf_q932_presentationRestrictedNumberScreened);
}


static const ber_choice_t PresentedNumberScreened_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_presentationAllowedNumberScreened_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_presentationRestricted_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_numberNotAvailableDueToInterworking_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_presentationRestrictedNumberScreened_impl },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PresentedNumberScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PresentedNumberScreened_choice, hf_index, ett_q932_PresentedNumberScreened,
                                 NULL);

  return offset;
}


static const ber_choice_t PresentedNumberUnscreened_choice[] = {
  {   0, BER_CLASS_CON, 0, 0, dissect_presentationAllowedNumber },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_presentationRestricted_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_numberNotAvailableDueToInterworking_impl },
  {   3, BER_CLASS_CON, 3, 0, dissect_presentationRestrictedNumber },
  { 0, 0, 0, 0, NULL }
};

int
dissect_q932_PresentedNumberUnscreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 PresentedNumberUnscreened_choice, hf_index, ett_q932_PresentedNumberUnscreened,
                                 NULL);

  return offset;
}



int
dissect_q932_PresentationAllowedIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}


static const value_string q932_EntityType_vals[] = {
  {   0, "endPINX" },
  {   1, "anyTypeOfPINX" },
  { 0, NULL }
};


static int
dissect_q932_EntityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}
static int dissect_sourceEntity_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_EntityType(TRUE, tvb, offset, actx, tree, hf_q932_sourceEntity);
}
static int dissect_destinationEntity_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_EntityType(TRUE, tvb, offset, actx, tree, hf_q932_destinationEntity);
}



static int
dissect_q932_AddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_q932_PartyNumber(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}
static int dissect_sourceEntityAddress(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_AddressInformation(FALSE, tvb, offset, actx, tree, hf_q932_sourceEntityAddress);
}
static int dissect_destinationEntityAddress(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_AddressInformation(FALSE, tvb, offset, actx, tree, hf_q932_destinationEntityAddress);
}


static const ber_sequence_t NetworkFacilityExtension_U_sequence[] = {
  { BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_sourceEntity_impl },
  { BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_NOTCHKTAG, dissect_sourceEntityAddress },
  { BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_destinationEntity_impl },
  { BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_NOTCHKTAG, dissect_destinationEntityAddress },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_NetworkFacilityExtension_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   NetworkFacilityExtension_U_sequence, hf_index, ett_q932_NetworkFacilityExtension_U);

  return offset;
}



static int
dissect_q932_NetworkFacilityExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_CON, 10, TRUE, dissect_q932_NetworkFacilityExtension_U);

  return offset;
}


static const value_string q932_NetworkProtocolProfile_U_vals[] = {
  {  19, "acse" },
  {  32, "dse" },
  { 0, NULL }
};


static int
dissect_q932_NetworkProtocolProfile_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_q932_NetworkProtocolProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_CON, 18, TRUE, dissect_q932_NetworkProtocolProfile_U);

  return offset;
}


static const value_string q932_InterpretationComponent_U_vals[] = {
  {   0, "discardAnyUnrecognisedInvokePdu" },
  {   1, "clearCallIfAnyInvokePduNotRecognised" },
  {   2, "rejectAnyUnrecognisedInvokePdu" },
  { 0, NULL }
};


static int
dissect_q932_InterpretationComponent_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_q932_InterpretationComponent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_CON, 11, TRUE, dissect_q932_InterpretationComponent_U);

  return offset;
}

/*--- PDUs ---*/

static void dissect_NetworkFacilityExtension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
  dissect_q932_NetworkFacilityExtension(FALSE, tvb, 0, &asn1_ctx, tree, hf_q932_NetworkFacilityExtension_PDU);
}
static void dissect_NetworkProtocolProfile_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
  dissect_q932_NetworkProtocolProfile(FALSE, tvb, 0, &asn1_ctx, tree, hf_q932_NetworkProtocolProfile_PDU);
}
static void dissect_InterpretationComponent_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
  dissect_q932_InterpretationComponent(FALSE, tvb, 0, &asn1_ctx, tree, hf_q932_InterpretationComponent_PDU);
}


/*--- End of included file: packet-q932-fn.c ---*/
#line 130 "packet-q932-template.c"

/*--- dissect_q932_facility_ie -------------------------------------------------------*/
/*static*/ void
dissect_q932_facility_ie(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int length) {
  guint8 class;
  gboolean pc;
  guint32 tag;
  guint32 len;
  int hoffset, eoffset;
  int ie_end;
  tvbuff_t *next_tvb;

  ie_end = offset + length;
  proto_tree_add_item(tree, hf_q932_pp, tvb, offset, 1, FALSE);
  offset++;
  while (offset < ie_end) {
    hoffset = offset;
    offset = get_ber_identifier(tvb, offset, &class, &pc, &tag);
    offset = get_ber_length(tree, tvb, offset, &len, NULL);
    eoffset = offset + len;
    next_tvb =  tvb_new_subset(tvb, hoffset, eoffset - hoffset, eoffset - hoffset);
    switch (class) {
      case BER_CLASS_CON:
        switch (tag) {
          case 10 :  /* Network Facility Extension */
            dissect_NetworkFacilityExtension_PDU(next_tvb, pinfo, tree);
            break;
          case 18 :  /* Network Protocol Profile */
            dissect_NetworkProtocolProfile_PDU(next_tvb, pinfo, tree);
            break;
          case 11 :  /* Interpretation Component */
            dissect_InterpretationComponent_PDU(next_tvb, pinfo, tree);
            break;
          /* ROSE APDU */
          case  1 :  /* invoke */
          case  2 :  /* returnResult */
          case  3 :  /* returnError */
          case  4 :  /* reject */
            q932_rose_ctx.apdu_depth = 1;
            dissect_rose_apdu(next_tvb, pinfo, tree, &q932_rose_ctx);
            break;
          /* DSE APDU */
          case 12 :  /* begin */
          case 14 :  /* end */
          case 15 :  /* continue */
          case 17 :  /* abort */
            offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
            offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
            proto_tree_add_text(tree, tvb, offset, len, "DSE APDU (not supported)");
            break;
          default:
            offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
            offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
            proto_tree_add_text(tree, tvb, offset, len, "Unknown Component");
        }
        break;
      case BER_CLASS_APP:
        switch (tag) {
          /* ACSE APDU */
          case  0 :  /* aarq */
          case  1 :  /* aare */
          case  2 :  /* rlrq */
          case  3 :  /* rlre */
          case  4 :  /* abrt */
            offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
            offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
            proto_tree_add_text(tree, tvb, offset, len, "ACSE APDU (not supported)");
            break;
          default:
            offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
            offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
            proto_tree_add_text(tree, tvb, offset, len, "Unknown Component");
        }
        break;
      default:
        offset = dissect_ber_identifier(pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
        offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
        proto_tree_add_text(tree, tvb, offset, len, "Unknown Component");
    }
    offset = eoffset;
  }
}

/*--- dissect_q932_ni_ie -------------------------------------------------------*/
static void
dissect_q932_ni_ie(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, int length) {
  int remain = length;
  guint8 octet = 0;
  guint32 value = 0;

  while ((remain > 0) && !(octet & 0x80)) {
    octet = tvb_get_guint8(tvb, offset++);
    remain--;
    value <<= 7;
    value |= octet & 0x7F;
  }
  proto_tree_add_uint(tree, hf_q932_nd, tvb, offset - (length - remain), length - remain, value);

  if (remain > 0) {
    proto_tree_add_text(tree, tvb, offset - remain, remain, "ASN.1 Encoded Data Structure(NOT IMPLEMENTED): %s", tvb_bytes_to_str(tvb, offset - remain, remain));
  }
}

/*--- dissect_q932_ie -------------------------------------------------------*/
static void
dissect_q932_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
  gint offset;
  proto_item *ti, *ti_ie;
  proto_tree *ie_tree;
  guint8 ie_type, ie_len;

  offset = 0;

  ti = proto_tree_add_item_hidden(tree, proto_q932, tvb, offset, -1, FALSE);

  ie_type = tvb_get_guint8(tvb, offset);
  ie_len = tvb_get_guint8(tvb, offset + 1);

  ti_ie = proto_tree_add_text(tree, tvb, offset, -1, "%s",
            val_to_str(ie_type, VALS(q932_str_ie_type), "unknown (0x%02X)"));
  ie_tree = proto_item_add_subtree(ti_ie, ett_q932_ie); 
  proto_tree_add_item(ie_tree, hf_q932_ie_type, tvb, offset, 1, FALSE);
  proto_tree_add_item(ie_tree, hf_q932_ie_len, tvb, offset + 1, 1, FALSE);
  offset += 2;
  if (tvb_length_remaining(tvb, offset) <= 0)
    return;
  switch (ie_type) {
    case Q932_IE_FACILITY :
      dissect_q932_facility_ie(tvb, offset, pinfo, ie_tree, ie_len);
      break;
    case Q932_IE_NOTIFICATION_INDICATOR :
      dissect_q932_ni_ie(tvb, offset, pinfo, ie_tree, ie_len);
      break;
    default:
      if (ie_len > 0) {
        if (tree) proto_tree_add_item(ie_tree, hf_q932_ie_data, tvb, offset, ie_len, FALSE);
      }
  }
}

/*--- dissect_q932_apdu -----------------------------------------------------*/
static void
dissect_q932_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
  dissect_rose_apdu(tvb, pinfo, tree, pinfo->private_data);
}

/*--- proto_register_q932 ---------------------------------------------------*/
void proto_register_q932(void) {

  /* List of fields */
  static hf_register_info hf[] = {
    { &hf_q932_ie_type, { "Type", "q932.ie.type",
                          FT_UINT8, BASE_HEX, VALS(q932_str_ie_type), 0x0,
                          "Information Element Type", HFILL }},
    { &hf_q932_ie_len,  { "Length", "q932.ie.len",
                          FT_UINT8, BASE_DEC, NULL, 0x0,
                          "Information Element Length", HFILL }},
    { &hf_q932_ie_data, { "Data", "q932.ie.data",
                          FT_BYTES, BASE_HEX, NULL, 0x0,
                          "Data", HFILL }},
    { &hf_q932_pp,      { "Protocol profile", "q932.pp",
                          FT_UINT8, BASE_HEX, VALS(str_pp), 0x1F,
                          "Protocol profile", HFILL }},
    { &hf_q932_nd,      { "Notification description", "q932.nd",
                          FT_UINT8, BASE_HEX, VALS(str_nd), 0x0,
                          "Notification description", HFILL }},

/*--- Included file: packet-q932-hfarr.c ---*/
#line 1 "packet-q932-hfarr.c"
    { &hf_q932_NetworkFacilityExtension_PDU,
      { "NetworkFacilityExtension", "q932.NetworkFacilityExtension",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NetworkFacilityExtension", HFILL }},
    { &hf_q932_NetworkProtocolProfile_PDU,
      { "NetworkProtocolProfile", "q932.NetworkProtocolProfile",
        FT_UINT32, BASE_DEC, NULL, 0,
        "q932.NetworkProtocolProfile", HFILL }},
    { &hf_q932_InterpretationComponent_PDU,
      { "InterpretationComponent", "q932.InterpretationComponent",
        FT_UINT32, BASE_DEC, NULL, 0,
        "q932.InterpretationComponent", HFILL }},
    { &hf_q932_presentationAlIowedAddress,
      { "presentationAlIowedAddress", "q932.presentationAlIowedAddress",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.AddressScreened", HFILL }},
    { &hf_q932_presentationRestricted,
      { "presentationRestricted", "q932.presentationRestricted",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NULL", HFILL }},
    { &hf_q932_numberNotAvailableDueTolnterworking,
      { "numberNotAvailableDueTolnterworking", "q932.numberNotAvailableDueTolnterworking",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NULL", HFILL }},
    { &hf_q932_presentationRestrictedAddressScreened,
      { "presentationRestrictedAddress", "q932.presentationRestrictedAddress",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.AddressScreened", HFILL }},
    { &hf_q932_presentationAllowedAddress,
      { "presentationAllowedAddress", "q932.presentationAllowedAddress",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.Address", HFILL }},
    { &hf_q932_presentationRestrictedAddress,
      { "presentationRestrictedAddress", "q932.presentationRestrictedAddress",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.Address", HFILL }},
    { &hf_q932_presentationAllowedNumberScreened,
      { "presentationAllowedNumber", "q932.presentationAllowedNumber",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NumberScreened", HFILL }},
    { &hf_q932_numberNotAvailableDueToInterworking,
      { "numberNotAvailableDueToInterworking", "q932.numberNotAvailableDueToInterworking",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NULL", HFILL }},
    { &hf_q932_presentationRestrictedNumberScreened,
      { "presentationRestrictedNumber", "q932.presentationRestrictedNumber",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.NumberScreened", HFILL }},
    { &hf_q932_presentationAllowedNumber,
      { "presentationAllowedNumber", "q932.presentationAllowedNumber",
        FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
        "q932.PartyNumber", HFILL }},
    { &hf_q932_presentationRestrictedNumber,
      { "presentationRestrictedNumber", "q932.presentationRestrictedNumber",
        FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
        "q932.PartyNumber", HFILL }},
    { &hf_q932_partyNumber,
      { "partyNumber", "q932.partyNumber",
        FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
        "q932.PartyNumber", HFILL }},
    { &hf_q932_screeninglndicator,
      { "screeninglndicator", "q932.screeninglndicator",
        FT_UINT32, BASE_DEC, VALS(q932_ScreeningIndicator_vals), 0,
        "q932.ScreeningIndicator", HFILL }},
    { &hf_q932_partySubaddress,
      { "partySubaddress", "q932.partySubaddress",
        FT_UINT32, BASE_DEC, VALS(q932_PartySubaddress_vals), 0,
        "q932.PartySubaddress", HFILL }},
    { &hf_q932_screeningIndicator,
      { "screeningIndicator", "q932.screeningIndicator",
        FT_UINT32, BASE_DEC, VALS(q932_ScreeningIndicator_vals), 0,
        "q932.ScreeningIndicator", HFILL }},
    { &hf_q932_unknownPartyNumber,
      { "unknownPartyNumber", "q932.unknownPartyNumber",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_publicPartyNumber,
      { "publicPartyNumber", "q932.publicPartyNumber",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.PublicPartyNumber", HFILL }},
    { &hf_q932_nsapEncodedNumber,
      { "nsapEncodedNumber", "q932.nsapEncodedNumber",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932.NsapEncodedNumber", HFILL }},
    { &hf_q932_dataPartyNumber,
      { "dataPartyNumber", "q932.dataPartyNumber",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_telexPartyNumber,
      { "telexPartyNumber", "q932.telexPartyNumber",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_privatePartyNumber,
      { "privatePartyNumber", "q932.privatePartyNumber",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.PrivatePartyNumber", HFILL }},
    { &hf_q932_nationalStandardPartyNumber,
      { "nationalStandardPartyNumber", "q932.nationalStandardPartyNumber",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_publicTypeOfNumber,
      { "publicTypeOfNumber", "q932.publicTypeOfNumber",
        FT_UINT32, BASE_DEC, VALS(q932_PublicTypeOfNumber_vals), 0,
        "q932.PublicTypeOfNumber", HFILL }},
    { &hf_q932_publicNumberDigits,
      { "publicNumberDigits", "q932.publicNumberDigits",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_privateTypeOfNumber,
      { "privateTypeOfNumber", "q932.privateTypeOfNumber",
        FT_UINT32, BASE_DEC, VALS(q932_PrivateTypeOfNumber_vals), 0,
        "q932.PrivateTypeOfNumber", HFILL }},
    { &hf_q932_privateNumberDigits,
      { "privateNumberDigits", "q932.privateNumberDigits",
        FT_STRING, BASE_NONE, NULL, 0,
        "q932.NumberDigits", HFILL }},
    { &hf_q932_userSpecifiedSubaddress,
      { "userSpecifiedSubaddress", "q932.userSpecifiedSubaddress",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932.UserSpecifiedSubaddress", HFILL }},
    { &hf_q932_nSAPSubaddress,
      { "nSAPSubaddress", "q932.nSAPSubaddress",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932.NSAPSubaddress", HFILL }},
    { &hf_q932_subaddressInformation,
      { "subaddressInformation", "q932.subaddressInformation",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932.SubaddressInformation", HFILL }},
    { &hf_q932_oddCountIndicator,
      { "oddCountIndicator", "q932.oddCountIndicator",
        FT_BOOLEAN, 8, NULL, 0,
        "q932.BOOLEAN", HFILL }},
    { &hf_q932_sourceEntity,
      { "sourceEntity", "q932.sourceEntity",
        FT_UINT32, BASE_DEC, VALS(q932_EntityType_vals), 0,
        "q932.EntityType", HFILL }},
    { &hf_q932_sourceEntityAddress,
      { "sourceEntityAddress", "q932.sourceEntityAddress",
        FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
        "q932.AddressInformation", HFILL }},
    { &hf_q932_destinationEntity,
      { "destinationEntity", "q932.destinationEntity",
        FT_UINT32, BASE_DEC, VALS(q932_EntityType_vals), 0,
        "q932.EntityType", HFILL }},
    { &hf_q932_destinationEntityAddress,
      { "destinationEntityAddress", "q932.destinationEntityAddress",
        FT_UINT32, BASE_DEC, VALS(q932_PartyNumber_vals), 0,
        "q932.AddressInformation", HFILL }},

/*--- End of included file: packet-q932-hfarr.c ---*/
#line 297 "packet-q932-template.c"
  };

  /* List of subtrees */
  static gint *ett[] = {
    &ett_q932,
    &ett_q932_ie,

/*--- Included file: packet-q932-ettarr.c ---*/
#line 1 "packet-q932-ettarr.c"
    &ett_q932_PresentedAddressScreened,
    &ett_q932_PresentedAddressUnscreened,
    &ett_q932_PresentedNumberScreened,
    &ett_q932_PresentedNumberUnscreened,
    &ett_q932_AddressScreened,
    &ett_q932_NumberScreened,
    &ett_q932_Address,
    &ett_q932_PartyNumber,
    &ett_q932_PublicPartyNumber,
    &ett_q932_PrivatePartyNumber,
    &ett_q932_PartySubaddress,
    &ett_q932_UserSpecifiedSubaddress,
    &ett_q932_NetworkFacilityExtension_U,

/*--- End of included file: packet-q932-ettarr.c ---*/
#line 304 "packet-q932-template.c"
  };

  /* Register protocol and dissector */
  proto_q932 = proto_register_protocol(PNAME, PSNAME, PFNAME);
  register_dissector("q932.apdu", dissect_q932_apdu, proto_q932);

  /* Register fields and subtrees */
  proto_register_field_array(proto_q932, hf, array_length(hf));
  proto_register_subtree_array(ett, array_length(ett));

  /* Register dissector tables */
  q932_rose_ctx.arg_global_dissector_table = register_dissector_table("q932.ros.global.arg", "Q.932 Operation Argument (global opcode)", FT_STRING, BASE_NONE);
  q932_rose_ctx.res_global_dissector_table = register_dissector_table("q932.ros.global.res", "Q.932 Operation Result (global opcode)", FT_STRING, BASE_NONE);
  q932_rose_ctx.arg_local_dissector_table = register_dissector_table("q932.ros.local.arg", "Q.932 Operation Argument (local opcode)", FT_UINT32, BASE_HEX); 
  q932_rose_ctx.res_local_dissector_table = register_dissector_table("q932.ros.local.res", "Q.932 Operation Result (local opcode)", FT_UINT32, BASE_HEX); 
}

/*--- proto_reg_handoff_q932 ------------------------------------------------*/
void proto_reg_handoff_q932(void) {
  dissector_handle_t q932_ie_handle;

  q932_ie_handle = create_dissector_handle(dissect_q932_ie, proto_q932);
  /* Facility */
  dissector_add("q931.ie", (0x00 << 8) | Q932_IE_FACILITY, q932_ie_handle); 
  /* Notification indicator */
  dissector_add("q931.ie", (0x00 << 8) | Q932_IE_NOTIFICATION_INDICATOR, q932_ie_handle); 

  data_handle = find_dissector("data");
}

/*---------------------------------------------------------------------------*/
