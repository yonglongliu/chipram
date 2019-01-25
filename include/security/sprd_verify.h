

#ifndef __SPRD_VERIFY_H
#define __SPRD_VERIFY_H

#include<security/sprdsec_header.h>
#include<security/sprd_rsa.h>

void dumpHex(const char *title, uint8_t * data, int len);
void cal_sha256(uint8_t * input, uint32_t bytes_num, uint8_t * output);
bool sprd_verify_cert(uint8_t * hash_key_precert, uint8_t * hash_data, uint8_t * certptr);
uint8_t * sprd_get_sechdr_addr(uint8_t * buf);
uint8_t * sprd_get_code_addr(uint8_t * buf);
uint8_t * sprd_get_cert_addr(uint8_t * buf);
bool sprd_verify_img(uint8_t * hash_key_precert, uint8_t * imgbuf);
SecBoot_Result_Ret sprd_secure_check(uint8_t * current_img_addr,uint8_t * data_header);

#endif	/* !HEADER_AES_H */
