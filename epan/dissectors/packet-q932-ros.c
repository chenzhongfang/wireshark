/* Do not modify this file.                                                   */
/* It is created automatically by the ASN.1 to Wireshark dissector compiler   */
/* .\packet-q932-ros.c                                                        */
/* ../../tools/asn2wrs.py -b -T -p q932.ros -c q932-ros.cnf -o q932-ros -s packet-q932-ros-template q932-ros.asn */

/* Input file: packet-q932-ros-template.c */

#line 1 "packet-q932-ros-template.c"
/* packet-q932-ros.c
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

#include <string.h>

#include <epan/packet.h>
#include <epan/prefs.h>
#include <epan/strutil.h>
#include <epan/emem.h>
#include <epan/asn1.h>

#include "packet-ber.h"
#include "packet-q932-ros.h"

#define PNAME  "Q.932 Operations Service Element"
#define PSNAME "Q932.ROS"
#define PFNAME "q932.ros"

/* Initialize the protocol and registered fields */
int proto_rose = -1;

/*--- Included file: packet-q932-ros-hf.c ---*/
#line 1 "packet-q932-ros-hf.c"
static int hf_q932_ros_RoseAPDU_PDU = -1;         /* RoseAPDU */
static int hf_q932_ros_local = -1;                /* T_local */
static int hf_q932_ros_global = -1;               /* T_global */
static int hf_q932_ros_invoke = -1;               /* Invoke */
static int hf_q932_ros_returnResult = -1;         /* ReturnResult */
static int hf_q932_ros_returnError = -1;          /* ReturnError */
static int hf_q932_ros_reject = -1;               /* Reject */
static int hf_q932_ros_invokeId = -1;             /* InvokeId */
static int hf_q932_ros_linkedId = -1;             /* T_linkedId */
static int hf_q932_ros_linkedIdPresent = -1;      /* InvokeId */
static int hf_q932_ros_absent = -1;               /* NULL */
static int hf_q932_ros_opcode = -1;               /* Code */
static int hf_q932_ros_argument = -1;             /* InvokeArgument */
static int hf_q932_ros_result = -1;               /* T_result */
static int hf_q932_ros_resultArgument = -1;       /* ResultArgument */
static int hf_q932_ros_errcode = -1;              /* Code */
static int hf_q932_ros_parameter = -1;            /* T_parameter */
static int hf_q932_ros_problem = -1;              /* T_problem */
static int hf_q932_ros_general = -1;              /* GeneralProblem */
static int hf_q932_ros_invokeProblem = -1;        /* InvokeProblem */
static int hf_q932_ros_returnResultProblem = -1;  /* ReturnResultProblem */
static int hf_q932_ros_returnErrorProblem = -1;   /* ReturnErrorProblem */
static int hf_q932_ros_present = -1;              /* INTEGER */

/*--- End of included file: packet-q932-ros-hf.c ---*/
#line 48 "packet-q932-ros-template.c"

/* Initialize the subtree pointers */

/*--- Included file: packet-q932-ros-ett.c ---*/
#line 1 "packet-q932-ros-ett.c"
static gint ett_q932_ros_Code = -1;
static gint ett_q932_ros_RoseAPDU = -1;
static gint ett_q932_ros_Invoke = -1;
static gint ett_q932_ros_T_linkedId = -1;
static gint ett_q932_ros_ReturnResult = -1;
static gint ett_q932_ros_T_result = -1;
static gint ett_q932_ros_ReturnError = -1;
static gint ett_q932_ros_Reject = -1;
static gint ett_q932_ros_T_problem = -1;
static gint ett_q932_ros_InvokeId = -1;

/*--- End of included file: packet-q932-ros-ett.c ---*/
#line 51 "packet-q932-ros-template.c"

/* Preferences */

/* Subdissectors */
static dissector_handle_t data_handle = NULL; 

/* Gloabl variables */
static rose_context *rose_ctx;

static gint32 code_choice;
static guint32 code_local;
static const gchar *code_global;
static guint32 problem_val;
static gchar problem_str[64];
static tvbuff_t *arg_next_tvb, *res_next_tvb, *err_next_tvb;



/*--- Included file: packet-q932-ros-fn.c ---*/
#line 1 "packet-q932-ros-fn.c"
/*--- Fields for imported types ---*/




static int
dissect_q932_ros_T_local(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  &code_local);

#line 31 "q932-ros.cnf"
  code_choice = 0;

  return offset;
}
static int dissect_local(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_local(FALSE, tvb, offset, actx, tree, hf_q932_ros_local);
}



static int
dissect_q932_ros_T_global(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &code_global);

#line 33 "q932-ros.cnf"
  code_choice = 1;

  return offset;
}
static int dissect_global(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_global(FALSE, tvb, offset, actx, tree, hf_q932_ros_global);
}


static const value_string q932_ros_Code_vals[] = {
  {   0, "local" },
  {   1, "global" },
  { 0, NULL }
};

static const ber_choice_t Code_choice[] = {
  {   0, BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_local },
  {   1, BER_CLASS_UNI, BER_UNI_TAG_OID, BER_FLAGS_NOOWNTAG, dissect_global },
  { 0, 0, 0, 0, NULL }
};

static int
dissect_q932_ros_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 24 "q932-ros.cnf"
  code_choice = -1;
  code_local = -1;
  code_global = "";

  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 Code_choice, hf_index, ett_q932_ros_Code,
                                 NULL);

  return offset;
}
static int dissect_opcode(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_Code(FALSE, tvb, offset, actx, tree, hf_q932_ros_opcode);
}
static int dissect_errcode(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_Code(FALSE, tvb, offset, actx, tree, hf_q932_ros_errcode);
}



static int
dissect_q932_ros_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}
static int dissect_present(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_INTEGER(FALSE, tvb, offset, actx, tree, hf_q932_ros_present);
}



static int
dissect_q932_ros_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}
static int dissect_absent(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_NULL(FALSE, tvb, offset, actx, tree, hf_q932_ros_absent);
}
static int dissect_absent_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_NULL(TRUE, tvb, offset, actx, tree, hf_q932_ros_absent);
}


static const value_string q932_ros_InvokeId_vals[] = {
  {   0, "present" },
  {   1, "absent" },
  { 0, NULL }
};

static const ber_choice_t InvokeId_choice[] = {
  {   0, BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_present },
  {   1, BER_CLASS_UNI, BER_UNI_TAG_NULL, BER_FLAGS_NOOWNTAG, dissect_absent },
  { 0, 0, 0, 0, NULL }
};

static int
dissect_q932_ros_InvokeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 InvokeId_choice, hf_index, ett_q932_ros_InvokeId,
                                 NULL);

  return offset;
}
static int dissect_invokeId(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_InvokeId(FALSE, tvb, offset, actx, tree, hf_q932_ros_invokeId);
}
static int dissect_linkedIdPresent_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_InvokeId(TRUE, tvb, offset, actx, tree, hf_q932_ros_linkedIdPresent);
}


static const value_string q932_ros_T_linkedId_vals[] = {
  {   0, "present" },
  {   1, "absent" },
  { 0, NULL }
};

static const ber_choice_t T_linkedId_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_linkedIdPresent_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_absent_impl },
  { 0, 0, 0, 0, NULL }
};

static int
dissect_q932_ros_T_linkedId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 T_linkedId_choice, hf_index, ett_q932_ros_T_linkedId,
                                 NULL);

  return offset;
}
static int dissect_linkedId(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_linkedId(FALSE, tvb, offset, actx, tree, hf_q932_ros_linkedId);
}



static int
dissect_q932_ros_InvokeArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 59 "q932-ros.cnf"
  gint len;

  len = tvb_length_remaining(tvb, offset);
  if (len)
    proto_tree_add_item(tree, hf_index, tvb, offset, len, FALSE);
  arg_next_tvb = tvb_new_subset(tvb, offset, len, len);

  offset += tvb_length_remaining(tvb, offset);



  return offset;
}
static int dissect_argument(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_InvokeArgument(FALSE, tvb, offset, actx, tree, hf_q932_ros_argument);
}


static const ber_sequence_t Invoke_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_invokeId },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_linkedId },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_opcode },
  { BER_CLASS_ANY, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_argument },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_ros_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "q932-ros.cnf"
  dissector_handle_t arg_handle = NULL;

  arg_next_tvb = NULL;

  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   Invoke_sequence, hf_index, ett_q932_ros_Invoke);

#line 73 "q932-ros.cnf"
  if (code_choice == 0) {
    arg_handle = dissector_get_port_handle(rose_ctx->arg_local_dissector_table, code_local);
  } else if (code_choice == 1) {
    arg_handle = dissector_get_string_handle(rose_ctx->arg_global_dissector_table, code_global);
  } else {
    arg_handle = NULL;
  }

  proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), "  INV:");
  if (!arg_handle || 
      !proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(arg_handle)))) {
    if (code_choice == 0)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %d", code_local);
    else if (code_choice == 1)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %s", code_global);
  }
  if (arg_next_tvb) {
    actx->pinfo->private_data = rose_ctx;
    call_dissector((arg_handle)?arg_handle:data_handle, arg_next_tvb, actx->pinfo, tree);
  }

  return offset;
}
static int dissect_invoke_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_Invoke(TRUE, tvb, offset, actx, tree, hf_q932_ros_invoke);
}



static int
dissect_q932_ros_ResultArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 102 "q932-ros.cnf"
  gint len;

  len = tvb_length_remaining(tvb, offset);
  if (len)
    proto_tree_add_item(tree, hf_index, tvb, offset, len, FALSE);
  res_next_tvb = tvb_new_subset(tvb, offset, len, len);

  offset += tvb_length_remaining(tvb, offset);



  return offset;
}
static int dissect_resultArgument(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_ResultArgument(FALSE, tvb, offset, actx, tree, hf_q932_ros_resultArgument);
}


static const ber_sequence_t T_result_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_opcode },
  { BER_CLASS_ANY, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_resultArgument },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_ros_T_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   T_result_sequence, hf_index, ett_q932_ros_T_result);

  return offset;
}
static int dissect_result(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_result(FALSE, tvb, offset, actx, tree, hf_q932_ros_result);
}


static const ber_sequence_t ReturnResult_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_invokeId },
  { BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_result },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_ros_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 112 "q932-ros.cnf"
  dissector_handle_t res_handle = NULL;

  res_next_tvb = NULL;

  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ReturnResult_sequence, hf_index, ett_q932_ros_ReturnResult);

#line 116 "q932-ros.cnf"
  if (code_choice == 0) {
    res_handle = dissector_get_port_handle(rose_ctx->res_local_dissector_table, code_local);
  } else if (code_choice == 1) {
    res_handle = dissector_get_string_handle(rose_ctx->res_global_dissector_table, code_global);
  } else {
    res_handle = NULL;
  }

  proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), "  RES:");
  if (!res_handle || 
      !proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(res_handle)))) {
    if (code_choice == 0)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %d", code_local);
    else if (code_choice == 1)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %s", code_global);
  }
  if (res_next_tvb) {
    actx->pinfo->private_data = rose_ctx;
    call_dissector((res_handle)?res_handle:data_handle, res_next_tvb, actx->pinfo, tree); 
  }

  return offset;
}
static int dissect_returnResult_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_ReturnResult(TRUE, tvb, offset, actx, tree, hf_q932_ros_returnResult);
}



static int
dissect_q932_ros_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 144 "q932-ros.cnf"

  gint len;

  len = tvb_length_remaining(tvb, offset);
  if (len)
    proto_tree_add_item(tree, hf_index, tvb, offset, len, FALSE);
  res_next_tvb = tvb_new_subset(tvb, offset, len, len);

  offset += tvb_length_remaining(tvb, offset);



  return offset;
}
static int dissect_parameter(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_parameter(FALSE, tvb, offset, actx, tree, hf_q932_ros_parameter);
}


static const ber_sequence_t ReturnError_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_invokeId },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_errcode },
  { BER_CLASS_ANY, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_parameter },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_ros_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 155 "q932-ros.cnf"
  dissector_handle_t err_handle = NULL;

  err_next_tvb = NULL;

  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ReturnError_sequence, hf_index, ett_q932_ros_ReturnError);

#line 159 "q932-ros.cnf"
  if (code_choice == 0) {
    /*err_handle = dissector_get_port_handle(rose_ctx->err_local_dissector_table, code_local);*/
  } else if (code_choice == 1) {
    /*err_handle = dissector_get_string_handle(rose_ctx->err_global_dissector_table, code_global);*/
  } else {
    err_handle = NULL;
  }

  proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), "  ERR:");
  if (!err_handle || 
      !proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(err_handle)))) {
    if (code_choice == 0)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %d", code_local);
    else if (code_choice == 1)
      proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), " %s", code_global);
  }
  if (err_next_tvb) {
    actx->pinfo->private_data = rose_ctx;
    call_dissector((err_handle)?err_handle:data_handle, err_next_tvb, actx->pinfo, tree); 
  }

  return offset;
}
static int dissect_returnError_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_ReturnError(TRUE, tvb, offset, actx, tree, hf_q932_ros_returnError);
}


static const value_string q932_ros_GeneralProblem_vals[] = {
  {   0, "unrecognizedComponent" },
  {   1, "mistypedComponent" },
  {   2, "badlyStructuredComponent" },
  { 0, NULL }
};


static int
dissect_q932_ros_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  &problem_val);

#line 44 "q932-ros.cnf"
  strcpy(problem_str, val_to_str(problem_val, VALS(q932_ros_GeneralProblem_vals), ""));

  return offset;
}
static int dissect_general_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_GeneralProblem(TRUE, tvb, offset, actx, tree, hf_q932_ros_general);
}


static const value_string q932_ros_InvokeProblem_vals[] = {
  {   0, "duplicateInvocation" },
  {   1, "unrecognizedOperation" },
  {   2, "mistypedArgument" },
  {   3, "resourceLimitation" },
  {   4, "releaseInProgress" },
  {   5, "unrecognizedLinkedId" },
  {   6, "linkedResponseUnexpected" },
  {   7, "unexpectedLinkedOperation" },
  { 0, NULL }
};


static int
dissect_q932_ros_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  &problem_val);

#line 46 "q932-ros.cnf"
  strcpy(problem_str, val_to_str(problem_val, VALS(q932_ros_InvokeProblem_vals), ""));

  return offset;
}
static int dissect_invokeProblem_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_InvokeProblem(TRUE, tvb, offset, actx, tree, hf_q932_ros_invokeProblem);
}


static const value_string q932_ros_ReturnResultProblem_vals[] = {
  {   0, "unrecognizedInvocation" },
  {   1, "resultResponseUnexpected" },
  {   2, "mistypedResult" },
  { 0, NULL }
};


static int
dissect_q932_ros_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  &problem_val);

#line 48 "q932-ros.cnf"
  strcpy(problem_str, val_to_str(problem_val, VALS(q932_ros_ReturnResultProblem_vals), ""));

  return offset;
}
static int dissect_returnResultProblem_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_ReturnResultProblem(TRUE, tvb, offset, actx, tree, hf_q932_ros_returnResultProblem);
}


static const value_string q932_ros_ReturnErrorProblem_vals[] = {
  {   0, "unrecognizedInvocation" },
  {   1, "errorResponseUnexpected" },
  {   2, "unrecognizedError" },
  {   3, "unexpectedError" },
  {   4, "mistypedParameter" },
  { 0, NULL }
};


static int
dissect_q932_ros_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  &problem_val);

#line 50 "q932-ros.cnf"
  strcpy(problem_str, val_to_str(problem_val, VALS(q932_ros_ReturnErrorProblem_vals), ""));

  return offset;
}
static int dissect_returnErrorProblem_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_ReturnErrorProblem(TRUE, tvb, offset, actx, tree, hf_q932_ros_returnErrorProblem);
}


static const value_string q932_ros_T_problem_vals[] = {
  {   0, "general" },
  {   1, "invoke" },
  {   2, "returnResult" },
  {   3, "returnError" },
  { 0, NULL }
};

static const ber_choice_t T_problem_choice[] = {
  {   0, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_general_impl },
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_invokeProblem_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_returnResultProblem_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_returnErrorProblem_impl },
  { 0, 0, 0, 0, NULL }
};

static int
dissect_q932_ros_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 T_problem_choice, hf_index, ett_q932_ros_T_problem,
                                 NULL);

  return offset;
}
static int dissect_problem(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_T_problem(FALSE, tvb, offset, actx, tree, hf_q932_ros_problem);
}


static const ber_sequence_t Reject_sequence[] = {
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_invokeId },
  { BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_problem },
  { 0, 0, 0, NULL }
};

static int
dissect_q932_ros_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 184 "q932-ros.cnf"
  problem_str[0] = '\0';

  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   Reject_sequence, hf_index, ett_q932_ros_Reject);

#line 186 "q932-ros.cnf"
  proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rose_ctx->apdu_depth), "  REJ: %s", problem_str);

  return offset;
}
static int dissect_reject_impl(proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_) {
  return dissect_q932_ros_Reject(TRUE, tvb, offset, actx, tree, hf_q932_ros_reject);
}


static const value_string q932_ros_RoseAPDU_vals[] = {
  {   1, "invoke" },
  {   2, "returnResult" },
  {   3, "returnError" },
  {   4, "reject" },
  { 0, NULL }
};

static const ber_choice_t RoseAPDU_choice[] = {
  {   1, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_invoke_impl },
  {   2, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_returnResult_impl },
  {   3, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_returnError_impl },
  {   4, BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_reject_impl },
  { 0, 0, 0, 0, NULL }
};

static int
dissect_q932_ros_RoseAPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 RoseAPDU_choice, hf_index, ett_q932_ros_RoseAPDU,
                                 NULL);

  return offset;
}


static const value_string q932_ros_RejectProblem_vals[] = {
  {   0, "general-unrecognizedPDU" },
  {   1, "general-mistypedPDU" },
  {   2, "general-badlyStructuredPDU" },
  {  10, "invoke-duplicateInvocation" },
  {  11, "invoke-unrecognizedOperation" },
  {  12, "invoke-mistypedArgument" },
  {  13, "invoke-resourceLimitation" },
  {  14, "invoke-releaseInProgress" },
  {  15, "invoke-unrecognizedLinkedId" },
  {  16, "invoke-linkedResponseUnexpected" },
  {  17, "invoke-unexpectedLinkedOperation" },
  {  20, "returnResult-unrecognizedInvocation" },
  {  21, "returnResult-resultResponseUnexpected" },
  {  22, "returnResult-mistypedResult" },
  {  30, "returnError-unrecognizedInvocation" },
  {  31, "returnError-errorResponseUnexpected" },
  {  32, "returnError-unrecognizedError" },
  {  33, "returnError-unexpectedError" },
  {  34, "returnError-mistypedParameter" },
  { 0, NULL }
};


static int
dissect_q932_ros_RejectProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}

/*--- PDUs ---*/

static int dissect_RoseAPDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
  offset = dissect_q932_ros_RoseAPDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_q932_ros_RoseAPDU_PDU);
  return offset;
}


/*--- End of included file: packet-q932-ros-fn.c ---*/
#line 69 "packet-q932-ros-template.c"

/*--- dissect_rose_apdu -----------------------------------------------------*/
int dissect_rose_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, rose_context *rctx) {
  if (rctx)
    rose_ctx = rctx;
  return dissect_RoseAPDU_PDU(tvb, pinfo, tree);
}

/*--- proto_register_rose ---------------------------------------------------*/
void proto_register_rose(void) {

  /* List of fields */
  static hf_register_info hf[] = {

/*--- Included file: packet-q932-ros-hfarr.c ---*/
#line 1 "packet-q932-ros-hfarr.c"
    { &hf_q932_ros_RoseAPDU_PDU,
      { "RoseAPDU", "q932.ros.RoseAPDU",
        FT_UINT32, BASE_DEC, VALS(q932_ros_RoseAPDU_vals), 0,
        "q932_ros.RoseAPDU", HFILL }},
    { &hf_q932_ros_local,
      { "local", "q932.ros.local",
        FT_INT32, BASE_DEC, NULL, 0,
        "q932_ros.T_local", HFILL }},
    { &hf_q932_ros_global,
      { "global", "q932.ros.global",
        FT_OID, BASE_NONE, NULL, 0,
        "q932_ros.T_global", HFILL }},
    { &hf_q932_ros_invoke,
      { "invoke", "q932.ros.invoke",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.Invoke", HFILL }},
    { &hf_q932_ros_returnResult,
      { "returnResult", "q932.ros.returnResult",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.ReturnResult", HFILL }},
    { &hf_q932_ros_returnError,
      { "returnError", "q932.ros.returnError",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.ReturnError", HFILL }},
    { &hf_q932_ros_reject,
      { "reject", "q932.ros.reject",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.Reject", HFILL }},
    { &hf_q932_ros_invokeId,
      { "invokeId", "q932.ros.invokeId",
        FT_UINT32, BASE_DEC, VALS(q932_ros_InvokeId_vals), 0,
        "q932_ros.InvokeId", HFILL }},
    { &hf_q932_ros_linkedId,
      { "linkedId", "q932.ros.linkedId",
        FT_UINT32, BASE_DEC, VALS(q932_ros_T_linkedId_vals), 0,
        "q932_ros.T_linkedId", HFILL }},
    { &hf_q932_ros_linkedIdPresent,
      { "present", "q932.ros.present",
        FT_UINT32, BASE_DEC, VALS(q932_ros_InvokeId_vals), 0,
        "q932_ros.InvokeId", HFILL }},
    { &hf_q932_ros_absent,
      { "absent", "q932.ros.absent",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.NULL", HFILL }},
    { &hf_q932_ros_opcode,
      { "opcode", "q932.ros.opcode",
        FT_UINT32, BASE_DEC, VALS(q932_ros_Code_vals), 0,
        "q932_ros.Code", HFILL }},
    { &hf_q932_ros_argument,
      { "argument", "q932.ros.argument",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932_ros.InvokeArgument", HFILL }},
    { &hf_q932_ros_result,
      { "result", "q932.ros.result",
        FT_NONE, BASE_NONE, NULL, 0,
        "q932_ros.T_result", HFILL }},
    { &hf_q932_ros_resultArgument,
      { "result", "q932.ros.result",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932_ros.ResultArgument", HFILL }},
    { &hf_q932_ros_errcode,
      { "errcode", "q932.ros.errcode",
        FT_UINT32, BASE_DEC, VALS(q932_ros_Code_vals), 0,
        "q932_ros.Code", HFILL }},
    { &hf_q932_ros_parameter,
      { "parameter", "q932.ros.parameter",
        FT_BYTES, BASE_HEX, NULL, 0,
        "q932_ros.T_parameter", HFILL }},
    { &hf_q932_ros_problem,
      { "problem", "q932.ros.problem",
        FT_UINT32, BASE_DEC, VALS(q932_ros_T_problem_vals), 0,
        "q932_ros.T_problem", HFILL }},
    { &hf_q932_ros_general,
      { "general", "q932.ros.general",
        FT_INT32, BASE_DEC, VALS(q932_ros_GeneralProblem_vals), 0,
        "q932_ros.GeneralProblem", HFILL }},
    { &hf_q932_ros_invokeProblem,
      { "invoke", "q932.ros.invoke",
        FT_INT32, BASE_DEC, VALS(q932_ros_InvokeProblem_vals), 0,
        "q932_ros.InvokeProblem", HFILL }},
    { &hf_q932_ros_returnResultProblem,
      { "returnResult", "q932.ros.returnResult",
        FT_INT32, BASE_DEC, VALS(q932_ros_ReturnResultProblem_vals), 0,
        "q932_ros.ReturnResultProblem", HFILL }},
    { &hf_q932_ros_returnErrorProblem,
      { "returnError", "q932.ros.returnError",
        FT_INT32, BASE_DEC, VALS(q932_ros_ReturnErrorProblem_vals), 0,
        "q932_ros.ReturnErrorProblem", HFILL }},
    { &hf_q932_ros_present,
      { "present", "q932.ros.present",
        FT_INT32, BASE_DEC, NULL, 0,
        "q932_ros.INTEGER", HFILL }},

/*--- End of included file: packet-q932-ros-hfarr.c ---*/
#line 83 "packet-q932-ros-template.c"
  };

  /* List of subtrees */
  static gint *ett[] = {

/*--- Included file: packet-q932-ros-ettarr.c ---*/
#line 1 "packet-q932-ros-ettarr.c"
    &ett_q932_ros_Code,
    &ett_q932_ros_RoseAPDU,
    &ett_q932_ros_Invoke,
    &ett_q932_ros_T_linkedId,
    &ett_q932_ros_ReturnResult,
    &ett_q932_ros_T_result,
    &ett_q932_ros_ReturnError,
    &ett_q932_ros_Reject,
    &ett_q932_ros_T_problem,
    &ett_q932_ros_InvokeId,

/*--- End of included file: packet-q932-ros-ettarr.c ---*/
#line 88 "packet-q932-ros-template.c"
  };

  /* Register protocol and dissector */
  proto_rose = proto_register_protocol(PNAME, PSNAME, PFNAME);
  proto_set_cant_toggle(proto_rose);

  /* Register fields and subtrees */
  proto_register_field_array(proto_rose, hf, array_length(hf));
  proto_register_subtree_array(ett, array_length(ett));

}

/*--- proto_reg_handoff_rose ------------------------------------------------*/
void proto_reg_handoff_rose(void) {
  data_handle = find_dissector("data");
}

/*---------------------------------------------------------------------------*/
