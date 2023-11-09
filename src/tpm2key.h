/*
 *   Copyright (C) 2023 SUSE LLC
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef TPM2KEY_H
#define TPM2KEY_H

#include <openssl/asn1.h>
#include <openssl/bio.h>
#include <tss2_mu.h>
#include "util.h"
#include "tpm2key-asn.h"

bool	tpm2key_basekey(TSSPRIVKEY **tpm2key, const TPM2_HANDLE parent,
			const TPM2B_PUBLIC *sealed_pub,
			const TPM2B_PRIVATE *sealed_priv);

bool	tpm2key_add_policy_policypcr(TSSPRIVKEY *tpm2key,
			const TPML_PCR_SELECTION *pcr_sel);

bool	tpm2key_add_policy_policynv (TSSPRIVKEY *tpm2key,
			TPM2_HANDLE tpm_handle,
			const TPM2B_OPERAND *operand);

bool	tpm2key_add_authpolicy_policyauthorize(TSSPRIVKEY *tpm2key,
			const char *name,
			const TPML_PCR_SELECTION *pcr_sel,
			const TPM2B_PUBLIC *pub_key,
			const TPMT_SIGNATURE *signature,
			TPM2_HANDLE nvindex,
			const TPM2B_OPERAND *operand,
			bool append);

bool	tpm2key_read_file(const char *path, TSSPRIVKEY **tpm2key);

bool	tpm2key_write_file(const char *path, const TSSPRIVKEY *tpm2key);

#endif
