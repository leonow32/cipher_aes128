#ifndef AES128_CBC_H_
#define AES128_CBC_H_
#if COMPONENT_CIPHER_AES128

#include "../uCosmos/uCosmos.h"
#include "../_config/aes128_config.h"
#if AES128_USE_CBC
#include "aes/esp_aes.h"

namespace aes128_cbc {
	// Ciphertext and plaintext must not be the same pointers.
	// Length must be a multiple of 16 bytes.
	void encrypt(uint8_t * ciphertext, const uint8_t * plaintext,  size_t length);
	void decrypt(uint8_t * plaintext,  const uint8_t * ciphertext, size_t length);
}

#endif
#endif
#endif
