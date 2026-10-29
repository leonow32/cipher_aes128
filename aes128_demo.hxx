#if AES128_USE_DEMO_COMMANDS
	#if AES128_USE_ECB
		{"aes128_ecb_e",		aes128_demo::aes128_ecb_encrypt_cmd},
		{"aes128_ecb_d",		aes128_demo::aes128_ecb_decrypt_cmd},
	#endif

	#if AES128_USE_ECB_SOFT
		{"aes128_ecb_soft_e",	aes128_demo::aes128_ecb_soft_encrypt_cmd},
		{"aes128_ecb_soft_d",	aes128_demo::aes128_ecb_soft_decrypt_cmd},
	#endif

	#if AES128_USE_CBC
		{"aes128_cbc_e",		aes128_demo::aes128_cbc_encrypt_cmd},
		{"aes128_cbc_d",		aes128_demo::aes128_cbc_decrypt_cmd},
	#endif

	#if AES128_USE_CBC_SOFT
		{"aes128_cbc_soft_e",	aes128_demo::aes128_cbc_soft_encrypt_cmd},
		{"aes128_cbc_soft_d",	aes128_demo::aes128_cbc_soft_decrypt_cmd},
	#endif
#endif
