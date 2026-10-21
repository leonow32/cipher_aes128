#include "../config.h"
#if COMPONENT_CIPHER_AES128
#include "aes128_ecb.h"
#if AES128_USE_ECB

namespace aes128_ecb {

	static void process(uint8_t *out, const uint8_t *in, size_t length, int mode) {
		esp_aes_context context;
		esp_aes_init(&context);
		esp_aes_setkey(&context, aes128_key, 128);

		for(size_t offset = 0; offset < length; offset += 16) {
			esp_aes_crypt_ecb(&context, mode, in + offset, out + offset);
		}

		esp_aes_free(&context);
	}
	
	void encrypt(uint8_t *ciphertext, const uint8_t *plaintext, size_t length) {
		process(ciphertext, plaintext, length, ESP_AES_ENCRYPT);
	}

	void decrypt(uint8_t *plaintext, const uint8_t *ciphertext, size_t length) {
		process(plaintext, ciphertext, length, ESP_AES_DECRYPT);
	}
}

#endif
#endif
