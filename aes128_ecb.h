#ifndef AES128_ECB_H_
#define AES128_ECB_H_
#if COMPONENT_CIPHER_AES128

#include "esp_log.h"
#include "aes128_config.h"
#include "aes/esp_aes.h"

#if AES128_USE_ECB
namespace aes128_ecb {
	// Ciphertext and plaintext must not be the same pointers.
	// Length must be a multiple of 16 bytes.
	void encrypt(uint8_t * ciphertext, const uint8_t * plaintext,  size_t length);
	void decrypt(uint8_t * plaintext,  const uint8_t * ciphertext, size_t length);
}

#endif
#endif
#endif
