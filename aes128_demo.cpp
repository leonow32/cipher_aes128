#include "../config.h"
#if COMPONENT_CIPHER_AES128
#include "aes128_demo.h"
#if AES128_USE_DEMO_COMMANDS

#if PICO_RP2040 || PICO_RP2350
	#include "pico/stdlib.h"
#endif

namespace aes128_demo {

static inline uint64_t get_time_us(void) {
	#if ESP_PLATFORM
		return uint64_t(esp_timer_get_time());
	#elif PICO_RP2040 || PICO_RP2350
		return time_us_64();
	#else
		#warning "Platform not supported"
		return 0;
	#endif
}

#if AES128_USE_ECB

// aes128_ecb/e 00000000000000000000000000000000
// aes128_ecb/d FDE4FBAE4A09E020EFF722969F83832B

// aes128_ecb/e 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// aes128_ecb/d FDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832B

void aes128_ecb_encrypt_cmd(int argc, char * argv[]) {
	uint8_t data[128];
	size_t length;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_ecb::encrypt(data, data, length);
	uint64_t time_2 = get_time_us();
	
	printf("ciphertext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

void aes128_ecb_decrypt_cmd(int argc, char * argv[]) {
	printf("%s\n", __func__);
	uint8_t data[128]  = {0};
	size_t length = 0;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_ecb::decrypt(data, data, length);
	uint64_t time_2 = get_time_us();

	printf("plaintext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

#endif

#if AES128_USE_ECB_SOFT

// aes128_ecb_soft/e 00000000000000000000000000000000
// aes128_ecb_soft/d FDE4FBAE4A09E020EFF722969F83832B

// aes128_ecb_soft/e 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// aes128_ecb_soft/d FDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832BFDE4FBAE4A09E020EFF722969F83832B

void aes128_ecb_soft_encrypt_cmd(int argc, char * argv[]) {
	uint8_t data[128];
	size_t length;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_ecb_soft::encrypt(data, data, length);
	uint64_t time_2 = get_time_us();
	
	printf("ciphertext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

void aes128_ecb_soft_decrypt_cmd(int argc, char * argv[]) {
	printf("%s\n", __func__);
	uint8_t data[128]  = {0};
	size_t length = 0;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_ecb_soft::decrypt(data, data, length);
	uint64_t time_2 = get_time_us();

	printf("plaintext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

#endif

#if AES128_USE_CBC

// aes128_cbc/e 00000000000000000000000000000000
// aes128_cbc/d FDE4FBAE4A09E020EFF722969F83832B

// aes128_cbc/e 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// aes128_cbc/d FDE4FBAE4A09E020EFF722969F83832BEFD8C376CDBAB8DA096E7BCB0673CF8E5EA348D42992D4ACA939162AC47D19F54785948F09766FE5987731325524354A

void aes128_cbc_encrypt_cmd(int argc, char * argv[]) {
	uint8_t data[128];
	size_t length;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_cbc::encrypt(data, data, length);
	uint64_t time_2 = get_time_us();
	
	printf("ciphertext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

void aes128_cbc_decrypt_cmd(int argc, char * argv[]) {
	uint8_t data[128]  = {0};
	size_t length = 0;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_cbc::decrypt(data, data, length);
	uint64_t time_2 = get_time_us();

	printf("plaintext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

#endif

#if AES128_USE_CBC_SOFT

// aes128_cbc_soft/e 00000000000000000000000000000000
// aes128_cbc_soft/d FDE4FBAE4A09E020EFF722969F83832B

// aes128_cbc_soft/e 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// aes128_cbc_soft/d FDE4FBAE4A09E020EFF722969F83832BEFD8C376CDBAB8DA096E7BCB0673CF8E5EA348D42992D4ACA939162AC47D19F54785948F09766FE5987731325524354A

void aes128_cbc_soft_encrypt_cmd(int argc, char * argv[]) {
	uint8_t data[128];
	size_t length;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_cbc_soft::encrypt(data, data, length);
	uint64_t time_2 = get_time_us();
	
	printf("ciphertext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

void aes128_cbc_soft_decrypt_cmd(int argc, char * argv[]) {
	printf("%s\n", __func__);
	uint8_t data[128]  = {0};
	size_t length = 0;
	if(parse_hex_string(argv[1], data, &length, sizeof(data))) return;

	uint64_t time_1 = get_time_us();
	aes128_cbc_soft::decrypt(data, data, length);
	uint64_t time_2 = get_time_us();

	printf("plaintext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", data[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

#endif

}

#endif
#endif
