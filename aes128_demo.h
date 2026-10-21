#ifndef AES128_COMMANDS_H_
#define AES128_COMMANDS_H_

#include "aes128_cbc.h"
#include "aes128_cbc_soft.h"
#include "aes128_ecb.h"
#include "aes128_ecb_soft.h"
#include "../uCosmos/console.h"

namespace aes128_demo {
	#if AES128_USE_ECB
		void aes128_ecb_encrypt_cmd(int argc, char * argv[]);
		void aes128_ecb_decrypt_cmd(int argc, char * argv[]);
	#endif

	#if AES128_USE_ECB_SOFT
		void aes128_ecb_soft_encrypt_cmd(int argc, char * argv[]);
		void aes128_ecb_soft_decrypt_cmd(int argc, char * argv[]);
	#endif

	#if AES128_USE_CBC
		void aes128_cbc_encrypt_cmd(int argc, char * argv[]);
		void aes128_cbc_decrypt_cmd(int argc, char * argv[]);
	#endif

	#if AES128_USE_CBC_SOFT
		void aes128_cbc_soft_encrypt_cmd(int argc, char * argv[]);
		void aes128_cbc_soft_decrypt_cmd(int argc, char * argv[]);
	#endif
}

#endif
