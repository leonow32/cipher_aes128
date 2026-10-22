#include "../_config/_config.h"
#if COMPONENT_CIPHER_AES128
#include "aes128_cbc.h"
#if AES128_USE_CBC

namespace aes128_cbc {

	static void process(uint8_t *out, const uint8_t *in, size_t length, int mode) {
		uint8_t iv_local[16];
		memcpy(iv_local, aes128_iv, sizeof(iv_local));
		
		esp_aes_context context;
		esp_aes_init(&context);
		esp_aes_setkey(&context, aes128_key, 128);
		esp_aes_crypt_cbc(&context, mode, length, iv_local, in, out);
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
